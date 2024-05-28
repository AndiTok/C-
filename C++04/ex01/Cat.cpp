/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:40:46 by atok              #+#    #+#             */
/*   Updated: 2023/08/21 20:05:46 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

using std::cout;

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	cout << "Default Cat constructor called\n";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	cout << "Copy Cat constructor called\n";
	*this = copy;
}

Cat &Cat::operator=(Cat const &rhs)
{
	cout << "Cat Copy assingment operator called\n";
	if (this != &rhs)
	{
		this->_type = rhs._type;
		// this->_brain = rhs._brain; // shallow copy
		this->_brain = new Brain(*rhs._brain); // deep copy
	}
	return *this;
}

Cat::~Cat()
{
	cout << "Cat Destructor called\n";
	delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << _type << ": Meow!\n";
}
