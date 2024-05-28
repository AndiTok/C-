/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:15:42 by atok              #+#    #+#             */
/*   Updated: 2023/08/16 19:41:51 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string input;
	//std::string input = "";
	
	// std::cin >> input;
	// getline(std::cin,input);
	
	while(1)
	{
		std::cout << "ADD,SEARCH,EXIT\n";
		//std::cin >> input; // cin only take 1 word
		// UNLESS std::string input = "";
		getline(std::cin,input); // takes whole string & has option to parse in
		
		if(input == "ADD" || input == "add" || input == "a")
			phoneBook.add();
		else if(input == "SEARCH" || input == "search" || input == "s")
			phoneBook.search();
		else if(input == "EXIT" || input == "exit" || input == "e")
			break;
	}
	return (0);
}

