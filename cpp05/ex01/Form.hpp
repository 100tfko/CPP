/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:37:03 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/01 13:44:59 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
public:
	Form();
	Form(const std::string oname, const int osign,  const int oexecute);
	Form(const Form &other);
	Form & operator = (const Form &other);
	~Form();

	std::string		getName() const;
	int 			getGradeToSign() const;
	int 			getGradeToExecute() const;
	bool			getSigned() const;

	void	beSigned(Bureaucrat &hermes);

	class GradeTooHighException: public std::exception
	{
		public:
			const char *what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
			const char *what() const throw();
	};

	//es una manera de definir custom exceptions classes



};

std::ostream& operator<<(std::ostream& outs, const Form &obj);


#endif
