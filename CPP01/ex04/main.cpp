/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:03:48 by macaruan          #+#    #+#             */
/*   Updated: 2025/11/21 12:49:44 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	if (s1.empty())
		return str;

	while ((found = str.find(s1, pos)) != std::string::npos)
	{
		result += str.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += str.substr(pos);

	return result;
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Use: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: cannot open file " << filename << std::endl;
		return 1;
	}

	std::string outFilename = filename + ".replace";
	std::ofstream outfile(outFilename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: cannot create file " << outFilename << std::endl;
		infile.close();
		return 1;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		outfile << replaceAll(line, s1, s2) << std::endl;
	}
	infile.close();
	outfile.close();

	std::cout << "File created: " << outFilename << std::endl;
	return 0;
}
