/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:06:53 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/12 06:35:35 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <ctime>

int main(void)
{
	srand(time(0));
	ZombieHorde horde(10);
	horde.announce();
	return (0);
}