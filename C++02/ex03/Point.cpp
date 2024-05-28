/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:19:44 by atok              #+#    #+#             */
/*   Updated: 2023/08/14 18:19:44 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

using std::cout;

Point::Point() : _x(0), _y(0)
{
	//this->_y = 0; 
	// cant use this because there is an operator assingment overflow function?
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{

}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y)
{
	//*this = copy;
}

Point &Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		this->set_x(rhs.get_x()); // this ft is in Point scope
		this->set_y(rhs.get_y()); // but return Fixed
		// (Fixed)this->_x = rhs.get_x(); // wihtout const it will not be compatible
		// (Fixed)this->_y = rhs.get_y(); // without Fixed tped cast it wount work
	}
	return *this;
}

Point::~Point()
{
	
}

Fixed Point::get_x() const
{
	return this->_x;
}

Fixed Point::get_y() const
{
	return this->_y;
}

void Point::set_x(Fixed x)
{
	//this->_x = x;
	(Fixed)this->_x = x;
}

void Point::set_y(Fixed y)
{
	//this->_y = y;
	(Fixed)this->_y = y;
}
