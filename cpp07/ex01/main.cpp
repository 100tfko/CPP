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

#include "iter.hpp"
#include <string>

int main() {
	std::cout << "--- Non-const char array ---" << std::endl;
	std::string str = "char array";
	iter(str.c_str(), str.length(), printT<char>);
	std::cout << std::endl;

	std::cout << "--- Const char array ---" << std::endl;
	std::string conststr = "char array";
	iter(str.c_str(), str.length(), printT<char>);
	std::cout << std::endl;

	std::cout << "--- Non-const str array ---" << std::endl;
	const std::string strArray[] = {"One", "Two", "Three"};
	iter(strArray, 3, printT<std::string>);
	std::cout << std::endl;
	
	std::cout << "--- Const str array ---" << std::endl;
	std::string conststrArray[] = {"One", "Two", "Three"};
	iter(conststrArray, 3, printT<std::string>);
	std::cout << std::endl;

	std::cout << "--- Non-const int array ---" << std::endl;
	int intArray[] = {1, 2, 3};
	iter(intArray, 3, printT<int>);
	std::cout << std::endl;

	std::cout << "--- Const int array ---" << std::endl;
	const int constIntArray[] = {1, 2, 3};
	iter(constIntArray, 3, printT<int>);
	std::cout << std::endl;
	
	return 0;
}

