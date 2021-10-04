#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
	
		MateriaSource(void);
		virtual ~MateriaSource(void);
		MateriaSource(const MateriaSource & other);
		MateriaSource & operator=(const MateriaSource & other);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

	private:
		int _idx;
		int _maxSize;
		AMateria *_storage[4];
};
