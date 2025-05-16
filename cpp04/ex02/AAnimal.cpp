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

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor called" << std::endl;
	this->type = "AAnimal";
	return ;
}

AAnimal::AAnimal(std::string type) {
	std::cout << "AAnimal specific constructor called for " << type << std::endl;
	this->type = type;
	return ;
}

AAnimal::AAnimal(const AAnimal & copy) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = copy.type;
	return ;
}

AAnimal & AAnimal::operator = (const AAnimal & src) {
		std::cout << "AAnimal copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called"<< std::endl;
	return ;
}

void	AAnimal::makeSound() const {
	std::cout << "Generic cheap AAnimal sound" << std::endl;
}

std::string	AAnimal::getType() const {
	return (this->type);
}