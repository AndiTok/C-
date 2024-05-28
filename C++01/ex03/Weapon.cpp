/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:36:42 by atok              #+#    #+#             */
/*   Updated: 2023/07/21 23:36:42 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string input)
{
	_type = input;
	std::cout << "Wep CON \n";
}

Weapon::~Weapon()
{
	std::cout << "Wep dCON \n";
}

const std::string &Weapon::getType() const 
{
	//returns a const string that cannot be modified
	//a refference(&) to have the ability to modify the _type directly
	//But the const at the end promise to not modify _type ???WHY?
	//instructed create a member function that returns a const reference to type
	//const at the end prevent thats as get only should get & not modify/set
    return _type;
}

void Weapon::setType(std::string newType)
{
	std::cout << "Set New Type \n";
	this->_type = newType;
}