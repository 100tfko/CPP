/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:59:41 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/17 12:59:42 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
    Zombie  *Horde;
    
    Horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        Horde[i].nameZ(name);
    return (Horde);
}
