/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:13:01 by atok              #+#    #+#             */
/*   Updated: 2024/05/11 06:13:01 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Bureaucrat Sudo ("Sudo",1);
	// ShrubberyCreationForm Shrub ("output");
	// std::cout << Sudo;
	// std::cout << Shrub;
	// Shrub.beSigned(Sudo); // sign form or throw exception
	// Sudo.signForm(Shrub); // check form status
	// // Sudo.executeForm(Shrub); // running this will not throw excetion
	// // Shrub.execute(Sudo); // running this will throw exception
	
	Bureaucrat Sudo ("Sudo",1);
	RobotomyRequestForm target ("target");
	std::cout << Sudo;
	std::cout << target;
	target.beSigned(Sudo);
	for (int i = 0; i < 5; i++)
		Sudo.executeForm(target);
	//c++ *.cpp && ./a.out | grep tomi

	// Bureaucrat Sudo ("Sudo",1);
	// PresidentialPardonForm target ("target");
	// std::cout << Sudo;
	// std::cout << target;
	// target.beSigned(Sudo);
	// Sudo.executeForm(target);
	return 0;
}