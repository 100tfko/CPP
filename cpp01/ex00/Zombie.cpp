/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:59:26 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/17 12:59:27 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    return ;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie " << name << " has been destroyed" << std::endl;
    return ;
}
//debería usar this->name

void    Zombie::announce(void) const{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}