/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:58:12 by atok              #+#    #+#             */
/*   Updated: 2023/08/08 04:58:12 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// CANONIC FORM
// Class containing at least:
// 1) Constructor default
// 2) Copy constructor (if the re pointer/array need to allocate memory)
// 3) '=' Operator overload
// 4) Destructor (normally blank but need funtion to delete pointer/array)

class Fixed
{
	private:
		int	_fixed_point; // store the fixed-point number value
		static const int _fraction_bits = 8; // store the number of fractional bits [8]
	
	public:
		Fixed(); // constructor		
		Fixed (const Fixed &copy);	// copy constructor ??
		Fixed &operator = (const Fixed& rhs); // copy assignment aka "=" operator overload ??
		~Fixed(); // destructor

	/* member function */
	int getRawBits( void ) const; // returns the raw value of the fixed-point value
	void setRawBits( int const raw ); // sets the raw value of the fixed-point number

};

#endif

// '&' aka reference "fererring to..."