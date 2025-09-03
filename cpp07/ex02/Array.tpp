/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:57:58 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/17 15:57:59 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp" //should not be neccesary

template<typename T>
Array<T>::Array()
{
	this->array = new T[0];
	this->len = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->len = n;
}

template<typename T>
Array<T>::Array(const Array &other)
{
	this->array = new T[other.len];
	this->len = other.len;
	for (unsigned int i = 0; i < len; i++)
		this->array[i] = other.array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->array; //repasar, why [] and suposedly its ok to delete over clean.
		this->array = new T[other.len];
		this->len = other.len;
		for (unsigned int i = 0; i < len; i++)
			this->array[i] = other.array[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->array; //if I use new[] I need delete[]
}

template<typename T>
unsigned int Array<T>::size() const
{
	return this->len;
}

template<typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i < this->len)
		return this->array[i];
	throw Array<T>::OutOfBoundsException();
}

template<typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}