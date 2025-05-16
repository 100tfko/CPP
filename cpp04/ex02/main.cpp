/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:37:20 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/11/15 12:37:23 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	AAnimal* animals[10];

	for (int i = 0; i < 10; i++)
	{
	if (i % 2 == 0)
		animals[i] = new Dog;
		else
		animals[i] = new Cat;
	}

	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	for (int i = 0; i < 10; i++)
		delete animals[i];
	
	Dog basic;
	{
		Dog tmp = basic;
	}
	return 0;
}
//dice marina que se puede usar delete [] animals si se han creado con new.
// creo que no, simplemente que para new tengo que hacerlo con 	Animal** animals = new Animal*[10]; y le tengo que meter el delete al puntero puntero como 	delete [] animals;