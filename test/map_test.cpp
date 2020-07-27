#include "main.hpp"
#include "utils.hpp"

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

//	Capacity
static void std_empty()
{
	std::map<char,int> mymap;	
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;	
	while (!mymap.empty())
	{
	  std::cout << mymap.begin()->first << " => " << mymap.begin()->second << " ";
	  mymap.erase(mymap.begin());
	}
}
static void ft_empty()
{/*
	ft::map<char,int> mymap;	
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;	
	while (!mymap.empty())
	{
	  std::cout << mymap.begin()->first << " => " << mymap.begin()->second << " ";
	  mymap.erase(mymap.begin());
	}
*/	
}
static void std_size()
{
	std::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;	
	std::cout << "mymap.size() is " << mymap.size() << std::endl;
	print_const_map(mymap);
}
static void ft_size()
{
	ft::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;	
	std::cout << "mymap.size() is " << mymap.size() << std::endl;
	print_const_map(mymap);
}
static void std_max_size()
{
	int i;
	std::map<int,int> mymap;	
	if (mymap.max_size()>1000)
	{
	  for (i=0; i<1000; i++) mymap[i]=0;
	  std::cout << "The map contains 1000 elements.";
	}
	else std::cout << "The map could not hold 1000 elements.";
}
static void ft_max_size()
{
	int i;
	ft::map<int,int> mymap;	
	if (mymap.max_size()>1000)
	{
	  for (i=0; i<1000; i++) mymap[i]=0;
	  std::cout << "The map contains 1000 elements.";
	}
	else std::cout << "The map could not hold 1000 elements.";
}

static void Capacity()
{
	tester(std_empty, ft_empty, "empty");
	tester(std_size, ft_size, "size");
	tester(std_max_size, ft_max_size, "max_size");
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
	Capacity();
	//Modifiers();

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
