/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:22:59 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/01 12:23:05 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat lowestgump("Forrest", 200);
	Bureaucrat highestgump("Gump", 1);

	std::cout << lowestgump << std::endl;
	std::cout << highestgump << std::endl;

	highestgump.incrementGrade();
	std::cout << highestgump << std::endl;
	highestgump.decrementGrade();
	std::cout << highestgump << std::endl;
	highestgump.decrementGrade();
	std::cout << highestgump << std::endl;
	highestgump.incrementGrade();
	std::cout << highestgump << std::endl;
	return (0);
}
