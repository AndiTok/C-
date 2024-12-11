#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

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
void insert_s_to_b(Container& arr, typename Container::value_type& value)
{
	static int n = 1; // point to original b container head
	std::cout << "n =" << n <<std::endl; // n+=2 coz as we add s to b we move the R/upperbound point to the right  
	int pos = binary_interval_search(arr, value, 0, n += 2);// arr.size()); // n+=2 to optimize
	arr.insert(arr.begin() + pos, value);
}

template<typename Container>
void execute(Container& arr)
{
	if (arr.size() <= 1 || is_sorted(arr)) 
	{
		return;
	}


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

	//checking b & s container
	for (typename Container::iterator it = b.begin(); it != b.end(); ++it)
			std::cout << *it << ", ";
	std::cout << std::endl;
	for (typename Container::iterator it = s.begin(); it != s.end(); ++it)
			std::cout << *it << ", ";

	b.insert(b.begin(),*s.begin()); // insert 1st s into b head \/ +1 s.begin

	// Insert elements from s into b using binary search
	for (typename Container::iterator it = s.begin() + 1; it != s.end(); ++it)
	{
		insert_s_to_b(b, *it);
	}

	// Insert the temporary element back into the array
	if (!tmp.empty())
	{
		// typename Container::iterator pos = std::lower_bound(b.begin(), b.end(), tmp[0]);
		// b.insert(pos, tmp[0]);

		typename Container::iterator it;
		for (it = b.begin(); it != b.end(); ++it)
		{
			if (*it > tmp[0]) 
			{
				break;  // Found the position to insert
			}
		}
		b.insert(it, tmp[0]);  // Insert at the found position
	}

	// Assign sorted container b back to the original array
	arr = b;
}

int main() 
{
	// int vec_arr[] = {5, 11, 3, 9, 8, 6, 10,2, 7, 4, 1};
	int vec_arr[] = {1,4,20,11,35,33,26,6,29,28,41,48,14,10,39,2,46,19,25};
	// int vec_arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
	std::vector<int> vec(vec_arr, vec_arr + sizeof(vec_arr) / sizeof(vec_arr[0]));
	execute(vec);

	std::cout << "Sorted vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// int deq_arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
	// std::deque<int> deq(deq_arr, deq_arr + sizeof(deq_arr) / sizeof(deq_arr[0]));
	// execute(deq);

	// std::cout << "Sorted deque: ";
	// for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) 
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;

	return 0;
}



/* 
#include "PmergeMe.hpp"

std::deque<int> recurse(std::deque<int> main, int n)
{
	if (main.size() == n)
		return main;
	
	std::deque<int> b;
	std::deque<int> s;
	// std::deque<int> t;

	int size = main.size();
	// if(size % 2 != 0)
	// {
	// 	t.push_back(*main.end());
	// 	main.pop_back();
	// 	size--;
	// }
	for (int i = 0; i < size; i+=2)
	{
		if(main[i] >= main[i+1]) // pair & sort
		{
			b.push_back(main[i]);
			s.push_back(main[i+1]);
		}
		else
		{
			b.push_back(main[i+1]);
			s.push_back(main[i]);
		}
	}
	b = recurse(b,n);

	std::deque<int> o;
	o.insert(o.end(), b.begin(), b.end());
 	o.insert(o.end(), s.begin(), s.end());
	return o;
}

int main()
{
	// std::deque<int> main = {3,5,4,1,9,12,10,11,13,14,6,2,7,8};

	// std::deque<int> main = {3,5,4,1,6,2,7,8};
	// std::deque<int> main = {3,5,4,1,6,9,2,7,8};

	// std::deque<int> main = {5,2,3,1,4,7,6}; //odd
	// std::deque<int> main = {5,2,3,1,4,7}; //even
	std::deque<int> main = {9,4,6,8,3,5,7,1}; 

	std::deque<int> output = recurse(main,main.size()/2);

	for (std::deque<int>::iterator it = output.begin(); it != output.end(); ++it)
	{
		std::cout << *it << " ";
	}
	// work with even number array
	// recursion funtion sort of wroks as intended
	// output is correct if u split to half
	// then sort both array the same way
	// can use insertion from mid point to place 1/2 list on right to left
	// if got strangler insert in
}
 */