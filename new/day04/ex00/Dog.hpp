#pragma once

#include "Animal.hpp"

#include <string>
#include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog & other);
		Dog & operator=(const Dog & other);

		void makeSound( void ) const ;
};
