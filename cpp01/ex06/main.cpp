/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:12:18 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/29 10:12:19 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main (int argc, char **argv)
{
		if (argc != 2)
	{

		std::cout << "This program will only handle 1 argument" << std::endl;
		std::cout << "Usage---> ./harl <FILTER>" << std::endl;
		return (1);
	}

	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}