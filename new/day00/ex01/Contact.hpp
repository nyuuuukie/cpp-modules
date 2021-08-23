#pragma once

#include <string>
#include "Attribute.hpp"

class Contact
{
	private:
		static const int _size = 6;
		Attribute _attr[_size];
		
	public:
		Contact(void);
		~Contact(void);	
		
		void		addValues(int index);
		void		printContactInfo(void);

		static int	getSize(void);

		std::string operator[](int index);
		std::string &operator[](std::string key);
};
