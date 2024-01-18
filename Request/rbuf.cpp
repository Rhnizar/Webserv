/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbuf.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:54:45 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/01/17 14:33:49 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, char ** argv)
{
	std::ifstream	inputFile;//Declare a file stream object:
	std::ostringstream buffer;
	inputFile.open(argv[1]);
	if (inputFile.is_open())//Check if the file was successfully opened:
        buffer << inputFile.rdbuf();
	std::cout << buffer.str();
	return 0;
}