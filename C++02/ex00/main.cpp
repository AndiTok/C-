/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:57:16 by atok              #+#    #+#             */
/*   Updated: 2023/08/08 04:57:16 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {

	Fixed a; // initialize class Fixed with a
	Fixed b( a ); // copy class a to class b
	Fixed c;
	
	//Fixed c = Fixed b;
	c = b; // assign b class to c class
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}

/* 
Fixed a 	Default constructor called

Fixed b(a)	Copy constructor called
			Copy assignment operator overload called <-- will appear if use *this = copy
			getRawBits member function called

Fixed c 	Default constructor called
c = b		Copy assignment operator overload called
			getRawBits member function called

a.getRawBits()	getRawBits member function called
				0
b.getRawBits()	getRawBits member function called
				0
c.getRawBits()	getRawBits member function called
				0

Destructor called
Destructor called
Destructor called
 */