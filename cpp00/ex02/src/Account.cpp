/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:24:10 by lgracia-          #+#    #+#             */
/*   Updated: 2025/09/06 16:06:43 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    time_t ahora = time(0);
    struct tm *tiempoLocal = localtime(&ahora);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tiempoLocal);
    std::cout << "[" << std::string(buffer) << "] " << std::flush;
}

Account::Account(int initial_diposit)
{
	this->_amount = initial_diposit;
	this->_displayTimestamp();
	this->_accountIndex=_nbAccounts;
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() 
	<< ";total:" << Account::getTotalAmount() 
	<< ";deposits:" << Account::getNbDeposits()
	<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount
	<< ";deposit:" << deposit << std::flush;
	this -> _amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	res;

	res = this->_amount - withdrawal;
	if (res >= 0)
	{
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:" << withdrawal << std::flush;
		this -> _amount -= withdrawal;
		Account::_totalAmount += withdrawal;
		std::cout << ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:refused" << std::endl;
	}
	return false;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}
