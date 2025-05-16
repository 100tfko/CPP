/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:45:43 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/10 09:45:45 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
    _fields[0] = "Frist name: ";
    _fields[1] = "Last name: ";
    _fields[2] = "Nickname : ";
    _fields[3] = "Phone number: ";
    _fields[4] = "Darkest secret: ";
    return;
}

Contact::~Contact(void) {
}

void    Contact::add_contact() {
    
    for (int i = 0; i < 5; i++)
    {
        do
		{
    		std::cout << _fields[i];
    	    if (!std::getline(std::cin, _data[i]))
    	        break ;
			if (_data[i].empty())
				std::cout << "This field cannot be empty" << std::endl;
			if (i == 3)
			{
				for (int j = 0; j < (int)_data[i].length(); j++)
				{
					if (!std::isdigit(_data[i][j]))
					{
						std::cout << "This field must be a phone number" << std::endl;
						_data[i].clear();
						break;
					}	
				}
			}
		} while (_data[i].empty());
    }
}

std::string Contact::formatEntry(const std::string& entry) {
    
    std::string formattedEntry;
    
    if (entry.length() > 10) {
        formattedEntry = entry.substr(0, 9) + ".";
    } else {
        formattedEntry = entry;
    }
    int padding = 10 - formattedEntry.length();
    formattedEntry.insert(0, padding, ' ');
    return formattedEntry;
}

void    Contact::search_print_header() {
    for (int i = 0; i < 3; i++)
    {
    std::cout << "|";
    std::cout << formatEntry(_data[i]);
    }
	std::cout << "|" << std::endl;
}

void    Contact::get_fields(void) {
	std::cout << _fields[0] << _data[0] << std::endl;
	std::cout << _fields[1] << _data[1] << std::endl;
	std::cout << _fields[2] << _data[2] << std::endl;
	std::cout << _fields[3] << _data[3] << std::endl;
	std::cout << _fields[4] << _data[4] << std::endl;

}