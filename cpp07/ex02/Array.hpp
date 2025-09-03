/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:50:36 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/17 14:50:37 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
	private:
		T				*array;
		unsigned int	len;
	public:	
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		
		T &operator[](unsigned int i);
		unsigned int size() const;
		class OutOfBoundsException : public std::exception
		{
			const char *what() const throw();
		};
};

#include "Array.tpp" //may be circular, has to checl.

#endif
