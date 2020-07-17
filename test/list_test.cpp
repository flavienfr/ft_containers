/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:32:47 by froussel          #+#    #+#             */
/*   Updated: 2020/07/17 13:30:00 by froussel         ###   ########.fr       */
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
	std::list<int> mylist;
	int i = -1;	
	while (++i < 10)
		mylist.push_back (i);
	PRINT_SIZE(mylist);LINE;
	PRINT_LIST(std::list<int>, mylist);
}
void		ft_push_back()
{
	ft::list<int>mylist;
	int i = -1;	
	while (++i < 10)
		mylist.push_back(i);
	PRINT_SIZE(mylist);LINE;
	PRINT_LIST(ft::list<int>, mylist);
}
static void	Modifiers()
{
	tester(std_push_back, ft_push_back, "push_back");
}


void		std_begin_end()
{
	{
		int myints[] = {75,23,65,42,13};
		std::list<int> mylist (myints,myints+5);		
		std::list<int>::iterator itend = mylist.end();
		PRINT("IT:", *(itend));LINE;
		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it !=itend; ++it)
		  std::cout << ' ' << *it;
	}
	LINE;
	{
		std::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);		
		std::list<int>::reverse_iterator itend = mylist.rend();
		PRINT("IT:", *(itend));LINE;
		std::cout << "mylist backwards:";
		for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=itend; ++rit)
			std::cout << ' ' << *rit;
	}
}
void		ft_begin_end()
{
	{
		int myints[] = {75,23,65,42,13};
		ft::list<int> mylist (myints,myints+5);		
		ft::list<int>::iterator itend = mylist.end();
		PRINT("IT:", *(itend));LINE;
		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it != itend; ++it)
		  std::cout << ' ' << *it;
	}
	LINE;
	{
		ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);		
		ft::list<int>::reverse_iterator itend = mylist.rend();
		PRINT("IT:", *(itend));LINE;
		std::cout << "mylist backwards:";
		for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=itend; ++rit)
			std::cout << ' ' << *rit;	
	}
}

static void	Iterators()
{
	tester(std_begin_end, ft_begin_end, "begin_end");
}

void	list_test()
{
	Modifiers();
	Iterators();

	//ft::list<int> mylist;
	//ft::list<int>::iterator it=mylist.begin();
	//ft::list<int>::iterator it2=mylist.end();
	//PRINT("it:", *(it));LINE;
	//PRINT("it:", *(it2));LINE;
}
