/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TCP_Server.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:44:12 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/12/17 18:19:14 by rrhnizar         ###   ########.fr       */
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
	// 1. Create a socker for the server 
	int serverSocketFd = socket(AF_INET, SOCK_STREAM, 0);
	if(serverSocketFd == -1)
	{
		std::cerr << "Error opening socket ." << std::endl;
		exit(1);
	}
	// 2. Bind this socker to a specific port number 

	struct sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(atoi(argv[1]));

	if (bind(serverSocketFd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1)
	{
		std::cerr << "Binding Failed " << std::endl;
		exit(1);
	}
	// 3. listen to the clients connection requests
	
	listen(serverSocketFd, 5);
	// 4. accept the connection request

	struct sockaddr_in cli_add;
	// memset(&cli_add, 0, sizeof(cli_add));
	socklen_t cliAddressLenght = sizeof(cli_add);
	int newSockFd = accept(serverSocketFd, (struct sockaddr *) &cli_add, &cliAddressLenght);
	if (newSockFd == -1)
	{
		std::cerr << "Failed to accept a connection request." << std::endl;
		exit(1);
	}
	// 5. send or receieve data from the client 
	char recievMsg[1024];
	memset(recievMsg, 0, sizeof(recievMsg));
	recv(newSockFd, recievMsg, 1024, 0);
	std::cout  << recievMsg << std::endl;
	// 6. close the socket

	while (1)
	{
		/* code */
	}
	
	close(newSockFd);
	close(serverSocketFd);
	return 0;
}