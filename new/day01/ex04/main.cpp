#include "Replacer.hpp"
#include "Utils.hpp"

void getInput(std::string title, std::string &input)
{
	do 
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(input.size());
			clearerr(stdin);
		}
		std::cout << title;
		getline(std::cin, input);
	} while (std::cin.eof());
}

int main(void)
{
	Replacer repl;
	
	const std::string extension = "replace";
	std::string filename;
	std::string replacee;
	std::string replacer;

	for (;;)
	{
		getInput("Enter input filename: ", filename);
		getInput("Enter \"replacee\": ", replacee);
		getInput("Enter replacer: ", replacer);

		if (!repl.setExtension(extension) && 
			!repl.setReplacer(replacer) &&
			!repl.setReplacee(replacee) &&
			!repl.setInput(filename)) {
			break ;
		}	
		Utils::print("Wrong input.", RED);
	}
	if (repl.makeReplace() == 2)
		Utils::print("Pattern " + replacee + " not found.", RED);
	
	return 0;
}
