#pragma once

#include "Brain.hpp"
#include <string>
#include <iostream>

class Animal
{
	public:
		Animal( void );
		virtual ~Animal();
		Animal( const Animal & other );
		virtual Animal & operator=( const Animal & other );
		
		virtual const std::string &getType( void ) const;
		virtual void setType( const std::string &type );
		
		virtual void makeSound( void ) const = 0;

	protected:
		std::string _type;
};
