/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:09:10 by atok              #+#    #+#             */
/*   Updated: 2024/06/06 00:09:10 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

using std::cout;

RPN::RPN()
{
	// cout << "Default RPN constructor called\n";
}

RPN::RPN(const RPN &copy)
{
	(void) copy;
	cout << "Copy RPN constructor called\n";
}

RPN &RPN::operator=(const RPN &rhs)
{
	(void) rhs;
	cout << "Copy assingment constructor RPN called\n";
	return *this;
}

RPN::~RPN()
{
	// cout << "Deconstructor RPN called\n";
}

void RPN::checkinput(std::string input)
{
	for (size_t i = 0; i < input.size(); i++) // checks for ( & )
	{
		if (input[i] == '(' || input[i] == ')')
		{
			std::cout << "Error ( )\n";
			exit(1);
		}
	}

	for (size_t i = 1; i < input.size(); i+=2) // check for <0 , >9 & sapce evenly
	{
		if (input[i] != ' ')
		{
			std::cout << "Error uneven ' '\n";
			exit(1);
		}
	}

	for (size_t i = 0; i < input.size(); i+=2) // 0 to 9 and +-/*
	{
		std::string token = "+-*/";

		if (!isdigit(input[i]) && token.find(input[i]) == std::string::npos)
		{
			std::cout << "Error alpha\n";
			exit(1);
		}
	}
	return ;
}

void RPN::calculate(std::string input)
{
	std::stack<int> stack;
	std::string token = "+-*/";
	int l, r, a;

	size_t i = 0;
	while (i < input.size())
	{
		if (token.find(input[i]) != std::string::npos)
		{
			if (stack.size() < 2)
			{
				std::cout << "Error: operands more than numbers " << std::endl;
				exit(1);
			}
			r = stack.top(); stack.pop();
			l = stack.top(); stack.pop();
			switch (input[i])
			{
				case '+':
					a = l + r;
					break;
				case '-':
					a = l - r;
					break;
				case '*':
					a = l * r;
					break;
				case '/':
					if (r == 0)
					{
						std::cout << "Error: dividing by zero\n";
						exit(1);
					}
					a = l / r;
					break;
				default:
					{
						std::cout << "Error: no such operator\n";
						exit(1);
					}
			}
			stack.push(a);
		}
		else if (isdigit(input[i]))
		{
			int num = input[i] - '0';
			stack.push(num);
		}
		i += 2;
	}

	if (stack.size() != 1)
	{
		std::cout << "Error: numbers more than operands\n";
		exit(1);
	}

	std::cout << "Ans => " << stack.top() << std::endl;
}

void RPN::execute(std::string input)
{
	RPN::checkinput(input);
	RPN::calculate(input);

	return ;
}