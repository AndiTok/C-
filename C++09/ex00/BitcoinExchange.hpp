/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 06:45:19 by atok              #+#    #+#             */
/*   Updated: 2024/06/01 06:45:19 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream> // cout
#include <sstream> // string stream >> istringstream
#include <fstream> // file stream
#include <map> // key | val container
#include <string> // string
#include <ctime> // time
// #include <time.h> // strptime()
// #include <cstdlib>
#include <algorithm> // remove_if()
#include <iomanip> // std::fixed + std::setprecision()

class BitcoinExchange
{
	private:

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void execute(std::ifstream &input);
		std::map<long,float> parsecsv(void);
		long datetodays(std::string date);
		void printvalue(std::map<long,float> &csv, std::ifstream &input);
		bool validdate(std::string date);
		bool isLeapYear(int year);

};

#endif