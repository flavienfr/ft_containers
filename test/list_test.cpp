/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:32:47 by froussel          #+#    #+#             */
/*   Updated: 2020/07/20 18:42:25 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#include <cmath>

#define PRINT_SIZE(lst) std::cout << "Size= " << lst.size();
#define PRINT_LIST(type, lst) for (type::iterator it = lst.begin(); it != lst.end(); ++it) std::cout <<*it<< " ";
#define PRINT_LIST_CONST(type, lst) for (type::const_iterator it = lst.begin(); it != lst.end(); ++it) std::cout <<*it<< " ";
#define PRINT_LIST_REVERSE(type, lst) for (type::reverse_iterator it = lst.rbegin(); it != lst.rend(); ++it) std::cout <<*it<< " ";
#define PRINT_LIST_REVERSE_CONST(type, lst) for (type::const_reverse_iterator it = lst.rbegin(); it != lst.rend(); ++it) std::cout <<*it<< " ";
#define PRINT(str, value) std::cout << str << ": " << value;
#define LINE std::cout << std::endl;

extern bool output_stream;
extern std::ofstream ft_list;
extern std::ofstream std_list;

//	Iterators
static void	std_begin_end()
{
	{
		int myints[] = {75,23,65,42,13};
		std::list<int> mylist (myints,myints+5);		
		std::list<int>::iterator itend = mylist.end();
		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it !=itend; ++it)
		  std::cout << ' ' << *it;
	}
	LINE;
	{
		std::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);		
		std::list<int>::reverse_iterator itend = mylist.rend();
		std::cout << "mylist backwards:";
		for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=itend; ++rit)
			std::cout << ' ' << *rit;
	}
}
static void	ft_begin_end()
{
	{
		int myints[] = {75,23,65,42,13};
		ft::list<int> mylist (myints,myints+5);		
		ft::list<int>::iterator itend = mylist.end();
		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it != itend; ++it)
		  std::cout << ' ' << *it;
	}
	LINE;
	{
		ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);		
		ft::list<int>::reverse_iterator itend = mylist.rend();
		std::cout << "mylist backwards:";
		for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=itend; ++rit)
			std::cout << ' ' << *rit;	
	}
}
static void std_const_iterator()
{
	std::list<double>lst;
	lst.push_front(1);
	lst.push_front(0);
	lst.push_front(0);
	lst.push_front(1);
	PRINT_LIST_CONST(std::list<double>, lst);
}
static void ft_const_iterator()
{
	ft::list<double>lst;
	lst.push_front(1);
	lst.push_front(0);
	lst.push_front(0);
	lst.push_front(1);
	//for (ft::list<double>::const_iterator it = lst.begin(); it != lst.end(); ++it)
	//	std::cout <<*it<< " ";
	//PRINT_LIST_CONST(ft::list<double>, lst);
}
static void	Iterators()
{
	tester(std_begin_end, ft_begin_end, "begin_end");
	tester(std_const_iterator, ft_const_iterator, "const_iterator");
}

//	Capacity
static void	std_max_size()
{
	std::list<int>vec;
	std::cout << vec.max_size() << std::endl;	
	std::list<char>vec2;
	std::cout << vec2.max_size() << std::endl;
	std::list<float>vec3;
	std::cout << vec3.max_size() << std::endl;
	std::list<std::string>vec4;
	std::cout << vec4.max_size() << std::endl;
	ft::vector<bool>vec5;
	std::cout << vec5.max_size();
}
static void	ft_max_size()
{
	ft::list<int>vec;
	std::cout << vec.max_size() << std::endl;	
	ft::list<char>vec2;
	std::cout << vec2.max_size() << std::endl;
	ft::list<float>vec3;
	std::cout << vec3.max_size() << std::endl;
	ft::list<std::string>vec4;
	std::cout << vec4.max_size() << std::endl;
	ft::vector<bool>vec5;
	std::cout << vec5.max_size();
}
static void Capacity()
{
	tester(std_max_size, ft_max_size, "max_size");
}

//	Element access
static void	std_front_back()
{
	{
		std::list<int> mylist;		
		mylist.push_back(77);
		mylist.push_back(22);		
		// now front equals 77, and back 22		
		mylist.front() -= mylist.back();		
		std::cout << "mylist.front() is now " << mylist.front();
	}
	LINE;
	{
		std::list<int> mylist;		
		mylist.push_back(10);		
		while (mylist.back() != 0)
		{
		  mylist.push_back ( mylist.back() -1 );
		}		
		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
		  std::cout << ' ' << *it;
	}
}
static void	ft_front_back()
{
	{
		ft::list<int> mylist;		
		mylist.push_back(77);
		mylist.push_back(22);		
		// now front equals 77, and back 22		
		mylist.front() -= mylist.back();		
		std::cout << "mylist.front() is now " << mylist.front();
	}
	LINE;
	{
		ft::list<int> mylist;		
		mylist.push_back(10);		
		while (mylist.back() != 0)
		{
		  mylist.push_back ( mylist.back() -1 );
		}		
		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
		  std::cout << ' ' << *it;
	}
}
static void	Element_access()
{
	tester(std_front_back, ft_front_back, "font_back");
}

//	Modifiers
static void	std_assign()
{
	std::list<int> first;
	std::list<int> second;	
	first.assign (7,100);                      // 7 ints with value 100	
	second.assign (first.begin(),first.end()); // a copy of first	
	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array	
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size());
}
static void	ft_assign()
{
	ft::list<int> first;
	ft::list<int> second;	
	first.assign (7,100);                      // 7 ints with value 100	
	second.assign (first.begin(),first.end()); // a copy of first	
	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array	
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size());
}
static void	std_push_pop_front()
{
	{
		std::list<int> mylist (2,100);         // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);	
		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
	}
	LINE;
	{
		std::list<int> mylist;
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);	
		std::cout << "Popping out the elements in mylist:";
		while (!mylist.empty())
		{
		  std::cout << ' ' << mylist.front();
		  mylist.pop_front();
		}	
		std::cout << "\nFinal size of mylist is " << mylist.size();
	}
}
static void	ft_push_pop_front()
{
	{
		ft::list<int> mylist (2,100);         // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);	
		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
	}
	LINE;
	{
		ft::list<int> mylist;
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);	
		std::cout << "Popping out the elements in mylist:";
		while (!mylist.empty())
		{
		  std::cout << ' ' << mylist.front();
		  mylist.pop_front();
		}	
		std::cout << "\nFinal size of mylist is " << mylist.size();
	}
}
static void	std_push_pop_back()
{
	{
		std::list<int> mylist;
		int i = -1;	
		while (++i < 10)
			mylist.push_back (i);
		PRINT_SIZE(mylist);LINE;
		PRINT_LIST(std::list<int>, mylist);
	}
	LINE;
	{
		std::list<int> mylist;
		int sum (0);
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);		
		while (!mylist.empty())
		{
		  sum+=mylist.back();
		  mylist.pop_back();
		}		
		std::cout << "The elements of mylist summed " << sum;
	}
}
static void	ft_push_pop_back()
{
	{
		ft::list<int> mylist;
		int i = -1;	
		while (++i < 10)
			mylist.push_back (i);
		PRINT_SIZE(mylist);LINE;
		PRINT_LIST(ft::list<int>, mylist);
	}
	LINE;
	{
		ft::list<int> mylist;
		int sum (0);
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);		
		while (!mylist.empty())
		{
			sum+=mylist.back();
			mylist.pop_back();
		}		
		std::cout << "The elements of mylist summed " << sum;
	}
}
static void std_insert()
{
	std::list<int> mylist;
	std::list<int>::iterator it;	
	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i);
	it = mylist.begin();
	++it;
	mylist.insert (it,10);
	PRINT_LIST(std::list<int>, mylist);LINE;PRINT("size: ", mylist.size());LINE;
	mylist.insert (it,2,20);
	PRINT_LIST(std::list<int>, mylist);LINE;PRINT("size: ", mylist.size());LINE;
	--it;
	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
	PRINT_LIST(std::list<int>, mylist);LINE;PRINT("size: ", mylist.size())
}
static void ft_insert()
{
	ft::list<int> mylist;
	ft::list<int>::iterator it;	
	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i);
	it = mylist.begin();
	++it;
	mylist.insert (it,10);
	PRINT_LIST(ft::list<int>, mylist);LINE;PRINT("size: ", mylist.size());LINE;
	mylist.insert (it,2,20);
	PRINT_LIST(ft::list<int>, mylist);LINE;PRINT("size: ", mylist.size());LINE;
	--it;
	ft::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
	PRINT_LIST(ft::list<int>, mylist);LINE;PRINT("size: ", mylist.size())
}
static void std_erase()
{
	std::list<int> mylist;
	std::list<int>::iterator it1,it2;	
	// set some values:
	for (int i=1; i<10; ++i) mylist.push_back(i*10);	
	it1 = it2 = mylist.begin(); 
	//std::advance (it2,6);
	++it1;
	it1 = mylist.erase (it1);
	PRINT_LIST(std::list<int>, mylist);LINE;PRINT("size: ", mylist.size());LINE;
	it2 = mylist.erase (it2);
	PRINT_LIST(std::list<int>, mylist);LINE;PRINT("size: ", mylist.size());LINE;
	++it1;
	--it2;
	mylist.erase (it1,it2);
	PRINT_LIST(std::list<int>, mylist);LINE;PRINT("size: ", mylist.size());
}
static void ft_erase()
{
	ft::list<int> mylist;
	ft::list<int>::iterator it1,it2;	
	// set some values:
	for (int i=1; i<10; ++i) mylist.push_back(i*10);
	it1 = it2 = mylist.begin(); 
	//std::advance(it2,6);
	++it1;
	it1 = mylist.erase (it1);
	PRINT_LIST(ft::list<int>, mylist);LINE;PRINT("size: ", mylist.size());LINE;
	it2 = mylist.erase (it2);
	PRINT_LIST(ft::list<int>, mylist);LINE;PRINT("size: ", mylist.size());LINE;
	++it1;
	--it2;
	mylist.erase (it1,it2);
	PRINT_LIST(ft::list<int>, mylist);LINE;PRINT("size: ", mylist.size());
}
static void std_swap()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200	
	foo.swap(bar);
	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
	  std::cout << ' ' << foo[i];
	std::cout << '\n';
	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
	  std::cout << ' ' << bar[i];
}
static void ft_swap()
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200	
	foo.swap(bar);
	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
	  std::cout << ' ' << foo[i];
	std::cout << '\n';
	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
	  std::cout << ' ' << bar[i];
}
static void std_resize()
{
	std::list<int> mylist;	
	// set some initial content:
	for (int i=1; i<10; ++i) mylist.push_back(i);	
	mylist.resize(5);
	mylist.resize(8,100);
	mylist.resize(12);	
	PRINT_LIST(std::list<int>, mylist);
}
static void ft_resize()
{
	ft::list<int> mylist;	
	// set some initial content:
	for (int i=1; i<10; ++i) mylist.push_back(i);	
	mylist.resize(5);
	mylist.resize(8,100);
	mylist.resize(12);	
	PRINT_LIST(ft::list<int>, mylist);
}
static void	Modifiers()
{
	tester(std_assign, ft_assign, "assign");
	tester(std_push_pop_front, ft_push_pop_front, "push_pop_front");
	tester(std_push_pop_back, ft_push_pop_back, "push_pop_back");
	tester(std_insert, ft_insert, "insert");
	tester(std_erase, ft_erase, "erase");
	tester(std_swap, ft_swap, "swap");
	tester(std_resize, ft_resize, "resize");
}

//	Operations
static void std_splice()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;	

	for (int i=1; i<=4; ++i)
	   mylist1.push_back(i);
	for (int i=1; i<=3; ++i)
	   mylist2.push_back(i*10);
	it = mylist1.begin();
	++it;
	mylist1.splice (it, mylist2);
	PRINT_LIST(std::list<int>, mylist1);LINE;
	PRINT_LIST(std::list<int>, mylist2);LINE;

	mylist2.splice (mylist2.begin(),mylist1, it);
	PRINT_LIST(std::list<int>, mylist1);LINE;
	PRINT_LIST(std::list<int>, mylist2);LINE;

	it = mylist1.begin();
	++it;++it;++it;
	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
	PRINT_LIST(std::list<int>, mylist1);LINE;
	PRINT_LIST(std::list<int>, mylist2);LINE;
	PRINT("size=", mylist1.size());
}
static void ft_splice()
{
	ft::list<int> mylist1, mylist2;
	ft::list<int>::iterator it;	

	for (int i=1; i<=4; ++i)
	   mylist1.push_back(i);
	for (int i=1; i<=3; ++i)
	   mylist2.push_back(i*10);
	it = mylist1.begin();
	++it;
	mylist1.splice (it, mylist2);
	PRINT_LIST(ft::list<int>, mylist1);LINE;
	PRINT_LIST(ft::list<int>, mylist2);LINE;

	mylist2.splice (mylist2.begin(),mylist1, it);
	PRINT_LIST(ft::list<int>, mylist1);LINE;
	PRINT_LIST(ft::list<int>, mylist2);LINE;

	it = mylist1.begin();
	++it;++it;++it;
	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
	PRINT_LIST(ft::list<int>, mylist1);LINE;
	PRINT_LIST(ft::list<int>, mylist2);LINE;
	PRINT("size=", mylist1.size());
}
static void std_remove()
{
	int myints[]= {17,89,7,14};
	std::list<int>mylist (myints,myints+4);	
	mylist.remove(89);
	PRINT_LIST(std::list<int>, mylist);
}
static void ft_remove()
{
	int myints[]= {17,89,7,14};
	ft::list<int>mylist (myints,myints+4);	
	mylist.remove(89);
	PRINT_LIST(ft::list<int>, mylist);
}
bool single_digit (const int &value) { return (value<10); }
struct is_odd { bool operator() (const int &value) { return (value%2)==1; }};
static void std_remove_if()
{
	int myints[]= {15,36,7,17,20,39,4,1};
	std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1	
	mylist.remove_if (single_digit);           // 15 36 17 20 39	
	mylist.remove_if (is_odd());               // 36 20	
	PRINT_LIST(std::list<int>, mylist);
}
static void ft_remove_if()
{
	int myints[]= {15,36,7,17,20,39,4,1};
	ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1	
	mylist.remove_if (single_digit);           // 15 36 17 20 39	
	mylist.remove_if (is_odd());               // 36 20	
	PRINT_LIST(ft::list<int>, mylist);
}
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }
struct is_near { bool operator() (double first, double second) { return (fabs(first-second)<5.0); } };
static void std_unique()
{
	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
	                     12.77, 73.35, 72.25, 15.3,  72.25 };
	std::list<double> mylist (mydoubles,mydoubles+10);

	mylist.sort();
	mylist.unique();
	mylist.unique (same_integral_part);
	mylist.unique (is_near());
	PRINT_LIST(std::list<double>, mylist);
}
static void ft_unique()
{
	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
	                     12.77, 73.35, 72.25, 15.3,  72.25 };
	ft::list<double> mylist (mydoubles,mydoubles+10);
	
	mylist.sort();
	mylist.unique();
	mylist.unique (same_integral_part);
	mylist.unique (is_near());
	PRINT_LIST(ft::list<double>, mylist);
}
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}
static void std_sort()
{
	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");	
	mylist.sort();	
	PRINT_LIST(std::list<std::string>, mylist);LINE;
	mylist.sort(compare_nocase);
	PRINT_LIST(std::list<std::string>, mylist);
}
static void ft_sort()
{
	ft::list<std::string> mylist;
	ft::list<std::string>::iterator it;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");	
	mylist.sort();	
	PRINT_LIST(ft::list<std::string>, mylist);LINE;
	mylist.sort(compare_nocase);
	PRINT_LIST(ft::list<std::string>, mylist);
}
static void std_reverse()
{
	std::list<int> mylist;	
	for (int i=1; i<9; ++i) mylist.push_back(i);	
	mylist.reverse();
	
	//for (std::list<int>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)
	//	std::cout <<*it<< " ";
	//LINE;
	PRINT_LIST_CONST(std::list<int>, mylist);LINE;
	PRINT_LIST_REVERSE(std::list<int>, mylist);
}
static void ft_reverse()
{
	ft::list<int> mylist;	
	for (int i=1; i<9; ++i) mylist.push_back(i);
	mylist.reverse();
	//for (ft::list<int>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)
	//	std::cout <<*it<< " ";
	//LINE;
	PRINT_LIST(ft::list<int>, mylist);LINE;
	PRINT_LIST_REVERSE(ft::list<int>, mylist);
}
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }
static void std_merge()
{
	std::list<double> first, second;	
	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);	
	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);	
	first.sort();
	second.sort();
	PRINT_LIST(std::list<double>, first);LINE;
	PRINT_LIST(std::list<double>, second);LINE;
	first.merge(second);
	PRINT_LIST(std::list<double>, first);LINE;
	PRINT_LIST(std::list<double>, second);LINE;
	second.push_back (2.1);	
	first.merge(second, mycomparison);
	PRINT_LIST(std::list<double>, first);LINE;
	PRINT_LIST(std::list<double>, second);
}
static void ft_merge()
{
	ft::list<double> first, second;	
	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);	
	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);	
	first.sort();
	second.sort();
	PRINT_LIST(ft::list<double>, first);LINE;
	PRINT_LIST(ft::list<double>, second);LINE;
	first.merge(second);
	PRINT_LIST(ft::list<double>, first);LINE;
	PRINT_LIST(ft::list<double>, second);LINE;
	second.push_back (2.1);	
	first.merge(second, mycomparison);
	PRINT_LIST(ft::list<double>, first);LINE;
	PRINT_LIST(ft::list<double>, second);
}
static void	Operations()
{
	tester(std_splice, ft_splice, "slice");
	tester(std_remove, ft_remove, "remove");
	tester(std_remove_if, ft_remove_if, "remove_if");
	tester(std_unique, ft_unique, "unique");
	tester(std_sort, ft_sort, "sort");
	tester(std_reverse, ft_reverse, "reverse");
	tester(std_merge, ft_merge, "merge");
}

//	Non-member function overloads
static void std_operators()
{
	std::list<int> a;
	a.push_back(10);a.push_back(20);a.push_back(30);
	std::list<int> b;
	b.push_back(10);b.push_back(20);b.push_back(30);
	std::list<int> c;
	c.push_back(30);c.push_back(20);c.push_back(10);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b";
}
static void ft_operators()
{
	ft::list<int> a;
	a.push_back(10);a.push_back(20);a.push_back(30);
	ft::list<int> b;
	b.push_back(10);b.push_back(20);b.push_back(30);
	ft::list<int> c;
	c.push_back(30);c.push_back(20);c.push_back(10);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b";
}
static void Non_member()
{
	tester(std_operators, ft_operators, "operators");
}

void	list_test()
{
	Iterators();
	Capacity();
	Element_access();
	Modifiers();
	Operations();
	Non_member();
}
