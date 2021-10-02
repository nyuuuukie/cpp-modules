#pragma once

#include "WrongAnimal.hpp"

#include <string>
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		virtual ~WrongCat(void);
		WrongCat(const WrongCat & other);
		WrongCat & operator=(const WrongCat & other);

		void makeSound( void ) const ;
};
