/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:51:23 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/15 13:07:34 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

void error(std::string msg)
{
	perror(msg.c_str());
	exit(1);
}

Request::Request()
{}

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
	std::cout << "\n---------------------------------------------------------------------------------\n";
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
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

	Request ReqClass;
	// if(argc < 2)
	// {
	// 	std::cerr << "Port number Not provided. Program terminated " << std::endl;
	// 	exit(1);
	// }
	
	// int sockfd, newsockfd, portno, n;
	// struct sockaddr_in serv_add, cli_add;
	// socklen_t clilen;
	// char buffer[1024];
	// sockfd = socket(AF_INET, SOCK_STREAM, 6);
	// if(sockfd == -1)
	// 	error("Error Opening Socket .\n");
	// bzero((char *) &serv_add, sizeof(serv_add));
	// portno = atoi(argv[1]);

	// serv_add.sin_family = AF_INET;

	// serv_add.sin_addr.s_addr = INADDR_ANY;
	// serv_add.sin_port = htons(portno);
	
	// if(bind(sockfd, (struct sockaddr *) &serv_add, sizeof(serv_add)) < 0)
	// 	error("Binding Failed .\n");

	// listen(sockfd, 5);
	
	// while(1)
	// {
		// std::string httpRequest;
		// newsockfd = accept(sockfd, (struct sockaddr *) &cli_add, &clilen);
		// if(newsockfd < 0)
		// 	error("Error On Accept.\n");
		// bzero(buffer, 1024);
		// n = recv(newsockfd, buffer, 1024, 0);
		// if (n < 0)
		// 	error("Error on reading.\n");
		// std::string buf(buffer, n);
		// httpRequest += buf;
		ReqClass.Parse_Request(httpRequest);
	// }
	// close(newsockfd);
	// close(sockfd);
	return 0;
}



// https://events.teams.microsoft.com/event/afc3f64d-8cb7-4628-985e-e97dce4fc2ca@8301b3bc-3365-44a8-b592-fc43d1c24632