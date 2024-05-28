/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:49:38 by atok              #+#    #+#             */
/*   Updated: 2023/07/24 16:49:38 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weaponA(weapon)
{
	_nameA = name;
	//_weapon = weapon;
	std::cout << "HA CON \n";
}

HumanA::~HumanA()
{
	std::cout << "HA dCON \n";
}

void HumanA::attack(void)
{
	std::cout << this->_nameA 
	<< " attack with " << this->_weaponA.getType() 
	<< "\n";
}
