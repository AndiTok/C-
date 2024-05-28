/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:15:13 by atok              #+#    #+#             */
/*   Updated: 2023/08/22 15:21:37 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

using std::cout;

FragTrap::FragTrap()
{
	this->_name = "Default Frag";
	this->_hp = 100; 
	this->_ep = 100; 
	this->_ap = 30; 

	cout << "Default Frag constructor called\n";
	cout << "FragTrap " << _name << " constructed\n\n";
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hp = 100; 
	this->_ep = 100; 
	this->_ap = 30; 

	cout << "Parameter Frag constructor called\n";
	cout << "FragTrap " << _name << " constructed\n\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	cout << "Copy Frag constructor called\n\n";
	*this = copy;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	cout << "Frag Copy assingment operator called\n\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ap = rhs._ap;
	}

	return *this;
}

FragTrap::~FragTrap()
{
	cout << "Frag Destructor called\n";
	cout << "FragTrap " << _name << " erased\n\n";
}

void FragTrap::highFivesGuys()
{
	if (this->_hp == 0)
	{
		cout << "FragTrap " << _name << " is dead... unable to hi5\n\n";
		return;
	}
	if (this->_ep == 0)
	{
		cout << "FragTrap " << _name << " has 0 ep to hi5\n\n";
		return;
	}
	else
	{
		cout << "FragTrap " << _name << " High 5 !\n\n";
		_ep--;
	}
}