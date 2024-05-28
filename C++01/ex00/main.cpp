/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:39:44 by atok              #+#    #+#             */
/*   Updated: 2023/07/19 18:39:44 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	test_zom()
{
		Zombie *heapzombie = newZombie("Heap Zombie "); //permanant untill delete
		heapzombie->announce();
		//delete heapzombie;
}

int main ()
{
	// Zombie zombie;
	// zombie.announce();
    
	std::cout << "----\n";
	//test_zom();
	
	// newZombie("Heap "); // same as below but not stored in any object
	Zombie *heapzombie = newZombie("Heap Zombie "); //permanant untill delete
	heapzombie->announce();

    std::cout << "----\n";
	randomChump("Stack Zombie "); // temporary till job is done
    std::cout << "----\n";

	delete heapzombie; // will decon when called to delete
	//system("leaks a.out"); // onyl can find if leaks is in a function outside of main
	return (0);
}

// optional use valgrind
// your executbale must not be run with -fsanitize=address
// else will bug
// it is able to find leaks in the main
// valgrind ./a.out << or what u name ur executable