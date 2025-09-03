/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:36:55 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/01 13:44:39 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Default")
{
	this->_grade = 150;
	return ;
}

Bureaucrat::Bureaucrat(const std::string oname, int ograde): _name(oname)
{
	try
	{
		if (ograde < 1)
		{
			this->_grade = 150;
			throw GradeTooHighException();
		}
		else if (ograde > 150)
		{
			this->_grade = 150;
			throw GradeTooLowException();
		}
		else
			this->_grade = ograde;

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) 
{
	if (this != &other)
		*this = other;
	return ;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat & other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

std::string		Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade < 2)
		{
			throw GradeTooHighException();
		}
		else
 			this->_grade -= 1;
		std::cout << "Bureaucrat " <<  this->_name << " grade increased to: " << this->_grade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade > 149)
		{
			throw GradeTooLowException();
		}
		else
 			this->_grade += 1;
		std::cout << "Bureaucrat " <<  this->_name << " grade decreased to: " << this->_grade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &form)
{
	if(form.getSigned())
		std::cout << this->_name << " couldn't sign " << form.getName() << " because form is already signed" << std::endl;
	else
		form.beSigned(*this);

}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " could not execute " << form.getName() << " because: ";
		std::cerr << e.what() << std::endl;
	}
	
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade you're trying to assign is too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade you're trying to assign is too high");
}

std::ostream& operator<<(std::ostream& outs, const Bureaucrat &obj) {
	outs << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
 	return outs;
}
