/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:41:58 by atok              #+#    #+#             */
/*   Updated: 2023/07/12 15:41:58 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

void Contact::setAttribute(std::string attributeName, std::string input) 
{
    if (attributeName == "first")
        _first = input;
    else if (attributeName == "last")
        _last = input;
    else if (attributeName == "nickname")
        _nickname = input;
    else if (attributeName == "number")
        _number = input;
    else if (attributeName == "secret")
        _secret = input;
    else if (attributeName == "index")
        _index = input;
}

int checker(std::string type , std::string input)
{
	if (input.empty())
    {
        std::cout << "Input cannot be empty, try again\n";
        return 0;
    }
	if(type == "first" || type == "last" || type =="nickname")
	{
		//for(char c : input) // only available on c++11
		for(size_t i = 0; input[i] != 0x00; i++)
		{
			//if(!isalpha(c)) // only available on c++11
			if(!isalpha(input[i]))// || !isspace(input[i]));
			{
				std::cout << "alphabet only, try again \n";
				return 0;
			}
		}
		return 1;
	}
	else if(type == "number")
	{
		for(size_t i = 0; i < input.length(); i++) //input.size()
		{
			if(!isdigit(input[i]))
			{
				std::cout << "digits only, try again \n";
				return 0;
			}
		}
		return 1;
	}
	return 1;
}

void PhoneBook::add()
{
	Contact newContact;
    std::string input;
	
	std::stringstream oss; // int to string
    oss << (_index + 1);
    newContact.setAttribute("index", oss.str());
	//newContact.setAttribute("index", std::to_string(_index + 1)); //+1 to indicate index 1
																	// only avalable on c++11
    std::cout << "Enter First Name: \n";
    std::getline(std::cin, input);
	while(checker("first",input) != 1)
		std::getline(std::cin, input);
    newContact.setAttribute("first", input);

    std::cout << "Enter Last Name: \n";
    std::getline(std::cin, input);
	while(checker("last",input) != 1)
		std::getline(std::cin, input);
    newContact.setAttribute("last", input);

    std::cout << "Enter Nickname: \n";
    std::getline(std::cin, input);
	while(checker("nickname",input) != 1)
		std::getline(std::cin, input);
    newContact.setAttribute("nickname", input);

    std::cout << "Enter Number: \n";
    std::getline(std::cin, input);
	while(checker("number",input) != 1)
		std::getline(std::cin, input);
    newContact.setAttribute("number", input);

    std::cout << "Enter Secret: \n";
    std::getline(std::cin, input);
	while(checker("secret",input) != 1)
		std::getline(std::cin, input);
    newContact.setAttribute("secret", input);

    _contacts[_index++ % N] = newContact; // set to 8 later, set 1 or 2 to test
    //_index++;

    std::cout << "Contact added successfully!" << std::endl;

}