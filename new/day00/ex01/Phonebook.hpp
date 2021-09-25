#pragma once

#include <iostream>
#include "Table.hpp"
#include "Contact.hpp"

class Phonebook
{
private:
	static const int _size = 8;
	Contact          _contacts[_size];
	static int       _currentIndex;

public:
	void add();
	void help();
	void exit();
	void print();
	void search();

	void addContact(void);
	static int getCount(void);
};

int getNumber(std::string s);
void printLine(std::string line);
void getInputString(std::string title, std::string &input);
