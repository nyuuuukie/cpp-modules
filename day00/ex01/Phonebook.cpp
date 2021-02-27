/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:02:18 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/27 08:09:04 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"
#include "Table.hpp"
#include "Phonebook.hpp"

void	printLine(std::string msg)
{
	std::cout << msg << std::endl;
}

int getNumber(std::string s)
{
	int i = 0;
	int number = 0;

    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
           || s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
            i++;
    while (s[i] >= '0' && s[i] <= '9')
    {
            number = number * 10 + (s[i] - '0');
            i++;
    }
	if (s[i] != '\0' || s[i - 1] < '0' || s[i - 1] > '9')
		number = -1;
    return (number);
}

void	getInputString(std::string title, std::string &input)
{
	do 
	{
		if (std::cin.eof())
		{
	        std::cout << std::endl;
	        std::cin.clear();
	        std::cin.ignore(input.size());
	        clearerr(stdin);   
	    }
		std::cout << title;
		getline(std::cin, input);
	} while (std::cin.eof());
}

void	Phonebook::print()
{
	const int rows = getCount();
	const int cols = 4;
	Table table(rows, cols);
	
	std::string	titles[cols] = {	
		"index", "first name", "last name", "nickname"
	};
	
	std::string indexes[rows];
	std::string firstNames[rows];
	std::string lastNames[rows];
	std::string nicknames[rows];

	for (int i = 0; i < rows; i++)
	{
		indexes[i] = this->_contacts[i].getIndex();
		nicknames[i] = this->_contacts[i].getNickname();
		lastNames[i] = this->_contacts[i].getLastName();
		firstNames[i] = this->_contacts[i].getFirstName();
	}

	table.setTitles(titles);
	table.setColumnData(0, indexes);
	table.setColumnData(1, firstNames);
	table.setColumnData(2, lastNames);
	table.setColumnData(3, nicknames);	
	table.printTable();
}

void	Phonebook::add()
{
	int lastIndex;
	
	lastIndex = Phonebook::getCount();
	if (lastIndex < _max_contacts)
	{
		this->_contacts[lastIndex].addValues(lastIndex);
		Phonebook::_amountOf_contacts++;
	}
	else
		printLine("Ugh, out of space, dear!");
}

void	Phonebook::search()
{
	int	searchIndex;
	std::string input;

	print();
	do {
	 	getInputString("Index (0 to exit): ", input);

		searchIndex = getNumber(input);
		if (searchIndex == -1)
			printLine("Invalid phonebook index.");
		else if (searchIndex > getCount())
			printLine("No contact with this index.");
		else if (searchIndex > 0 && searchIndex < _max_contacts + 1)
			this->_contacts[searchIndex - 1].printContactInfo();
	} while (searchIndex != 0);
}

void	Phonebook::help()
{
	std::cout << "Type " << COLOR_RED << "ADD " << COLOR_RESET;
	std::cout << "to create new contact." << std::endl; 
	std::cout << "Type " << COLOR_RED << "SEARCH " << COLOR_RESET;
	std::cout << "to see all _contacts." << std::endl;
	std::cout << "Type " << COLOR_RED << "EXIT " << COLOR_RESET;
	std::cout << "to quit." << std::endl;
}

void	Phonebook::exit()
{
	printLine(COLOR_RED);
	printLine("-All those _contacts will be lost in time");
	printLine("like tears in rain. Time to die.");
	printLine(COLOR_RESET);
}

int Phonebook::getCount()
{
	return _amountOf_contacts;
}

int Phonebook::_amountOf_contacts = 0;
const int Phonebook::_max_contacts = MAX__contacts;