#include "Attribute.hpp"

void
Attribute::setValue(std::string value)
{
	this->_value = value;
}

void
Attribute::setName(std::string name)
{
	this->_name = name;
}

std::string &
Attribute::getValue(void)
{
	return this->_value;
}

std::string
Attribute::getName(void) const
{
	return this->_name;
}

Attribute::Attribute() {}
Attribute::~Attribute() {}
