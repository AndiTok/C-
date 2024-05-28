/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:57:49 by atok              #+#    #+#             */
/*   Updated: 2023/08/18 16:10:23 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

using std::cout; // only using cout in the std library

// to run -> c++ *.cpp -std=c++98 && ./a.out
// to store output > c++ *.cpp -std=c++98 && ./a.out > output.txt

//declared staticint defined here
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::checkAmount() const // dont have to use thie function
{
	//if were to use, can use to check/use any attribute in Account class
	//becase it is an Account function
	//in the withdrawal function use this to check amount if its negative
	//initalise a tmp var to store original amount in the withdrawal funtion
	//let it withdraw then run check funtion to chekc if it negative
	//if negative, in withdraw function revert to original amout
	//assing back the ori amount from the tmp var
	return(this->_amount);
}

void Account::_displayTimestamp()
{
	std::time_t unixEpochTime = std::time(nullptr); // display number of seconds elapsed since January 1, 1970, known as the Unix epoch.
	std::tm* localTime = std::localtime(&unixEpochTime); //localtime() expect a pointer
	
	char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);

	cout << buffer;
}

//alternate mathematical inaccurate way
// void Account::_displayTimestamp ()
// {
//     // Calculate the number of seconds, minutes, hours, days, months, and years
//     std::time_t unixTime = std::time(nullptr);
// 	const std::time_t oneDay = 24 * 60 * 60;
//     const std::time_t oneHour = 60 * 60;
//     const std::time_t oneMinute = 60;
//
//     std::time_t seconds = unixTime % oneMinute;
//     std::time_t minutes = (unixTime / oneMinute) % 60;
//     std::time_t hours = (unixTime / oneHour) % 24;
//     std::time_t days = (unixTime / oneDay) % 31 + 1;
//     std::time_t months = ((unixTime / oneDay) / 31) % 12 + 1;
//     std::time_t years = (unixTime / (oneDay * 365)) + 1970;
//
//     // Output the converted time components
//     // std::cout << "Current Time: "
//     //           << years << "-" << months << "-" << days << " "
//     //           << hours << ":" << minutes << ":" << seconds << std::endl;
//    
// 	std::cout << "["
//               << years << months << days << "_"
//               << hours << minutes << seconds 
// 			  << "]";
// }

Account::Account(int initial_deposit)
{	
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";";
	cout << "amount:" << _amount << ";";
	cout << "created \n";
}

// same as above
// Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
// 										_amount(initial_deposit),
// 										_nbDeposits(_totalNbDeposits),
// 										_nbWithdrawals(_totalNbWithdrawals)
// {	
// 	_nbAccounts++;
// 	_totalAmount += initial_deposit;
//	_displayTimestamp();
//
// }	

Account::~Account()
{
	//it display/decon in reverse order due to compiler/os.
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";";
	cout << "amount:" << _amount << ";";
	cout << "closed \n";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << this->_amount << ";";
	cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	_totalAmount += deposit;//
	cout << "amount:" << this->_amount << ";";
	this->_nbDeposits += 1;
	_totalNbDeposits++;
	cout << "nb_deposit:" << this->_nbDeposits << ";";
	cout << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << this->_amount << ";";
	if(_amount < withdrawal)
	{	
		this->_nbWithdrawals += 0;
		cout << "refused \n";
		return (0);
	}
	else
	cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;//
	cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals++;
	cout << "nb_withdrawal:" << this->_nbWithdrawals << ";";
	cout << "\n";
	return (1);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";";
	cout << "deposits:" << this->_nbDeposits << ";";
	cout << "withdrawals:" << this->_nbWithdrawals<< ";";
	cout << "\n";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	cout << "accounts:" << getNbAccounts() << ";";
	cout << "total:" << getTotalAmount() << ";";
	cout << "deposits:" << getNbDeposits() << ";";
	cout << "withdrawals:" << _totalNbWithdrawals << ";"; //test
	cout << "\n";
}

int Account::getNbAccounts()
{
	return(_nbAccounts);
}

int Account::getTotalAmount()
{
	return(_totalAmount);
}

int Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);
}