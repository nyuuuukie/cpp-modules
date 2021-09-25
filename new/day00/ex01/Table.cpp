#include <iostream>
#include <iomanip>

#include "Table.hpp"

Table::Table(int rows, int columns)
{
	_rows = rows;
	_columns = columns;
	_columnWidth = 15;
	setBorderColor(COLOR_GREEN);
	_separator = '|';
	_borderSymbol = '-';

	if (rows > 0 && columns > 0)
	{
		_data = new std::string *[rows];
		for (size_t i = 0; i < _rows; i++)
			_data[i] = new std::string[columns];
	}
}

Table::~Table(void)
{
	if (_rows > 0 && _columns > 0)
	{
		for (size_t i = 0; i < this->_rows; i++)
			delete[] _data[i];
		delete[] _data;
	}
}

void Table::printTableBorder()
{
	std::cout << _currentColor;
	for (size_t i = 0; i <= (_columnWidth + 1) * _columns; i++)
	{
		std::cout << _borderSymbol;
	}
	std::cout << COLOR_RESET << std::endl;
}

void Table::printTableLine(std::string data[])
{
	std::string dataTemp;

	std::cout << _currentColor << _separator << COLOR_RESET;
	for (size_t i = 0; i < _columns; i++)
	{
		if (data[i].length() > _columnWidth)
			dataTemp = data[i].substr(0, _columnWidth - 3) + "...";
		else
			dataTemp = data[i];
		std::cout << std::setw(_columnWidth) << dataTemp;
		std::cout << _currentColor << _separator << COLOR_RESET;
	}
	std::cout << std::endl;
}

void Table::printTitles()
{
	printTableLine(this->_titles);
}

void Table::printTable()
{
	printTableBorder();
	printTitles();
	printTableBorder();
	for (size_t i = 0; i < _rows; i++)
		printTableLine(_data[i]);
	printTableBorder();
}

void Table::setMaxWidth()
{
	for (size_t i = 0; i < _rows; i++)
	{
		for (size_t j = 0; j < _columns; j++)
		{
			if (_data[i][j].length() > _columnWidth)
				_columnWidth = _data[i][j].length();
		}
	}
}

void Table::setBorderColor(std::string color)
{
	this->_currentColor = color;
}

void Table::setSeparator(char separator)
{
	this->_separator = separator;
}

void Table::setBorderSymbol(char borderSymbol)
{
	this->_borderSymbol = borderSymbol;
}

void Table::setTitles(std::string *titles)
{
	this->_titles = titles;
}

void Table::setColumnData(int columnIndex, std::string *data)
{
	for (size_t i = 0; i < this->_rows; i++)
	{
		this->_data[i][columnIndex] = data[i];
	}
}
