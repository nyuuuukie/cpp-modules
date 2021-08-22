#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string	input;
	
	while (true)
	{
		getInputString("> ", input);

		if (input.compare("HELP") == 0)
			phonebook.help();
		else if (input.compare("ADD") == 0)
			phonebook.add();
		else if (input.compare("SEARCH") == 0)
			phonebook.search();
		else if (input.compare("EXIT") == 0)
			break;
		else
			printLine("Command not found: " + input);
	}
	phonebook.exit();
	return (0);
}