#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>
#include <iostream>

class Dog : public Animal
{
	private:
		Brain *_brain;

	public:
		Dog(void);
		~Dog();
		Dog(const Dog & other);
		virtual Dog & operator=(const Dog & other);

		void makeSound( void ) const ;
		
		Brain *getBrain( void ) const;
};
