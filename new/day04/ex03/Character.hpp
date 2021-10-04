#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		~Character(void);
		Character(const Character & other);
		Character & operator=(const Character & other);

		virtual std::string const & getName() const;
		void setName(const std::string &name);

		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:
		int _maxSize;
		int _idx;
		AMateria *_storage[4];
		std::string _name;
};
