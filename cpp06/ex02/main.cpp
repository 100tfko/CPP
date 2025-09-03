/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:44:52 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/14 10:44:53 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	Base *base;
	for (int i = 0; i < 10; i++)
	{
		base = generate();
		std::cout << "Identify with Pointers" << std::endl;
		identify(base);
		std::cout << "Identify with References" << std::endl;
		identify(*base);
		std::cout << std::endl;
	}

	Base * fail = NULL;
	std::cout << "Identify with Pointers" << std::endl;
	identify(fail);
	std::cout << "Identify with References" << std::endl;
	identify(*fail);
	std::cout << std::endl;


	delete	base;
	return 0;
}
