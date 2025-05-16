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

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitpoints;
		int			_energypoints;
		int			_attackdamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap & copy);
		ClapTrap & operator = (const ClapTrap& src);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int		getHitpoints( void ) const;
		void	setHitpoints( int const n );
		int		getEnergypoints( void ) const;
		void	setEnergypoints( int const n );
		int		getDamage( void ) const;
		void	setDamage( int const n );
};

//voy a hacer un getter del damage

#endif
