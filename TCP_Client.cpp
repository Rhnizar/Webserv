/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TCP_Client.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:25:24 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/12/17 18:36:37 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>


int main(int argc, char **argv)
{
	(void)argc;
	// 1. create a socket for the client 
	int CliSockFd = socket(AF_INET, SOCK_STREAM, 0);
	if (CliSockFd == -1)
	{
		std::cerr << "error opening socker." << std::endl;
		exit(1);
	}

	// 2. connect the client to a specific server
	struct sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(atoi(argv[1]));
	if(connect(CliSockFd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1)
	{
		std::cerr << "Faild to connect." << std::endl;
		exit (1);
	}
	// 3. send data to the server
	char buffer[1024] = "Hello Server";
	send(CliSockFd, buffer, strlen(buffer), 0);
	
	// // 4. receive data from the server
	// recv(CliSockFd, buffer, 1024, 0);
	read(CliSockFd, buffer, 1024);
	// std::cout << "The receive data:  " << buffer << std::endl;
	close(CliSockFd);
	return 0;
}