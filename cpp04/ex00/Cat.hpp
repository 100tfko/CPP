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

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"


class Cat : public Animal
{

public:
	Cat();
	Cat(const Cat & copy);
	Cat & operator = (const Cat& src);
	~Cat();

	void	makeSound() const;
};

// getters para el type? 
#endif
