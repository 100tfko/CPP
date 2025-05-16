/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:37:03 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/11/15 12:37:05 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
        static const int _scavEnergypoints = 50;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap & copy);
		ScavTrap & operator = (const ScavTrap& src);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};

#endif
