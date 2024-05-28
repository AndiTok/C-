/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:24:05 by atok              #+#    #+#             */
/*   Updated: 2023/07/24 17:24:05 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string input)
{
	_nameB = input;
	this->_weaponB = NULL;
	std::cout << "HB CON \n";
}

HumanB::~HumanB()
{
	std::cout << "HB dCON \n";
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weaponB = &new_weapon;
}

void HumanB::attack(void)
{
	if (_weaponB != NULL) 
	{
        std::cout << _nameB 
		<< " has attacks with " << _weaponB->getType() 
		<< std::endl;
    } 
	else if (_weaponB == NULL)
	{
        std::cout << _nameB << " no weapon to attack " 
		<< std::endl;
    }
}