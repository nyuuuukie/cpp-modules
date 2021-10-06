#include "serialize.hpp"

int main() {

	Data *d = new Data();

	d->_data = "Born2Code";
	d->_num = 21;

	std::cout << d << std::endl;
	std::cout << d->_data << std::endl;
	std::cout << d->_num << std::endl;

	uintptr_t raw = serialize(d);

	Data *b = deserialize(raw);
	std::cout << b << std::endl;
	std::cout << b->_data << std::endl;
	std::cout << b->_num << std::endl;

	return 0;
}
