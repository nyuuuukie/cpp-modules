/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:08:58 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/19 22:23:29 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "Table.class.hpp"

Contact::Contact(void) { }

Contact::~Contact(void)
{
	if (firstName.compare("") != 0) 
	{
		std::cout << "Contact " << firstName << " ";
		std::cout << "has been destroyed." << std::endl;
	}
	Contact::_amountOfContacts--;
}

void	Contact::addContact(void)
{
	std::cout << "Enter first name:";
	std::cin >> this->firstName;

	std::cout << "Enter last name:";
	std::cin >> this->lastName;

	std::cout << "Enter nickname:";
	std::cin >> this->nickname;

	std::cout << "Enter login:";
	std::cin >> this->login;

	std::cout << "Enter postal address:";
	std::cin >> this->postalAddress;

	std::cout << "Enter email address:";
	std::cin >> this->emailAddress;

	std::cout << "Enter phone number:";
	std::cin >> this->phoneNumber;

	std::cout << "Enter birthday date:";
	std::cin >> this->birthdayDate;

	std::cout << "Enter favorite meal:";
	std::cin >> this->favoriteMeal;

	std::cout << "Enter underwear color:";
	std::cin >> this->underwearColor;

	std::cout << "Enter darkest secret:";
	std::cin >> this->darkestSecret;

	this->index = _amountOfContacts + '1';
	Contact::_amountOfContacts++;
}

void	Contact::printContactInfo(void)
{
	Table table(12, 2, 15);
	std::string **data = new std::string*[12];
	for (int i = 0; i < 12; i++)
		data[i] = new std::string[2];

	data[0][0] = "index";
	data[0][1] = index;
	data[1][0] = "login";
	data[1][1] = login;
	data[2][0] = "nickname";
	data[2][1] = nickname;
	data[3][0] = "last name";
	data[3][1] = lastName;
	data[4][0] = "first name";
	data[4][1] = firstName;
	data[5][0] = "phoneNumber";
	data[5][1] = phoneNumber;
	data[6][0] = "favoriteMeal";
	data[6][1] = favoriteMeal;
	data[7][0] = "emailAddress";
	data[7][1] = emailAddress;
	data[8][0] = "birthdayDate";
	data[8][1] = birthdayDate;
	data[9][0] = "darkestSecret";
	data[9][1] = darkestSecret;
	data[10][0] = "postalAddress";
	data[10][1] = postalAddress;
	data[11][0] = "underwearColor";
	data[11][1] = underwearColor;

	table.setMaxWidth(data);
	table.setBorderSymbol('-');
	table.setSeparator('|');
	table.setBorderColor(COLOR_GREEN);
	
	table.printTableBorder();
	for (int i = 0; i < 12; i++)
		table.printTableLine(data[i]);
	table.printTableBorder();
}

int Contact::getCount()
{
	return _amountOfContacts;
}

std::string Contact::getIndex()
{
	return this->index;
}

std::string Contact::getFirstName()
{
	return this->firstName;
}

std::string Contact::getLastName()
{
	return this->lastName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

int Contact::_amountOfContacts = 0;