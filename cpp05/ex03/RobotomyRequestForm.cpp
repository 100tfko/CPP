/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:50:15 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/02 11:41:45 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm ("Robotomy", "DefaultTarget", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm ("Robotomy", target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) 
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw(RobotomyRequestForm::NotSignedException());
	else if (getGradeToExecute() < executor.getGrade())
		throw(RobotomyRequestForm::GradeTooLowException());
	else
	{
		std::cout << "BRRRRR*drilling noises*rrrrr" << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << this->getTarget() << " robotomization completed succesfully!" << std::endl;
		else
			std::cout << this->getTarget() << " robotomitacion failed succesfully!" << std::endl;
	}
}


