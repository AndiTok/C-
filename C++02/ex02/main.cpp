/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:55:15 by atok              #+#    #+#             */
/*   Updated: 2023/08/11 02:55:15 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	//Fixed c (5);

	std::cout << a << std::endl; // a = 0
	std::cout << ++a << std::endl; // update a with + ϵ = 0.00390625 then show the updated a
	std::cout << a << std::endl; // current updated a
	std::cout << a++ << std::endl; // show current updated a then + ϵ = 0.00390625
	std::cout << a << std::endl; // show the current updated a

	std::cout << b << std::endl; //
	//std::cout << c+c << std::endl; //

	std::cout << Fixed::max( a, b ) << std::endl;
	//std::cout << Fixed::min( a, b ) << std::endl;

	cout << "***** CUSTOM  TEST *****" << endl;
    Fixed x;
    Fixed const y(-10);//
    Fixed z(20);

    Fixed m(y);

    Fixed n(10.01f);
    Fixed const o(-20.02f);//

    Fixed j(5);
    Fixed const k(-15);
    Fixed l(5.0f);
    Fixed const q(15.0f);

    std::cout << "n: " << n << std::endl;
    std::cout << "o: " << o << std::endl;

    cout << "***** ARITHMETIC  TEST *****\n\tINT" << endl;
        x = y + k;
        std::cout << "PLUS: " << x << std::endl;
        x = y - k;
        std::cout << "MINUS: " << x << std::endl;
        x = y * k;
        std::cout << "MULTIPLY: " << x << std::endl;
        x = y / k;
        std::cout << "DIVISION: " << x << std::endl;

    cout << "\n***** ARITHMETIC  TEST *****\n\tFLOAT" << endl;
        x = n + l;
        std::cout << "PLUS: " << x << std::endl;
        x = n - l;
        std::cout << "MINUS: " << x << std::endl;
        x = n * l;
        std::cout << "MULTIPLY: " << x << std::endl;
        x = n / l;
        std::cout << "DIVISION: " << x << std::endl;

    cout << "\n***** ARITHMETIC  TEST *****\n\tMIXED" << endl;
        x = o + m;
        std::cout << "PLUS: " << x << std::endl;
        x = o - m;
        std::cout << "MINUS: " << x << std::endl;
        x = o * m;
        std::cout << "MULTIPLY: " << x << std::endl;
        x = o / m;
        std::cout << "DIVISION: " << x << std::endl;

	return 0;
}