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

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal & copy);
	Animal & operator = (const Animal& src);
	virtual ~Animal();

	virtual void	makeSound() const;
	std::string		getType() const;
};

// getters para el type? 
#endif
