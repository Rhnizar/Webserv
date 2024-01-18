/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:51:23 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/18 19:15:50 by rrhnizar         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	Request ReqClass;
	if(argc < 2)
	{
		std::cerr << "Port number Not provided. Program terminated " << std::endl;
		exit(1);
	}
	
	int sockfd, newsockfd, portno, n;
	struct sockaddr_in serv_add, cli_add;
	socklen_t clilen;
	char buffer[1024];
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
	
	while(1)
	{
		std::string httpRequest;
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_add, &clilen);
		if(newsockfd < 0)
			error("Error On Accept.\n");
		bzero(buffer, 1024);
		n = recv(newsockfd, buffer, 1024, 0);
		if (n < 0)
			error("Error on reading.\n");
		std::string buf(buffer, n);
		httpRequest += buf;
		ReqClass.Parse_Request(httpRequest);
		// Handle the client request ===> response 
        ReqClass.Response(newsockfd);

		//response
		// send(newsockfd, "/app1/index.html", 16, 0);
	}
	close(newsockfd);
	close(sockfd);
	return 0;
}



// https://events.teams.microsoft.com/event/afc3f64d-8cb7-4628-985e-e97dce4fc2ca@8301b3bc-3365-44a8-b592-fc43d1c24632