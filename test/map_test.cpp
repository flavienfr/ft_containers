#include "main.hpp"

//#define PRINT_MAP(type, c) for (typemame type::iterator it = c.begin(); it != c.end(); it++) { std::cout << "(" << it->first << ", " << it->second << ")"<< " ";} std::cout << std::endl;

template <typename Map>
void print_map(Map c)
{//std::cout << "what its's going on here !" << c.begin()->first << "\n";
	for (typename Map::iterator it = c.begin(); it != c.end(); it++)
		std::cout << "(" << it->first << ", " << it->second << ")" << " ";
}

//	Modifiers
static void std_insert()
{
	std::map<char,int> mymap;
	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('v',58) );
	mymap.insert ( std::pair<char,int>('d',190) );
	mymap.insert ( std::pair<char,int>('y',60) );
	mymap.insert ( std::pair<char,int>('g',300) );
	mymap.insert ( std::pair<char,int>('k',500) );
	mymap.insert ( std::pair<char,int>('z',200) );

	print_map(mymap);

}
// I NEED TO REPLACE THE HEAD TO THE LESS VALUE KEY 
static void ft_insert()
{
	ft::map<char,int> mymap;

	//first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('v',58) );
	mymap.insert ( ft::pair<char,int>('d',190) );
	mymap.insert ( ft::pair<char,int>('y',60) );
	mymap.insert ( ft::pair<char,int>('g',300) );
	mymap.insert ( ft::pair<char,int>('k',500) );
	mymap.insert ( ft::pair<char,int>('z',200) );

	//std::cout << mymap.begin()->first << std::endl;
	//std::cout << mymap.begin().as_node()->right->item.first << std::endl;
	//std::cout << mymap.begin().as_node()->right->left->item.first << std::endl;
	//std::cout << mymap.begin().as_node()->right->left->right->item.first << std::endl;
	//std::cout << mymap.begin().as_node()->right->right->item.first << std::endl;

	
	//std::cout << (mymap.begin())->first <<" => "<<  (mymap.begin())->second << std::endl;
	//std::cout << (--mymap.end())->first <<" => "<< (--mymap.end())->second << std::endl;
	//print_map(mymap);

	//ft::map<char,int>::iterator it1 = mymap.begin();std::cout << "(" << it1->first << ", " << it1->second << ")" << " ";
	//ft::map<char,int>::iterator it2 = ++it1;std::cout << "(" << it2->first << ", " << it2->second << ")" << " ";
	//ft::map<char,int>::iterator it3 = ++it2;std::cout << "(" << it3->first << ", " << it3->second << ")" << " ";
	//ft::map<char,int>::iterator it4 = ++it3;std::cout << "(" << it4->first << ", " << it4->second << ")" << " ";
	//ft::map<char,int>::iterator it5 = ++it4;std::cout << "(" << it5->first << ", " << it5->second << ")" << " ";

	for (ft::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		std::cout << "(" << it->first << ", " << it->second << ")" << " ";

	//std::cout << mymap.begin()->first <<" => "<<  mymap.begin()->second << std::endl;
	//std::cout << mymap.begin().as_node()->right->item.first <<" => "<<  mymap.begin().as_node()->right->item.second << std::endl;
	//std::cout << mymap.begin().as_node()->right->left->item.first <<" => "<<  mymap.begin().as_node()->right->left->item.second << std::endl;	
	//std::cout << mymap.begin().as_node()->right->right->item.first <<" => "<<  mymap.begin().as_node()->right->right->item.second << std::endl;
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
