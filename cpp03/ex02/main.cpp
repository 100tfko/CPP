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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
    ClapTrap basic ("BasicB");
	FragTrap brandom;
	ScavTrap xiii ("XIII");

	xiii.attack("default");
	brandom.takeDamage(xiii.getDamage());
	brandom.attack("XIII");
	brandom.beRepaired(5);
	brandom.attack("XIII");
	xiii.takeDamage(brandom.getDamage());
    xiii.attack("BasicB");
    basic.takeDamage(xiii.getDamage());
    basic.attack("XIII");
	xiii.setEnergypoints(0);
	xiii.attack("default");
	brandom.highFivesGuys();
}
