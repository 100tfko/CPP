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

Zombie::Zombie(){}

Zombie::Zombie(std::string name) : name(name) {
    return ;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie " << this->name << " has been destroyed" << std::endl;
    return ;
}
//tengo que investigar lo del this mejor

void    Zombie::announce(void) const{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::nameZ(std::string name) {
    this->name = name;
}