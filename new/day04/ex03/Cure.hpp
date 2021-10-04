#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <cstdlib>

class Cure : public AMateria
{
	private:
		int _healPowerPercentage;

	public:
		Cure(void);
		~Cure(void);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);

		virtual int getPower() const;
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};
