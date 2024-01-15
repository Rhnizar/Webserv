/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:15:17 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/14 12:32:58 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>


void error(std::string msg)
{
	perror(msg.c_str());
	exit(1);
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cerr << "Port number Not provided. Program terminated " << std::endl;
		exit(1);
	}
	
	int sockfd, newsockfd, portno, n;
	char buffer[255];

	struct sockaddr_in serv_add, cli_add;
	socklen_t clilen;

	sockfd = socket(AF_INET, SOCK_STREAM, 6);
	if(sockfd == -1)
		error("Error Opening Socket .\n");
	
	bzero((char *) &serv_add, sizeof(serv_add));
	portno = atoi(argv[1]);

	serv_add.sin_family = AF_INET;

	serv_add.sin_addr.s_addr = INADDR_ANY;
	serv_add.sin_port = htons(portno);

	if(bind(sockfd, (struct sockaddr *) &serv_add, sizeof(serv_add)) < 0)
		error("Binding Failed .\n");

	listen(sockfd, 5);
	clilen = sizeof(cli_add);
	while(1)
	{
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_add, &clilen);
		if(newsockfd < 0)
			error("Error On Accept.\n");
		bzero(buffer, 256);
		n = read(newsockfd, buffer, 255);
		if (n < 0)
			error("Error on reading.\n");
		
		std::cout << "\n" <<  buffer << std::endl;
		// bzero(buffer, 255);
		// fgets(buffer, 255, stdin);
		
		// n = write(newsockfd, buffer, strlen(buffer));
		// if (n < 0)
		// 	error("Error on writing.\n");
	}
	close(newsockfd);
	close(sockfd);
	return 0;
}