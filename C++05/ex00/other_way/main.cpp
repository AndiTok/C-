/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:42:59 by atok              #+#    #+#             */
/*   Updated: 2024/04/29 00:42:59 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// Bureaucrat a; //Defualt constructor
	// Bureaucrat tmp ("tmp",24); //Parameter constructor
	// Bureaucrat b = tmp; // copy/copy assign operator

	// Bureaucrat upper("upper",9000);
	// Bureaucrat lower("-lower",-9000);

	try
	{
		Bureaucrat HIGH ("HIGH",1);
		std::cout << HIGH;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat MID ("MID",75);
		std::cout << MID;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat LOW ("LOW",150);
		std::cout << LOW;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat up ("up",2);
		std::cout << up; // 2
		up.increaseGrade(); // rank up
		std::cout << up; // 1
		up.increaseGrade(); // rank up & stopped here
		std::cout << up;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	
	try
	{
		Bureaucrat down ("down",150);
		std::cout << down; // 150
		down.decreaseGrade(); // rank down & stopped here
		std::cout << down; // 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	//deconstructor called before exception [google it]
	// whwy deconsctor run before exception
	// because both run at the same time but decopnsturctor is faster
	// current implementation, deconstructor is quicker in printing out
}