/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 05:23:29 by atok              #+#    #+#             */
/*   Updated: 2024/06/03 05:23:29 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

using std::cout;

BitcoinExchange::BitcoinExchange()
{
	// cout << "Default BitcoinExchange constructor called\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void) copy;
	cout << "Copy BitcoinExchange constructor called\n";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	(void) rhs;
	cout << "Copy assingment constructor BitcoinExchange called\n";
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	// cout << "Deconstructor BitcoinExchange called\n";
}

#include "BitcoinExchange.hpp"

bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::validdate(std::string date)
{
	int year;
	int month;
	int day;

	sscanf(date.c_str(), "%d-%d-%d", &year,&month,&day);

	if (year < 1900 || year > 9999)
		return false; // Year out of valid range

		
	if (month < 1 || month > 12)
		return false; // Month out of valid range
		
	// Days in each month
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
	// Adjust for leap year
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;
		
	if (day < 1 || day > daysInMonth[month - 1])
		return false; // Day out of valid range for the given month

	return true; // Date is valid
}

long BitcoinExchange::datetodays(std::string date)
{
	if(!BitcoinExchange::validdate(date))
		return -1;

	// time_t epoch;
	struct tm t;
	// strptime(date.c_str(), "%Y-%m-%d", &t); // dont have in my time.h at home
	sscanf(date.c_str(), "%d-%d-%d", &t.tm_year,&t.tm_mon,&t.tm_mday);
	t.tm_year -= 1900;
	t.tm_mon -= 1;
	// t.tm_mday; // no need
	t.tm_hour = 8; //=8 for GMT =0 for Malaysia time
	t.tm_min = 0;
	t.tm_sec = 0;
	t.tm_isdst = -1; // daylight saving flag 0 not in effect /1 in effect /-1 no information 

	long output = static_cast<long> (mktime(&t));
	output = output / 86400; // conver from sec to days

	/* old method */
	// const char *str = date.c_str();
	// long output;
	// long y;
	// long m;
	// long d;
	// sscanf(str, "%ld-%ld-%ld", &y,&m,&d);
	// output = (y * 12 * 28) + (m * 28) + d;

	return output;
}

std::map<long,float> BitcoinExchange::parsecsv(void)
{
	std::map<long,float> csv;
	std::string line;
	std::ifstream file ("data.csv");

	if (file.is_open())
	{
		std::getline(file,line); // skip header
		while (std::getline(file,line))
		{
			std::istringstream ss(line);
			std::string date;
			std::string rate;

			std::getline(ss,date,',');
			std::getline(ss,rate);

			long days = BitcoinExchange::datetodays(date);
			float frate = std::atof(rate.c_str());

			csv[days] = frate;
			// std::cout << days << " , " << std::fixed  << std::setprecision(2) << frate << '\n';
		}
	}
	else
	{
		std::cout << "Error : data.csv could not be open.\n";
		exit (1);
	}
	file.close();
	return csv;
}

void BitcoinExchange::printvalue(std::map<long,float> &csv, std::ifstream &input)
{
	// std::map<long,float> tmp;
	std::string line;
	// std::getline(input,line); // skip header <<< handled without header it works

	// int z = 0;
	while(std::getline(input,line))
	{	
		std::istringstream ss(line);
		std::string date;
		std::string value;
		std::getline(ss,date,'|');
		std::getline(ss,value);
		date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());
		value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
		
		if (line.find('|') == std::string::npos)
			std::cout << "Error : invaid format\n";
		else if (date == "date" && value == "value")
			continue;
		else if(date != "date" && value != "value")
		{
			long days = BitcoinExchange::datetodays(date);
			float fval = std::atof(value.c_str());
			if (days == -1 && (fval < 0 || fval > 1000))
			{
				std::cout << "Error : Invalid date & value.\n";
				continue;
			}
			else if (days == -1)
			{
				std::cout << "Error : Bad input => " << date << ".\n";
				continue;
			}
			else if (fval < 0)
			{
				std::cout << "Error : Not a postive number.\n";
				continue;
			}
			else if (fval > 1000)
			{
				std::cout << "Error : Too large a number.\n";
				continue;
			}

			// tmp[days] = fval;
			// std::cout << date << " , " << fval << '\n'; // <<
			std::map<long,float>::iterator begin = csv.begin();
			std::map<long,float>::iterator end = csv.end();
			end--;
			// std::map<long,float>::iterator cmp = tmp.begin();
			// long tmp = 141260; // 2009-01-02
			// std::cout << begin->first << "\n";
			
			float output;
			// std::cout << "input : " << days << ',' << begin->first << ',' <<end->first << '\n';
			if (days < begin->first)
				output = fval * begin->second;
			else if (days > end->first)
				output = fval * end->second;
			else
			{
				while (begin != end)
				{
					if (begin->first == days)
					{
						// std::cout << fval << ',' <<begin->second << "\n";
						output = begin->second * fval;
						break;
					}
					else if (begin->first > days)
					{
						begin--;
						// std::cout << fval << ',' <<begin->second << "\n";
						output = begin->second * fval;
						break;
					}
					begin++;
				}
			}
			// std::cout << output << '\n';
			std::cout << date << " => " << value << " = " << output << '\n';
		}
	}
}

void BitcoinExchange::execute(std::ifstream &input)
{
	std::map<long,float> csv;

	csv = BitcoinExchange::parsecsv();
	BitcoinExchange::printvalue(csv,input);

	/* checking */
	// std::map<long,float>::iterator i;
	// for (i = csv.begin(); i != csv.end(); i++)
	// {
	// 	std::cout << i->first <<'\n';
	// 	std::cout << i->second <<'\n';
	// }
	
	// std::cout << csv[19080] << '\n';
}