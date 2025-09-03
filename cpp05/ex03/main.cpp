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

#include "Intern.hpp"
#include <ctime>

int main (void)
{
	std::srand(std::time(NULL));

	Bureaucrat	fry("Philippe J. Fry", 150);
	Bureaucrat  numberone("Number One Dot Zero", 5);
	std::cout << fry;
	std::cout << numberone;
	std::cout << std::endl;

	Intern		npc;

	AForm	*shrub = npc.makeForm("shrubbery", "orchard");
	AForm	*robotomy = npc.makeForm("robotomy", "Bender");
	AForm	*pardon = npc.makeForm("pardon", "Rebel Scum");
	std::cout << std::endl;


	std::cout << *shrub;
	fry.signForm(*shrub);
	numberone.executeForm(*shrub);
	numberone.signForm(*shrub);
	numberone.executeForm(*shrub);
	fry.executeForm(*shrub);
	std::cout << std::endl;

	std::cout << *robotomy;
	numberone.signForm(*robotomy);
	numberone.executeForm(*robotomy);
	std::cout << std::endl;

	std::cout << *pardon;
	numberone.signForm(*pardon);
	numberone.executeForm(*pardon);
	numberone.decrementGrade();
	numberone.executeForm(*pardon);
	std::cout << std::endl;

	delete shrub;
	delete robotomy;
	delete pardon;
}


/* #include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    try {
        Intern  randomIntern;
        AForm	*formSh = randomIntern.makeForm("shrubbery creation", "Butterfree");
        AForm	*formRo = randomIntern.makeForm("robotomy request", "Pikachu");
        AForm	*formPr = randomIntern.makeForm("presidential pardon", "Charmander");
        Bureaucrat bureaucrat("Ash", 1);

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(*formSh);
        bureaucrat.executeForm(*formSh);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(*formRo);
        bureaucrat.executeForm(*formRo);
        bureaucrat.executeForm(*formRo);
        bureaucrat.executeForm(*formRo);
        bureaucrat.executeForm(*formRo);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(*formPr);
        bureaucrat.executeForm(*formPr);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
} */