/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Table.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 07:06:11 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/12 06:58:56 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ANSIColors.hpp"

class Table
{
	public:
		
		Table(int rows, int columns, int columnsWidth);
		~Table(void);
		void		printTableBorder();
		void		printTableLine(std::string data[]);
		void		setMaxWidth(std::string **data);
		void		setBorderColor(std::string color);
		void		setSeparator(char separator);
		void		setBorderSymbol(char borderSymbol);
	private:
		
		char		separator;
		char		borderSymbol;
		size_t		rows;
		size_t		columns;
		size_t		columnWidth;
		std::string currentColor;

};
