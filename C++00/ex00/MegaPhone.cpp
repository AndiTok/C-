/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:01:31 by atok              #+#    #+#             */
/*   Updated: 2023/07/10 14:48:08 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <string>

// int main (int ac, char **av)
// {
// 	while(ac > 1)
// 	{
// 		for(int i = 1; av[i]; i++)
// 		{
// 			std::cout << av[i];
// 		}
// 		std::cout << "\n";
// 		return(0);
// 	}
// 	if(ac == 1)
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
// 		return (0);
// }

// int main (int ac, char **av)
// {
// 	while(ac > 1)
// 	{
// 		for(int i = 1; av[i]; i++)
// 		{
// 			char *out = av[i];
// 			while(*out)
// 			{
// 				*out = std::toupper(*out);
// 				out++;
// 			}
// 			std::cout << av[i];
// 		}
// 		std::cout << "\n";
// 		return(0);
// 	}
// 	if(ac == 1)
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
// 		return (0);
// }

// int main (int ac, char **av)
// {
// 	while(ac > 1)
// 	{
// 		int i = 1;
// 		std::string out;
// 		while(av[i])
// 		{
// 			out += av[i];
// 			i++;
// 		}
// 		i = 0;
// 		while(out[i])
// 		{
// 			out[i] = toupper(out[i]);
// 			i++;
// 		}
// 		std::cout << out;
// 		std::cout << "\n";
// 		return(0);
// 	}
// 	if(ac == 1)
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
// 		return (0);
// }

int main (int ac, char **av)
{
	while(ac > 1)
	{
		int i = 1;
		int j = 0;
		while(av[i])
		{
			j = 0;
			while(av[i][j])
			{
				std::cout << (char)toupper(av[i][j]);
				j++;
			}
			i++;
		}
		std::cout << "\n";
		return(0);
	}
	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
		return (0);
}
