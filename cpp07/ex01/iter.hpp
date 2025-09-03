/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:57:24 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/17 11:57:25 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename ft>
void	iter(T *address, int len, ft f)
{
	for (int i = 0; i < len; i++)
		f(address[i]);
}
// Originaly y had: template <typename T> void	iter(T *address, int len, void (*f)(T &)))
// This seems to make problems with consts, I am not sure.
//this new way requires casting when calling it in main.

template <typename T>
void printT(T x)
{
	std::cout << x;
}

#endif
