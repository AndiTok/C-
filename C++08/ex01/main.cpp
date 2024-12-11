/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:29:44 by atok              #+#    #+#             */
/*   Updated: 2024/05/28 10:29:44 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

// -------

	/* random value with repeats */
	Span tmp = Span(42); // 42 space allocated + added 2 elements
	tmp.addNumber(4);
	tmp.addNumber(2);
	srand(time(0));
	int range = 10000; // increase range to reduce duplicates
	int n = 40;
	std::vector<int> vec;
	for (int i = 0; i < n; i++) // generated 40 random elements
		vec.push_back(rand() % range);
	tmp.addNumber(vec.begin(),vec.end()); // add to main container

	/* random value w/o repetas */
	// Span tmp = Span(42);
	// int range = 10000;
	// int n = 42;
	// std::vector<int> vec;
	// for (int i = 0; i <= range; i++)
	// 	vec.push_back(i);
	// srand(time(0));
	// std::random_shuffle(vec.begin(),vec.end());
	// tmp.addNumber(vec.begin(),vec.begin() + n);

//----------

	for (std::vector<int>::iterator i = tmp._container.begin(); i != tmp._container.end(); i++)
		std::cout << *i << ","; // print out what it currently have
	std::cout << '\n';

	std::cout << "sorted below \n";
	std::sort(tmp._container.begin(),tmp._container.end()); // sort ascending
	for (std::vector<int>::iterator i = tmp._container.begin(); i != tmp._container.end(); i++)
		std::cout << *i << ","; // print after sorted for convenience
	std::cout << '\n';
	
	std::cout << "answer below \n";
	std::cout << tmp.shortestSpan() << std::endl;
	std::cout << tmp.longestSpan() << std::endl;

	return 0;
}