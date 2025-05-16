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

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed(const Fixed & copy) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return ;
}

Fixed & Fixed::operator = (const Fixed& src) {
		std::cout << "Copy assigment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "serRawBits member function called" << std::endl;
	this->_value = raw;
}
