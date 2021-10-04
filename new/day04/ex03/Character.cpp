#include "Character.hpp"

Character::Character(void) : _maxSize(4), _idx(0) {
	for (int i = 0; i < _maxSize; i++)
		_storage[i] = 0;
}

Character::Character(std::string name) : _maxSize(4), _idx(0) {
	_name = name;
	for (int i = 0; i < _maxSize; i++)
		_storage[i] = 0;
}

Character::~Character(void)  {
	for (int i = 0; i < _maxSize; i++) {
		if (this->_storage[i])
			delete this->_storage[i];
	}
}

Character::Character(const Character & other) {
	this->_maxSize = other._maxSize;	
	for (int i = 0; i < _maxSize; i++)
		_storage[i] = 0;
	*this = other;
}

Character &Character::operator=(const Character & other) {
	if (this != &other) {
		this->_name = other._name;
		this->_maxSize = other._maxSize;

		for (int i = 0; i < _maxSize; i++) {
			if (_storage[i] != 0)
				delete _storage[i];
			if (other._storage[i] != 0)
				_storage[i] = other._storage[i]->clone();
		}

	}
	return *this;
}
std::string const &Character::getName() const {
	return this->_name;
}

void Character::setName(const std::string &name) {
	this->_name = name;
}

void Character::equip(AMateria* m) {
	if (_idx >= _maxSize)
		return ;

	std::cout << m->getType() << " prepare to be equipped!" << std::endl;
	if (m != 0) {
		std::cout << m->getType() << " equipped!" << std::endl;
		_storage[_idx] = m;
		_idx++;
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= _maxSize)
		return ;
	
	if (_storage[idx]) {
		_storage[idx] = 0;
		_idx--;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= _maxSize)
		return ;
	
	std::cout << _storage[idx]->getType() << " prepared to use!" << std::endl;
	if (_storage[idx] != 0) {
		
		_storage[idx]->use(target);
	}
}
