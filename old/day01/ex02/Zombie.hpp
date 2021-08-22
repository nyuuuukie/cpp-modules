/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:02:43 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/12 04:43:19 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
	public:

		Zombie(std::string name, std::string type);
		Zombie(void);
		~Zombie(void);
		void	announce(void) const;
		void	setAnnounceText(std::string text);
		static 	std::string getRandomName(void);
		static 	std::string getRandomType(void);

	private:

		std::string _name;
		std::string _type;
		std::string _announceText;
};