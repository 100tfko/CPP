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

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
	return ;
}

Cat::Cat(const Cat & copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = copy.type;
	this->_brain = new Brain(*copy._brain);
	return ;
}

Cat & Cat::operator = (const Cat & src) {
		std::cout << "Cat copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called"<< std::endl;
	delete this->_brain;
	return ;
}

void	Cat::makeSound() const {
	std::cout << "Meow..." << std::endl;
}
