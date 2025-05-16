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

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << this->_bits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f *(1 << this->_bits));
	//roundf not strictky needed but improves accuracy
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

bool Fixed::operator > (const Fixed& src) const{
	return this->_value > src._value;
}

bool Fixed::operator < (const Fixed& src) const{
	return this->_value < src._value;
}

bool Fixed::operator >= (const Fixed& src) const{
	return this->_value >= src._value;
}

bool Fixed::operator <= (const Fixed& src) const{
	return this->_value <= src._value;
}

bool Fixed::operator == (const Fixed& src) const{
	return this->_value == src._value;
}

bool Fixed::operator != (const Fixed& src) const{
	return this->_value != src._value;
}

Fixed Fixed::operator + (const Fixed& src) const{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator - (const Fixed& src) const{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator * (const Fixed& src) const{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator / (const Fixed& src) const{
	return (Fixed(this->toFloat() / src.toFloat()));
	//no protection against zero
}

Fixed Fixed::operator ++ (int) {
	Fixed	cpy(*this);
	this->_value++;
	return cpy;
}

Fixed Fixed::operator -- (int) {
	Fixed	cpy(*this);
	this->_value--;
	return cpy;
} 

Fixed & Fixed::operator ++ () {
	this->_value++;
	return (*this);
} 

Fixed & Fixed::operator -- () {
	this->_value--;
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

int	Fixed::toInt( void ) const {
	return (this->_value >> this->_bits);
}

float	Fixed::toFloat( void ) const {
	return (static_cast < float > (this->_value) / (1 << this->_bits));
}

std::ostream&	operator << (std::ostream & out, const Fixed & src) {
	return (out << src.toFloat());	
}

//can be shorter with ternariy operators. Some people use getRawBits
Fixed & Fixed::min(Fixed & n1, Fixed & n2) {
	if (n1._value < n2._value)
		return (n1);
	return (n2);
}

Fixed & Fixed::max(Fixed & n1, Fixed & n2) {
	if (n1._value > n2._value)
		return (n1);
	return (n2);
}

const Fixed & Fixed::min(Fixed const& n1, Fixed const& n2) {
	if (n1._value < n2._value)
		return (n1);
	return (n2);
}

const Fixed & Fixed::max(Fixed const& n1, Fixed const& n2) {
	if (n1._value > n2._value)
		return (n1);
	return (n2);
}