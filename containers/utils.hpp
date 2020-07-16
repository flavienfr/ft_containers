#ifndef UTILIS_HPP
# define UTILIS_HPP

namespace ft {

template <typename T>
struct Node
{
	T		value; // call default constructor ?
	Node	*prev;
	Node	*next;

	//Node() : value(value_type()), prev(NULL), next(NULL) {};
	Node(const T &value) : value(value), prev(NULL), next(NULL) {};
	Node(const T &value, Node *prev, Node *next) : value(value), prev(prev), next(next) {};
	//Node(const Node &x) { *this = x; };
	//Node &operator=(const Node &x) { value = x.value; prev = x.prev; next = x.next; return (*this); };
	//~Node();
};

template <typename T>
void	template_swap(T &a, T &b)
{
	T tmp(a);
	a = b;
	b = tmp;
}

template<typename value_type>
value_type const &min(value_type const &a, value_type const &b)
{
	return (a < b ? a : b);
}

}

#endif


