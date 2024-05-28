/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:44:19 by atok              #+#    #+#             */
/*   Updated: 2023/08/20 15:44:19 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

using std::cout;

Animal::Animal() : _type("unknown")
{
	cout << "Default Animal constructor called\n";
	cout << "Animal " << _type << " constructed\n";
}

Animal::Animal(const Animal &copy)
{
	cout << "Copy Animal constructor called\n\n";
	*this = copy;
}

Animal &Animal::operator=(Animal const &rhs)
{
	cout << "Animal Copy assingment operator called\n";
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}

	return *this;
}

Animal::~Animal()
{
	cout << "Animal Destructor called\n";
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << _type << " animal sound!\n";
}
