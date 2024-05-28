/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:02:23 by atok              #+#    #+#             */
/*   Updated: 2023/08/19 15:14:33 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;

ClapTrap::ClapTrap() : _name("Default Clap"), _hp(10), _ep(10), _ap(0)
{
	cout << "Default Clap constructor called\n";
	cout << "ClapTrap " << _name << " constructed\n\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ap(0)
{
	cout << "Parameter Clap constructor called\n";
	cout << "ClapTrap " << _name << " constructed\n\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	cout << "Copy Clap constructor called\n\n";
	*this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	cout << "Clap Copy assingment operator called\n\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ap = rhs._ap;
	}

	return *this;
}

ClapTrap::~ClapTrap()
{
	cout << "Calp Destructor called\n";
	cout << "ClapTrap " << _name << " erased\n\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (_hp == 0)
	{
		cout << "ClapTrap " << _name << " is dead... can't atk\n\n";
		return;
	}
    if (_ep == 0)
    {
        cout << "ClapTrap " << _name << " has 0 ep to atk!\n\n";
        return;
    }
	else 
    {	
		cout << "ClapTrap " << _name << " atk " << target;
		cout << ", dealing " << _ap << " dmg\n\n";
	    _ep--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount == _hp)
    {
        cout << "ClapTrap " << _name << " Perfect KO!\n\n";
		_hp = _hp - amount;
        return;
    }
    else if (amount > _hp)
    {
        cout << "ClapTrap " << _name << " took " << amount << " dmg Overkill KO!\n\n";
		_hp = 0;
        return;
    }
    else if (amount < _hp)
	{
		cout << "ClapTrap " << _name << " took " << amount << " dmg\n\n";
    	_hp = _hp - amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0)
	{
		cout << "ClapTrap " << _name << " is dead... can't repair\n\n";
		return;
	}
	if (_ep == 0)
    {
        cout << "ClapTrap " << _name << " has 0 ep to repair!\n\n";
        return;
    }
	else
    {
		cout << "ClapTrap " << _name << " repairs " << amount << " HP\n\n";
    	_ep--;
    	_hp = _hp + amount;
	}
}
