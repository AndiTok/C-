/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:03:00 by atok              #+#    #+#             */
/*   Updated: 2023/08/28 17:53:47 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

using std::cout;

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	cout << "Default WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	cout << "Copy WrongCat constructor called\n";
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	cout << "WrongCat Copy assingment operator called\n";
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}

	return *this;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat Destructor called\n";
}

// void WrongCat::makeSound() const
// {
//     std::cout << _type << ": Wrong Meow!?\n";
// }
