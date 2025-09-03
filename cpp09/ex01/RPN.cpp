/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:28:24 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/08/08 12:28:25 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{}

bool RPN::isNumber(const std::string &tmp) const
{
	int i = 0;
	if (tmp[0] == '-')
		i = 1;
	if (tmp.size() == (unsigned long)(i + 1) && std::isdigit(tmp[i]))
		return true;
	return false;
}

bool RPN::isOperator(const std::string &token) const
{
	if (token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
                                 token[0] == '*' || token[0] == '/'))
		return true;
	return false;
}

int RPN::operate(int a, int b, char op) const
{
    switch (op)
	{
        case '+':
			return a + b;
        case '-':
			return a - b;
        case '*':
			return a * b;
        case '/':
            if (b == 0)
				throw std::runtime_error("Error");
            return a / b;
    }
    throw std::runtime_error("Error");
}

bool RPN::Calculator(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string tmp;

    while (iss >> tmp) //maybe I should check errors in a more strick way
	{
        if (isNumber(tmp))
		{
            stack.push(std::atoi(tmp.c_str())); //also check if I should handle more erros or atoi does it for me
        }
        else if (isOperator(tmp))
		{
            if (stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return false;
            }
            int b = stack.top();
			stack.pop();
            int a = stack.top();
			stack.pop();
            
			try
			{
                stack.push(operate(a, b, tmp[0]));
            } 
			catch (const std::runtime_error &e)
			{
                std::cerr << e.what() << std::endl;
                return false;
            }
        }
        else
		{
            std::cerr << "Error" << std::endl;
            return false;
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return false;
    }

    std::cout << stack.top() << std::endl;
    return true;
}

