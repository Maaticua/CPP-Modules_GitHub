/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:56:50 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/21 11:00:30 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{

private:
	std::string type;

public:
	Weapon(std::string type);
	const std::string& getType(void) const;
	void setType(std::string newType);
};

#endif
