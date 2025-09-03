/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:58:13 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/24 14:58:14 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

Span::Span() : _n(0)
{}

Span::Span(const unsigned int n) : _n(n)
{}

Span::Span(const Span &other) : _n(other._n), _vector(other._vector)
{}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_n = other._n;
		this->_vector = other._vector;
	}
	return *this;
}

Span::~Span()
{}

void	Span::addNumber(int n)
{
	if (this->_vector.size() < this->_n)
		this->_vector.push_back(n);
	else
		throw std::runtime_error("span is full");
}

int		Span::shortestSpan()
{
	if (this->_vector.size() < 2)
		throw std::runtime_error("no span");

	std::vector<int> sorted = this->_vector;
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		if (sorted[i] - sorted[i - 1] < shortest)
			shortest = sorted[i] - sorted[i - 1];
	}
	return shortest;
}

int 	Span::longestSpan()
{
	if (this->_vector.size() < 2)
		throw std::runtime_error("no span");
	
	std::sort(this->_vector.begin(), this->_vector.end());
	int longest = this->_vector[this->_vector.size() - 1] - this->_vector[0];
	return longest;
}