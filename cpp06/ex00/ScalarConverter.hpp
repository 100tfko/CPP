/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:37:03 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/11 10:46:04 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <cerrno>

enum	scalarTypes
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
};


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter & operator = (const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void	convert(std::string str);
};

#endif
