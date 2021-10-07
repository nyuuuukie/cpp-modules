#include "Parse.hpp"

// 0 - All convertations done successfully 
// 1 - Incorrect usage
// 2 - There were some problems with convertations

int main(int argc, char **argv) {
	int res;
	
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0];
		std::cerr << " <num>" << std::endl;
		res = 1;
	}
	else {
		Parse parse(argv[1]);
		res = parse.parse();
	}
	return res;
}
