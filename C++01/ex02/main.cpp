/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:23:46 by atok              #+#    #+#             */
/*   Updated: 2023/07/21 00:23:46 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using std::cout;

void addstr(std::string &str)
{
	str += " Hello";
}

void addpstr(std::string *str)
{
	*str += " Hello";
}

int main ()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str; //holding memory address of str
	std::string &stringREF = str;  // referencing str aka same as str BUT any changes made in stringREF will change str
	
	cout << &str << "\n"; // get address with &
	cout << stringPTR << "\n";// already contain adress itself
	cout << &stringREF << "\n";// it itself is pointing to str
	
	cout << str << "\n"; // get value that is in str
	cout << *stringPTR << "\n";// point to value 
	cout << stringREF << "\n"; // get value of str

	// stringREF = "HUH?";
	// *stringPTR += " Hello";
	// &stringREF += " Hello";
	// addstr(str);
	// addpstr(&str);

	cout << &str << "\n";
	cout << stringPTR << "\n";
	cout << &stringREF << "\n";
	
	cout << str << "\n";
	cout << *stringPTR << "\n";
	cout << stringREF << "\n";
}
// BASICALLY TRY with '*' or with '&' OR 'none'

// Write a program that contains:
	//• A string variable initialized to "HI THIS IS BRAIN".
	//• stringPTR: A pointer to the string.
	//• stringREF: A reference to the string.
// Your program has to print:
	// • The memory address of the string variable.
	// • The memory address held by stringPTR.
	// • The memory address held by stringREF.
// And then:
	// • The value of the string variable.
	// • The value pointed to by stringPTR.
	// • The value pointed to by stringREF.

// That’s all, no tricks. The goal of this exercise is to demystify references which can
// seem completely new. Although there are some little differences, this is another syntax
// for something you already do: address manipulation.
