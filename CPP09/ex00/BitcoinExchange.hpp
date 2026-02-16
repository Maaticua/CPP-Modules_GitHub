/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:42:35 by macaruan          #+#    #+#             */
/*   Updated: 2026/02/16 10:56:14 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

		bool isValidDate(const std::string& date) const;
		float getExchangeRate(const std::string& date) const;
		std::string trim (const std::string& str) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void loadDatabase(const std::string &filename);
		void processInput(const std::string &filename);
};

#endif