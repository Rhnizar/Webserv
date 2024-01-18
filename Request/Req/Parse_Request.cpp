/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_Request.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:02:47 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/18 20:48:04 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

void	Request::Parse_ReqLine(std::string line)
{
	std::cout << "\n---------------  HttpRequestLine --------------------------------\n";
	// Find positions of spaces
    size_t pos1 = line.find(' ');
    size_t pos2 = line.find(' ', pos1 + 1);
    size_t pos3 = line.find_last_of(' ');

    // Extract values
    ReqLine.Method = line.substr(0, pos1);
    ReqLine.Path = line.substr(pos1 + 1, pos2 - pos1 - 1);
    ReqLine.HttpVersion = line.substr(pos3 + 1);
	
	std::cout << "Method:	" << ReqLine.Method << std::endl;
    std::cout << "Path: 	" << ReqLine.Path << std::endl;
    std::cout << "HTTP Version: 	" << ReqLine.HttpVersion << std::endl;
	std::cout << "\n----------------------------------------------------------------\n";
}

void Request::Parse_Request(std::string httpRequest)
{
	std::istringstream ss(httpRequest);
    std::string line;
    std::vector<std::pair<std::string, std::string> > Header;
	
	std::getline(ss, line);
	Parse_ReqLine(line);
    while (std::getline(ss, line))
	{
        // Find the position of the colon in the line
        size_t pos = line.find(':');
        if (pos != std::string::npos)
		{
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            // Remove leading and trailing whitespaces from key and value
            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);
            // Store in the Vector
			Header.push_back(std::make_pair(key, value));
        }
    }
	std::vector<std::pair<std::string, std::string> >::iterator it = Header.begin();
	std::cout << "\n---------------------------------- Header ---------------------------------------\n";
    for (; it != Header.end(); it++)
        std::cout << "Key: " << it->first << "   |   Value: " << it->second << std::endl;
    // std::cout << httpRequest << std::endl;
	std::cout << "\n---------------------------------------------------------------------------------\n";
    
}

