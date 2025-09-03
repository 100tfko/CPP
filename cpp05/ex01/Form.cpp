/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:36:55 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/01 13:44:54 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"),  _grade_to_sign(150), _grade_to_execute(150)
{
	this->_signed = false;
	return ;
}

Form::Form(const std::string oname, int osign, int oexecute): _name(oname), _grade_to_sign(osign), _grade_to_execute(oexecute) {
	try
	{
		if (osign < 1 || oexecute < 1)
			throw GradeTooHighException();
		if (osign > 150 || oexecute > 150)
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl; //cerr and endl make redundant flushes but should be ok, cleaning over cleaned
	}
	return ;
}

Form::Form(const Form & other) : _name(other._name),  _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute)
{
	this->_signed = other._signed;
	return ;
}

Form & Form::operator = (const Form & other) {
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

Form::~Form()
{}

std::string	Form::getName() const
{
	return this->_name;
}

int Form::getGradeToSign() const
{
	return this->_grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return this->_grade_to_execute;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

void	Form::beSigned(Bureaucrat &hermes)
{
	try
	{
		if(hermes.getGrade() <= _grade_to_sign)
		{
			this->_signed = true;
			std::cout << hermes.getName() << " signed " << this->getName() << std::endl;
		}
		else
			throw(Form::GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << hermes.getName() << " couldn't sign " << this->_name << " because " << e.what() << std::endl;
	}
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

std::ostream& operator<<(std::ostream& outs, const Form &obj) {
	outs << obj.getName() << ", requires grade to sign " << obj.getGradeToSign() << " and grade to execute " << obj.getGradeToExecute() << std::endl;
 	return outs;
}
