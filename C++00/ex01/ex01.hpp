/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:55:17 by atok              #+#    #+#             */
/*   Updated: 2023/08/16 19:43:34 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_HPP
# define EX01_HPP

#include <string> // std::string, isempty(), length(), size()
#include <iostream> //cout,cin,getline()
#include <iomanip> //setw
#include <locale> // isalpha, isdigit
#include <sstream> // std:stringstream

#define N 8 // modify here to test 

class Contact
{
	private:
		std::string _index;
		std::string _first;
		std::string _last;
		std::string _nickname;
		std::string _number;
		std::string _secret;

	public:
		Contact(){}
		~Contact(){}
		std::string getAttribute(std::string attributeName);
    	void setAttribute(std::string attributeName, std::string input);
};

class PhoneBook
{
	private:
		Contact _contacts[N]; // _text to idenity is private
		unsigned int _index; // to iterate next contact
		//unsigned int _index = 0; // only in c11
	public:
		//PhoneBook(): _index(0) {} // initialize in constructor
		PhoneBook() //same as above BUT mush have curly brackets
		{
			_index = 0;
		}
		~PhoneBook(){}
		void add();
		void search();
		void ft_display();
		//void exit();
};

//run = 3 cmd ADD, SEARCH, EXIT
//ADD frist, last, nickname, number & secret 
//SEARCH index, first, last & nickname.
//EXIT
//all max 10char if more replace the 10th with '.'
#endif
