/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:15:12 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/19 15:46:43 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm* timeinfo = std::localtime(&now);

	std::cout << "[";
	std::cout << (1900 + timeinfo->tm_year);

	if (timeinfo->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << (timeinfo->tm_mon + 1);

	if (timeinfo->tm_mday < 10)
		std::cout << "0";
	std::cout << timeinfo->tm_mday;

	std::cout << "_";

	if (timeinfo->tm_hour < 10)
		std::cout << "0";
	std::cout << timeinfo->tm_hour;

	if (timeinfo->tm_min < 10)
		std::cout << "0";
	std::cout << timeinfo->tm_min;

	if (timeinfo->tm_sec < 10)
		std::cout << "0";
	std::cout << timeinfo->tm_sec;

	std::cout << "] ";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount = _totalAmount - _amount;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" <<  deposit;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";

	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;

}
