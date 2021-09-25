#include "Phonebook.hpp"
#include "Contact.hpp"
#include "Table.hpp"
#include "Parse.hpp"

Contact::Contact(void)
{
	this->_attr[0].setName("index");
	this->_attr[1].setName("first name");
	this->_attr[2].setName("last name");
	this->_attr[3].setName("nickname");
	this->_attr[4].setName("phone number");
	this->_attr[5].setName("darkest secret");
}

Contact::~Contact(void) {}

void Contact::addValues(int index)
{
	std::string name = "";
	std::string value = "";
	std::string title = "";

	this->_attr[0].setValue(Parse::itos(index + 1, 10));
	for (int i = 1; i < this->_size; i++)
	{
		name = this->_attr[i].getName();
		title = "Enter " + name + ": ";

		getInputString(title, value);

		if (value.compare("") == 0)
			value = "not specified";

		this->_attr[i].setValue(value);
	}
}

void Contact::printContactInfo(void)
{
	const int rows = Contact::getSize();
	const int cols = 2;

	Table table(rows, cols);

	std::string *attributes = new std::string[rows];
	std::string *values = new std::string[rows];

	for (size_t i = 0; i < _size; i++)
	{
		attributes[i] = _attr[i].getName();
		values[i] = _attr[i].getValue();
	}

	std::string titles[cols] = {
		"Attribute", "Value"};

	table.setTitles(titles);
	table.setColumnData(0, attributes);
	table.setColumnData(1, values);
	table.setMaxWidth();
	table.printTable();

	delete[] attributes;
	delete[] values;
}

int Contact::getSize()
{
	return _size;
}

std::string
Contact::operator[](int index)
{
	return this->_attr[index].getName();
}

std::string &
Contact::operator[](std::string key)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (this->_attr[i].getName() == key)
			return this->_attr[i].getValue();
	}
	throw std::string("AttributeNotFound");
}
