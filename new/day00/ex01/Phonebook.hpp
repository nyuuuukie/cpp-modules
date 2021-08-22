#pragma once

# include <iostream>
# include "Table.hpp"
# include "Contact.hpp"

# define CONTACTS 8

class Phonebook
{
	public:

		void		print();
		void		search();
		void		add();
		void		help();
		void		exit();
		
		static int	getCount(void);
		void		addContact(void);
		
	private:
	
		Contact			 _contacts[CONTACTS];
		static int		 _amountOf_contacts;
		static const int _CONTACTS;
};

void	getInputString(std::string title, std::string &input);
void	printLine(std::string line);
int		getNumber(std::string s);

