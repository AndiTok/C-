/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 02:56:50 by atok              #+#    #+#             */
/*   Updated: 2023/08/11 02:56:50 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;

Fixed::Fixed() : _fixed_point(0) //_fraction_bits(8)
{
	// this->_fixed_point = 0;
	// this->_fraction_bits = 8;
	//cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy)
{
	//std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed & Fixed::operator = ( Fixed const & rhs) // [=] [class obect]
{
	//std::cout << "Copy assignment operator overload called\n";
	if (this != &rhs) // check if the obj assingned is same or not
		this->setRawBits(rhs.getRawBits());  
	//else if it is the same, there is no need to copy thus returning a pointer to itself
	return (*this);	
}

Fixed::~Fixed()
{
	//cout << "Destructor called\n";
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
	//cout << "Int constructor called\n";
	setRawBits(input << _fraction_bits);
}

Fixed::Fixed(const float input) // float to fixp
{
	//cout << "Float constructor called\n";
	setRawBits(roundf(input * (1 << _fraction_bits))); // 1 << 8 aka 100000000 = 256

}

float Fixed::toFloat( void ) const // fixp to float
{
/* 	//int to float whole number
	float msb = (_fixed_point / (1 << _fraction_bits));
	//int to flaot hence typecast float to float for decimal number
	float lsb = (float)(_fixed_point & ((1 << _fraction_bits) - 1)) / (1 << _fraction_bits);
	return (msb + lsb); */
	return ((float)_fixed_point / (1 << _fraction_bits));
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

//----------------------------------------------------|

bool Fixed::operator>(const Fixed &rhs) const
{
    return (_fixed_point > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (_fixed_point < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (_fixed_point >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (_fixed_point <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (_fixed_point == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (_fixed_point != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(toFloat() + rhs.toFloat()));
    //return (this->_fixed_point + rhs.getRawBits());
}	

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void) // ++ i
{
    _fixed_point++; 
    return *this;
}

Fixed Fixed::operator++(int) // i ++
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    _fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b); // is .. ? true : false
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}
