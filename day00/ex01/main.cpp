/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 06:04:19 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/27 06:10:11 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

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