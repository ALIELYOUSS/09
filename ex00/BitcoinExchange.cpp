#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return (false);

	std::string line;
	std::getline(file, line); // Skip header

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t comma_pos = line.find(',');
		if (comma_pos == std::string::npos)
			continue;

		std::string date = line.substr(0, comma_pos);
		std::string price_str = line.substr(comma_pos + 1);

		char* endptr;
		float price = std::strtof(price_str.c_str(), &endptr);

		if (*endptr != '\0')
			continue;

		_database[date] = price;
	}

	file.close();
	return (true);
}

float BitcoinExchange::getExchangeRate(const std::string& date)
{
	std::map<std::string, float>::iterator it = _database.find(date);
	
	if (it != _database.end())
		return (it->second);

	it = _database.lower_bound(date);
	
	if (it == _database.begin())
		return (-1);

	--it;
	return (it->second);
}

bool isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return (false);
	}

	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);

	return (true);
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line); // Skip header

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::istringstream iss(line);
		std::string date;
		std::string value_str;
		char delimiter;

		if (!(iss >> date >> delimiter >> value_str))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		// Validate date format and content
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		// Parse and validate value
		char* endptr;
		float value = std::strtof(value_str.c_str(), &endptr);

		if (*endptr != '\0')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		float rate = getExchangeRate(date);
		if (rate == -1)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}

	file.close();
}
