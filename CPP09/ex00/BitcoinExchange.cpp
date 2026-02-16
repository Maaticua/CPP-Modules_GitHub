/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:42:38 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/16 12:21:08 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {*this = src;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		this->_data = src._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		std::exit(1);
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t sep = line.find(',');
		if (sep != std::string::npos)
		{
			std::string date = line.substr(0, sep);
			float rate = static_cast<float>(std::atof(line.substr(sep + 1).c_str()));
			_data[date] = rate;
		}
	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int y = std::atoi(date.substr(0, 4).c_str());
	int m = std::atoi(date.substr(5, 2).c_str());
	int d = std::atoi(date.substr(8, 2).c_str());

	if (y < 2000 || m < 1 || m > 12 || d < 1 || d > 31)
		return false;
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
		days[1] = 29;
	return d <= days[m - 1];
}

std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it =_data.lower_bound(date);
	if (it != _data.end() && it->first == date)
		return it->second;
	if (it == _data.begin())
		return 0;
	it--;
	return it->second;
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, sep));
		std::string valStr = trim(line.substr(sep + 1));

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		char *endptr;
		double val = std::strtod(valStr.c_str(), &endptr);
		if (*endptr != '\0' && !isspace(*endptr))
		{
			std::cout << "Error: bad input => " << valStr << std::endl;
			continue;
		}
		if (val < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (val > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			float rate = getExchangeRate(date);
			std::cout << date << " => " << valStr << " = " << (val * rate) << std::endl;
		}
	}
}