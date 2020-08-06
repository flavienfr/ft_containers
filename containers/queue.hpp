/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:48:57 by froussel          #+#    #+#             */
/*   Updated: 2020/08/06 17:16:12 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>

namespace ft {

template <class T, class Container = std::deque<T> >
class queue
{
public:
	typedef T			value_type;
	typedef Container 	container_type;
	typedef size_t		size_type;

private:
	container_type ctn;

public:
	//	Allocation
	explicit queue (const container_type &ctnr = container_type())
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
	value_type& front()
	{
		return (ctn.front());
	}
	const value_type& front() const
	{
		return (ctn.front());
	}
	value_type& back()
	{
		return (ctn.back());
	}
	const value_type& back() const
	{
		return (ctn.back());
	}
	void push (const value_type& val)
	{
		ctn.push_back(val);
	}
	void pop()
	{
		ctn.pop_front();
	}

	//	Non-member function overloads
	friend bool operator== (const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.ctn == rhs.ctn);
	}
	friend bool operator!= (const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.ctn != rhs.ctn);
	}
	friend bool operator<  (const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.ctn < rhs.ctn);
	}
	friend bool operator<= (const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.ctn <= rhs.ctn);
	}
	friend bool operator>  (const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.ctn > rhs.ctn);
	}
	friend bool operator>= (const queue<T,Container> &lhs, const queue<T,Container> &rhs)
	{
		return (lhs.ctn >= rhs.ctn);
	}
};

} //namespace
