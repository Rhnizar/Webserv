/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:05:37 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/12/16 23:46:33 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

int main()
{
	sockaddr;
	
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_add;
	
	server_add.sin_family = AF_INET;
	server_add.sin_port = htons(999);
	server_add.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(fd, (sockaddr*)&server_add, sizeof(server_add)) == -1)
		std::cout << "Error bind \n";
	listen(fd, 10);
	char buf[5000];
	while (1)
	{
		// check is inside in this fd content the request or no 
		int c = accept(fd, 0, 0);
		if(c == -1)
		{
			std::cout << "continue;";
			continue;
		}
		else
		{
			// sleep(2);
			std::string str;
			std::string str1;
			while (1)
			{
				int re = read(c, buf, 5000);
				buf[re] = 0;
				str += buf;
				if (re < 0 || re != 5000)
					break ;
				else if (re == 5000)
					continue;
			}
			std::cout << str << std::endl;
			
			std::cout << "\n=----------------------=\n";
			std::cout << "c   " << c << "   fd    " << fd << std::endl;
			while (1)
			{
				int re = read(fd, buf, 5000);
				buf[re] = 0;
				str1 += buf;
				if (re < 0 || re != 5000)
					break ;
				else if (re == 5000)
					continue;
			}
			std::string line = "HTTP/1.1 200 OK\r\nContent-Type: text/HTML\r\nContent- Length: 100\r\n\r\nTest";
			write (c, line.c_str(), line.length());
			std::cout << str1 << std::endl;
		}
	}
	return 0;
}