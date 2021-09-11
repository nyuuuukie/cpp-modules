#include "Karen.hpp"

int main(void)
{
	Karen Smith;

	Smith.complain("INFO");
	Smith.complain("DEBUG");
	Smith.complain("WARNING");
	Smith.complain("ERROR");
	
	Smith.complain("FAKE");
	return 0;
}
