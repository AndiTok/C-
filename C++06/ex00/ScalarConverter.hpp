/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 06:22:45 by atok              #+#    #+#             */
/*   Updated: 2024/05/18 06:22:45 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAERCONVERTER_HPP
#define SCALAERCONVERTER_HPP

#include <string>   // For std::string
#include <iostream> // For std::cout
#include <cstdlib>  // For std::strtol, std::strtof, std::strtod
#include <climits>  // For INT_MIN, INT_MAX
#include <cfloat>   // For FLT_MAX
#include <cctype>   // For isprint, isdigit
#include <cmath>    // For define I INFINITY
// #include <cerrno>   // For errno
#include <limits>   // For std::numeric_limits<int>::max()

class ScalarConverter
{
	private:
	// Prevent class from instantiation by user
	// by shifting all "Orthodox Canonical Form" here
	// as this class does not store anything at all.
	// Adding "= delete" adds to clarity >>(only in c++11)<<
	// explicitly telling it is disables/not allowed
	// good practice to include it for better readability 
	// and to prevent accidental misuse of the class
	// preventing unintentional behaviour
		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter &operator=(const ScalarConverter& rhs);
		~ScalarConverter();

	public:
		static void convert(std::string input);
};
#endif