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

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal & copy);
	AAnimal & operator = (const AAnimal& src);
	virtual ~AAnimal();

	virtual void	makeSound() const = 0;
	std::string		getType() const;
};

// getters para el type? 
#endif
