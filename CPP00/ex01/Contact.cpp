/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:16:25 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/14 18:31:15 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::setfirstname(std::string firstname)
{
	this->firstname = firstname;
}
void Contact::setlastname(std::string lastname)
{
	this->lastname = lastname;
}
void Contact::setnickname(std::string nickname)
{
	this->nickname = nickname;
}
void Contact::setphonenumber(std::string phonenumber)
{
	this->phonenumber = phonenumber;
}
void Contact::setdarkestsecret(std::string darkestsecret)
{
	this->darkestsecret = darkestsecret;
}
std::string Contact::getfirstname()
{
	return this->firstname;
}
std::string Contact::getlastname()
{
	return this->lastname;
}
std::string Contact::getnickname()
{
	return this->nickname;
}
std::string Contact::getphonenumber()
{
	return this->phonenumber;
}
std::string Contact::getdarkestsecret()
{
	return this->darkestsecret;
}
