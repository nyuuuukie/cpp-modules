#pragma once

#include "Brain.hpp"
#include <string>
#include <iostream>

class Animal
{
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal & other);
		virtual Animal & operator=(const Animal & other);

		const std::string &getType( void ) const;
		void setType(const std::string &type);
		
		virtual void makeSound( void ) const;

	protected:
		std::string _type;
};
