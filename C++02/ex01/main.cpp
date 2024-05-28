/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:54:55 by atok              #+#    #+#             */
/*   Updated: 2023/08/09 20:54:55 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {

/* 	float i = 42.42; // (double)(42.42000000000000171)
	float j = 42.42f; // (float)(42.41999817F)
	double k = 42.42; // (double)(42.42000000000000171)
	double l = 42.42f; // (float)(42.41999817F)
	int m = 42.42123623423; // (double)(42.42000000000000171)
	int n = 42.42f; // (float)(42.41999817F) */
	// >> hovering over i,j,k,l,m,n will show raw number <<
	// placing f/F at the end of any decimal variable number [explicit]
	// will turn to float which have 7-8 decimal place with an F at the end
	// without it by default will turn to double with 15-17 decimal places

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f ); // 42.41999817F
	Fixed const d( b );

	a = Fixed( 1234.4321f ); // 1234.432129F
	
	// std::cout << "b is " << b.getRawBits() << std::endl;
	
	// running only the <<operator function
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	// running toint function
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
// fixe point value are stored as int if whole number
// float or double if have decimal
// 10 = 00001010.0
// shift << 8
// 2560 = 101000000000.0
// shifting bit "<< x" is the same as "2^x" 