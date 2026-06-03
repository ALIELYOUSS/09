#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

int RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");

			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			int result;

			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "*")
				result = a * b;
			else // token == "/"
			{
				if (b == 0)
					throw std::runtime_error("Error");
				result = a / b;
			}

			_stack.push(result);
		}
		else
		{
			// Validate it's a single digit number
			if (token.length() != 1 || !std::isdigit(token[0]))
				throw std::runtime_error("Error");

			int num = std::atoi(token.c_str());
			_stack.push(num);
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return (_stack.top());
}
