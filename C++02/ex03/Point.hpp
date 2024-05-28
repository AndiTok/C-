/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:30:28 by atok              #+#    #+#             */
/*   Updated: 2023/08/14 17:30:28 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
		// const Fixed _y = 0; // unavailable in c++98

	public:
		Point(); // initialize x & y to 0
		Point(const float x, const float y); // set x & y
		Point(const Point &copy); // to allow multiple initlized copy to diff obj
		Point &operator=(const Point &rhs); // to allow class assignment
		~Point();

		// get/set has "Fixed" becase the private attribute is Fixed
		Fixed get_x() const; // forgot the const...
		Fixed get_y() const; 
		void set_x(Fixed x);
		void set_y(Fixed y);
	
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif