/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:32:47 by froussel          #+#    #+#             */
/*   Updated: 2020/07/16 19:46:37 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#include "list.hpp"
#include <list>

#define PRINT_SIZE(lst) std::cout << "Size= " << lst.size();
#define PRINT_LIST(type, lst) for (type::iterator it = lst.begin(); it != lst.end(); ++it) std::cout <<*it<< " ";
#define PRINT(str, value) std::cout << str << ": " << value;
#define LINE std::cout << std::endl;

extern bool output_stream;
extern std::ofstream ft_list;
extern std::ofstream std_list;

//	Modifiers
void		std_push_back()
{
	//std::list<int> mylist;
	//int i = -1;	
	//while (++i < 10)
	//	mylist.push_back (i);
	//PRINT_SIZE(mylist);LINE;
	//PRINT_LIST(std::list<int>, mylist);
}
void		ft_push_back()
{
	ft::list<int>mylist;
	//int i = -1;	
	//while (++i < 10)
	//	mylist.push_back(i);
	//PRINT_SIZE(mylist);LINE;
	//PRINT_LIST(ft::list<int>, mylist);
}
static void	Modifiers()
{
	tester(std_push_back, ft_push_back, "push_back");
}


void		std_begin_end()
{
	int myints[] = {75,23,65,42,13};
	std::list<int> mylist (myints,myints+5);//what it call ?????????????
	std::list<int>::iterator it = mylist.begin();
	++it;
	PRINT("it", *it);


	{
		//std::list<int> mylist;
		//std::list<int>::iterator it = mylist.end();
		//PRINT("*(it--)", *(it));
	}
}
void		ft_begin_end()
{
	int myints[] = {75,23,65,42,13};
	ft::list<int> mylist(myints,myints+5);//what it call ?????????????
	ft::list<int>::iterator it = mylist.begin();
	++it;
	PRINT("it", *it);
	//PRINT_LIST(ft::list<int>, mylist);LINE;

	{
		//ft::list<int> mylist(0);
		//std::list<int>::iterator it = mylist.end();
		//PRINT("*(it--)", *(it));
	}
}
static void	Iterators()
{
	tester(std_begin_end, ft_begin_end, "begin_end");
}

void	list_test()
{
	Modifiers();
	//Iterators();
}
