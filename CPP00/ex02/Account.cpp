#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


// Constructor
// parameterized
Account::Account(int initial_deposit) : _amount(initial_deposit) , _nbDeposits(0), _nbWithdrawals(0)
{
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " " << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
} 

// Destructor
Account::~Account( void ) 
{
    _displayTimestamp();
    this->_nbAccounts--;
    std::cout << " " << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

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

int	 Account::checkAmount( void ) const
{
    return _amount;
} 

// Deposits the ammount to the account ant increases the total amount
// Updates the nb of deposits
// Logs what is happening
void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex 
    << ";p_amount:" << this->_amount
    << ";deposits:" << deposit ;

    // self
    this->_amount += deposit;
    this->_nbDeposits++;

    // class
    _totalAmount+= deposit;
    _totalNbDeposits++;

    std::cout << ";amount:" << this->_amount
    << ";nb_deposits:" << this->_nbDeposits << std::endl;
} 

// If the account has enough money to withdrawal the asked amount it
// removes the total from the account and the total amount and updates the
// nb of withdrawals
// Logs what is happening
bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex 
    << ";p_amount:" << this->_amount 
    << ";withdrawal:";

    if (checkAmount() < withdrawal)
    {
        std::cout << "refused" << std::endl; 
        return false;
    }
    
    //self
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    
    //class
    _totalAmount -= withdrawal;
    this->_totalNbWithdrawals++;
   
   
    std::cout << withdrawal 
    << ";amount:" << this->_amount
    << ";nb_withdrawals:" << this->_nbWithdrawals
    << std::endl; 
    return true;
} 

void	Account::_displayTimestamp( void )
{
    // time_t => segundos    time(0) => segundos since epoch
    std::time_t currentTime = std::time(0); 

    // struct tm .anos .mes .dia....
    std::tm* localTime = std::localtime(&currentTime);
    
    std::cout << "[" 
    << localTime->tm_year + 1900
    << localTime->tm_mon + 1
    << localTime->tm_mday
    << "_"
    << localTime->tm_hour
    << localTime->tm_min
    << localTime->tm_sec
    <<"]";
} 


void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() 
    << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals()
    << std::endl;
} 


void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
    << ";amount:" << this->_amount 
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals
    << std::endl;
}