#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _idx(0), _maxSize(4) {
	for (int i = 0; i < _maxSize; i++)
		_storage[i] = 0;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < _maxSize; i++) {
		if (this->_storage[i])
			delete this->_storage[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		this->_maxSize = other._maxSize;

		for (int i = 0; i < _maxSize; i++) {
			delete _storage[i];
			_storage[i] = other._storage[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (_idx >= _maxSize)
			return ;

	std::cout << "learned " << m->getType() << std::endl;
	if (m != 0) {
		_storage[_idx] = m->clone();
		_idx++;
	}
}

AMateria* MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < _maxSize; ++i) {
		if (this->_storage[i] && this->_storage[i]->getType() == type) {
			return (this->_storage[i]->clone());
		}
	}
	return 0;
}

