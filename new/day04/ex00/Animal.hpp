#pragma once

#include <string>
#include <iostream>

class Animal
{
	public:
		Animal(void);
		~Animal(void);
		Animal(const Animal & other);
		Animal & operator=(const Animal & other);

		const std::string &getType( void ) const;
		void setType(const std::string &type);
		
		virtual void makeSound( void ) const;

	protected:
		std::string _type;
};
