#include "Contact.hpp"
#include "Table.hpp"
#include "Phonebook.hpp"

Contact::Contact(void) {
	// this->_attr
}
Contact::~Contact(void) { }

void	Contact::addValues(int index)
{
	// std::string titles[] = { 
	// 	"login", "nickname", "last name",
	// 	"first name", "phone number","darkest secret",
	// };

	// std::string *values[] = {
	// 	&_login, &_nickname, &_lastName,
	// 	&_firstName, &_phoneNumber, &_darkestSecret,
	// };
	
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

	// std::string attributes[rows] = {
	// 	"index", "login", "nickname","last name", 
	// 	"first name", "phone number", "darkest secret"
	// };

	// std::string values[rows] = { 
	// 	_index, _login, _nickname, _lastName,
	// 	_firstName, _phoneNumber, _darkestSecret,
	// };

	std::string titles[cols] = {
		"Attribute", "Value"
	};

	table.setTitles(titles);
	table.setColumnData(0, attributes);
	table.setColumnData(1, values);
	table.setMaxWidth();
	table.printTable();
}

// std::string Contact::getIndex()
// {
// 	return this->_index;
// }

// std::string Contact::getFirstName()
// {
// 	return this->_firstName;
// }

// std::string Contact::getLastName()
// {
// 	return this->_lastName;
// }

// std::string Contact::getNickname()
// {
// 	return this->_nickname;
// }

unsigned int Contact::_size = 5;
