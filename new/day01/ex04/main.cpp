#include "Replacer.hpp"
#include "Utils.hpp"

void getInputString(std::string title, std::string &input)
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

//int	getParameter(std::string &prm, std::string title)
//{
//	std::string input = "";

//	do {
//		std::cout << title;
//		getline(std::cin, input);
		
//		if (std::cin.eof())
//			return (1);
//	}
//	while (input.compare("") == 0);
//	prm = input;
//	return (0);
//}

int main(void)
{
	Replacer repl;
	
	const std::string extension = "replace";
	std::string filename;
	std::string replacee;
	std::string replacer;

	for (;;)
	{
		getInputString("Enter filename: ", filename);
		getInputString("What do you want to replace: ", replacee);
		getInputString("What do you want to replace with: ", replacer);

		repl.setExtension(extension);
		repl.setInput(filename);
		repl.setReplacee(replacee);
		repl.setReplacer(replacer);

		if (repl.getCode() != BAD_ARGUMENTS)
			break;

		Utils::printLine("Wrong input. ");
	}
	repl.makeReplace();
	if (repl.getCode() == STRING_NOT_FOUND)
		Utils::printColorLine("\nPattern " + replacee + " not found.", RED);
	return (repl.getCode());
}
