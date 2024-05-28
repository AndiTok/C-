/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:34:23 by atok              #+#    #+#             */
/*   Updated: 2023/08/15 20:34:23 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
	ClapTrap p1 = ClapTrap("P1"); //same as below
	ClapTrap p2("Dummy"); // same as above

	std::string input;

	while(1)//p2._hp > 0)
	{
		//std::cout << "atk,rpr,exit\n";
		//std::cin >> input; // cin only take 1 word
		getline(std::cin,input); // takes whole string & has option to parse in
		
		if(input == "a")
		{
			p1.attack("Dummy");
			p1.takeDamage(4);
		}
		else if(input == "r")
		{
			p1.beRepaired(1);
			//std::cout << "P! HP = " << p1._hp << "\n\n";
		}
		else if(input == "e")
			break;
	}

	return 0;
}
