/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:45:49 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/10/10 09:45:51 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <limits>

class Contact {

	private:
		std::string	_data[5];
		std::string	_fields[5];

	public:
	    Contact(void);
	    ~Contact(void);
		
		void	add_contact(void);
		void	get_fields(void);
		void	search_print_header();
		std::string formatEntry(const std::string& entry);
};

#endif