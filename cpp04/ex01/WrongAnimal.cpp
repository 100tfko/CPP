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

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
	return ;
}

WrongAnimal::WrongAnimal(std::string type) {
	std::cout << "WrongAnimal specific constructor called for " << type << std::endl;
	this->type = type;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal & copy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return ;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal & src) {
		std::cout << "WrongAnimal copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called"<< std::endl;
	return ;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Generic cheap WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}