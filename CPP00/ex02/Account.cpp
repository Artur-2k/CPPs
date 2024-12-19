#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit) : _amount(initial_deposit) 
{
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " " << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account( void ) {}

// Getters
int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " " << "index:" << this->_accountIndex 
    << ";amount:" << deposit << ";deposits:"
    << this->_nbDeposits << ";withdrawals:"<<this->_nbWithdrawals << std::endl;

    this->_amount += deposit;
    this->_nbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " " << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";

    if (checkAmount() < withdrawal)
    {
        std::cout << "refused";
        return false;
    }
    else
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals; 
    }
    return true;
}

int	 Account::checkAmount( void ) const
{
    return _amount;
}


void	Account::_displayTimestamp( void )
{
    std::cout << "19/12/24 13:46:25";
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbDeposits << std::endl;
}