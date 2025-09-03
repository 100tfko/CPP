/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:37:03 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/01 13:43:55 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string oname, int ograde);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat & operator = (const Bureaucrat &other);
	~Bureaucrat();

	std::string		getName() const;
	int 			getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

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

	//I can define this small personalized class exceptions that inherits from std::exception
	//then I define them in this .cpp
	// this is because the Subjects tell me that I do not need COplien for exceptions

};

std::ostream& operator<<(std::ostream& outs, const Bureaucrat &obj);

#endif
