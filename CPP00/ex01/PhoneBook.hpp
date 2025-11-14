/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:12:19 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/14 18:34:43 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <cctype>
# include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
private:
	Contact contacts[8];
	int count;
	int oldindex;

public:
	PhoneBook();
	void AddContact();
	void SearchContact();
};

#endif
