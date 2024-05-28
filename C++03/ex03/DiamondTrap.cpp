/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:46:19 by atok              #+#    #+#             */
/*   Updated: 2023/08/17 16:46:19 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

using std::cout;

DiamondTrap::DiamondTrap()
{
	this->_name = "Default Diamond";
	ClapTrap::_name = this->_name + "_clap_trap";
	_hp = FragTrap:: _hp;
	_ep = ScavTrap:: _ep;
	_ap = FragTrap:: _ap;

	cout << "Default Diamond constructor called\n";
	cout << "DiamondTrap " << _name << " constructed\n\n";
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_trap"; // specifically assign ClapTrap _name attribute
	_hp = FragTrap:: _hp;				// else it will use the last constructed _name by default
	_ep = ScavTrap:: _ep;
	_ap = FragTrap:: _ap;
	// cout << _hp << "\n"; 
	// cout << _ep << "\n"; 
	cout << "Parameter Diamond constructor called\n";
	cout << "DiamondTrap " << _name << " constructed\n\n";
}

//base class ‘class ClapTrap’ should be explicitly initialized in the copy constructor 
DiamondTrap::DiamondTrap(const DiamondTrap &copy) //: ClapTrap(copy), FragTrap(copy), ScavTrap(copy) // B must be in order 1st = base then following .hpp order
{
	cout << "Copy Diamond constructor called\n\n";
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	cout << "Diamond Copy assingment operator called\n\n";
	if (this != &rhs)
	{

		// this->_name = rhs._name;  // A
		// ClapTrap::_name = rhs._name + "_clap_trap";
		// _hp = FragTrap:: _hp;
		// _ep = ScavTrap:: _ep;
		// _ap = FragTrap:: _ap;

		this->_name = rhs._name; // B
		ClapTrap::_name = rhs._name + "_clap_trap";
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ap = rhs._ap;
	}

	return *this;
}

DiamondTrap::~DiamondTrap()
{
	cout << "Diamond Destructor called\n";
	cout << "DiamondTrap " << _name << " erased\n\n";
}

void DiamondTrap::whoAmI()
{
	if (this->_hp == 0)
	{
		cout << "DiamondTrap " << _name << " is dead... unable to speak\n\n";
		return;
	}
	if (this->_ep == 0)
	{
		cout << "DiamondTrap " << _name << " has 0 ep to speak\n\n";
		return;
	}
	else
	{
		cout << "DiamondTrap says : I am " << this->_name << "\n";
		cout << "DiamondTrap says : my ancestor is " << ClapTrap::_name << "\n\n";
		//is using & showing Scav defualt constructor name 
		//coz Scav is the last to be constructed/initialized 
		//& there is a private string _name in Diamond.hpp
		// wihtout it, it will call/use it's own name
		_ep--;
	}
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}