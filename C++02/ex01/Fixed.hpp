/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:58:24 by atok              #+#    #+#             */
/*   Updated: 2023/08/09 20:58:24 by atok             ###   ########.fr       */
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
		Fixed &operator = (const Fixed& rhs);
		~Fixed();
		Fixed(const int input); // convert int to fixed point
		Fixed(const float input); // convert float to fixed point

	/* member function */
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const; // convert fixed point to float
	int toInt( void ) const; // convert fixed point to int
};

std::ostream & operator<<(std::ostream & os, Fixed const & rhs); // "<<" "class object"
// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.


#endif

// is quicker & more efficient compute using fixed-point
//
// [4 decimal place]
// computer compute 
// float-point pi = 3.141592653589793238462643383279502884197
// fixed-point pi = 3.1415
// show
// float-point pi = 3.1415
// fixed-point pi = 3.1415
//
// In fixed point notation, 
// there are a "fixed number" of digits after the decimal point, 
// whereas floating point number 
// allows for a "varying" number of digits after the decimal point.