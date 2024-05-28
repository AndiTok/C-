/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:03:10 by atok              #+#    #+#             */
/*   Updated: 2023/08/18 14:10:59 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//single level/multi level inheritence

int main ()
{
	ScavTrap p1 = ScavTrap("SCAV-1"); //same as below
	// ClapTrap p2("ClAP"); // same as above
	// ScavTrap p3 = p1;
	ScavTrap p4("SCAV-2");
	

	p1.attack("SCAV-2");
	p1.attack("SCAV-2");
	p1.attack("SCAV-2");
	p1.attack("SCAV-2");
	p4.takeDamage(80);
	p4.guardGate();
	p4.beRepaired(5);
	p1.attack("SCAV-2");
	p4.takeDamage(20);
	p4.guardGate();
	p4.beRepaired(5);
	p1.attack("SCAV-2");
	p4.takeDamage(20);
	p4.guardGate();
	p4.beRepaired(10);

}