/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:04:25 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/10 05:19:26 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact {
	private:
		std::string index;
		std::string login;
		std::string nickname;
		std::string lastName;
		std::string firstName;
		std::string phoneNumber;
		std::string favoriteMeal;
		std::string emailAddress;
		std::string birthdayDate;
		std::string darkestSecret;
		std::string postalAddress;
		std::string underwearColor;
		static int _amountOfContacts;

	public:

		Contact(void);
		~Contact(void);	
		
		static int	getCount(void);
		void		addContact(void);
		void		printContactInfo(void);
		std::string getIndex(void);
		std::string getNickname(void);
		std::string getLastName(void);
		std::string getFirstName(void);
};
