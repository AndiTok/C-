/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 00:18:20 by atok              #+#    #+#             */
/*   Updated: 2023/08/21 00:18:20 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

using std::cout;

WrongAnimal::WrongAnimal() : _type("unknown wrong")
{
	cout << "Default WrongAnimal constructor called\n";
	cout << "WrongAnimal " << _type << " constructed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	cout << "Copy WrongAnimal constructor called\n\n";
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	cout << "WrongAnimal Copy assingment operator called\n";
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}

	return *this;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal Destructor called\n";
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}

void WrongAnimal::makeSound() const
{
    std::cout << _type << " animal wrong sound!\n";
}
