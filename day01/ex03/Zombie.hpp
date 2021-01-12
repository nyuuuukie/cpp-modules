/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:02:43 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/12 06:27:07 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define COLOR_RESET		"\033[0m"
#define COLOR_GREEN 	"\033[32m"
#define COLOR_BLUE 		"\033[34m"

class Zombie
{
	public:

		Zombie(std::string name, std::string type);
		Zombie(void);
		~Zombie(void);
		void	announce(void) const;
		void	setAnnounce(std::string text);
		static 	std::string getRandomName(void);
		static 	std::string getRandomType(void);
		static 	std::string getRandomAnnounce(void);

	private:

		std::string _name;
		std::string _type;
		std::string _announce;
};