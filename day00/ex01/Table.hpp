/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Table.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 07:06:11 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/26 12:59:05 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ANSIColors.hpp"

class Table
{
	public:
		
		Table(int rows, int columns);
		~Table(void);
		void		printTableBorder();
		void		printTableLine(std::string data[]);
		void		setMaxWidth();
		void		setBorderColor(std::string color);
		void		setSeparator(char separator);
		void		setBorderSymbol(char borderSymbol);
		void		setTitles(std::string *titles);
		void		setColumnData(int columnIndex, std::string *data);
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
