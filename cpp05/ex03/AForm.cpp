/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:36:55 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/01 13:44:54 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Default"), _target("DefaultTarget") ,  _grade_to_sign(150), _grade_to_execute(150)
{
	this->_signed = false;
	return ;
}

AForm::AForm(const std::string oname, const std::string otarget, int osign, int oexecute): _name(oname), _target(otarget), _grade_to_sign(osign), _grade_to_execute(oexecute)
{

	try
	{
		if (osign < 1 || oexecute < 1)
			throw GradeTooHighException();
		if (osign > 150 || oexecute > 150)
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl; //endl hace flush redundante
	}
	return ;
}

AForm::AForm(const AForm & other) : _name(other._name),  _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
	this->_signed = other._signed;
	return ;
}

AForm & AForm::operator = (const AForm & other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm()
{}

std::string	AForm::getName() const
{
	return this->_name;
}

std::string	AForm::getTarget() const
{
	return this->_target;
}

int AForm::getGradeToSign() const
{
	return this->_grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return this->_grade_to_execute;
}

bool	AForm::getSigned() const
{
	return this->_signed;
}

void	AForm::beSigned(Bureaucrat &hermes)
{
	try
	{
		if(hermes.getGrade() <= _grade_to_sign)
		{
			this->_signed = true;
			std::cout << hermes.getName() << " signed " << this->getName() << std::endl;
		}
		else
			throw(AForm::GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << hermes.getName() << " couldn't sign " << this->_name << " because " << e.what() << std::endl;
	}
	
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::NotSignedException::what() const throw() {

	return ("Form Not Signed");
}

std::ostream& operator<<(std::ostream& outs, const AForm &obj) {
	outs << obj.getName() << ", requires grade to sign " << obj.getGradeToSign() << " and grade to execute " << obj.getGradeToExecute() << std::endl;
 	return outs;
}
