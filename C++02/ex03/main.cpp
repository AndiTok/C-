/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 23:35:52 by atok              #+#    #+#             */
/*   Updated: 2023/08/15 23:35:52 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
	// Point a = (Fixed (10.5f), Fixed (15.5f));
	// Point b = (Fixed (5), Fixed (5));
	// Point c = (Fixed (15.5f), Fixed (5));
	// Point point = (Fixed (7), Fixed (13.5f));

	Point a(10.5f, 15.5f);
    Point b(5.0f, 5.0f);
    Point c(15.5f, 5.0f);

    Point point(8.0f, 8.8f);
	
	// Point a(0,0);
    // Point b(0,10);
    // Point c(10,0);

    // Point point(3,7);

	if (bsp(a,b,c,point))
		std::cout << "TRUE\n";
	else	
		std::cout << "FALSE\n";
	
	return 0;
}

//https://www.omnicalculator.com/math/area-triangle-coordinates