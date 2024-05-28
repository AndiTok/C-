/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:39:07 by atok              #+#    #+#             */
/*   Updated: 2023/08/25 16:39:07 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

using std::cout;

Ice::Ice() // : AMateria("ice") // A
{
    this->type = "ice"; // B
    cout << "Default Ice constructor called\n";
}

Ice::Ice(const Ice &copy) : AMateria(copy) 
{
    // cout << "Copy Ice constructor called\n";
    *this = copy;
}

Ice &Ice::operator=(const Ice &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.getType();
    }
    return *this;
}

Ice::~Ice() 
{
    cout << "Ice Destructor called\n";
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}