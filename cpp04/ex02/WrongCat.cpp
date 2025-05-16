/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:36:55 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/11/15 12:36:57 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
	return ;
}

WrongCat::WrongCat(const WrongCat & copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return ;
}

WrongCat & WrongCat::operator = (const WrongCat & src) {
		std::cout << "WrongCat copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called"<< std::endl;
	return ;
}

void	WrongCat::makeSound() const {
	std::cout << "WrongMeow..." << std::endl;
}
