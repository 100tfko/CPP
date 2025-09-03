/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:37:03 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/01 13:44:59 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"


class AForm
{
private:
	const std::string	_name;
	const std::string	_target;
	bool				_signed;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
public:
	AForm();
	AForm(const std::string oname, const std::string otarget, const int osign,  const int oexecute);
	AForm(const AForm &other);
	AForm & operator = (const AForm &other);
	virtual ~AForm();

	std::string		getName() const;
	std::string		getTarget() const;
	int 			getGradeToSign() const;
	int 			getGradeToExecute() const;
	bool			getSigned() const;

	void	beSigned(Bureaucrat &hermes);

	virtual void	execute(Bureaucrat const & executor) const = 0;

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
	class NotSignedException  : public std::exception {
		public:
			const char *what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& outs, const AForm &obj);

#endif
