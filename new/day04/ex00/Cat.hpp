#pragma once

#include "Animal.hpp"

#include <string>
#include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(const Cat & other);
		Cat & operator=(const Cat & other);

		void makeSound( void ) const ;
};
