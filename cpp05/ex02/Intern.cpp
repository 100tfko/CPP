/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:34:12 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/02 13:34:14 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
	*this = other;
}
		
Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		*this = other;
	return *this;
}
		
Intern::~Intern()
{}

		
AForm *Intern::makeForm(std::string name, std::string target)
{

	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i = 0;
	
	while (i < 3)
	{
		if (forms[i] == name)
			break ;
		i++;
	}
	switch (i) {
		case 0:
			std::cout << "Intern creates a Presidential Pardon Form" << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates a Robotomy Request Form" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates a Shrubbery Creation Form" << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Requested Form doesn't exist" << std::endl;
			return (NULL);
	}
}