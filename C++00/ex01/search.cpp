/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 01:17:27 by atok              #+#    #+#             */
/*   Updated: 2023/07/13 01:17:27 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

std::string Contact::getAttribute(std::string attributeName)
{
    if (attributeName == "first") //2
        return _first;
    else if (attributeName == "last") //3
        return _last;
    else if (attributeName == "nickname") //4
        return _nickname;
    else if (attributeName == "number")	
        return _number;
    else if (attributeName == "secret")
        return _secret;
    else if (attributeName == "index") //1
        return _index;
	else
		//std::cout << "first,last,nickname,number,secret or index \n";
    	return "";
}

void PhoneBook::ft_display()
{
    std::cout   << ".--------------Contact Display--------------.\n"
	            << "|     Index|First Name| Last Name|  Nickname|\n"
	            << "|===========================================|\n";

    for (int i = 0; i < N; i++) // change to 2 to test
    {
        //std::cout << '|' << std::setw(10) << _contacts[i].getAttribute("index") << '|';
        std::cout << '|' << std::setw(10) << i + 1 << '|';
		
		std::string output;
		output = _contacts[i].getAttribute("first");
		if(output.length() > 10)
			output.resize(10);
		output[9] = '.';
		std::cout << std::setw(10);
		std::cout << output;
		std::cout << '|';

		output = _contacts[i].getAttribute("last");
		if(output.length() > 10)
			output.resize(10);
		output[9] = '.';
		std::cout << std::setw(10);
		std::cout << output;
		std::cout << '|';

		output = _contacts[i].getAttribute("nickname");
		if(output.length() > 10)
			output.resize(10);
		std::cout << std::setw(10);
		output[9] = '.';
		std::cout << output << "|\n";
    }
	std::cout   << "'''''''''''''''''''''''''''''''''''''''''''''\n";
}

void PhoneBook::search()
{
	std::string input;

	PhoneBook::ft_display();
	std::cout << "Enter 1 to 8 or back \n";
	
	while (1)
	{
		std::getline(std::cin, input);
		std::stringstream iss(input); //string to int
		int index;
		iss >> index;
		if(input == "back" || input == "exit" || input == "clear" ||
				input == "b" || input == "e"|| input == "c")
			break;
		else if (input.empty())
			std::cout << "Enter 1 to 8 or back \n";
		//else if(std::stoi(input) > 0 && std::stoi(input) < 9) // does not run on std98
		else if(index > 0 && index < N + 1) // does not run on std98
		{
			//int index = std::stoi(input);
			index = index - 1; // - 1 becase to start from 0
		
			std::cout << "First name     : " << _contacts[index].getAttribute("first") << std::endl;
			std::cout << "Last name      : " << _contacts[index].getAttribute("last") << std::endl;
			std::cout << "Nickename      : " << _contacts[index].getAttribute("nickname") << std::endl;
			std::cout << "Phone number   : " << _contacts[index].getAttribute("number") << std::endl;
			std::cout << "Darkest secret : " << _contacts[index].getAttribute("secret") << std::endl;
			
			std::cout << "Enter 1 to 8 or back \n";
		}
		else 
			std::cout << "Enter 1 to 8 or back \n";
	}
}
