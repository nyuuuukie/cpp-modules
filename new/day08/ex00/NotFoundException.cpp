#include "NotFoundException.hpp"

const char *NotFoundException::what() const throw() {
	return ("Not found (<Exception>)");
};