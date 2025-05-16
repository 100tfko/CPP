/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:53:35 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/09 16:53:37 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {

	_index = 0;
	_count = 0;
}

PhoneBook::~PhoneBook(void) {
	
	_index = 0;
	_count = 0;
}

void	PhoneBook::print_search_header(int count) {

    std::cout << "|     INDEX";
    std::cout << "|FIRST NAME";
    std::cout << "| LAST NAME";
    std::cout << "|  NICKNAME|" << std::endl;

    for (int index = 0; index < count; index++)
    {
        std::cout << "|         " << (index + 1);
        _contacts[index].search_print_header();
    }
}

void	PhoneBook::search_contact() {
	int		i;

	i = 0;
	if (_count == 0)
	{
		std::cout << "There are no contacts in the phonebook" << std::endl;
		return ;	
	}
	print_search_header(_count);
	std::cout << "Insert contact index" << std::endl;
	if (!(std::cin >> i))
	{
		std::cout << "Value inserted is not valid" << std::endl;
		std::cout << "All index available at the momment are ";
		std::cout << "between 1 and " << (_count) << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (i < 1 || i > (_count))
	{
		std::cout << "Index " << (i) << " is not available" << std::endl;
		std::cout << "All index available at the momment are";
		std::cout << "between 1 and " << (_count) << std::endl;
		std::cin.clear();
		std::cin.ignore();
		return ;
	}
	_contacts[(i - 1)].get_fields();
	std::cin.clear();
	std::cin.ignore();
}

void	PhoneBook::add_contact(void){
	if (_count >= 8)
	{
		std::cout << "Phonebook full." << std::endl;
		std::cout << "This new entry will replace the oldest one" << std::endl;
		if (_index > 7)
			_index = 0;
	}
	_contacts[_index].add_contact();
	std::cout << "Contact has been saved" << std::endl;
	if (_count < 8)
		_count++;
	_index++;
}

void	PhoneBook::loop(void) {

	std::string	input;

	while (42)
	{
		std::cout << "\n----> CHOOSE BETWEEN THE FOLLOWING OPTIONS: \n" << std::endl;
		std::cout << "----> ADD    <----" << std::endl;
		std::cout << "----> SEARCH <----" << std::endl;
		std::cout << "----> EXIT   <----" << std::endl;
		std::cout << std::endl << "--> PLEASE TYPE YOUR OPTION: ";
		if (!std::getline(std::cin, input))
			return ;
		else if (input == "EXIT")
			return ;
		else if (input == "ADD")
			add_contact();
		else if (input == "SEARCH")
			search_contact();
		else
			std::cout << "Wrong input: Please input a valid option" << std::endl;
	}
}

