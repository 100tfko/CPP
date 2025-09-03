/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:50:06 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/08/06 10:50:07 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::string input)
{
	(void)input;
	this->_loadFlag = 0;
	loadCSV();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->data = other.data;
	this->_loadFlag = other._loadFlag;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->data = other.data;
		this->_loadFlag = other._loadFlag;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

int	BitcoinExchange::getLoadFlag()
{
	return this->_loadFlag;
}

void	BitcoinExchange::loadCSV()
{
	std::ifstream	csv("data.csv");
	std::string		line;

	if (!csv.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl; // un throw standar error?
		return ;
	}
	std::getline(csv, line); // need to skip for the next loop to work

	while (std::getline(csv, line))
	{
		std::istringstream stringstream(line);
		std::string date, xrate;

		if (std::getline(stringstream, date, ',') && std::getline(stringstream, xrate))
		{
			std::stringstream ratestream(xrate);
			float rate;
			ratestream >> rate;

			if (!ratestream.fail())
				data[date] = rate;
		}
	}
	csv.close();
	this->_loadFlag = 1;
}

bool	BitcoinExchange::value(const std::string &amountStr, std::map<std::string, float>::iterator it, std::string date)
{
	double	amount;
	std::istringstream as(amountStr);
	as >> amount;
	if (amount < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (amount > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	float rate = it->second; //could save this line
	double result = amount * rate;
	std::cout << date << " => " << amount << " = " << result << std::endl;
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	int	day = std::atoi(date.substr(8, 10).c_str());
	int	month = std::atoi(date.substr(5, 7).c_str());
	int	year = std::atoi(date.substr(0, 4).c_str());

	if (day < 1 || month < 1 || year < 1)
		return false;

	char len[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

	if (month < 1 || month > 12)
		return false;
	if (month == 2 && year % 4 == 0 && day == 29)
		return true;
	if (day > len[month - 1])
		return false;

	return true;
}

void BitcoinExchange::loadInput(const std::string& file)
{
	std::ifstream	input(file.c_str());
	std::string		line;

	if (!input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::getline(input, line); // need to skip for the next loop to work

	while (std::getline(input, line))
	{
		std::istringstream stringstream(line);
		std::string date, amountStr ;

		std::getline(stringstream >> std::ws, date, '|');
		std::getline(stringstream >> std::ws, amountStr);

		if (stringstream.fail())
		{
		    std::cerr << "Error: bad input => " << line << std::endl;
		    continue;
		}
		// erase trailing spaces
		date.erase(date.find_last_not_of(" \t") + 1);

		if (!BitcoinExchange::isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = data.lower_bound(date);
		if (it == data.end() || it->first != date)
		{
			if (it == data.begin()) {
				std::cerr << "Error: no exchange rate available for date: " << date << std::endl;
				continue;
			}
			--it; // go to the previous (lower) date
		}

		if (BitcoinExchange::value(amountStr, it, date))
			continue;
	}
}

//debug function to show map contents
void BitcoinExchange::printMap() const
{
	std::map<std::string, float>::const_iterator it;

	for (it = data.begin(); it != data.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}
