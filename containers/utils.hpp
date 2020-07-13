#ifndef UTILIS_HPP
# define UTILIS_HPP

namespace ft {

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


