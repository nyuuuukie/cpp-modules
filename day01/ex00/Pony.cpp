/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:05:13 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/10 20:44:35 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

static void printColorLine(std::string color, std::string text)
{
	std::cout << color << text << RESET;
}

void	Pony::saySomething(std::string color, std::string text)
{
	printColorLine(RESET, "[" + _hairColor + " " + _name + "]: ");
	printColorLine(color, text + " " + _speech + "\n\n");
}

Pony::Pony(void)
{
	std::cin.clear();
	printColorLine(RESET, "-----------------CONSTRUCTOR----------------\n");
	printColorLine(GREEN, "-Salut, mon amie!");
	printColorLine(RESET, " -> [Greeting]\n");
	printColorLine(RESET, "-");
	getline(std::cin, this->_greeting);
	
	printColorLine(GREEN, "-Quel est ton nom? ");
	printColorLine(RESET, " -> [Name]\n");
	printColorLine(RESET, "-Sorry, I don't speak French... I'm ");
	getline(std::cin, this->_name);
	
	printColorLine(GREEN, "-Tu as un joli nom!\n");
	printColorLine(GREEN, "-Tes cheveux... De quelle couleur?");
	printColorLine(RESET, " -> [Hair color]\n");
	printColorLine(RESET, "-");
	getline(std::cin, this->_hairColor);
	
	printColorLine(GREEN, "-Tres bien, tres bien!\n");
	printColorLine(RESET, "-Merci beaucoup!\n");
	printColorLine(GREEN, "-Tu veux me dire quelque chose?");
	printColorLine(RESET, " -> [Speech]\n");
	printColorLine(RESET, "-");
	getline(std::cin, this->_speech);

	printColorLine(RESET, "--------------------------------------------\n\n");
}

Pony::~Pony(void)
{
	printColorLine(RESET, "-----------------DESTRUCTOR-----------------\n");
	printColorLine(RESET, "Au revoir, mon " + _name + " !\n" );
	printColorLine(RESET, "--------------------------------------------\n");
}