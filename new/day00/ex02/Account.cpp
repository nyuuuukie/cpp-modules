#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Getters for static members
int
Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int
Account::getTotalAmount( void ) {
	return _totalAmount;
}

int
Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int
Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

static void displayValue(std::string title, int value, std::string ending) {
	std::cout << title << ":";
	if (value >= 0)
		std::cout << value;
	std::cout << ending;
}

static std::string itos(int number, int base = 10)
{
	std::string res = "";
	
	if (number / base)
		res = itos(number / base, base);
	if (number % base < 10)
		res += number % base + '0';
	else
		res += number % base - 10 + 'A';
	return res;
}

static std::string format(int number) {
	std::string prefix = "";

	if (number < 10)
		prefix = "0";
	return prefix + itos(number);
}

void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::tm tm;

	tm.tm_year = 1992;
	tm.tm_mon = 1;
	tm.tm_mday = 4;
	tm.tm_hour = 9;
	tm.tm_min = 15;
	tm.tm_sec = 32;

	std::cout << "[" << format(tm.tm_year) << format(tm.tm_mon) << format(tm.tm_mday);
	std::cout << "_" ;
	std::cout << format(tm.tm_hour) << format(tm.tm_min) << format(tm.tm_sec) << "] ";
}

void	Account::makeDeposit( int deposit ) {
	const int p_amount = this->_amount;

	this->_nbDeposits++;
	this->_amount += deposit;
	
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	Account::_displayTimestamp();
	displayValue("index", this->_accountIndex, ";");
	displayValue("p_amount", p_amount, ";");
	displayValue("deposit", deposit, ";");
	displayValue("amount", this->_amount, ";");
	displayValue("nb_deposits", this->_nbDeposits, "\n");
}

bool	Account::makeWithdrawal( int withdrawal ) {
	const int p_amount = this->_amount;
	bool accepted = false;

	if (checkAmount() && withdrawal < _amount) {
		accepted = true;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;

		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
	}

	Account::_displayTimestamp();
	displayValue("index", this->_accountIndex, ";");
	displayValue("p_amount", p_amount, ";");
	
	if (accepted) {
		displayValue("withdrawal", withdrawal, ";");
		displayValue("amount", this->_amount, ";");
		displayValue("nb_withdrawals", this->_nbWithdrawals, "\n");
	} else {
		displayValue("withdrawal", -1, "refused\n");
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
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;

	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += this->_amount;
	
	Account::_displayTimestamp();
	displayValue("index", this->_accountIndex, ";");
	displayValue("amount", this->_amount, ";");
	std::cout << "created" << std::endl;
}

Account::Account( void ) {}

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
