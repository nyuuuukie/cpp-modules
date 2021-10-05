#pragma once

#include <algorithm>

#include "NotFoundException.hpp"

template <typename T>
typename T::iterator easyfind(T &arr, int number) {
	typename T::iterator found;
	
	found = find(arr.begin(), arr.end(), number);
	if (found == arr.end()) {
		throw NotFoundException();
	}
	return found;
}
