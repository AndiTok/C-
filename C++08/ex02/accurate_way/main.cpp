/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:54:39 by atok              #+#    #+#             */
/*   Updated: 2024/05/31 06:54:39 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <list>

int main()
{
	// default stack with deque as container
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack); // able to copy construct stack using mutant stack
	std::cout << '\n';

//-------
	// stack wiht explicit vector as its container
	MutantStack<int, std::vector<int> > vmstack;

	vmstack.push(5);
	vmstack.push(17);

	std::cout << vmstack.top() << std::endl;

	vmstack.pop();

	std::cout << vmstack.size() << std::endl;

	vmstack.push(3);
	vmstack.push(5);
	vmstack.push(737);
	//[...]
	vmstack.push(0);

	MutantStack<int, std::vector<int> >::iterator vi = vmstack.begin();
	MutantStack<int, std::vector<int> >::iterator ve = vmstack.end();

	++vi;
	--vi;
	while (vi != ve)
	{
		std::cout << *vi << std::endl;
		++vi;
	}
	std::stack<int, std::vector<int> > v(vmstack);
	std::cout << '\n';
//----
	// 17 1 5 3 5 737 0
	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);

	// std::cout << *lstack.begin() << std::endl;
	std::cout << lstack.back() << std::endl;

	lstack.pop_back();

	std::cout << lstack.size() << std::endl;

	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);

	std::list<int>::iterator i = lstack.begin();
	std::list<int>::iterator end = lstack.end();

	++i;
	--i;
	while (i != end)
	{
		std::cout << *i << std::endl;
		++i;
	}
	std::list<int> l(lstack);
	return 0;
}