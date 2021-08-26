#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

static void displayValue(std::string title, int value, std::string ending) {
	std::cout << title << ":" << value << ending;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::tm tm;
	tm.tm_year = 1992 - 1900;
	tm.tm_mon = 0;
	tm.tm_mday = 4;
	tm.tm_hour = 9;
	tm.tm_min = 15;
	tm.tm_sec = 32;
	std::time_t t = std::mktime(&tm); 
	std::cout << std::put_time(std::gmtime(&t), "[%Y%m%d_%H%M%S] ");
}

void	Account::makeDeposit( int deposit ) {
	this->_nbDeposits++;
	this->_amount += deposit;
	
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	displayValue("index", this->_accountIndex, ";");
	displayValue("p_amount", this->_amount - deposit, ";");
	displayValue("deposits", deposit, ";");
	displayValue("amount", this->_amount, ";");
	displayValue("nb_deposits", this->_nbDeposits, "\n");
}

bool	Account::makeWithdrawal( int withdrawal ) {
	bool accepted = false;
	
	displayValue("index", this->_accountIndex, ";");
	displayValue("p_amount", this->_amount - withdrawal, ";");

	if (checkAmount() && withdrawal < _amount) {
		accepted = true;

		this->_amount -= withdrawal;
		this->_nbWithdrawals++;

		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;

		displayValue("withdrawals", withdrawal, ";");
		displayValue("amount", this->_amount, ";");
		displayValue("nb_withdrawals", this->_nbWithdrawals, "\n");
	} else {
		std::cout << "withdrawal:refused" << std::endl;
	}

	return accepted;
}

int		Account::checkAmount( void ) const {
	return (this->_amount > 0);
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	displayValue("index", this->_accountIndex, ";");
	displayValue("amount", this->_amount, ";");
	displayValue("deposits", this->_nbDeposits, ";");
	displayValue("withdrawals", this->_nbWithdrawals, "\n");
}

Account::Account( int initial_deposit ) {
	this->_nbDeposits = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;

	Account::_displayTimestamp();
	displayValue("index", this->_accountIndex, ";");
	displayValue("amount", this->_amount, ";");
	std::cout << "created" << std::endl;
}

Account::Account( void ) {
	
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	displayValue("index", this->_accountIndex, ";");
	displayValue("amount", this->_amount, ";");
	std::cout << "closed" << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
