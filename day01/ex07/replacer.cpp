/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:08:50 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 11:46:38 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replacer(std::ifstream& file, std::string s1, std::string s2)
{
	std::stringstream ss;

	do {
		getline(file, ss);
	} while (!file.eof());
}

std::string getParameter(std::string title)
{
	std::string input;

	do {
		std::cout << title;
		getline(std::cin, input);
	}
	while (input.compare("") == 0);
	return input;
}

int main(void)
{
	std::string filename;
	std::string whatReplace;
	std::string whatReplaceWith;

	for (;;)
	{
		filename = getParameter("Enter filename: ");
		whatReplace = getParameter("What do you want to replace: ");
		whatReplaceWith = getParameter("What do you want to replace with: ");
		if (std::cin.eof())
			break;
		
		std::ifstream file(filename);
		if (file.is_open()) 
			replacer(file, whatReplace, whatReplaceWith);
		else
		{
			std::cout << "file not found." << std::endl;
			break;
		}
		file.close();
	}
	std::cout << "Bye!" << std::endl;
	return (0);
}