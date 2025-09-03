/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:36:55 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/11 10:46:00 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
	(void)other;
}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter & other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() 
{}

static void	_FromChar(std::string str)
{
	char c = str[0];

	if(!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
	std::cout << "char: " << c << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	return;
}

static void	_FromInt(std::string str)
{
	char* endptr;
	errno = 0;
	long n = std::strtol(str.c_str(), &endptr, 10);

	if (*endptr != '\0' || errno == ERANGE || n < INT_MIN || n > INT_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	int i = static_cast<int>(n);

	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(i)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << i << ".0f" << std::endl;
	std::cout << "double: " << i << ".0" << std::endl;
	// could cast i with static_cast<float> for example
}

static void	_FromFloat(std::string str)
{
	char* endptr;
	errno = 0;

	std::string withoutF = str.substr(0, str.length() - 1);
	float f = std::strtof(withoutF.c_str(), &endptr);

	if (*endptr != '\0' || errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
    }

	if (f < 0 || f > 127 || std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(f))))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;

	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX) || std::isnan(f) || std::isinf(f))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "float: " << f << "f" << std::endl; //do i need that f?
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void	_FromDouble(std::string str)
{
	char* endptr;
	errno = 0;
	double d = std::strtod(str.c_str(), &endptr);

	if (*endptr != '\0' || errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
    }

	if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(d))))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;

	if (d < INT_MIN || d > INT_MAX || std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << std::fixed << std::setprecision(6);
	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	
	std::cout << "double: " << (d) << std::endl;
}

static void	_Pseudo(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "-inf" || str == "-inff")
	{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

static int _IdentifyType(std::string str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" ||
	str == "-inf" || str == "-inff")
		return PSEUDO;
	if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])) && !std::isdigit(str[0]))
	    return CHAR;
	
	char* strend;

	if (!str.empty() && (str[str.length() -1] == 'f' || str[str.length() -1] == 'F'))
	{
		std::string withoutF = str.substr(0, str.length() - 1);
		std::strtod(withoutF.c_str(), &strend);
		if (*strend == '\0')
			return FLOAT;
		else
			return -1;
	}

	std::strtol(str.c_str(), &strend, 10);
	if (*strend == '\0')
		return INT;

	std::strtod(str.c_str(), &strend);
	if (*strend == '\0')
		return DOUBLE;

	return -1;
}

void	ScalarConverter::convert(std::string str)
{
	switch (_IdentifyType(str))
	{
		case CHAR:
			_FromChar(str);
			break;
		case INT:
			_FromInt(str);
			break;
		case FLOAT:
			_FromFloat(str);
			break;
		case DOUBLE:
			_FromDouble(str);
			break;
		case PSEUDO:
			_Pseudo(str);
			break;
		default:
			std::cerr << "Error! Invalid literal input" << std::endl;
			break;
	}
}