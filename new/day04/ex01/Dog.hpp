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
		~Dog(void);
		Dog(const Dog & other);
		virtual Dog & operator=(const Dog & other);

		void makeSound( void ) const ;
		
		virtual	Brain *getBrain( void ) const;
		virtual void setBrain( Brain *brain);
};
