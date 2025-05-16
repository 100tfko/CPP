/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:59:11 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/17 12:59:12 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	name;
	public:
// forma alternativa?		Zombie(std::string name): name(name) {}
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce(void) const;
		void	nameZ(std::string name);
};

//estas son nonmember pa que cualquier pueda?
Zombie*	zombieHorde(int N, std::string name);

#endif
