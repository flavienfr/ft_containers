#ifndef UTILIS_HPP
# define UTILIS_HPP

#include <functional>

namespace ft {

template < class T1, class T2 >
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	first_type	first;
	second_type	second;

	pair() : first(first()), second(second()) {};
	template<class U, class V>
	pair(const pair<U,V> &pr) : first(pr.first), second(pr.first) {};//pas sur
	pair(const first_type &a, const second_type &b) : first(a), second(b) {};
	pair& operator= (const pair& pr)
	{
		first = pr.first;
		second = pr.second;
	};
};

template <class T1, class T2>
pair<T1,T2> make_pair(T1 x, T2 y)
{
	return (pair<T1,T2>(x,y));
}

template <typename Key, typename T>
struct BST_node
{
	pair<Key, T>	item;
	BST_node		*parent;
	BST_node		*left;
	BST_node		*right;

	BST_node() : item(item()), parent(NULL), left(NULL), right(NULL)  {}
	BST_node(const T &item, const BST_node *parent, const BST_node *left, const BST_node *right) :
	item(item), parent(NULL), left(left), right(right) {}
};

template <typename T>
struct Node
{
	T		value;
	Node	*prev;
	Node	*next;

	Node() : value(T()), prev(NULL), next(NULL) {};
	Node(const T &value) : value(value), prev(NULL), next(NULL) {};
	Node(const T &value, Node *prev, Node *next) : value(value), prev(prev), next(next) {};
};


template <typename T>
void	swap_node(T *n1, T *n2)
{
	if (n1->next == n2 && n2->prev == n1)
	{
		T *tmp = n1->prev;

		n1->next = n2->next;
		n1->prev = n2;
		n1->next->prev = n1;

		n2->prev = tmp;
		n2->next = n1;
		n2->prev->next = n2;
	}
	else
	{
		T *tmp_prev = n1->prev;
		T *tmp_next = n1->next;

		n1->next = n2->next;
		n1->prev = n2->prev;
		n1->next->prev = n1;
		n1->prev->next = n1;

		n2->prev = tmp_prev;
		n2->next = tmp_next;
		n2->prev->next = n2;
		n2->next->prev = n2;
	}
}

template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1!=last1)
	{
		if (!(*first1 == *first2))
		  return false;
		++first1; ++first2;
	}
	return true;
}

template <class T> struct equal_to : std::binary_function <T,T,bool>
{
	bool operator() (const T& x, const T& y) const {return x==y;}
};

template <class T> struct less : std::binary_function<T,T,bool>	// keep or delete functinal ?
{
	bool operator() (const T& x, const T& y) const {return x<y;}
};

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1) return false;
		else if (*first1<*first2) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}

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

/* enable_ if */
template <bool Condition, typename T = void>
struct enable_if
{
};
template <typename T>
struct enable_if<true, T>
{
	typedef T type;
};
/* is_integral */
template <typename T>
struct is_integral
{
	static const bool value = false;
};
template <>
struct is_integral<bool>
{
	static const bool value = true;
};
template <>
struct is_integral<char>
{
	static const bool value = true;
};
template <>
struct is_integral<wchar_t>
{
	static const bool value = true;
};
template <>
struct is_integral<signed char>
{
	static const bool value = true;
};
template <>
struct is_integral<short int>
{
	static const bool value = true;
};
template <>
struct is_integral<int>
{
	static const bool value = true;
};
template <>
struct is_integral<long int>
{
	static const bool value = true;
};
template <>
struct is_integral<long long int>
{
	static const bool value = true;
};
template <>
struct is_integral<unsigned char>
{
	static const bool value = true;
};
template <>
struct is_integral<unsigned short int>
{
	static const bool value = true;
};
template <>
struct is_integral<unsigned int>
{
	static const bool value = true;
};
template <>
struct is_integral<unsigned long int>
{
	static const bool value = true;
};
template <>
struct is_integral<unsigned long long int>
{
	static const bool value = true;
};

}

#endif


