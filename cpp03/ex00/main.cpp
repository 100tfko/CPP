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

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap brandom;
	ClapTrap xiii ("XIII");

	xiii.attack("default");
	brandom.takeDamage(xiii.getDamage());
	xiii.setDamage(5);
	brandom.takeDamage(xiii.getDamage());
	brandom.takeDamage(xiii.getDamage());
	brandom.attack("XIII");
	brandom.beRepaired(5);
	brandom.attack("XIII");
	xiii.takeDamage(brandom.getDamage());
	xiii.setEnergypoints(0);
	xiii.attack("default");
}
