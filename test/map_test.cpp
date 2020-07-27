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

//	Element access
static void std_Element_access()
{
	std::map<char,std::string> mymap;
	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];		
	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';		
	std::cout << "mymap now contains " << mymap.size() << " elements.";	
}
static void ft_Element_access()
{
	ft::map<char,std::string> mymap;
	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];		
	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';		
	std::cout << "mymap now contains " << mymap.size() << " elements.";	
}
static void Element_access()
{
	tester(std_Element_access, ft_Element_access, "Element_access");
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
static void std_erase()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;	
	// insert some values:
	//mymap['a']=10;
	//mymap['b']=20;
	//mymap['c']=30;
	//mymap['d']=40;
	//mymap['e']=50;
	//mymap['f']=60;	
	//it=mymap.find('b');
	//mymap.erase (it);                   // erasing by iterator	
	//mymap.erase ('c');                  // erasing by key	
	//it=mymap.find ('e');
	//mymap.erase ( it, mymap.end() );    // erasing by range

	print_const_map(mymap);
}
static void ft_erase()
{
}
static void	Modifiers()
{
	//tester(std_insert, ft_insert, "insert");
	tester(std_erase, ft_erase, "erase");
}

//	Operations
static void std_find()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;	
	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;	
	it = mymap.find('b');
	if (it != mymap.end())
	  mymap.erase (it);	
	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}
static void ft_find()
{/*
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;	
	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;	
	it = mymap.find('b');
	if (it != mymap.end())
	  mymap.erase (it);	
	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
*/}
static void std_count()
{
	std::map<char,int> mymap;
	char c;	
	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;	
	for (c='a'; c<'h'; c++)
	{
	  std::cout << c;
	  if (mymap.count(c)>0)
	    std::cout << " is an element of mymap.\n";
	  else 
	    std::cout << " is not an element of mymap.\n";
	}
}
static void ft_count()
{
	ft::map<char,int> mymap;
	char c;	
	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;	
	for (c='a'; c<'h'; c++)
	{
	  std::cout << c;
	  if (mymap.count(c)>0)
	    std::cout << " is an element of mymap.\n";
	  else 
	    std::cout << " is not an element of mymap.\n";
	}
}
static void Operations()
{
	//tester(std_find, ft_find,"find");
	tester(std_count, ft_count,"count");
}

void map_test()
{
	//Capacity();
	//Element_access();
	Modifiers();
	//Operations();
}
