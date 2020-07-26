#include "main.hpp"

#define LINE std::cout << "\n";

template <typename Map>
void print_map(Map &c)
{
	for (typename Map::iterator it = c.begin(); it != c.end(); it++)
		std::cout << "(" << it->first << ", " << it->second << ")" << " ";
}
template <typename Map>
void print_const_map(Map &c)
{
	for (typename Map::const_iterator it = c.begin(); it != c.end(); it++)
		std::cout << "(" << it->first << ", " << it->second << ")" << " ";
}
template <typename Map>
void print_reverse_map(Map &c)
{
	for (typename Map::reverse_iterator it = c.rbegin(); it != c.rend(); it++)
		std::cout << "(" << it->first << ", " << it->second << ")" << " ";
}
template <typename Map>
void print_const_reverse_map(Map &c)
{
	for (typename Map::const_reverse_iterator it = c.rbegin(); it != c.rend(); it++)
		std::cout << "(" << it->first << ", " << it->second << ")" << " ";
}
//	Modifiers

static void std_insert()
{
	{
		std::map<char,int> mymap;

		mymap.insert ( std::pair<char,int>('g',300) );
		mymap.insert ( std::pair<char,int>('g',300) );
		mymap.insert ( std::pair<char,int>('k',500) );
		mymap.insert ( std::pair<char,int>('k',500) );
		mymap.insert ( std::pair<char,int>('g',300) );
		mymap.insert ( std::pair<char,int>('v',58) );
		mymap.insert ( std::pair<char,int>('a',100) );
		mymap.insert ( std::pair<char,int>('y',60) );
		mymap.insert ( std::pair<char,int>('z',200) );
		mymap.insert ( std::pair<char,int>('z',200) );
		mymap.insert ( std::pair<char,int>('z',200) );
		mymap.insert ( std::pair<char,int>('d',190) );
		mymap.insert ( std::pair<char,int>('v',58) );

		print_map(mymap);LINE;
		print_const_map(mymap);LINE;
		print_reverse_map(mymap);LINE;
		print_const_reverse_map(mymap);
	}
}

static void ft_insert()
{
	{
		ft::map<char,int> mymap;

		mymap.insert ( ft::pair<char,int>('g',300) );
		mymap.insert ( ft::pair<char,int>('g',300) );
		mymap.insert ( ft::pair<char,int>('k',500) );
		mymap.insert ( ft::pair<char,int>('k',500) );
		mymap.insert ( ft::pair<char,int>('g',300) );
		mymap.insert ( ft::pair<char,int>('v',58) );
		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('y',60) );
		mymap.insert ( ft::pair<char,int>('z',200) );
		mymap.insert ( ft::pair<char,int>('z',200) );
		mymap.insert ( ft::pair<char,int>('z',200) );
		mymap.insert ( ft::pair<char,int>('d',190) );
		mymap.insert ( ft::pair<char,int>('v',58) );

		print_map(mymap);LINE;
		print_const_map(mymap);LINE;
		print_reverse_map(mymap);LINE;
		print_const_reverse_map(mymap);
	}
}

static void	Modifiers()
{
	tester(std_insert, ft_insert, "insert");
}

void map_test()
{
	Modifiers();

/*
	std::map<int,int> mymap;
	// first insert function version (single parameter):
	mymap.insert ( std::pair<int,int>(1,100) );
	mymap.insert ( std::pair<int,int>(0,200) );	

	if (mymap.begin() == mymap.end())
		std::cout<< "oui\n";
	std::map<int,int>::iterator it = mymap.begin();

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';	*/
}
