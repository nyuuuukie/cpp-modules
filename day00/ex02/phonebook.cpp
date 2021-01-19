/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:02:18 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/19 07:36:24 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


#include "Contact.hpp"

void	printLine(std::string msg)
{
	std::cout << msg << std::endl;
}

void	printTableLine(std::string data[], size_t columns, size_t width)
{
	std::string temp;

	for (size_t i = 0; i < columns; i++)
	{
		if (data[i].length() > width)
			temp = data[i].substr(0, width - 3) + "...";
		else
			temp = data[i];
		std::cout << std::setw(width) << temp;
		std::cout << "|" << std::endl;	
	}
}

void	printTable(Contact *contacts, int amount)
{
	int width = 10;
	int columns = 4;
	std::string	data[4] = {	"index", "first name", "last name", "nickname" };
	
	for (int i = 0; i <= (width + 1) * columns; i++)
		std::cout << "-";

	printTableLine(data, columns, width);

	for (int i = 0; i < amount; i++)
	{
		data[0] = contacts[i].getIndex();
		data[1] = contacts[i].getFirstName();
		data[2] = contacts[i].getLastName();
		data[3] = contacts[i].getNickname();
		
		printTableLine(data, columns, width);
	}

	for (int i = 0; i <= (width + 1) * columns; i++)
		std::cout << "-";

	std::cout << std::endl;
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
		std::cout << "Index (0 to exit): ";

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

void	phonebookExit()
{
	printLine("-All those contacts will be lost in time");
	printLine("like tears in rain. Time to die.");
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

		if (input.compare("ADD") == 0)
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