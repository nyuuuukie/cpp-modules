/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:27:51 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 23:01:55 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Victim.hpp"

typedef std::string string;

class Sorcerer
{
	public:
	
		Sorcerer(string name, string title);
		~Sorcerer(void);
		Sorcerer(const Sorcerer & other);
		Sorcerer & operator=(const Sorcerer & other);

		string getName(void) const;
		string getTitle(void) const;
		void polymorph(Victim const &) const;

	private:

		string _name;
		string _title;
	
};

std::ostream& operator<<(std::ostream & out, const Sorcerer& sorcerer);