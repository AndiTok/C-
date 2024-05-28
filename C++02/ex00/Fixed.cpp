/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 05:13:11 by atok              #+#    #+#             */
/*   Updated: 2023/08/08 05:13:11 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	*this = copy; // uses the "copy assingment function [below]" defined in public class section by you
	//this->_fixed_point = copy._fixed_point; // more direct approach , directly copies the data and does not rely on the copy assignment operator.
											// if there are more var memebr, need to 1 by 1 declare
											// notice there is no *, if got it will modify original one but got const to prevent it
}

Fixed & Fixed::operator = ( Fixed const & rhs) // operator '=' will do copy funtion
{
	std::cout << "Copy assignment operator overload called\n";
	this->_fixed_point = rhs._fixed_point;
	//this->setRawBits(rhs.getRawBits()); // set c but get from b
	return (*this);						//this-> / *this same thing aka itself puna address
}

Fixed::~Fixed()
{
	cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const //funtion to get var from private section of class
{
	cout << "getRawBits member function called\n";
	return this->_fixed_point;
}

void Fixed::setRawBits( int const raw ) //funtion to set var at private section of class
{
	//cout << "setRawBits member function called\n";
	this->_fixed_point = raw;
}
