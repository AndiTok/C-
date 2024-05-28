/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:09:15 by atok              #+#    #+#             */
/*   Updated: 2023/08/25 17:09:15 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

using std::cout;

Cure::Cure() // : AMateria("ice") // A
{
    this->type = "cure"; // B
    cout << "Default Cure constructor called\n";
}

Cure::Cure(const Cure &copy) : AMateria(copy) 
{
    // cout << "Copy Cure constructor called\n";
    *this = copy;
}

Cure &Cure::operator=(const Cure &rhs)
{
    if (this != &rhs)
    {
        this->type = rhs.getType();
    }
    return *this;
}

Cure::~Cure() 
{
    cout << "Cure Destructor called\n";
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << " *\n";
}