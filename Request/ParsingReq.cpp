/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingReq.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:28:30 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/15 11:34:28 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <vector>

int main() {
    std::string httpRequest = "GET / HTTP/1.1\n"
                              "Host: localhost:999\n"
                              "Connection: keep-alive\n"
                              "sec-ch-ua: \"Not/A)Brand\";v=\"99\", \"Google Chrome\";v=\"115\", \"Chromium\";v=\"115\"\n"
                              "sec-ch-ua-mobile: ?0\n"
                              "sec-ch-ua-platform: \"macOS\"\n"
                              "Upgrade-Insecure-Requests: 1\n"
                              "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36\n"
                              "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7\n"
                              "Sec-Fetch-Site: none\n"
                              "Sec-Fetch-Mode: navigate\n"
                              "Sec-Fetch-User: ?1\n"
                              "Sec-Fetch-Dest: document\n"
                              "Accept-Encoding: gzip, deflate, br\n"
                              "Accept-Language: en-US,en;q=0.9,fr;q=0.8,ar;q=0.7\n"
                              "Cookie: PHPSESSID=82e6bdd4dee2f22c198d1453a9c96d50; theme=dark";

    std::istringstream ss(httpRequest);
    std::string line;

	std::vector<std::pair<std::string, std::string> > keyValueVector;

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
			keyValueVector.push_back(std::make_pair(key, value));
        }
    }
	std::vector<std::pair<std::string, std::string> >::iterator it = keyValueVector.begin();
    for (; it != keyValueVector.end(); it++)
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;

    return 0;
}
