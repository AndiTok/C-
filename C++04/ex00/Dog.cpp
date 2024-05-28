/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:01:19 by atok              #+#    #+#             */
/*   Updated: 2023/08/21 13:02:09 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

using std::cout;

Dog::Dog()
{
	this->_type = "Dog";
	cout << "Default Dog constructor called\n";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	cout << "Copy Dog constructor called\n";
	*this = copy;
}

Dog &Dog::operator=(Dog const &rhs)
{
	cout << "Dog Copy assingment operator called\n";
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}

	return *this;
}

Dog::~Dog()
{
	cout << "Dog Destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << _type << ": Woof!\n";
}
