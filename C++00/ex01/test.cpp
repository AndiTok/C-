#include <iostream>
#include <sstream>
#include <string>

// int main ()
// {
// 	std::cout << "Hello, World!" << std::endl;

// 	int number = 42; // int to string
// 	std::stringstream ss;
// 	ss << number;
// 	std::string str = ss.str();

// 	std::string str = "42"; // string to int
// 	std::stringstream ss(str);
// 	int number;
// 	ss >> number;

// 	int number = 42; // int to string
// 	std::string str = static_cast<std::ostringstream&>(std::ostringstream() << number).str();

// 	std::string str = "42"; // strong to int
// 	int number;
// 	static_cast<std::istringstream&>(std::istringstream(str) >> number);

// 	return 0;
// }

// #include <limits>
// int main() 
// {
//     int number;
//     std::cout << "Enter an integer: ";

//     std::cin >> number;
// 	std::cin.clear();
// 	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//     std::cout << "Number: " << number << std::endl;

//     return 0;
// }