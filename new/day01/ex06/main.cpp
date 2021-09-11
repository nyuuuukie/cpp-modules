#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen Smith;
	std::string level = "";

	if (argc >= 2) {
		level = std::string(argv[1]);
	}
	Smith.complain(level);

	return 0;
}
