/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 07:06:45 by atok              #+#    #+#             */
/*   Updated: 2024/05/18 07:06:45 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

using std::cout;

ScalarConverter::ScalarConverter()
{
	cout << "Default ScalarConverter constructor called\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	cout << "Copy ScalarConverter constructor called\n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	cout << "Copy assingment constructor ScalarConverter called\n";
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	cout << "Deconstructor ScalarConverter called\n";
}

void ScalarConverter::convert(std::string input)
{
	// Handle special floating-point values
	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		cout << "char: impossible\n";
		cout << "int: impossible\n";
		cout << "float: " << input << "\n";
		cout << "double: " << input.substr(0, input.size() - 1) << "\n";
		// if intput == "-inff"
		// std::string mod = "-inf"
		// double print mod instead
		return;
	}
	if (input == "-inf" || input == "+inf" || input == "nan")
	{
		cout << "char: impossible\n";
		cout << "int: impossible\n";
		cout << "float: " << input + "f" << "\n";
		cout << "double: " << input << "\n";
		return;
	}
	
	// isprint can say is betwwen 32 & 127
	// isdigit cna say is between 0 & 9
	// length can say at input[1] == '\0'

	// Attempt to convert input to a char
	// if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
	// if (input.length() == 1)
	if (input[1] == 0x00)
	{
		cout << "at char\n";
		char c = input[0];
		cout << "char: '" << c << "'\n";
		cout << "int: " << static_cast<int>(c) << "\n";
		cout << "float: " << static_cast<float>(c) << ".0f\n";
		cout << "double: " << static_cast<double>(c) << ".0\n";
		return;
	}

	char *end; // points to the 1st character after the converted number in the input string

	// if str contain no decimal and no f = int
	// if str contain decimal and f = float
	// if str contain decimal and no f = double
	bool ff = false;
	bool dd = false;
	for (int i; i = 0; i++)
	{
		if (input[i] == '.')
			dd = true;
		if (input[i] == 'f')
			ff = true;
	}

	// Convert to int
	long l = std::strtol(input.c_str(), &end, 10);
	if (*end == '\0' && l >= INT_MIN && l <= INT_MAX)
	// if (*end == '\0' && !dd && !ff)
	{
		cout <<"at int\n";
		int i = static_cast<int>(l);
		if (i >=32 && i <= 127)
			cout << "char: '" << static_cast<char>(i) << "'\n";
		else if(i >=0 && i <=31)
			cout << "char: Non displayable\n";
		else
			cout << "char: impossible\n";
		cout << "int: " << i << "\n";
		cout << "float: " << static_cast<float>(i) << ".0f\n";
		cout << "double: " << static_cast<double>(i) << ".0\n";
		return;
	}

	// Convert to float
	float f = std::strtof(input.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
	{
		cout <<"at float\n";
		cout << f << '\n';
		if (f >= CHAR_MIN && f <= CHAR_MAX && isprint(static_cast<int>(f)))
			cout << "char: '" << static_cast<char>(f) << "'\n";
		else
			cout << "char: impossible\n";
		if (f >= INT_MIN && f <= INT_MAX)
			cout << "int: " << static_cast<int>(f) << "\n";
		else
			cout << "int: impossible\n";
		// std::cout.precision(10);
		// cout << "float: " << std::fixed << f << "f\n";
		cout << "float: " << f << "f\n";
		cout << "double: " << static_cast<double>(f) << "\n";
		return;
	}

	// Convert to double
	double d = std::strtod(input.c_str(), &end);
	if (*end == '\0')
	{
		cout <<"at double\n";
		if (d >= CHAR_MIN && d <= CHAR_MAX && isprint(static_cast<int>(d)))
			cout << "char: '" << static_cast<char>(d) << "'\n";
		else
			cout << "char: impossible\n";
		if (d >= INT_MIN && d <= INT_MAX)
			cout << "int: " << static_cast<int>(d) << "\n";
		else
			cout << "int: impossible\n";
		if (d >= -FLT_MAX && d <= FLT_MAX)
			cout << "float: " << static_cast<float>(d) << "f\n";
		else
			cout << "float: impossible\n";
		cout << "double: " << d << "\n";
		return;
	}

	// If none of the above, the input is invalid
	cout << "at other\n";
	cout << "char: impossible\n";
	cout << "int: impossible\n";
	cout << "float: impossible\n";
	cout << "double: impossible\n";
}