/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:35:52 by atok              #+#    #+#             */
/*   Updated: 2023/07/20 21:35:52 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 4;
	Zombie *horde = zombieHorde(N,"Zombie ");
/*     for (int i = 0; i < N; ++i)
    {
        horde[i].announce(); // Announce each Zombie
    } */
	delete[] horde; // delete the array
	return(0);
}