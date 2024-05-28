/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:19:08 by atok              #+#    #+#             */
/*   Updated: 2023/08/18 14:11:17 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ClapTrap.hpp"
#include "FragTrap.hpp"

//single level/multi level inheritence

int main ()
{
	FragTrap p1 = FragTrap("FRAG-1");
	FragTrap p2("FRAG-2");

	p1.attack("FRAG-2");
	p2.takeDamage(30);
	p2.attack("FRAG-2");
	p1.takeDamage(30);
	p1.highFivesGuys();
	p2.highFivesGuys();
	p1.attack("FRAG-2");
	p1.attack("FRAG-2");
	p1.attack("FRAG-2");
	p2.takeDamage(90);
	p1.highFivesGuys();
	p2.highFivesGuys();

}