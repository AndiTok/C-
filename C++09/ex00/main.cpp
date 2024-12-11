/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 06:41:13 by atok              #+#    #+#             */
/*   Updated: 2024/06/01 06:41:13 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	if (ac == 2)
	{
		std::ifstream input (av[1]);

		if(input.is_open())
		{
			if (input.peek() == std::ifstream::traits_type::eof())
			{
				std::cout << "Error : file is empty.\n";
				return (1);
			}
			//run programe
			BitcoinExchange btc;

			btc.execute(input);
			input.close();
		}
		else
			std::cerr << "Error : could not open file.\n";
	}
	else if (ac != 2)
		std::cerr << "Error : no input file.\n";
	return 0;
}