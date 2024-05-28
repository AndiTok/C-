/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:25:29 by atok              #+#    #+#             */
/*   Updated: 2023/08/25 14:25:29 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];

	public:
		Character();
		Character(std::string const &name);
		Character(const Character &copy);
		Character &operator=(const Character &rhs);
		~Character();
	
	// static AMateria *floor[]; //static non memeber to be shared by all;
	
	std::string const & getName() const;
	void equip(AMateria* type);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif