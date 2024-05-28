/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:35:26 by atok              #+#    #+#             */
/*   Updated: 2023/07/20 21:35:26 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream> //have to place her for ss to work at home

Zombie *zombieHorde( int N, std::string name )
{
/*     Zombie *horde = new Zombie[N]; // Create an array of N number of Zombies on the heap
	std::stringstream ss;
	for (int i = 0; i < N; ++i)
    {
		//std::cout << name + static_cast<std::string>(i + 1) + " ";
		//std::cout << name + std::to_string(i + 1) + " "; //does not prove it was crated
		//horde[i].announce();
		//---
		ss.str(""); // Clear the stream to avied appending
    	ss << name << i + 1 << " "; // Construct the name
		horde[i] = Zombie(ss.str()); // construct & set name + number for each Zombie in the horde
		// horde[i] = (ss.str()); // same as above?
		//---
		horde[i].announce();
    } */

	//-----
/* 	Zombie horde[N]; // <-warning: address of local variable ‘horde’ returned [-Wreturn-local-addr]
	for (int i = 0; i < N; ++i)
	{
		horde[i] = Zombie(name + std::to_string(i + 1));
		horde[i].announce();
	} */
	//------

	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		horde[i] = Zombie(name + std::to_string(i + 1));
		horde[i].announce();
	}
    return (horde);
}
