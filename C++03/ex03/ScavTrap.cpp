/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:16:39 by atok              #+#    #+#             */
/*   Updated: 2023/08/22 15:47:24 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;

ScavTrap::ScavTrap()
{
	this->_name = "Default Scav";
	this->_hp = 100; 
	this->_ep = 50; 
	this->_ap = 20; 

	cout << "Default Scav constructor called\n";
	cout << "ScavTrap " << _name << " constructed\n\n";
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hp = 100; 
	this->_ep = 50; 
	this->_ap = 20; 

	cout << "Parameter Scav constructor called\n";
	cout << "ScavTrap " << _name << " constructed\n\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	cout << "Copy Scav constructor called\n\n";
	*this = copy;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	cout << "Scav Copy assingment operator called\n\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ap = rhs._ap;
	}

	return *this;
}

ScavTrap::~ScavTrap()
{
	cout << "Scav Destructor called\n";
	cout << "ScavTrap " << _name << " erased\n\n";
}

void ScavTrap::guardGate()
{
	if (this->_hp == 0)
	{
		cout << "ScavTrap  " << _name << " is dead... unable to enter GK mode\n\n";
		return;
	}
    if (_ep == 0)
    {
        cout << "ScavTrap " << _name << " has 0 ep to pefrom GK mode\n\n";
        return;
    }
	else
	{
		cout << "ScavTrap " << _name << " is now in Gate keeper mode!\n\n";
		_ep--;
	}
}

void ScavTrap::attack(const std::string& target)
{
	if (_hp == 0)
	{
		cout << "ScavTrap  " << _name << " is dead...\n\n";
		return;
	}
    if (_ep == 0)
    {
        cout << "ScavTrap " << _name << " has 0 ep to atk!\n\n";
        return;
    }
	else 
    {	
		cout << "ScavTrap " << _name << " atk " << target;
		cout << ", dealing " << _ap << " dmg\n"; // \n
	    _ep--;
	}
}