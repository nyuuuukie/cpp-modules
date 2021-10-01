#pragma once

template<typename T>
void iter(const T *addr, unsigned int length, void (*func)(const T&)) {
	for (unsigned int i = 0; i < length; i++)
		func(addr[i]);
}
