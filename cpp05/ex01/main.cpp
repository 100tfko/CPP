/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:22:59 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/01 12:23:05 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main (void)
{
	Bureaucrat	hermes("Hermes", 36);
	Form		c_42("super important stuff", 10, 10);
	Bureaucrat  numberone("Number One Dot Zero", 1);
	
	std::cout << c_42;
	std::cout << hermes;
	std::cout << numberone;
	hermes.signForm(c_42);
	numberone.signForm(c_42);
}
