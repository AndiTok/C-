/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 04:18:49 by atok              #+#    #+#             */
/*   Updated: 2024/05/17 04:18:49 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// int main ()
// {
// 	Bureaucrat top("Top", 1);
// 	Intern someRandomIntern;
// 	AForm* rrf;

// 	std::cout << "\n";
// 	rrf = someRandomIntern.makeForm("robo", "Bender");//robo,shrub,pardon
// 	std::cout << *rrf;
// 	rrf->beSigned(top);
// 	top.signForm(*rrf);
// 	top.executeForm(*rrf);
// 	std::cout << "\n";
// 	return 0;	
// }

int main ()
{
	Bureaucrat top("Top", 1);
	Intern someRandomIntern;
	AForm* rrf;
	AForm* rrf2;

	std::cout << "\n";
	rrf = someRandomIntern.makeForm("robo", "Bender");//robo,shrub,pardon
	rrf2 = someRandomIntern.makeForm("pardon", "mek");
	// rrf = rrf2; // not intended to  assign as AForm have const attribute unlesss it is deleted prior to assign
	std::cout << *rrf;
	std::cout << *rrf2;
	std::cout << "\n";
	
	delete rrf;
	delete rrf2;

	// Intern does not store these forms & therefor not required Intern to delete
	// it only makes/generate form becase of its funtion
	// AForm itself is just and abstract/base class
	// it does not need to handle memeory allocation
	// the 3 concrete class implementation did not dynamically allocate memory
	// therfore not responible to delete 
	// if it did, we need to handle it within its class
	// Therefore, the ownership and responsibility to deallocate is you the user/client

	// one work arround is to have an array with a fix number 
	// to store the address of new forms 
	// but it is limited
	// since we cannot use vector it is a sudo vector

	//if vectore is used, we can "pushback" like a stack
	//inestead of looping trough array and storing it to empty ones
	return 0;
}
