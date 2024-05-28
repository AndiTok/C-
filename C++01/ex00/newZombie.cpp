/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:56:29 by atok              #+#    #+#             */
/*   Updated: 2023/07/20 15:56:29 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie( std::string name ) //heap memory = untill delete
{
	Zombie *zombie = new Zombie(name); // Create a new Zombie object like malloc
	//delete zombie;				   // dealloc/remove pointer
    return (zombie);  			   		// Return the pointer to the created Zombie
}