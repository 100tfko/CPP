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

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitpoints= 100;
	std::cout << "FragTrap initiated at " << this->_hitpoints << " hitpoints" << std::endl;
	this->_energypoints = 100;
	std::cout << "FragTrap initiated at " << this->_energypoints << " energy points" << std::endl;
	this->_attackdamage = 30;
	std::cout << "FragTrap initiated at " << this->_attackdamage << " attack power" << std::endl;
	std::cout << "FragTrap build finished" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "FragTrap name constructor called with name " << name << std::endl;
	this->_name = name;
	this->_hitpoints= 100;
	std::cout << "FragTrap initiated at " << this->_hitpoints << " hitpoints" << std::endl;
	this->_energypoints = 100;
	std::cout << "FragTrap initiated at " << this->_energypoints << " energy points" << std::endl;
	this->_attackdamage = 30;
	std::cout << "FragTrap initiated at " << this->_attackdamage << " attack power" << std::endl;
	std::cout << "FragTrap build finished" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap & copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return ;
}

FragTrap & FragTrap::operator = (const FragTrap & src) {
		std::cout << "FragTrap copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitpoints= src._hitpoints;
		this->_energypoints = src._energypoints;
		this->_attackdamage = src._attackdamage;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap default destructor called for " << this->_name << std::endl;
	return ;
}

void	FragTrap::attack(const std::string& target) {
	if (this->_hitpoints < 1)
	{
		std::cout << "FragTrap " << this->_name << " is too damaged to attack" << std::endl;
		return ;
	}
	if (this->_energypoints < 1)
	{
		std::cout << "FragTrap " << this->_name << " energy is too low to attack" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << " for " << this->_attackdamage << " points of damage" << std::endl;
	this->_energypoints -= 1;
}

void	FragTrap::highFivesGuys(void){
	if (this->_hitpoints < 1)
	{
		std::cout << "FragTrap " << this->_name << " is too damaged to high five" << std::endl;
		return ;
	}
	if (this->_energypoints < 1)
	{
		std::cout << "FragTrap " << this->_name << " energy is too low to high five" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " sais: high fives guys!" << std::endl << "Don't leave me hanging!" << std::endl;
	 
}