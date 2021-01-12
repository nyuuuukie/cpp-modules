/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:02:18 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/12 05:55:47 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.class.hpp"
#include "Table.class.hpp"

void	printLine(std::string msg)
{
	std::cout << msg << std::endl;
}

void	printTable(Contact *contacts, int amount)
{
	Table table(Contact::getCount(), 4, 10);
	std::string	data[4] = {	
							"index",
							"first name",
							"last name",
							"nickname"
	};
	
	table.setBorderSymbol('-');
	table.setSeparator('|');
	table.setBorderColor(COLOR_GREEN);
	table.printTableBorder();
	table.printTableLine(data);
	table.printTableBorder();
	for (int i = 0; i < amount; i++)
	{
		data[0] = contacts[i].getIndex();
		data[1] = contacts[i].getFirstName();
		data[2] = contacts[i].getLastName();
		data[3] = contacts[i].getNickname();
		table.printTableLine(data);
	}
	table.printTableBorder();
}

void	phonebookAdd(Contact contacts[])
{
	int lastIndex;
	
	lastIndex = Contact::getCount();
	if (lastIndex < 8)
		contacts[lastIndex].addContact();
	else
		printLine("Ugh, out of space, dear!");
}

void	phonebookSearch(Contact contacts[])
{
	int	searchIndex;
	std::string input;

	printTable(contacts, Contact::getCount());					
	do {
		std::cout << "Index (0 to ESC): ";

		getline(std::cin, input);
		if (std::cin.eof())
			break;

		searchIndex = std::stoi(input);
	 	if (Contact::getCount() == 0)
			printLine("Phonebook is empty.");
		else if (searchIndex > Contact::getCount())
			printLine("Invalid phonebook index.");
		else if (searchIndex > 0 && searchIndex < 9)
			contacts[searchIndex - 1].printContactInfo();
		else if (searchIndex != 0)
			printLine("Invalid phonebook index.");
	} while (searchIndex != 0);
}

void	phonebookHelp()
{
	std::cout << "Type " << COLOR_RED << "ADD " << COLOR_RESET;
	std::cout << "to create new contact." << std::endl; 
	std::cout << "Type " << COLOR_RED << "SEARCH " << COLOR_RESET;
	std::cout << "to see all contacts." << std::endl;
	std::cout << "Type " << COLOR_RED << "EXIT " << COLOR_RESET;
	std::cout << "to quit." << std::endl;
}

void	phonebookExit()
{
	printLine(COLOR_RED);
	printLine("-All those contacts will be lost in time");
	printLine("like tears in rain. Time to die.");
	printLine(COLOR_RESET);
}

int main()
{
	Contact	contacts[8];
	std::string	input;
	
	while (true)
	{
		std::cout << "> ";
		std::cin.clear();
		getline(std::cin, input);

		if (input.compare("HELP") == 0)
			phonebookHelp();
		else if (input.compare("ADD") == 0)
			phonebookAdd(contacts);
		else if (input.compare("SEARCH") == 0)
			phonebookSearch(contacts);
		else if (input.compare("EXIT") == 0)
			break;
		else
			printLine("Command not found: " + input);
		if (std::cin.eof())
			break;
	}
	phonebookExit();
	return (0);
}