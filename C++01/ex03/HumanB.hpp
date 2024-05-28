/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:03:04 by atok              #+#    #+#             */
/*   Updated: 2023/07/24 17:03:04 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _nameB;
		Weapon *_weaponB;
	
	public:
		HumanB(std::string input);
		~HumanB();
		void setWeapon(Weapon &new_weapon);
		void attack (void);
};

#endif