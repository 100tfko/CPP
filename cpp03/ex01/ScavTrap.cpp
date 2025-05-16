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

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitpoints= 100;
	std::cout << "ScavTrap initiated at " << this->_hitpoints << " hitpoints" << std::endl;
	this->_energypoints = 50;
	std::cout << "ScavTrap initiated at " << this->_energypoints << " energy points" << std::endl;
	this->_attackdamage = 20;
	std::cout << "ScavTrap initiated at " << this->_attackdamage << " attack power" << std::endl;
	std::cout << "ScavTrap build finished" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap name constructor called with name " << name << std::endl;
	this->_name = name;
	this->_hitpoints= 100;
	std::cout << "ScavTrap initiated at " << this->_hitpoints << " hitpoints" << std::endl;
	this->_energypoints = 50;
	std::cout << "ScavTrap initiated at " << this->_energypoints << " energy points" << std::endl;
	this->_attackdamage = 20;
	std::cout << "ScavTrap initiated at " << this->_attackdamage << " attack power" << std::endl;
	std::cout << "ScavTrap build finished" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap & copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return ;
}

ScavTrap & ScavTrap::operator = (const ScavTrap & src) {
		std::cout << "ScavTrap copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitpoints= src._hitpoints;
		this->_energypoints = src._energypoints;
		this->_attackdamage = src._attackdamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default destructor called for " << this->_name << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_hitpoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " is too damaged to attack" << std::endl;
		return ;
	}
	if (this->_energypoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " energy is too low to attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " for " << this->_attackdamage << " points of damage" << std::endl;
	this->_energypoints -= 1;
}

void	ScavTrap::guardGate() {
	if (this->_hitpoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " is too damaged to attack" << std::endl;
		return ;
	}
	if (this->_energypoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " energy is too low to attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}