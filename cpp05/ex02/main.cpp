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

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime> // time seed

int main (void)
{
	std::srand(std::time(NULL)); // seeding time only once per program
	
	
	Bureaucrat	fry("Philippe J. Fry", 150);
	Bureaucrat  numberone("Number One Dot Zero", 5);
	std::cout << fry;
	std::cout << numberone;
	std::cout << std::endl;

	ShrubberyCreationForm		shrub("trees");
	RobotomyRequestForm			robotomy("NooNoo");
	PresidentialPardonForm		pardon("Rebel Scum");
	std::cout << shrub;
	std::cout << robotomy;
	std::cout << pardon;
	std::cout << std::endl;


	fry.signForm(shrub);
	numberone.executeForm(shrub);
	numberone.signForm(shrub);
	numberone.executeForm(shrub);
	fry.executeForm(shrub);
	std::cout << std::endl;

	std::cout << robotomy;
	numberone.signForm(robotomy);
	numberone.executeForm(robotomy);
	std::cout << std::endl;

	std::cout << pardon;
	numberone.signForm(pardon);
	numberone.executeForm(pardon);
	numberone.decrementGrade();
	numberone.executeForm(pardon);
	std::cout << std::endl;
}
