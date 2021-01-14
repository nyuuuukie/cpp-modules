/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:08:50 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/15 02:40:56 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

typedef std::string string;

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
		if (getParameter(filename, "Enter filename: "))
			return (READ_FILE_ERROR);
		if (getParameter(whatReplace, "What do you want to replace: "))
			return (BAD_ARGUMENTS);
		if (getParameter(whatReplaceWith, "What do you want to replace with: "))
			return (BAD_ARGUMENTS);

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
