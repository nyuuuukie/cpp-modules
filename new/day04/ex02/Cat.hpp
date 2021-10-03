#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>
#include <iostream>

class Cat : public Animal
{
	private:
		Brain *_brain;

	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat & other);
		virtual Cat & operator=(const Cat & other);

		void makeSound( void ) const ;

		Brain *getBrain( void ) const;
};
