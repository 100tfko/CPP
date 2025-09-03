/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:50:09 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/08/06 10:50:11 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	data;
		int								_loadFlag;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		bool	isValidDate(const std::string& date);
		bool	value(const std::string &amountStr, std::map<std::string, float>::iterator it, std::string date);
		void	loadCSV();
	public:
		BitcoinExchange(std::string input);
		~BitcoinExchange();

		void	printMap() const;
		void	loadInput(const std::string& file);
		int		getLoadFlag();
};

#endif