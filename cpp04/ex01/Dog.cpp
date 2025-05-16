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

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
	return ;
}

Dog::Dog(const Dog & copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.type;
	this->_brain = new Brain(*copy._brain);
	return ;
}

Dog & Dog::operator = (const Dog & src) {
		std::cout << "Dog copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called"<< std::endl;
	delete this->_brain;
	return ;
}

void	Dog::makeSound() const {
	std::cout << "Bark bark!" << std::endl;
}
