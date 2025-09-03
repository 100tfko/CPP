/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:28:20 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/08/08 12:28:21 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>

class RPN
{
	private:
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		bool	isNumber(const std::string &token) const;
		bool	isOperator(const std::string &token) const;
		int		operate(int a, int b, char op) const;

	public:
		RPN();
		~RPN();

		bool Calculator(const std::string &expression);
};

#endif