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
	Node() : value(T()), prev(NULL), next(NULL) {};
	Node(const T &value) : value(value), prev(NULL), next(NULL) {};
	Node(const T &value, Node *prev, Node *next) : value(value), prev(prev), next(next) {};
	//Node(const Node &x) { *this = x; };
	//Node &operator=(const Node &x) { value = x.value; prev = x.prev; next = x.next; return (*this); };
	//~Node();
};

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


