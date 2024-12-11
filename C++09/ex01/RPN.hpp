/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:08:12 by atok              #+#    #+#             */
/*   Updated: 2024/06/06 00:08:12 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>

class RPN
{
	private:

	public:
		RPN();
		RPN(RPN const &copy);
		RPN &operator=(const RPN& rhs);
		~RPN();
	
	void execute(std::string input);
	void checkinput(std::string input);
	void calculate(std::string input);

};

#endif