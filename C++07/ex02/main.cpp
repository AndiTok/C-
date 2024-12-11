/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 06:00:24 by atok              #+#    #+#             */
/*   Updated: 2024/05/23 06:00:24 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ()
{
	// int *a = new int();
	// std::cout << *a << '\n';

	// Array<int> a();

	// std::cout << a << '\n';
//--------------

/* testing deep copy */

	// Array<int> a(4);
	// a[0] = 1;
	// a[1] = 2;
	// a[2] = 3;
	// a[3] = 4;

	// Array<int> c = a;

	// std::cout << "original a \n";
	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << a[i] << " ";
	// }
	// std::cout <<"\n\n";

	// std::cout << "before modifying c \n";
	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << c[i] << " ";
	// }
	// std::cout <<"\n\n";

	// c[0] = 42;
	// c[1] = 42;
	// c[2] = 42;
	// c[3] = 42;

	// std::cout << "before modifying c \n";
	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << c[i] << " ";
	// }
	// std::cout <<'\n';

//-------------------

/* testing the delete */

	Array<int> tmp;

	Array<int> arr1(5);

	// Create a copy of arr1 using the copy constructor (deep copy)
	Array<int> arr2 = arr1;

	// Create another array and use the assignment operator (deep copy)
	Array<int> arr3(10);
	arr3 = arr1;

/* 	why we need delete arr[] at the copy assingment
	as we do Array<int> a = Array<int> b(5);
	a is instantiated with a new empty array (default constructor)
	that is why we need to delete it prior to make a new one
	at the copy assingment operator if not will memory leak*/

//--------------------

/* using this as exmaple to show that 
everythign are normally deep copy by default*/

	// int i = 42;

	/* use either one */
	// int j(i); // copy operator
	// int j = i; // assignment operator
	
	// std::cout << i << '\n';
	// std::cout << j << '\n';
	
	/* use either one */
	// i = 24;
	// j = 24;
	// std::cout << i << '\n';
	// std::cout << j << '\n';
}