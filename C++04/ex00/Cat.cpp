/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:40:46 by atok              #+#    #+#             */
/*   Updated: 2023/08/21 12:41:56 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

using std::cout;

Cat::Cat()
{
	this->_type = "Cat";
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
	}

	return *this;
}

Cat::~Cat()
{
	cout << "Cat Destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << _type << ": Meow!\n";
}