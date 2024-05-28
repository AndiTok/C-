/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:58:39 by atok              #+#    #+#             */
/*   Updated: 2023/07/26 16:58:39 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <stdio.h>

Harl::Harl()
{

}
		
Harl::~Harl()
{
	
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ] \n"; 
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do! \n\n";
}

void	Harl::info( void )
{
	std::cout << "[ INFO ] \n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more \n\n";
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ] \n";
	std::cout << "I think I deserve to have some extra bacon for free. \n";
	std::cout << "I've been coming here for years and you just started working here last month. \n\n";
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ] \n";
	std::cout << "This is unacceptable, I want to speak to the manager now. \n\n";
}

// void Harl::complain(std::string level) 
// {
//     ptr2memberFunction functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};  
    
// 	std::string levels[4] = {"debug", "info", "warning", "error"};   

//     for (size_t i = 0; i < 4; i++) 
// 	{
//         if (level == levels[i]) 
// 		{
//             size_t level = i;
//             break;
//         }
//     }

//     std::cout << "Invalid Lv over 9000 !!! : \n " << level << std::endl;
// }

void Harl::complain(std::string input)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; 
	int j = 0;
	for (int i = 0; i < 4; i++) 
	{
        if (input == levels[i]) 
		{
            j = i;
            break;
        }
		else
		{
			j = -1;
			//std::cout << "[ Probably complaining about insignificant problems ] \n";
			// return ;
		}
    }

	switch (j) 
	{
        case 0:
            debug();
            info();
            warning();
            error();
            break;

        case 1:
            info();
            warning();
            error();
            break;

        case 2:
            warning();
            error();
            break;

        case 3:
            error();
            break;

        default:
            std::cout << "[ Probably complaining about insignificant problems ] \n";
            //std::cout << "Invalid input " << input << std::endl;
    }
}