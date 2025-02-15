/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:19:31 by kchaouki          #+#    #+#             */
/*   Updated: 2024/02/11 17:08:45 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ConfigParsing/Parser.hpp"
#include "./ConfigParsing/StringExtensions.hpp"
#include "./Request_Response/TmpServer.hpp"
#include <stdlib.h> // for atoi

int main(int ac, char **av)
{
	if (ac != 3)
		return (std::cout << "Usage: \n\t./webserv [configuration file]" << std::endl, 1);
	try
	{
		server(av[1], atoi(av[2]));
	}
	catch (CustomException ce)
	{
		std::cout << ce.what() << std::endl; 
	}
	return (0);
}
