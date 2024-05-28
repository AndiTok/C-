/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:22:25 by atok              #+#    #+#             */
/*   Updated: 2023/07/21 20:22:25 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string _type; // A private attribute "type", which is a "string".
	public:
		Weapon(std::string input);
		~Weapon();
		const std::string &getType() const; // A getType() <member function> that <returns a "const"> reference(&) to "type".
		void setType(std::string newType); // A setType() <member function> that sets type using the "new one" passed as parameter.
};

#endif