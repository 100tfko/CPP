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

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 5; ++i)
		vec.push_back(i);

	std::cout << "Testing easyfind with std::vector<int>:\n";

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 1);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
	std::cerr << "Exception (vec): " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 99);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception (vec): " << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	std::cout << "\nTesting easyfind with std::list<int>:\n";

	try
	{
		std::list<int>::iterator it = easyfind(lst, 1);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception (list): " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(lst, 99);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception (list): " << e.what() << std::endl;
	}

	return 0;
}
