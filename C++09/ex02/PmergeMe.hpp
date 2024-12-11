/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:36:40 by atok              #+#    #+#             */
/*   Updated: 2024/06/10 18:36:40 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime> //clock
#include <iomanip> // set preicsion
#include <exception>

class PmergeMe
{
	private:

	public:
		std::deque<int> _d;
		std::vector<int> _v;

		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(const PmergeMe& rhs);
		~PmergeMe();
	
	void parse_input(char **av);
	void print_d(void);
	void print_v(void);

template<typename Container>
void print_any(Container &c)
{
	for (typename Container::iterator it = c.begin(); it < c.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

template<typename Container>
bool is_sorted(Container &c)
{
	for (typename Container::size_type i = 1; i < c.size(); ++i)
	{
		if (c[i-1] > c[i])
		{
			return false;
		}
	}
	return true;
}

template<typename Container>
int binary_interval_search(Container &arr, typename Container::value_type &value, int L , int R)
{
	while (L < R)
	{
		int mid = (L + R) / 2; // use `-9 as example on keyboard
		if (arr[mid] < value) // if value > arr[mid] 
		{
			L = mid + 1; // shift search to right
		} 
		else 
		{
			R = mid; // shift search to left
		}
	}
	return L;
}

template<typename Container>
void insert_s_to_b(Container &arr, typename Container::value_type &value)
{
	static int n = 1; // point to original b container head
	// std::cout << "n =" << n <<std::endl; // n+=2 coz as we add s to b we move the R/upperbound point to the right  
	int pos = binary_interval_search(arr, value, 0, n += 2);// arr.size()); // n+=2 to optimize
	arr.insert(arr.begin() + pos, value);
}

template<typename Container>
void execute(Container &arr)
{
	if (arr.size() <= 1 || is_sorted(arr))
		return ;


	// Check if the array has an even number of elements
	Container tmp;
	if (arr.size() % 2 != 0) 
	{
		tmp.push_back(arr.back());
		arr.pop_back();
	}

	Container b, s;

	// Separate elements into b and s container
	for (typename Container::size_type i = 0; i < arr.size(); i += 2)
	{
		if (arr[i] > arr[i+1]) 
		{
			b.push_back(arr[i]);
			s.push_back(arr[i+1]);
		} 
		else 
		{
			b.push_back(arr[i+1]);
			s.push_back(arr[i]);
		}
	}

	// Sort b in ascending order and maintain the coresponsing order of s
	bool sorted = false; // instead of running is_sort funtion
	while (!sorted)      // as long swap happens is not sorted
	{
		sorted = true;
		for (typename Container::size_type i = 0; i < b.size() - 1; ++i)
		{
			if (b[i] > b[i+1]) 
			{
				std::swap(b[i], b[i+1]);
				std::swap(s[i], s[i+1]);
				sorted = false;
			}
		}
	}

	// checking b & s container
	// for (typename Container::iterator it = b.begin(); it != b.end(); ++it)
	// 		std::cout << *it << ", ";
	// std::cout << std::endl;
	// for (typename Container::iterator it = s.begin(); it != s.end(); ++it)
	// 		std::cout << *it << ", ";

	b.insert(b.begin(),*s.begin()); // insert 1st s into b head \/ +1 s.begin

	// Insert elements from s into b using binary search
	for (typename Container::iterator it = s.begin() + 1; it != s.end(); ++it)
		insert_s_to_b(b, *it);

	// Insert the temporary element back into the array
	if (!tmp.empty())
	{
		typename Container::iterator it;
		for (it = b.begin(); it != b.end(); ++it) 
		{
			if (*it > tmp[0]) 
				break;  // Found the position to insert
		}
		b.insert(it, tmp[0]);  // Insert at the found position
	}

	// Assign sorted container b back to the original array
	arr = b;
}

};

#endif