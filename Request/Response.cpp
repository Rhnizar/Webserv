/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:32:29 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/18 19:15:44 by rrhnizar         ###   ########.fr       */
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


std::string root = "./Resources";
std::string readHtmlFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    std::string line;
    std::string res;
	while (std::getline(file, line))
        res += line + "\n";
    return res;
    
    // if (file.is_open())
	// {
    //     std::ostringstream buffer;
    //     buffer << file.rdbuf();
    //     return buffer.str();
    // }
    // return "";
}

void Request::Response(int clientSocket)
{
    // here check file if exist or no
    std::string HTML_FILE_PATH = root + ReqLine.Path + "/index.html";
    const std::string htmlContent = readHtmlFile(HTML_FILE_PATH);

    std::string response = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/html\r\n"
                           "Content-Length: " + std::to_string(htmlContent.size()) + "\r\n"
                           "\r\n" + htmlContent;

    send(clientSocket, response.c_str(), response.size(), 0);

    // std::cout << "\n------------------------------------------------\n";
    // std::cout << htmlContent << std::endl;
    // std::cout << "\n------------------------------------------------\n";
    
    // Close the client socket
    close(clientSocket);
}


//realpath()

// file.rdbuf()
