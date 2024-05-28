/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:01:19 by atok              #+#    #+#             */
/*   Updated: 2023/08/21 18:43:44 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

using std::cout;

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
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
		// this->_brain = rhs._brain; // shallow copy
		this->_brain = new Brain(*rhs._brain); // deep copy
	}

	return *this;
}

Dog::~Dog()
{
	cout << "Dog Destructor called\n";
	delete this->_brain;
}

void Dog::makeSound() const
{
    std::cout << _type << ": Woof!\n";
}
