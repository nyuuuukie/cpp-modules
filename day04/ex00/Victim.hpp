/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:27:58 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 23:05:12 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string string;

class Victim
{
	public:
	
		Victim(string name);
		virtual ~Victim(void);

		Victim(const Victim & other);
		Victim & operator=(const Victim & other);

		string getName(void) const;
		virtual void getPolymorphed(void) const;

	protected:
		string _name;

};

std::ostream & operator<<(std::ostream & out, const Victim & Victim);
