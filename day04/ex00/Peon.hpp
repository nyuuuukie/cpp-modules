/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:29:23 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 22:50:13 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Victim.hpp"

typedef std::string string;

class Peon : public Victim
{
	public:
	
		Peon(string name);
		~Peon(void);
		
		Peon(const Peon & other);
		Peon & operator=(const Peon & other);

		virtual void getPolymorphed(void) const;
};
