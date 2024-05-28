/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:11:40 by atok              #+#    #+#             */
/*   Updated: 2023/08/25 15:11:40 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

using std::cout;

AMateria::AMateria() : type("BLANK")
{
	// cout << "Default AMateria constructor called\n";
	// cout << "AMateria " << type << " constructed\n";
}

AMateria::AMateria(std::string const & type) : type(type)
{
	// cout << "Parameter AMateria constructor called\n";
	// cout << "AMateria " << type << " constructed\n";
}


AMateria::AMateria(const AMateria & copy)
{
	// cout << "Copy AMateria constructor called\n";
	*this = copy;
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
	// cout << "AMateria Copy assingment operator called\n";
	if (this != &rhs)
	{
		// cout << "Error not the same AMateria type\n";
		// cout << "operation should not be peformed\n";
		// cout << "a BLANK is created instead\n";
		// return ;
	}
	return *this;
}

AMateria::~AMateria()
{
	// cout << "AMateria Destructor called\n";
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses " << type << " on " << target.getName() << " *\n";
}