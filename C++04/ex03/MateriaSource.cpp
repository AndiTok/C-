/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaterialSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:12:26 by atok              #+#    #+#             */
/*   Updated: 2023/08/25 21:12:26 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

using std::cout;

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        materia[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    for (int i = 0; i < 4; ++i)
    {
        if (copy.materia[i] != 0)
            materia[i] = copy.materia[i]->clone();
        else
            materia[i] = 0;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete materia[i];
            if (rhs.materia[i] != 0)
                materia[i] = rhs.materia[i]->clone();
            else
                materia[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete materia[i];
}

void MateriaSource::learnMateria(AMateria *type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materia[i] == 0)
        {
            materia[i] = type;
			cout << "successfully learned " << materia[i]->getType() << "\n";
			cout << "at BRAIN slot " << i << "\n";
            return;
        }
    }
	cout << "can not learn anymore\n";
	return ;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materia[i] != 0 && materia[i]->getType() == type)
    	{
			cout << "successfully created " << materia[i]->getType() << " Skill \n";
			return materia[i]->clone();
		}
    }
	cout << "can't create materia that has not learned \n";
    return 0; // Materia type not found
}
