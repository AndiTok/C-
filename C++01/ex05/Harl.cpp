/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:20:42 by atok              #+#    #+#             */
/*   Updated: 2023/07/26 14:20:42 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() 
{
	std::cout << "constructed \n";
}

Harl::~Harl() 
{
	std::cout << "DEconstructed \n";
}

void Harl::debug() 
{
    std::cout << "DEBUG Lv1 : \n I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info() 
{
    std::cout << "INFO Lv2 : \n I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning() 
{
    std::cout << "WARNING Lv3 : \n I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error() 
{
    std::cout << "ERROR Lv4 : \n This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) 
{
    //typedef void (Harl::*ptr2memberFunction)();

    ptr2memberFunction functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};  
	// Array of pointers to member functions, one for each complaint level
    
	std::string levels[4] = {"debug", "info", "warning", "error"};   
	// Array of strings/words that represent the complaint levels
    
	//const size_t functionlevel = sizeof(functions) / sizeof(functions[0]); 
	// for dynamic allocation scaling else repalce the static allocated '4' below with "functionlevel" & remove the '4' above

    for (size_t i = 0; i < 4; i++) 
	{
        if (level == levels[i]) 
		{
            (this->*(functions[i]))();
            return;
        }
    }

    std::cout << "Invalid Lv over 9000 !!! : \n " << level << std::endl;
}