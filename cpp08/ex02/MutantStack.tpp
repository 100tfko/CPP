/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:26:36 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/28 14:26:37 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	std::stack<T>::operator=(other);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin ()
{
	return this->c.begin();
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end ()
{
	return this->c.end();
}
