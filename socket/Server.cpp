/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:03:44 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/12/15 09:33:06 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

int main()
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in server_add;

	server_add.sin_family = AF_INET;
	server_add.sin_port = htons(555);
	server_add.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockfd, (sockaddr*)&server_add, sizeof(server_add)) == -1)
		std::cout << "Error bind \n";
	listen(sockfd, 10);
	
	char buf[500];
	int n;
	while (1)
	{
		bzero(buf, 500);
		fgets(buf, 500, stdin);
		
		buf[strlen(buf) - 1] = '\0';
		
		// std::cout << "===>  " << buf << "  sockfd    " << sockfd << std::endl;
		n = write(3, "rrr", 3);
		if (n < 0)
		{
			std::cout << &perror << std::endl;
			std::cout << "Error Writing to socket" << std::endl;
		}
		else
			std::cout << "success !!!!" << std::endl;
		// bzero(buf, 500);
		// n = read(sockfd, buf, 500);
		// if (n < 0)
		// 	 std::cout << "Error reading from  socket" << std::endl;

		// std::cout << "Server : " << buf << std::endl;
		
		// if (strncmp("Bye", buf, 3) == 0)
		// 	break;
		
		// std::string str;
		// int clfd = accept(sockfd, 0, 0);
		// while (1)
		// {
		// 	int re = read(clfd, buf, 5000);
		// 	buf[re] = 0;
		// 	str += buf;
		// 	if (re < 0 || re != 5000)
		// 		break ;
		// 	else if (re == 5000)
		// 		continue;
		// }
		// std::cout << buf << std::endl;
	}
	return 0;
}