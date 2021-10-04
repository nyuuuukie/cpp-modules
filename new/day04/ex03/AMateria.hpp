#pragma once

#include <iostream>
class ICharacter;

class AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria( void );
		AMateria(std::string const & type);
		AMateria(const AMateria &other);
		virtual ~AMateria();

		AMateria &operator=(const AMateria &other);

		std::string const & getType() const;
		virtual int getPower() const = 0;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};

#include "ICharacter.hpp"
