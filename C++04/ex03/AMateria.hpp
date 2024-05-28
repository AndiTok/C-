/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:24:13 by atok              #+#    #+#             */
/*   Updated: 2023/08/25 14:24:13 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &rhs);  //pretty obsolete, Ice & Cure run their own ft
		virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0; // = 0 no need to define funtion here
	virtual void use(ICharacter& target);
};

#endif