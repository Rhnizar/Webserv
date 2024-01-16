/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:32:29 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/16 11:27:34 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h> // For close function
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Request.hpp"

const int PORT = 808;
const std::string HTML_FILE_PATH = "./Resources/app1/index.html";


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


std::string readHtmlFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (file.is_open())
	{
        std::ostringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
    return "";
}

void handleClient(int clientSocket)
{
    const std::string htmlContent = readHtmlFile(HTML_FILE_PATH);

    std::string response = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/html\r\n"
                           "Content-Length: " + std::to_string(htmlContent.size()) + "\r\n"
                           "\r\n" + htmlContent;

    send(clientSocket, response.c_str(), response.size(), 0);

    // Close the client socket
    close(clientSocket);
}

int main(int argc, char **argv)
{
	Request ReqClass;
	if(argc < 2)
	{
		std::cerr << "Port number Not provided. Program terminated " << std::endl;
		exit(1);
	}
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
	{
        std::cerr << "Error creating socket" << std::endl;
        return EXIT_FAILURE;
    }
	int PORT = atoi(argv[1]);
    // Bind the socket to an address and port
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1)
	{
        std::cerr << "Error binding socket" << std::endl;
        close(serverSocket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 10) == -1)
	{
        std::cerr << "Error listening on socket" << std::endl;
        close(serverSocket);
        return EXIT_FAILURE;
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

	char buffer[1024];
    while (true)
	{
		std::string httpRequest;
        // Accept incoming connections
        sockaddr_in clientAddress;
        socklen_t clientAddressLength = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength);

        if (clientSocket == -1)
		{
            std::cerr << "Error accepting connection" << std::endl;
            continue;
        }

		bzero(buffer, 1024);
        std::cout << "Accepted connection from " << inet_ntoa(clientAddress.sin_addr) << std::endl;
		
		// Hndle Request 

		int n = recv(clientSocket, buffer, 1024, 0);
		if (n < 0)
			error("Error on reading.\n");
		std::string buf(buffer, n);
		httpRequest += buf;
		ReqClass.Parse_Request(httpRequest);

        // Handle the client request ===> response 
        handleClient(clientSocket);
    }

    // Close the server socket
    close(serverSocket);

    return EXIT_SUCCESS;
}
