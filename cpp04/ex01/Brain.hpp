/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:03:17 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/12/09 15:03:18 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string*	ideas;
	
	public:
		Brain();
		Brain(const Brain & copy);
		Brain & operator = (const Brain& src);
		~Brain();
};

#endif
