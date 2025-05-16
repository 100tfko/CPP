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

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
	return ;
}

Animal::Animal(std::string type) {
	std::cout << "Animal specific constructor called for " << type << std::endl;
	this->type = type;
	return ;
}

Animal::Animal(const Animal & copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return ;
}

Animal & Animal::operator = (const Animal & src) {
		std::cout << "Animal copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called"<< std::endl;
	return ;
}

void	Animal::makeSound() const {
	std::cout << "Generic cheap animal sound" << std::endl;
}

std::string	Animal::getType() const {
	return (this->type);
}