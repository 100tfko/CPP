/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:07:46 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/12/09 15:07:47 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	ideas = new std::string[100]; 
	//debe'ria iniciar las ideas? se pelea con el desctructor?
}

Brain::Brain(const Brain & copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	return ;
}

Brain & Brain::operator = (const Brain & src) {
	std::cout << "Brain copy assigment operator called" << std::endl;
	if (this != &src)
	{
		std::string* tmp = new std::string[100];
		for (int i = 0; i < 100; i++)
			tmp[i] = src.ideas[i];
		delete[] ideas;
		ideas = tmp;
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" <<std::endl;
	delete[] ideas;
}


