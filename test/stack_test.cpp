#include "main.hpp"
#include <deque>

static void std_constructor()
{
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	std::vector<int> myvector (2,200);        // vector with 2 elements	
	std::stack<int> first;                    // empty stack
	std::stack<int> second (mydeque);         // stack initialized to copy of deque	
	std::stack<int,std::vector<int> > third;  // empty stack using vector
	std::stack<int,std::vector<int> > fourth (myvector);	
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size();
}
static void ft_constructor()
{
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector (2,200);        // vector with 2 elements	
	ft::stack<int> first;                    // empty stack
	ft::stack<int> second (mydeque);         // stack initialized to copy of deque	
	ft::stack<int,ft::vector<int> > third;  // empty stack using vector
	ft::stack<int,ft::vector<int> > fourth (myvector);	
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size();
}
static void std_empty()
{
	std::stack<int> mystack;
	int sum (0);	
	for (int i=1;i<=10;i++) mystack.push(i);	
	while (!mystack.empty())
	{
	   sum += mystack.top();
	   mystack.pop();
	}	
	std::cout << "total: " << sum;
}
static void ft_empty()
{
	ft::stack<int> mystack;
	int sum (0);	
	for (int i=1;i<=10;i++) mystack.push(i);	
	while (!mystack.empty())
	{
	   sum += mystack.top();
	   mystack.pop();
	}	
	std::cout << "total: " << sum;
}
static void std_size()
{
	std::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';	
	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';	
	myints.pop();
	std::cout << "2. size: " << myints.size();
}
static void ft_size()
{
	ft::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';	
	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';	
	myints.pop();
	std::cout << "2. size: " << myints.size();
}
static void std_top()
{
	std::stack<int> mystack;	
	mystack.push(10);
	mystack.push(20);	
	mystack.top() -= 5;	
	std::cout << "mystack.top() is now " << mystack.top();
}
static void ft_top()
{
	ft::stack<int> mystack;	
	mystack.push(10);
	mystack.push(20);	
	mystack.top() -= 5;	
	std::cout << "mystack.top() is now " << mystack.top();
}
static void std_push_pop()
{
	std::stack<int> mystack;	
	for (int i=0; i<5; ++i) mystack.push(i);	
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
	   std::cout << ' ' << mystack.top();
	   mystack.pop();
	}
}
static void ft_push_pop()
{
	ft::stack<int, ft::list<int> > mystack;	
	for (int i=0; i<5; ++i) mystack.push(i);	
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
	   std::cout << ' ' << mystack.top();
	   mystack.pop();
	}
}
static void std_operators()
{
	std::stack<int> a;
	a.push(10);a.push(20);a.push(30);
	std::stack<int> b;
	b.push(10);b.push(20);b.push(30);
	std::stack<int> c;
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
	ft::stack<int> a;
	a.push(10);a.push(20);a.push(30);
	ft::stack<int> b;
	b.push(10);b.push(20);b.push(30);
	ft::stack<int> c;
	c.push(30);c.push(20);c.push(10);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b";
}

void stack_test()
{
	tester(std_constructor, ft_constructor, "constructor");
	tester(std_empty, ft_empty, "empty");
	tester(std_size, ft_size, "size");
	tester(std_top, ft_top, "top");
	tester(std_push_pop, ft_push_pop, "push_pop");
	tester(std_operators, ft_operators, "operators");
}
