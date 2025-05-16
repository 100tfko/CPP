/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:12:18 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/29 10:12:19 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid arguments" << std::endl;
		return (1);
	}

	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Error: Strings cannot be empty" << std::endl;
		return (1);
	}
	
	std::ifstream infile(argv[1]);
	if (!infile.is_open()) // can use .fail or !infile
	{
		std::cerr << "Error: Could not open file" << std::endl;
		return (1);
	}
	
	std::string	outf = std::string(argv[1]) + ".replace";
	std::ofstream outfile(outf.c_str());
	if (outfile.fail()) //can do !outfile
	{
		std::cerr << "Error: Could not create file" << std::endl;
		return (1);
	}

	std::string	str;
	while (std::getline(infile, str))
	{
		for (size_t i = 0; (i = str.find(s1, i)) != std::string::npos; i += s1.length()) {
			str.erase(i, s1.length());
			str.insert(i, s2);
		}
		outfile << str << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}