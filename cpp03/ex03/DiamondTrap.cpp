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

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::_name = "default_clap_name";
	this->_hitpoints= FragTrap::_hitpoints;
	std::cout << "DiamondTrap initiated at " << this->_hitpoints << " hitpoints" << std::endl;
	this->_energypoints = ScavTrap::_scavEnergypoints;
	std::cout << "DiamondTrap initiated at " << this->_energypoints << " energy points" << std::endl;
	this->_attackdamage = FragTrap::_attackdamage;
	std::cout << "DiamondTrap initiated at " << this->_attackdamage << " attack power" << std::endl;
	std::cout << "DiamondTrap build finished" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap name constructor called with name " << name << std::endl;
	this->_name = name;
	this->_hitpoints= FragTrap::_hitpoints;
	std::cout << "DiamondTrap initiated at " << this->_hitpoints << " hitpoints" << std::endl;
	this->_energypoints = ScavTrap::_scavEnergypoints;
	std::cout << "DiamondTrap initiated at " << this->_energypoints << " energy points" << std::endl;
	this->_attackdamage = FragTrap::_attackdamage;
	std::cout << "DiamondTrap initiated at " << this->_attackdamage << " attack power" << std::endl;
	std::cout << "DiamondTrap build finished" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap & copy) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	return ;
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap & src) {
		std::cout << "DiamondTrap copy assigment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitpoints= src._hitpoints;
		this->_energypoints = src._energypoints;
		this->_attackdamage = src._attackdamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap default destructor called for " << this->_name << std::endl;
	return ;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " << this->_name << " and his ClapTrap name is " << ClapTrap::_name << std::endl;
}
