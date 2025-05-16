/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:37:20 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/11/15 12:37:23 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap	one ("PersonalName");
	ScavTrap scav ("svav");
	ClapTrap random ;

	one.whoAmI();
	one.attack("default");
	random.takeDamage(one.getDamage());
	random.attack("PersonalName");
	scav.takeDamage(one.getDamage());
	scav.takeDamage(one.getDamage());
	scav.takeDamage(one.getDamage());
	scav.takeDamage(one.getDamage());
	scav.takeDamage(one.getDamage());
	scav.attack("PersonalName");
}
