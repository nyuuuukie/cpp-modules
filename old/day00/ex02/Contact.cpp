/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:08:58 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/20 02:45:28 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

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
	std::string titles[] = { "login", "nickname", "last name", "first name",
							 "phoneNumber", "favoriteMeal", "emailAddress", "birthdayDate",
							 "darkestSecret", "postalAddress", "underwearColor"
	};

	std::string *values[] = { &login, &nickname, &lastName, &firstName, 
							  &phoneNumber, &favoriteMeal, &emailAddress, &birthdayDate,
							  &darkestSecret, &postalAddress, &underwearColor
	};
	
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Enter " << titles[i] << ": ";
		getline(std::cin, *values[i]);
		
		if (std::cin.eof())
		{
			std::cout << "Wrong input of " << titles[i] << "." << std::endl;
		}
		if (values[i]->compare("") == 0)
		{
			*values[i] = "-_-";
		}
	}
	
	this->index = _amountOfContacts + '1';
	Contact::_amountOfContacts++;
}

void	Contact::printContactInfo(void)
{
	std::string titles[] = { "index", "login", "nickname", "last name", "first name", "phoneNumber",
	"favoriteMeal", "emailAddress", "birthdayDate", "darkestSecret", "postalAddress", "underwearColor"};

	std::string *values[] = { &index, &login, &nickname, &lastName, &firstName, &phoneNumber,
	&favoriteMeal, &emailAddress, &birthdayDate, &darkestSecret, &postalAddress, &underwearColor};

	for (int i = 0; i < 12; i++)
		std::cout << titles[i] << ": " << *values[i] << std::endl;
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