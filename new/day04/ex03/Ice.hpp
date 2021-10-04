#pragma once

#include "AMateria.hpp"
//#include "ICharacter.hpp"
#include <cstdlib>

class Ice : public AMateria
{
	private:
		int _powerPercentage;
	
	public:
		Ice(void);
		~Ice(void);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);

		virtual int getPower() const;
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};
