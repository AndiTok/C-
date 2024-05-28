/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:42:45 by atok              #+#    #+#             */
/*   Updated: 2023/08/20 15:42:45 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
/* 	const Animal* i = new Cat();
	std::cout << "\n";
	const Animal* j = new Dog(); 
	std::cout << "\n";
	delete i;
	std::cout << "\n";
	delete j;//should not create a leak 
	std::cout << "\n"; */
	///...

/* 
// copy assingment coded to be deep copy
//deep copy
	Cat *k = new Cat(); 
	std::cout << "\n";
	Cat *j = new Cat(*k); 
	std::cout << "\n";
	k->makeSound();
	j->makeSound();
	std::cout << "address k: " << &k << std::endl;
	std::cout << "address j: " << &j << std::endl;
	delete j;
	std::cout << "\n";
	k->makeSound();
	// j->makeSound(); // test if error with fsanitize is correct */

/* // shallow copy
	Cat *k = new Cat(); 
	std::cout << "\n";
	Cat *j = k; 
	std::cout << "\n";
	k->makeSound();
	j->makeSound();
	std::cout << "address k: " << k << std::endl;
	std::cout << "address j: " << j << std::endl;
	delete j;
	std::cout << "\n";
	k->makeSound(); */



	Animal *a[100]; //double array stack allocated
	for(int i = 0; i < 100; i++)
	{	
		if (i < 50)
			a[i] = new Dog();// heap allocated
		else
			a[i] = new Cat();// heap allocated
	}
	for(int i = 0; i < 100; i++)
	{	
		if (i < 50)
			delete a[i];// explicit delete/free heap
		else
			delete a[i];// explicit delete/free heap
	}
	// stack auto delete/free
	return 0;
}

//extercise is about deep vs shallow copy
// shallow int i = 0, int &j = i;
// deep inti = 0, int j = i;
// Zombiehord & Diamondtrap & Fixed point