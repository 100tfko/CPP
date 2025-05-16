/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:37:03 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/11/15 12:37:05 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_value;
		static int	const _bits;

	public:
		Fixed();
		Fixed(const Fixed & copy);
		Fixed & operator = (const Fixed& src);
		bool	operator > (const Fixed& src) const;
		bool	operator < (const Fixed& src) const;
		bool	operator >= (const Fixed& src) const;
		bool	operator <= (const Fixed& src) const;
		bool	operator == (const Fixed& src) const;
		bool	operator != (const Fixed& src) const;
		Fixed	operator + (const Fixed& src) const;
		Fixed	operator - (const Fixed& src) const;
		Fixed	operator * (const Fixed& src) const;
		Fixed	operator / (const Fixed& src) const;
		Fixed	operator ++ (int);
		Fixed &	operator ++ (void);
		Fixed	operator -- (int);
		Fixed &	operator -- (void);


		Fixed(const int i);
		Fixed(const float f);

		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed&	min(Fixed & n1, Fixed & n2);
		static Fixed&	max(Fixed & n1, Fixed & n2);
		static const Fixed&	min(Fixed const& n1, Fixed const& n2);
		static const Fixed&	max(Fixed const& n1, Fixed const& n2);
};

std::ostream & operator << (std::ostream & out, const Fixed & src);

#endif