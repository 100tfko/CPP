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

int	main (int argc, char **argv) {
	(void)argc;
	Zombie	z(argv[1]);
	z.announce();

	Zombie*	z2;
	z2 = newZombie("Zombicio");
	z2->announce();

	randomChump("Brandon");
	delete(z2);
	return (0);
}
