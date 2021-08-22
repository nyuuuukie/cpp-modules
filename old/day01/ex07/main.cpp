/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:08:50 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/27 08:37:29 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

typedef std::string string;

void	getInputString(string title, string &input)
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

int	getParameter(string &prm, string title)
{
	string input = "";

	do {
		std::cout << title;
		getline(std::cin, input);
		
		if (std::cin.eof())
			return (1);
	}
	while (input.compare("") == 0);
	prm = input;
	return (0);
}

int main(void)
{
	Replacer replacer;
	
	const string extension = "replace";
	string filename;
	string whatReplace;
	string whatReplaceWith;

	for (;;)
	{
		getInputString("Enter filename: ", filename);
		getInputString("What do you want to replace: ", whatReplace);
		getInputString("What do you want to replace with: ", whatReplaceWith);

		replacer.setExtension(extension);
		replacer.setInputFilename(filename);
		replacer.whatReplace(whatReplace);
		replacer.whatReplaceWith(whatReplaceWith);

		if (replacer.getCode() == BAD_ARGUMENTS)
			replacer.printLine("Wrong input. ");
		else
			break;
	}
	replacer.makeReplace();
	if (replacer.getCode() == STRING_NOT_FOUND)
		replacer.printColorLine("\nPattern " + whatReplace + " not found.", RED);
	return (replacer.getCode());
}
