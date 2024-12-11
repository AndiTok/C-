/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 07:46:33 by atok              #+#    #+#             */
/*   Updated: 2024/05/18 07:46:33 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// int main ()
// {
// 	std::string s = "234.7f";
// 	float f = 42.0f;
// 	char a = f;
// 	int i = -35;
// 	char b = 's';
// 	// ScalarConverter::convert(std::string("test"));
// 	// ScalarConverter::convert("test");
// 	std::cout << b;
// 	return 0;
// }

int main(int argc, char *argv[])
{
	// char a = 365;
	if (argc != 2)
	{
		std::cerr << "run this way > " << argv[0] << " <input>\n";
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

// int main ()
// {
// 	float a = 91876488462.5465540f;

// 	std::cout << a <<'\n';
// }


// int main ()
// {
// 	// #define I std::numeric_limits<int>::max() * -1;
// 	// #define I std::numeric_limits<float>::max() * -1;
// 	// #define I std::numeric_limits<double>::max() * -1;
// 	// #define I std::numeric_limits<int>::max();
// 	// #define I std::numeric_limits<float>::max();
// 	// #define I std::numeric_limits<double>::max();
// 	// #define I std::numeric_limits<long double>::max();
// 	// #define I INFINITY
// 	// #define I INFINITY * -1
// 	// #define I 0/0
// 	// #define I 'a'
// 	#define I sqrt(-2)

// 	char a = I;
// 	int b = I;
// 	float c = I;
// 	double d = I;

// 	std::cout << a << '\n';
// 	std::cout << b << '\n';
// 	std::cout << c << '\n';
// 	std::cout << d << '\n';
// }