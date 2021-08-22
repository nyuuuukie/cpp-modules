#pragma once

#include <string>
#include "ANSIColors.hpp"

class Table
{
	public:
		
		Table(int rows, int columns);
		~Table(void);

		void		setColumnData(int columnIndex, std::string *data);
		void		setBorderSymbol(char borderSymbol);
		void		setBorderColor(std::string color);
		void		setTitles(std::string *titles);
		void		setSeparator(char separator);
		void		setMaxWidth();

		void		printTableLine(std::string data[]);
		void		printTableBorder();
		void		printTitles();
		void		printTable();
		
	private:
		
		char		separator;
		char		borderSymbol;
		size_t		rows;
		size_t		columns;
		size_t		columnWidth;
		std::string currentColor;
		std::string *titles;
		std::string **data;

};
