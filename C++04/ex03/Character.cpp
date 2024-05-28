/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:05:42 by atok              #+#    #+#             */
/*   Updated: 2023/08/25 22:05:42 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

using std::cout;

Character::Character()
{
	this->name = "UNknown";
    for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
}

Character::Character(std::string const &name)
{
	this->name = name;
    for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
}

Character::Character(const Character &copy)
{
	this->name = copy.name;
    for (int i = 0; i < 4; ++i)
    {
        if (copy.inventory[i] != 0)
            inventory[i] = copy.inventory[i]->clone(); // wihtout the clone ft it will be shallow copy
        else
            inventory[i] = 0;
    }
}

Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
       for (int i = 0; i < 4; ++i)
        {
            delete inventory[i]; // delete then
            inventory[i] = 0;  // reallocate
        }
		
		name = rhs.name;
		 for (int i = 0; i < 4; ++i)
		{
			if (rhs.inventory[i] != 0)
				inventory[i] = rhs.inventory[i]->clone(); // wihtout the clone ft it will be shallow cop
			else
				inventory[i] = 0;
		}
	}
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *type)
{
	if(type == 0)
	{
		cout << "cannot to equip materia that is not created\n";
		return;
	}
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i] == 0)
        {
            inventory[i] = type;
			cout << "successfully equiped " << inventory[i]->getType() << "\n";
			cout << "at equipment slot " << i << "\n";
            return;
        }
    }
	cout << "inventory full!!! can not equip anymore \n";
	delete type;
	return ;
}

// AMateria *Character::floor[1];

void Character::unequip(int idx)
{
	AMateria *floor[1];
	if (idx >= 0 && idx < 4)
	{
		floor[0] = inventory[idx]; // pass the inventory Amateria address to a temporary space
		delete floor[0];			// then delete there
		inventory[idx] = 0; // not deleting becase not using delete still need the 4 inventory slot
		cout << "successfull unequiped\n";
		return ;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		cout << "only have slot 0 to 3\n";
		return ;
	}
	if (inventory[idx] == 0)
	{
		cout << "nothing in inveltory slot to use " << idx << "\n";
		return ;
	}
    if (idx >= 0 && idx < 4)
        // inventory[idx].use(target);
        inventory[idx]->use(target);
	//it either use/call the Ice or Cure use funtion
}
