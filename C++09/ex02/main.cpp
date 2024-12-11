/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 01:24:39 by atok              #+#    #+#             */
/*   Updated: 2024/06/10 01:24:39 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **av)
{
	if (ac > 1)
	{
		clock_t t;
		PmergeMe S;
		
		S.parse_input(av);
		
		std::cout << "Before : ";
		S.print_any(S._d);
		
		t = clock();
		S.execute(S._d);
		t = clock() - t;
		
		std::cout << "After  : ";
		S.print_any(S._d);

		std::cout << "It took > "
		<<  std::fixed  << std::setprecision(6)
		<< ((float) t) / CLOCKS_PER_SEC << " < Sec to sort "
		<< S._d.size() << " elemnts with std::deque \n";

		t = clock();
		S.execute(S._v);
		t = clock() - t;

		std::cout << "It took > "
		<<  std::fixed  << std::setprecision(6)
		<< ((float) t) / CLOCKS_PER_SEC << " < Sec to sort "
		<< S._d.size() << " elemnts with std::vector \n";

//-------------------------

		// clock_t t;
		// PmergeMe S;
		
		// S.parse_input(av);
		
		// std::cout << "Before ";
		// S.print_d();
		
		// t = clock();
		// S.execute(S._d);
		// t = clock() - t;
		
		// std::cout << "After ";
		// S.print_d();

		// std::cout << "it took "
		// <<  std::fixed  << std::setprecision(6)
		// << ((float) t) / CLOCKS_PER_SEC << " seconds to sort.\n";

		
		// std::cout << "Before ";
		// S.print_v();
		
		// t = clock();
		// S.execute(S._v);
		// t = clock() - t;
		
		// std::cout << "After ";
		// S.print_v();

		// std::cout << "it took "
		// <<  std::fixed  << std::setprecision(6)
		// << ((float) t) / CLOCKS_PER_SEC << " seconds to sort.\n";
	}
	else
	{
		std::cout << "Error : not enough arguments\n";
		return 1;
	}
	
	return 0;
}
// ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
// g++ -std=c++98 main.cpp PmergeMe.cpp -Wall -Wextra -Werror && ./a.out 3 6 5 4 8 9 2 7 1
// g++ -std=c++98 main.cpp PmergeMe.cpp -Wall -Wextra -Werror && ./a.out `shuf -i 1-100000 -n 3000 | tr "\n" " "`