/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 04:40:51 by atok              #+#    #+#             */
/*   Updated: 2024/05/28 04:40:51 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

int main()
{
	// Test with std::vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	int find = 4; // <<

	try
	{
		std::vector<int>::iterator it = easyfind(vec, find);
		std::cout << "Value " << find << " found at index " << std::distance(vec.begin(), it) << '\n';
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	// Test with std::deque
	std::deque<int> deq;
	deq.push_back(10);
	deq.push_back(20);
	deq.push_back(30);
	deq.push_back(40);
	deq.push_back(50);
	find = 20; // <<

	try
	{
		std::deque<int>::iterator it = easyfind(deq, find);
		std::cout << "Value " << find << " found at index " << std::distance(deq.begin(), it) << '\n';
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	// Test with std::list
	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(200);
	lst.push_back(300);
	lst.push_back(400);
	lst.push_back(500);
	find = 500;

	try
	{
		std::list<int>::iterator it = easyfind(lst, find);
		if (it != lst.end())
		{
			std::cout << "Value " << find << " found in the list." << '\n';
			std::cout << "Found at index: " << std::distance(lst.begin(),it) << '\n';
			// the above makes terminal stuck/hang if use T instead of T& in easyfind()
		}
		else
		{
			std::cout << "Value " << find << " not found in the list." << '\n';
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}