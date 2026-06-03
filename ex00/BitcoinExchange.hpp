#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_database;

	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

public:
	BitcoinExchange();
	~BitcoinExchange();

	bool	loadDatabase(const std::string& filename);
	void	processInput(const std::string& filename);
	float	getExchangeRate(const std::string& date);
};

#endif
