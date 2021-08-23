#pragma once

# include <iostream>
# include "Table.hpp"
# include "Contact.hpp"

class Phonebook
{
	private:
		static const int _size = 8;
		Contact			 _contacts[_size];
		static int		 _currentIndex;

	public:
		void		print();
		void		search();
		void		add();
		void		help();
		void		exit();
		
		static int	getCount(void);
		void		addContact(void);

};

void	getInputString(std::string title, std::string &input);
void	printLine(std::string line);
int		getNumber(std::string s);

