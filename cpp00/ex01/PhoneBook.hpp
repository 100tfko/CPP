/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:53:27 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/09 16:53:29 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_index;
	int		_count;
	

public:
	PhoneBook(void);
	~PhoneBook(void);
	void	loop(void);
	void	add_contact(void);
	void	print_search_header(int count);
	void	search_contact();
};

#endif