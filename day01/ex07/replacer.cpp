/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:08:50 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 19:30:03 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	replacer(std::ifstream& file, const std::string s1, const std::string s2)
{
	std::string input;
	std::string	total;
	
	do {
		getline(file, input);
		total += "\n" + input;
	} while (!file.eof());

	size_t index = 0;
	while ((index = total.find(s1, index)) != std::string::npos)
		total.replace(index, index + s1.length() - 1, s2);
	return total;
}

std::string getParameter(std::string title)
{
	std::string input;

	do {
		std::cout << title;
		getline(std::cin, input);
		
		if (std::cin.eof())
			return ("");
	}
	while (input.compare("") == 0);
	return input;
}

int main(void)
{
	std::string filename;
	std::string whatReplace;
	std::string whatReplaceWith;

	filename = getParameter("Enter filename: ");
	whatReplace = getParameter("What do you want to replace: ");
	whatReplaceWith = getParameter("What do you want to replace with: ");
	
	std::ifstream file(filename);
	std::ofstream newFile(filename + ".replace");
	if (file.is_open() && newFile.is_open())
		newFile << replacer(file, whatReplace, whatReplaceWith);
	else
		std::cout << "File " + filename + " not found." << std::endl;
	file.close();
	newFile.close();
	std::cout << "Replaced!" << std::endl;
	return (0);
}