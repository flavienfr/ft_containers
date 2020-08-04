/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:09:19 by froussel          #+#    #+#             */
/*   Updated: 2020/08/04 15:04:43 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <deque>

namespace ft {

template <class T, class Container = std::deque<T> >
class stack
{
public:
	typedef T			value_type;
	typedef Container 	container_type;
	typedef size_t		size_type;

private:
	container_type ctn;

public:
	//	Allocation
	explicit stack (const container_type &ctnr = container_type())
	{
		ctn = ctnr;
	}

	// Member functions
	bool empty() const
	{
		return (ctn.empty());
	}
	size_type size() const
	{
		return (ctn.size());
	}
	value_type& top()
	{
		return (ctn.back());
	}
	const value_type& top() const
	{
		return (ctn.back());
	}
	void push (const value_type &val)
	{
		ctn.push_back(val);
	}
	void pop()
	{
		ctn.pop_back();
	}
};

template <class T, class Container>
bool operator== (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
{
	return (lhs.ctn == rhs.ctn);
}
template <class T, class Container>
bool operator!= (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
{
	return (lhs.ctn != rhs.ctn);
}
template <class T, class Container>
bool operator<  (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
{
	return (lhs.ctn < rhs.ctn);
}
template <class T, class Container>
bool operator<= (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
{
	return (lhs.ctn <= rhs.ctn);
}
template <class T, class Container>
bool operator>  (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
{
	return (lhs.ctn > rhs.ctn);
}
template <class T, class Container>
bool operator>= (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
{
	return (lhs.ctn >= rhs.ctn);
}

} //namespace
