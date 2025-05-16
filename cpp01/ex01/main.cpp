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

#include "Zombie.hpp"

int	main (void) {
	Zombie*	horde;

	horde = zombieHorde(8, "Zom");
	for (int i = 0; i < 8; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
