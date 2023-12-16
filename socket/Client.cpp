/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:03:04 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/12/16 22:51:44 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>



void error(std::string msg)
{
	perror(msg.c_str());
	exit(1);
}

int main(int argc, char **argv)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_add;
    struct hostent *server;

    char buffer[255];
    if(argc < 3)
    {
        std::cerr << "error in arguments \n";
        exit(1);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        error("Error opening socket.\n");
    server = gethostbyname(argv[1]);
    if(!server)
        std::cerr << "Erro , no such host" << std::endl;
    bzero((char *) &serv_add, sizeof(serv_add));

    serv_add.sin_family = AF_INET;
    bcopy((char *) server->h_addr_list[0] , (char *) &serv_add.sin_addr.s_addr, server->h_length);
	serv_add.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr * ) &serv_add , sizeof(serv_add)) < 0)
        error("Connection Failed\n");
    while(1)
    {
        bzero(buffer, 255);
        fgets(buffer, 255, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if(n < 0)
            error("Error on writing.\n");
        bzero(buffer, 255);
        n = read(sockfd, buffer, 255);
        if(n < 0)
            error("Error on reading.\n");
        std::cout << "Server: " << buffer << std::endl;
        if(strncmp("Bye", buffer, 3) == 0)
			break;
    }
    close(sockfd);
    return 0;
}


// int main()
// {
//     int sockfd;
//     sockfd = socket(AF_INET, SOCK_STREAM, 0);
//     sockaddr_in server_add;

//     server_add.sin_family = AF_INET;
//     server_add.sin_port = htons(555);
//     server_add.sin_addr.s_addr = htonl(INADDR_LOOPBACK);  // Connect to localhost

//     if (connect(sockfd, (struct sockaddr*)&server_add, sizeof(server_add)) == -1)
// 	{
//         std::cout << "Error connecting to server\n";
//         return 1;
//     }

//     char buf[500];
//     int n;

//     while (1)
// 	{
//         std::cout << "Enter message: ";
//         bzero(buf, 500);
//         fgets(buf, 500, stdin);

//         n = write(sockfd, buf, strlen(buf));
//         if (n == -1)
// 		{
//             std::cout << "Error writing to socket" << std::endl;
//             break;
//         }

//         bzero(buf, 500);
//         n = read(sockfd, buf, 500);
//         if (n < 0)
// 		{
//             std::cout << "Error reading from socket" << std::endl;
//             break;
//         }

//         std::cout << "Server : " << buf << std::endl;

//         if (strncmp("Bye", buf, 3) == 0)
//             break;
//     }

//     close(sockfd);

//     return 0;
// }
