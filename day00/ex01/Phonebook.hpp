/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 04:36:57 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/27 08:09:11 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "Table.hpp"
# include "Contact.hpp"

# define MAX__contacts 8

class Phonebook
{
	
	public:

		void	print();
		void	search();
		void	add();
		void	help();
		void	exit();
		
		static int	getCount(void);
		void		addContact(void);
		

	private:
	
		Contact			 _contacts[MAX__contacts];
		static int		 _amountOf_contacts;
		static const int _max_contacts;

};

void	getInputString(std::string title, std::string &input);
void	printLine(std::string line);
int		getNumber(std::string s);

