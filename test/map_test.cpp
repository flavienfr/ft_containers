#include "main.hpp"
#include "utils.hpp"

#define LINE std::cout << "\n";
#define PRINT_SIZE(mymap) std::cout << "Map size = " << mymap.size();

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
{
	ft::map<char,int> mymap;	
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;	
	while (!mymap.empty())
	{
	  std::cout << mymap.begin()->first << " => " << mymap.begin()->second << " ";
	  mymap.erase(mymap.begin());
	}
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
		print_const_reverse_map(mymap);LINE;
		PRINT_SIZE(mymap);
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
		print_const_reverse_map(mymap);LINE;
		PRINT_SIZE(mymap);
	}
}
static void std_erase()
{
	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;	
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;	
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator	
		mymap.erase ('c');                  // erasing by key	
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		print_const_map(mymap);LINE;
		PRINT_SIZE(mymap);
	}
	LINE;
	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator it;	
		mymap['e']=50;
		mymap['c']=30;
		mymap['d']=40;
		mymap['d']=40;
		mymap['k']=40;
		mymap['n']=40;
		mymap['g']=40;
		mymap['a']=10;
		mymap['f']=60;	
		mymap['b']=20;
		it=mymap.find('a');
		mymap.erase (it);                   // erasing by iterator	
		mymap.erase ('c');                  // erasing by key	
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		print_const_map(mymap);LINE;
		PRINT_SIZE(mymap);
	}
}
static void ft_erase()
{
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;	
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;	
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator	
		mymap.erase ('c');                  // erasing by key	
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		print_const_map(mymap);LINE;
		PRINT_SIZE(mymap);
	}
	LINE;
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;	
		mymap['e']=50;
		mymap['c']=30;
		mymap['d']=40;
		mymap['d']=40;
		mymap['k']=40;
		mymap['n']=40;
		mymap['g']=40;
		mymap['a']=10;
		mymap['f']=60;	
		mymap['b']=20;
		it=mymap.find('a');
		mymap.erase (it);                   // erasing by iterator	
		mymap.erase ('c');                  // erasing by key	
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		print_const_map(mymap);LINE;
		PRINT_SIZE(mymap);
	}
}
static void std_swap()
{
	std::map<char,int> foo,bar;	
	foo['x']=100;
	foo['y']=200;	
	bar['a']=11;
	bar['b']=22;
	bar['c']=33;	
	foo.swap(bar);	
	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';	
	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
static void ft_swap()
{
	ft::map<char,int> foo,bar;	
	foo['x']=100;
	foo['y']=200;	
	bar['a']=11;
	bar['b']=22;
	bar['c']=33;	
	foo.swap(bar);	
	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';	
	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
static void std_clear()
{
	std::map<char,int> mymap;	
	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;	
	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';	
	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;	
	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
static void ft_clear()
{
	ft::map<char,int> mymap;	
	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;	
	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';	
	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;	
	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
static void	Modifiers()
{
	//tester(std_insert, ft_insert, "insert");
	tester(std_erase, ft_erase, "erase");
	//tester(std_swap, ft_swap, "swap");
	//tester(std_clear, ft_clear, "clear");
}

//	Observers
static void std_key_comp()
{
	std::map<char,int> mymap;	
	std::map<char,int>::key_compare mycomp = mymap.key_comp();	
	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;	
	std::cout << "mymap contains:\n";	
	char highest = mymap.rbegin()->first;     // key value of last element	
	std::map<char,int>::iterator it = mymap.begin();
	do {
	  std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );	
}
static void ft_key_comp()
{
	ft::map<char,int> mymap;	
	ft::map<char,int>::key_compare mycomp = mymap.key_comp();	
	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;	
	std::cout << "mymap contains:\n";	
	char highest = mymap.rbegin()->first;     // key value of last element	
	ft::map<char,int>::iterator it = mymap.begin();
	do {
	  std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );	
}
static void std_value_comp()
{
	std::map<char,int> mymap;	
	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;	
	std::cout << "mymap contains:\n";	
	std::pair<char,int> highest = *mymap.rbegin();          // last element	
	std::map<char,int>::iterator it = mymap.begin();
	do {
	  std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
}
static void ft_value_comp()
{
	ft::map<char,int> mymap;	
	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;	
	std::cout << "mymap contains:\n";	
	ft::pair<char,int> highest = *mymap.rbegin();          // last element	
	ft::map<char,int>::iterator it = mymap.begin();
	do {
	  std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
}
static void Observers()
{
	tester(std_key_comp, ft_key_comp, "key_comp");
	tester(std_value_comp, ft_value_comp, "value_comp");
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
{
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
}
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
static void std_lower_bound()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;	
	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;	
	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)
	std::cout << "first: " << itlow->first << " second: " << itup->first << "\n";
	mymap.erase(itlow,itup);        // erases [itlow,itup)	
	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
static void ft_upper_bound()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;	
	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;	
	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)
	std::cout << "first: " << itlow->first << " second: " << itup->first << "\n";
	mymap.erase(itlow,itup);        // erases [itlow,itup)	
	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
static void std_equal_range()
{
	std::map<char,int> mymap;	
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;	
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');	
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';	
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second;	
}
static void ft_equal_range()
{
	ft::map<char,int> mymap;	
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;	
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');	
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';	
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second;	
}
static void Operations()
{
	tester(std_find, ft_find,"find");
	tester(std_count, ft_count,"count");
	tester(std_lower_bound, ft_upper_bound,"upper_bound");
	tester(std_equal_range, ft_equal_range,"equal_range");
}

void map_test()
{
	//Capacity();
	//Element_access();
	Modifiers();//clear issue
	//Observers();
	//Operations();
}
