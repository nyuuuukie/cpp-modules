/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:08:58 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/27 08:07:07 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Table.hpp"
#include "Phonebook.hpp"

Contact::Contact(void) { }
Contact::~Contact(void) { }

void	Contact::addValues(int index)
{
	std::string titles[] = { "login", "nickname", "last name", "first name",
							 "phone number", "favorite meal", "email address", "birthday date",
							 "darkest secret", "postal address", "underwear color"
	};

	std::string *values[] = { &_login, &_nickname, &_lastName, &_firstName, 
							  &_phoneNumber, &_favoriteMeal, &_emailAddress, &_birthdayDate,
							  &_darkestSecret, &_postalAddress, &_underwearColor
	};
	
	for (int i = 0; i < 11; i++)
	{
		std::string title = "Enter " + titles[i] + ": ";
		getInputString(title, *values[i]);
		
		if (values[i]->compare("") == 0)
			*values[i] = "<null>";
	}
	this->_index = index + '1';
}

void	Contact::printContactInfo(void)
{
	const int rows = 12;
	const int cols = 2;
	
	Table table(rows, cols);

	std::string attributes[rows] = {
				"index", "login", "nickname", "last name",
				"first name", "phone number", "favorite meal",
	  			"email address", "birthday date", "darkest secret",
				"postal address", "underwear color"
	};

	std::string values[rows] = { 
				_index, _login, _nickname, _lastName,
				_firstName, _phoneNumber, _favoriteMeal,
				_emailAddress, _birthdayDate, _darkestSecret,
				_postalAddress, _underwearColor
	};

	std::string titles[cols] = {
				"Attribute", "Value"
	};

	table.setTitles(titles);
	table.setColumnData(0, attributes);
	table.setColumnData(1, values);
	table.setMaxWidth();
	table.printTable();
}

std::string Contact::getIndex()
{
	return this->_index;
}

std::string Contact::getFirstName()
{
	return this->_firstName;
}

std::string Contact::getLastName()
{
	return this->_lastName;
}

std::string Contact::getNickname()
{
	return this->_nickname;
}
