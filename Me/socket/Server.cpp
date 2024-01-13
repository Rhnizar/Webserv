/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:03:44 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/13 11:14:09 by rrhnizar         ###   ########.fr       */
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
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_add, &clilen);
	if(newsockfd < 0)
		error("Error On Accept.\n");
	while(1)
	{
		bzero(buffer, 256);
		n = read(newsockfd, buffer, 255);
		if (n < 0)
			error("Error on reading.\n");
		std::cout << "Client : " << buffer << std::endl;
		bzero(buffer, 255);
		fgets(buffer, 255, stdin);
		
		n = write(newsockfd, buffer, strlen(buffer));
		if (n < 0)
			error("Error on writing.\n");
		if(strncmp("Bye", buffer, 3) == 0)
			break;
	}
	close(newsockfd);
	close(sockfd);
	return 0;
}




// int main()
// {
// 	int sockfd;
// 	sockfd = socket(AF_INET, SOCK_STREAM, 0);
// 	sockaddr_in server_add;

// 	server_add.sin_family = AF_INET;
// 	server_add.sin_port = htons(555);
// 	server_add.sin_addr.s_addr = htonl(INADDR_ANY);

// 	if (bind(sockfd, (sockaddr*)&server_add, sizeof(server_add)) == -1)
// 		std::cout << "Error bind \n";
// 	listen(sockfd, 10);
	
// 	// if (connect(sockfd, (struct sockaddr*)&server_add, sizeof(server_add)) == -1)
// 	// {
//     //     std::cout << "Error connecting to client\n";
//     //     return 1;
//     // }

	
// 	char buf[500];
// 	int n;
// 	while (1)
// 	{
// 		bzero(buf, 500);
// 		fgets(buf, 500, stdin);
		
// 		n = write(sockfd, buf, strlen(buf));
		
// 		if (n == -1)
// 			std::cout << "Error Writing to socket" << std::endl;
		
// 		bzero(buf, 500);
// 		n = read(sockfd, buf, 500);
// 		if (n < 0)
// 			 std::cout << "Error reading from  socket" << std::endl;

// 		std::cout << "Server : " << buf << std::endl;
		
// 		if (strncmp("Bye", buf, 3) == 0)
// 			break;
// 	}
	
// 	close(sockfd);
	
// 	return 0;
// }