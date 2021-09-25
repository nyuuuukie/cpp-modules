#pragma once

#include <string>
#include "ANSIColors.hpp"

class Table
{
private:
	char        _separator;
	char        _borderSymbol;
	size_t      _rows;
	size_t      _columns;
	size_t      _columnWidth;
	std::string _currentColor;
	std::string *_titles;
	std::string **_data;

public:
	Table(int rows, int columns);
	~Table(void);

	void setColumnData(int columnIndex, std::string *data);
	void setBorderSymbol(char borderSymbol);
	void setBorderColor(std::string color);
	void setTitles(std::string *titles);
	void setSeparator(char separator);
	void setMaxWidth();

	void printTableLine(std::string data[]);
	void printTableBorder();
	void printTitles();
	void printTable();
};
