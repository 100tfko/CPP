/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:58:55 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/17 12:58:56 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main (void) {
	Weapon	shank("prison shank");
	HumanA	brandom("Brandom", shank);
	brandom.attack();
	shank.setType("rusty prison shank");
	brandom.attack();

	Weapon	fancy("epee");
	HumanB	mice("Mice");
	mice.setWeapon(fancy);
	mice.attack();
	fancy.setType("shiny epee");
	mice.attack();

	return (0);
}
