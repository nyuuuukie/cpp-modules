/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:08:50 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/14 18:57:52 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

typedef std::string string;

//string	toUpperCase(string src)
//{
//	for (size_t i = 0; i < src.length(); i++)
//	{
//		if (std::islower(src[i]))
//			src[i] = toupper(src[i]);
//	}
//	return src;
//}

//string getTextFromFile(std::ifstream& file)
//{
//	string input;
//	string total;
	
//	while (!file.eof());
//	{
//		getline(file, input);
//		total += "\n" + input;
//	}
//	return total;
//}

//string	replace(std::ifstream& file, const string s1, const string s2)
//{
//	string total;
//	size_t index;
	
//	index = 0;
//	total = getTextFromFile(file);
//	while ((index = total.find(s1, index)) != string::npos)
//	{
//		total.replace(index, index + s1.length() - 1, s2);
//	}
//	return total;
//}

void getParameter(string &prm, string title)
{
	string input;

	do {
		std::cout << title;
		getline(std::cin, input);
		
		if (std::cin.eof())
		{
			prm = "";
			break;
		}
	}
	while (input.compare("") == 0);
	prm = input;
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
		//Need to create a exit point
		getParameter(filename, "Enter filename: ");
		getParameter(whatReplace, "What do you want to replace: ");
		getParameter( whatReplaceWith, "What do you want to replace with: ");
		
		replacer.setExtension(extension);
		
		//One of these methods set BAD_ARG
		replacer.setInputFilename(filename);
		replacer.whatReplace(whatReplace);
		replacer.whatReplaceWith(whatReplaceWith);

		if (replacer.getCode() == BAD_ARGUMENTS)
			return (1);
		else
			replacer.makeReplace();		
	}
	return (0);
}