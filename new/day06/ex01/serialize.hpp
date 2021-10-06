#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
	int _num;
	std::string _data;
};

Data* deserialize(uintptr_t raw);
uintptr_t serialize(Data* ptr);

