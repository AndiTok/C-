/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:58:13 by atok              #+#    #+#             */
/*   Updated: 2023/08/09 20:58:13 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Fixed.hpp"

using std::cout;

Fixed::Fixed() : _fixed_point(0) //_fraction_bits(8)
{
	// this->_fixed_point = 0;
	// this->_fraction_bits = 8;
	cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed & Fixed::operator = ( Fixed const & rhs) // [=] [class obect]
{
	std::cout << "Copy assignment operator overload called\n";
	if (this != &rhs) // check if the obj assingned is same or not
		this->_fixed_point = rhs._fixed_point;
		//this->setRawBits(rhs.getRawBits());  
	//else if it is the same, there is no need to copy thus returning a pointer to itself
	return (*this);	
}

Fixed::~Fixed()
{
	cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const 
{
	//cout << "getRawBits member function called\n";
	return this->_fixed_point;
}

void Fixed::setRawBits( int const raw )
{
	//cout << "setRawBits member function called\n";
	this->_fixed_point = raw;
}

//----------------------------------------------------|

Fixed::Fixed(const int input) // int to fixp
{
	cout << "Int constructor called\n";
	setRawBits(input << _fraction_bits);
}

Fixed::Fixed(const float input) // float to fixp
{
	cout << "Float constructor called\n";
	setRawBits(roundf(input * (1 << _fraction_bits))); // 1 << 8 aka 100000000 = 256

}

float Fixed::toFloat( void ) const // fixp to float
{
	//int to float whole number
	float msb = (_fixed_point / (1 << _fraction_bits));
	//int to flaot hence typecast float to float for decimal number
	float lsb = (float)(_fixed_point & ((1 << _fraction_bits) - 1)) / (1 << _fraction_bits);
	return (msb + lsb);
}

int Fixed::toInt( void ) const // fixp to int
{
	return (_fixed_point >> _fraction_bits);
}

// fix to float  but trough << 
std::ostream & operator << (std::ostream &os, Fixed const & rhs) // [<<] class [object]
{
	os << rhs.toFloat();
	return (os);
}

// 0.00000000 > 8 fractional bits 
// 1/2   0.5		2^1 1<<1 10
// 1/4   0.25		2^2 1<<2 100
// 1/8   0.125		2^3 1<<3 1000
// 1/16  0.0625		2^4 1<<4 10000
// 1/32  0.03125	2^5 1<<5 100000
// 1/64  0.015625	2^6 1<<6 1000000
// 1/128 0.0078125	2^7 1<<7 10000000
// 1/256 0.00390625 2^8 1<<8 100000000
// 1 - 8