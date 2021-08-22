/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:04:25 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/27 08:07:36 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact {

	private:
	
		std::string _index;
		std::string _login;
		std::string _nickname;
		std::string _lastName;
		std::string _firstName;
		std::string _phoneNumber;
		std::string _favoriteMeal;
		std::string _emailAddress;
		std::string _birthdayDate;
		std::string _darkestSecret;
		std::string _postalAddress;
		std::string _underwearColor;
		
	public:

		Contact(void);
		~Contact(void);	
		
		void		addValues(int index);
		void		printContactInfo(void);
		std::string getIndex(void);
		std::string getNickname(void);
		std::string getLastName(void);
		std::string getFirstName(void);
};
