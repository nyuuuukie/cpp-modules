#include "Table.hpp"
#include "Parse.hpp"
#include "Contact.hpp"
#include "Phonebook.hpp"

void
printLine(std::string msg)
{
	std::cout << msg << std::endl;
}

void
getInputString(std::string title, std::string &input)
{
	do {
		if (std::cin.eof()) {
	        std::cout << "  \b\b \b\b" << std::endl;
	        std::cin.clear();
	        std::cin.ignore(input.size());
	        clearerr(stdin);   
	    }
		std::cout << title;
		getline(std::cin, input);
	} while (std::cin.eof());
}

void
Phonebook::print()
{
	const int rows = getCount();
	const int cols = 4;
	Table table(rows, cols);
	
	std::string	titles[Contact::getSize()];
	std::string data[cols][rows];

	for (int i = 0; i < Contact::getSize(); i++)
	{
		titles[i] = (*this->_contacts)[i];
	}

	for (int i = 0; i < rows; i++)
	{
		try {
			data[0][i] = this->_contacts[i]["index"];
			data[1][i] = this->_contacts[i]["nickname"];
			data[2][i] = this->_contacts[i]["last name"];
			data[3][i] = this->_contacts[i]["first name"];
		}
		catch (std::string &error) {
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
}

void
Phonebook::add()
{
	int last;
	
	last = Phonebook::getCount();
	if (last < _size)
		this->_contacts[last].addValues(last);
	if (last < _size - 1)
		Phonebook::_currentIndex++;
}

void
Phonebook::search()
{
	int	index;
	std::string input;

	print();
	do {
	 	getInputString("Index (0 to exit): ", input);

		if (Parse::stoi(input, index))
			printLine("Invalid phonebook index.");
		else if (index > getCount())
			printLine("No contact with this index.");
		else if (index > 0 && index < _size + 1)
			this->_contacts[index - 1].printContactInfo();
	} while (index != 0);
}

void
Phonebook::help()
{
	std::cout << "Type " << COLOR_RED << "ADD " << COLOR_RESET;
	std::cout << "to create new contact." << std::endl; 
	std::cout << "Type " << COLOR_RED << "SEARCH " << COLOR_RESET;
	std::cout << "to see all contacts." << std::endl;
	std::cout << "Type " << COLOR_RED << "EXIT " << COLOR_RESET;
	std::cout << "to quit." << std::endl;
}

void
Phonebook::exit()
{
	printLine(COLOR_RED);
	printLine("-All those contacts will be lost in time");
	printLine("like tears in rain. Time to die.");
	printLine(COLOR_RESET);
}

int
Phonebook::getCount()
{
	return _currentIndex;
}

int Phonebook::_currentIndex = 0;