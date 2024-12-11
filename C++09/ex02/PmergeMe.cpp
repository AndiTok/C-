/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:20:53 by atok              #+#    #+#             */
/*   Updated: 2024/06/13 06:20:53 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(PmergeMe const &copy) : _d(copy._d), _v(copy._v) { }

PmergeMe::~PmergeMe() { }

PmergeMe &PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		_d = rhs._d;
		_v = rhs._v;
	}
	return *this;
}

bool is_digit(std::string str)
{
	int i = 0;

	if (str[i] == '-') // has '-' or is negative
	{
		i = 1;
		std::cout << "Error : negative number \n";
		exit(1);
	}
	
	while (str[i] != 0x00)
	{
		if(!std::isdigit(str[i]))
			return false;
		i++;
	}
	
	return true;
}
void PmergeMe::parse_input(char **av)
{
	for(int i = 1; av[i]; i++)
	{
		if (!is_digit(av[i]))
		{
			std::cout << "Error : not a valid number\n";
			exit(1);
		}

		std::istringstream iss(av[i]);
		int nb;

		iss >> nb;
		_d.push_back(nb);
		_v.push_back(nb);
	}
	// print_d();
	// print_v();
}


void PmergeMe::print_d(void)
{
	std::cout << "deque  -> ";

	for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); ++it) 
		std::cout << *it << ' ';
	
	std::cout << std::endl;
}

void PmergeMe::print_v(void)
{
	std::cout << "vector -> ";

	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); ++it) 
		std::cout << *it << ' ';
	
	std::cout << std::endl;
}