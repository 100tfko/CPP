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

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hitpoints= 10;
	std::cout << "ClapTrap initiated at " << this->_hitpoints << " hitpoints" << std::endl;
	this->_energypoints = 10;
	std::cout << "ClapTrap initiated at " << this->_energypoints << " energy points" << std::endl;
	this->_attackdamage = 0;
	std::cout << "ClapTrap initiated at " << this->_attackdamage << " attack power" << std::endl;
	std::cout << "ClapTrap build finished" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap name constructor called with name " << name << std::endl;
	this->_name = name;
	this->_hitpoints= 10;
	std::cout << "ClapTrap initiated at " << this->_hitpoints << " hitpoints" << std::endl;
	this->_energypoints = 10;
	std::cout << "ClapTrap initiated at " << this->_energypoints << " energy points" << std::endl;
	this->_attackdamage = 0;
	std::cout << "ClapTrap initiated at " << this->_attackdamage << " attack power" << std::endl;
	std::cout << "ClapTrap build finished" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap & copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return ;
}

ClapTrap & ClapTrap::operator = (const ClapTrap & src) {
		std::cout << "ClapTrap copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitpoints= src._hitpoints;
		this->_energypoints = src._energypoints;
		this->_attackdamage = src._attackdamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap default destructor called for " << this->_name << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_hitpoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is too damaged to attack" << std::endl;
		return ;
	}
	if (this->_energypoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " energy is too low to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " for " << this->_attackdamage << " points of damage" << std::endl;
	this->_energypoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name << " recieves " << amount << " of damage" << std::endl;
	this->_hitpoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energypoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " energy is too low to repair" << std::endl;
		return ;
	}
	this->_hitpoints += amount;
	this->_energypoints -= 1;
	std::cout << "ClapTrap " << this->_name << " is repaired for" << amount << " hit points" << std::endl;
}


int	ClapTrap::getHitpoints( void ) const {
	std::cout << "getHitpoints member function called" << std::endl;
	return (this->_hitpoints);
}

void	ClapTrap::setHitpoints( int const n ) {
	std::cout << "setHitpoints member function called" << std::endl;
	this->_hitpoints = n;
	if (this->_hitpoints < 1)
		this->_hitpoints = 0;
}

int	ClapTrap::getEnergypoints( void ) const {
	std::cout << "getEnergypoints member function called" << std::endl;
	return (this->_energypoints);
}

void	ClapTrap::setEnergypoints( int const n ) {
	std::cout << "setEnergypoints member function called" << std::endl;
	this->_energypoints = n;
	if (this->_energypoints < 1)
		this->_energypoints = 0;
}

int	ClapTrap::getDamage( void ) const {
	std::cout << "getDamage member function called" << std::endl;
	return (this->_attackdamage);
}

void	ClapTrap::setDamage( int const n ) {
	std::cout << "setDamage member function called" << std::endl;
	this->_attackdamage = n;
	// can be negative to heal?
}