/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:46:16 by froussel          #+#    #+#             */
/*   Updated: 2020/07/23 13:24:07 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#define COUT 0
#define FILE 1

bool output_stream = COUT;
std::ofstream ft_container("ft_container.txt");
std::ofstream std_container("std_container.txt");

int main(int ac, char **av)
{
	if (ac == 2)
		output_stream = atoi(av[1]);

	//vector_test();
	//list_test();
	map_test();
	
	return (0);
}

center_helper<std::string::value_type> centered(const std::string& str)
{ return center_helper<std::string::value_type>(str); }

void	tester(void (*pf_1)(), void (*pf_2)(), std::string text)
{
	std::cout.fill( '-' );
	std::streambuf *coutbuf;

	if (pf_1)
	{
		if (output_stream)
		{
			coutbuf = std::cout.rdbuf(); //save old buf
    		std::cout.rdbuf(std_container.rdbuf());
		}
		std::cout << std::setw(50) << centered(text) << std::endl;
		pf_1();
		std::cout << std::endl;

		if (output_stream)
			std::cout.rdbuf(coutbuf);
	}
	if (pf_2)
	{
		if (output_stream)
		{
			coutbuf = std::cout.rdbuf(); //save old buf
    		std::cout.rdbuf(ft_container.rdbuf());
		}

		std::cout << std::setw(50) /*<< centered("STD vs FT")*/<< "-" << std::endl;
		pf_2();
		std::cout << std::endl;

		if (output_stream)
			std::cout.rdbuf(coutbuf);
	}
}
