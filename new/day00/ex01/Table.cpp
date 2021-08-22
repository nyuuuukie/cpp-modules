#include <iostream>
#include <iomanip>

#include "Table.hpp"

void	Table::printTableBorder()
{
	std::cout << currentColor;
	for (size_t i = 0; i <= (columnWidth + 1) * columns; i++)
	{
		std::cout << borderSymbol;
	}
	std::cout << COLOR_RESET << std::endl;
}

void	Table::printTableLine(std::string data[])
{
	std::string dataTemp;

	std::cout << currentColor << separator << COLOR_RESET;
	for (size_t i = 0; i < columns; i++)
	{
		if (data[i].length() > columnWidth)
			dataTemp = data[i].substr(0, columnWidth - 3) + "...";
		else
			dataTemp = data[i];
		std::cout << std::setw(columnWidth) << dataTemp;
		std::cout << currentColor << separator << COLOR_RESET;
	}
	std::cout << std::endl;
}

void	Table::setMaxWidth()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (data[i][j].length() > columnWidth)
				columnWidth = data[i][j].length();
		}
	}
}

void	Table::setBorderColor(std::string color)
{
	this->currentColor = color;
}

void	Table::setSeparator(char separator)
{
	this->separator = separator;
}

void	Table::setBorderSymbol(char borderSymbol)
{
	this->borderSymbol = borderSymbol;
}

void	Table::setTitles(std::string *titles)
{
	this->titles = titles;
}

void	Table::setColumnData(int columnIndex, std::string *data)
{
	for (size_t i = 0; i < this->rows; i++)
	{
		this->data[i][columnIndex] = data[i];
	}
}

void	Table::printTitles()
{
	printTableLine(this->titles);
}

void	Table::printTable()
{
	printTableBorder();
	printTitles();
	printTableBorder();
	for (size_t i = 0; i < rows; i++)
		printTableLine(data[i]);
	printTableBorder();
}

Table::Table(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->columnWidth = 15;
	this->setBorderColor(COLOR_GREEN);
	this->separator = '|';
	this->borderSymbol = '-';

	if (rows > 0 && columns > 0)
	{
		this->data = new std::string*[rows];
		for (size_t i = 0; i < this->rows; i++)
			data[i] = new std::string[columns];
	}
}

Table::~Table(void) {
	if (rows > 0 && columns > 0)
	{
		for (size_t i = 0; i < this->rows; i++)
			delete [] data[i];
		delete [] data;
	}
}