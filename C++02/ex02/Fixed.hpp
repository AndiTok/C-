/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:56:06 by atok              #+#    #+#             */
/*   Updated: 2023/08/11 02:56:06 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // roundf()

class Fixed
{
	private:
		int	_fixed_point;
		static const int _fraction_bits = 8;

	public:
		Fixed();
		Fixed (const Fixed &copy);
		Fixed &operator = (const Fixed &rhs);
		~Fixed();
		Fixed(const int input); // convert int to fixed point
		Fixed(const float input); // convert float to fixed point

	/* member function */
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const; // convert fixed point to float
	int toInt( void ) const; // convert fixed point to int

	/* relation/comparison operators */
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	/* arithmetic operators */
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	/* pre(before) & post(after) increment/decrement */
	Fixed &operator++(void); // pre ++,i [return an updated incremented self]
	Fixed operator++(int); // post i,++ [return current self but an incremented self later]
	Fixed &operator--(void);
	Fixed operator--(int);

	/* public overlaod member function for const & non-const */
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
};

std::ostream & operator << (std::ostream & os, Fixed const & rhs);
// static can only interact in class 
#endif