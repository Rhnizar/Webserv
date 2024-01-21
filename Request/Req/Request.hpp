/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:53:17 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/19 18:13:43 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <cstring>

struct RequestLine
{
	std::string Method;
	std::string Path;
	std::string HttpVersion;
};

class Request
{
	public:
		int checkRef;
		Request();
		RequestLine ReqLine;
		void	Parse_Request(std::string request);
		void	Parse_ReqLine(std::string line);
		void	Response(int clientSocket);
		
};
#endif