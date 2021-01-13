/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 06:02:25 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 06:23:16 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.hpp"

class Human
{
	public:

		Human(void);
		~Human(void);
		Brain& 		getBrain(void);
		std::string	identify(void);

	private:
		Brain brain;
};
	