#pragma once

#include <string>
#include "Attribute.hpp"

class Contact {

	private:
		static const unsigned int _size = 5;
		Attribute attr[_size];

		//std::string _index;
		//std::string _login;
		//std::string _nickname;
		//std::string _lastName;
		//std::string _firstName;
		//std::string _phoneNumber;
		//std::string _darkestSecret;
		
	public:

		Contact(void);
		~Contact(void);	
		
		void		addValues(int index);
		void		printContactInfo(void);
		std::string getIndex(void);
		std::string getNickname(void);
		std::string getLastName(void);
		std::string getFirstName(void);

		
};
