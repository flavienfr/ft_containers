/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:48:51 by froussel          #+#    #+#             */
/*   Updated: 2020/08/08 13:37:20 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static void std_alloc()
{
	std::deque<int> mydeck (3,100);        // deque with 3 elements
	std::list<int> mylist (2,200);         // list with 2 elements	
	std::queue<int> first;                 // empty queue
	std::queue<int> second (mydeck);       // queue initialized to copy of deque	
	std::queue<int,std::list<int> > third; // empty queue with list as underlying container
	std::queue<int,std::list<int> > fourth (mylist);	
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size();	
}
static void ft_alloc()
{
	std::deque<int> mydeck (3,100);        // deque with 3 elements
	ft::list<int> mylist (2,200);         // list with 2 elements
	ft::queue<int> first;                 // empty queue
	ft::queue<int> second (mydeck);       // queue initialized to copy of deque	
	ft::queue<int,ft::list<int> > third; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > fourth (mylist);	
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size();
}
static void std_empty()
{
	std::queue<int> myqueue;
	int sum (0);	
	for (int i=1;i<=10;i++) myqueue.push(i);	
	while (!myqueue.empty())
	{
	   sum += myqueue.front();
	   myqueue.pop();
	}	
	std::cout << "total: " << sum;
}
static void ft_empty()
{
	ft::queue<int> myqueue;
	int sum (0);	
	for (int i=1;i<=10;i++) myqueue.push(i);	
	while (!myqueue.empty())
	{
	   sum += myqueue.front();
	   myqueue.pop();
	}	
	std::cout << "total: " << sum;
}
static void std_size()
{
	std::queue<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';	
	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';	
	myints.pop();
	std::cout << "2. size: " << myints.size();
}
static void ft_size()
{
	ft::queue<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';	
	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';	
	myints.pop();
	std::cout << "2. size: " << myints.size();
}
static void std_front()
{
	std::queue<int> myqueue;	
	myqueue.push(77);
	myqueue.push(16);	
	myqueue.front() -= myqueue.back();    // 77-16=61	
	std::cout << "myqueue.front() is now " << myqueue.front();
}
static void ft_front()
{
	ft::queue<int> myqueue;	
	myqueue.push(77);
	myqueue.push(16);	
	myqueue.front() -= myqueue.back();    // 77-16=61	
	std::cout << "myqueue.front() is now " << myqueue.front();
}
static void std_back()
{
	std::queue<int> myqueue;	
	myqueue.push(12);
	myqueue.push(75);   // this is now the back	
	myqueue.back() -= myqueue.front();	
	std::cout << "myqueue.back() is now " << myqueue.back();
}
static void ft_back()
{
	ft::queue<int> myqueue;	
	myqueue.push(12);
	myqueue.push(75);   // this is now the back	
	myqueue.back() -= myqueue.front();	
	std::cout << "myqueue.back() is now " << myqueue.back();
}
static void std_push_pop()
{
	std::queue<int> myqueue;
	int myint = 0;		
	do {
	  myint += 5;
	  myqueue.push (myint);
	} while (myint < 50);	
	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
	  std::cout << ' ' << myqueue.front();
	  myqueue.pop();
	}
	std::cout << "\nsize= " << myqueue.size();
}
static void ft_push_pop()
{
	ft::queue<int, ft::list<int> > myqueue;
	int myint = 0;		
	do {
	  myint += 5;
	  myqueue.push (myint);
	} while (myint < 50);	
	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
	  std::cout << ' ' << myqueue.front();
	  myqueue.pop();
	}	
	std::cout << "\nsize= " << myqueue.size();
}
static void std_operators()
{
	std::queue<int> a;
	a.push(10);a.push(20);a.push(30);
	std::queue<int> b;
	b.push(10);b.push(20);b.push(30);
	std::queue<int> c;
	c.push(30);c.push(20);c.push(10);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b";
}
static void ft_operators()
{
	ft::queue<int> a;
	a.push(10);a.push(20);a.push(30);
	ft::queue<int> b;
	b.push(10);b.push(20);b.push(30);
	ft::queue<int> c;
	c.push(30);c.push(20);c.push(10);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b";
}

void	queue_test()
{
	tester(std_alloc, ft_alloc, "alloc");
	tester(std_empty, ft_empty, "empty");
	tester(std_size, ft_size, "size");
	tester(std_front, ft_front, "front");
	tester(std_back, ft_back, "back");
	tester(std_push_pop, ft_push_pop, "push_pop");
	tester(std_operators, ft_operators, "operators");
}
