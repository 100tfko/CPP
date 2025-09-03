/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:44:47 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/14 10:44:48 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{}

Base * generate(void)
{
	int i = std::rand() % 3;

	switch (i)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	default:
		return new C;
		break;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer to A class instance" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer to B class instance" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer to C class instance" << std::endl;
	else
		std::cout << "Error! Unknow pointer class" << std::endl;

}

//dynamic_cast with reference causes a throw
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference to A class instance" << std::endl;
		return;
    }
	catch (...)
	{}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference to B class instance" << std::endl;
		return;
    }
	catch (...)
	{}


	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference to C class instance" << std::endl;
		return;
    }
	catch (...)
	{}

	std::cout << "Error! Unknow reference class" << std::endl;
}
