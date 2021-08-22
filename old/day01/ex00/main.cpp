/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:35:46 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/20 19:55:36 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	Pony *heapPony = new Pony();
	
	heapPony->saySomething(MAGENTA, "Riding on the Heap!");
	delete heapPony;
}

void	ponyOnTheStack(void)
{	
	Pony stackPony;

	stackPony.saySomething(GREEN, "Riging on the Stack!");
}

void	cleanScreenRequest(void)
{
	std::string result;

	std::cout << std::endl;
	do {
		std::cout << "clear the screen? [yes/no] ";
		getline(std::cin, result);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		if (result.compare("yes") == 0)
		{
			std::cout << "\033[2J";
			break;
		}
	} while (result.compare("no") != 0);
}

int main(void)
{
	ponyOnTheHeap();
	cleanScreenRequest();
	ponyOnTheStack();
	
	return (0);
}