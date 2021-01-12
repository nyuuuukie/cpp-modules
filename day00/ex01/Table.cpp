/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Table.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 07:09:38 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/12 06:57:32 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	Table::setMaxWidth(std::string **data)
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

Table::Table(int rows, int columns, int columnsWidth)
{
	this->rows = rows;
	this->columns = columns;
	this->columnWidth = columnsWidth;
}

Table::~Table(void) { }