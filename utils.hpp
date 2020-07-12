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



}

#endif


