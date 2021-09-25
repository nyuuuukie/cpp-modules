#include "Table.hpp"
#include "Parse.hpp"
#include "Contact.hpp"
#include "Phonebook.hpp"
#include <limits>

void printLine(std::string msg)
{
	std::cout << msg << std::endl;
}

int	hasSymbol(std::string input, int c)
{
	for (unsigned int i = 0; i < input.length(); i++)
    {
        if (input.at(i) == c)
        {
			return 1;
        }
    }
	return 0;
}

void getInputString(std::string title, std::string &input)
{
	std::cout << title;
	std::getline(std::cin, input);
		
	if (std::cin.eof())
	{
		input = "";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		std::cout << std::endl;
		std::clearerr(stdin);
	}
}

void Phonebook::print()
{
	int cols = 4;
	int rows = getCount();
	if (getCount() / _size)
		rows = _size;
	Table table(rows, cols);

	std::string *titles = new std::string[Contact::getSize()];
	std::string **data = new std::string *[cols];
	for (int i = 0; i < cols; i++)
	{
		data[i] = new std::string[_size];
	}

	for (int i = 0; i < Contact::getSize(); i++)
	{
		titles[i] = (*this->_contacts)[i];
	}

	for (int i = 0; i < rows && i < _size; i++)
	{
		try
		{
			data[0][i] = this->_contacts[i]["index"];
			data[1][i] = this->_contacts[i]["first name"];
			data[2][i] = this->_contacts[i]["last name"];
			data[3][i] = this->_contacts[i]["nickname"];
		}
		catch (std::string &error)
		{
			std::cerr << error << std::endl;
			data[0][i] = "invalid data";
			data[1][i] = "invalid data";
			data[2][i] = "invalid data";
			data[3][i] = "invalid data";
		}
	}

	table.setTitles(titles);
	for (int i = 0; i < cols; i++)
		table.setColumnData(i, data[i]);
	table.printTable();

	delete[] titles;
	for (int i = 0; i < cols; i++)
		delete[] data[i];
	delete[] data;
}

void Phonebook::add()
{
	int last;

	last = Phonebook::getCount() % _size;
	if (last < _size)
		this->_contacts[last].addValues(last);
	Phonebook::_currentIndex++;
}

void Phonebook::search()
{
	int index;
	std::string input;

	print();
	do
	{
		getInputString("Index (0 to exit): ", input);

		if (Parse::stoi(input, index))
			printLine("Invalid phonebook index.");
		else if (index > getCount() || index > _size)
			printLine("No contact with this index.");
		else if (index > 0 && index < _size + 1)
			this->_contacts[index - 1].printContactInfo();
	} while (index != 0);
}

void Phonebook::help()
{
	std::cout << "Type " << COLOR_RED << "ADD " << COLOR_RESET;
	std::cout << "to create new contact." << std::endl;
	std::cout << "Type " << COLOR_RED << "SEARCH " << COLOR_RESET;
	std::cout << "to see all contacts." << std::endl;
	std::cout << "Type " << COLOR_RED << "EXIT " << COLOR_RESET;
	std::cout << "to quit." << std::endl;
}

void Phonebook::exit()
{
	printLine(COLOR_RED);
	printLine("-All those contacts will be lost in time");
	printLine("like tears in rain. Time to die.");
	printLine(COLOR_RESET);
}

int Phonebook::getCount()
{
	return _currentIndex;
}

int Phonebook::_currentIndex = 0;
