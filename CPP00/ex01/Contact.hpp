/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:16:27 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/14 18:22:24 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>

class Contact
{
  private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;

  public:
	void setfirstname(std::string firstname);
	void setlastname(std::string lastname);
	void setnickname(std::string nickname);
	void setphonenumber(std::string phonenumber);
	void setdarkestsecret(std::string darkestsecret);

	std::string getfirstname();
	std::string getlastname();
	std::string getnickname();
	std::string getphonenumber();
	std::string getdarkestsecret();
};

#endif
