#include "main.hpp"

template<class map>
void	print_map(map mymap)
{
	typename map::iterator it = mymap.begin();
	while (it != mymap.end())
	{
		std::cout << it->first << " => " << it->second;
		if (++it != mymap.end())
			std::cout << '\n';
	}
}

//	Modifiers
static void std_insert()
{
	std::map<char,int> mymap;	
	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );
	print_map(mymap);

/*	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}	
	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting	
	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));	
	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';	
	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';*/
}
static void ft_insert()
{
	ft::map<char,int> mymap;

	//first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );
	print_map(mymap);
//	ft::pair<ft::map<char,int>::iterator,bool> ret;
//	ret = mymap.insert ( ft::pair<char,int>('z',500) );
//	if (ret.second==false) {
//		std::cout << "element 'z' already existed";
//		std::cout << " with a value of " << ret.first->second << '\n';
//	}
	// second insert function version (with hint position):
/*	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));	
	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';	
	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';*/
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
