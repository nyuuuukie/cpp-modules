#pragma once

#include <algorithm>

#include "NotFoundException.hpp"

template <typename T>
typename T::iterator easyfind(T &cont, const typename T::value_type &val) {
	typename T::iterator found;
	
	found = find(cont.begin(), cont.end(), val);
	if (found == cont.end()) {
		throw NotFoundException();
	}
	return found;
}
