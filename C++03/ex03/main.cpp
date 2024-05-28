/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:08 by atok              #+#    #+#             */
/*   Updated: 2023/08/22 16:03:16 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

// hybrig inheritence = multiple & multilevel inheritence
// diamond problem

int main ()
{
	DiamondTrap p1 = DiamondTrap("DIAMOND-1");
	// DiamondTrap p1 = p2;

	p1.whoAmI();
	p1.attack("Dummy");
	p1.highFivesGuys();
	p1.guardGate();
}