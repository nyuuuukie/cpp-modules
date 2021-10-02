#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		~WrongAnimal(void);
		WrongAnimal(const WrongAnimal & other);
		WrongAnimal & operator=(const WrongAnimal & other);

		const std::string &getType( void ) const;
		void setType(const std::string &type);
		
		void makeSound( void ) const;

	protected:
		std::string _type;
};
