/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardon.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:50:15 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/02 12:49:12 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm ("Pardon", "DefaultTarget", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm ("Pardon", target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) 
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}
 
PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw(PresidentialPardonForm::NotSignedException());
	else if (getGradeToExecute() < executor.getGrade())
		throw(PresidentialPardonForm::GradeTooLowException());
	else
	{
		std::cout << this->getTarget() << " has been pardonded ny Zaphod Beeblebrox" << std::endl;
	}
}


