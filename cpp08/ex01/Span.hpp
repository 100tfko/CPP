/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:50:26 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/24 14:55:34 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
# define Span_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>

class Span
{
	private:
		unsigned int	_n;
		std::vector<int> _vector; 
		//in theory I could use a set, but behaviour will change
		Span();
	public:
		Span(const unsigned int n);
		Span(const Span &other);
		Span & operator=(const Span &other);
		~Span();

		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);

		template<typename I>
		void	addNumber(I begin, I end)
		{
			//if (_vector.size() + std::distance(begin, end) > this->_n)
			if (_vector.size() + (end - begin) > this->_n)
			throw std::runtime_error("span is nos big enough");
			_vector.insert(_vector.end(), begin, end);
		}
};

#endif