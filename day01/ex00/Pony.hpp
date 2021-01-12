/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:00:01 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/10 20:44:42 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define MAGENTA "\033[35m"
#define GREEN	"\033[32m"
#define RESET	"\033[0m"

class Pony
{
	public:

		Pony(void);
		~Pony(void);
		void	saySomething(std::string color, std::string text);
		
	private:

		std::string	_name;
		std::string	_greeting;
		std::string _hairColor;
		std::string	_speech;
};