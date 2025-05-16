/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:58:55 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/17 12:58:56 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


int	main (void) {
	std::string	string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Adress of the variable: " << &string << std::endl;
	std::cout << "Adress held in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "String value: " << string << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringRED: " << stringREF << std::endl;

	return (0);
}
