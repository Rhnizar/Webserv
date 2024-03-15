/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetGet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:29:34 by rrhnizar          #+#    #+#             */
/*   Updated: 2024/02/14 12:34:57 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Test
{
	private:
		std::string Location;
	public:
		std::string getLocation()
		{
			return Location;
		}
		void	setLocation(std::string location)
		{
			Location = location;
		}
		Test(): Location("default")
		{}
		void	PrintGet();
};

void	Test::PrintGet()
{
	std::cout << "Location =  " << getLocation() << std::endl;
}


int main()
{
	Test T;
	T.setLocation("rrrr");
	T.PrintGet();
	return 0;
}