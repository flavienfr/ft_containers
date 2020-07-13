/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:49:22 by froussel          #+#    #+#             */
/*   Updated: 2020/07/13 18:59:37 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>		// allocator
//# include <stdexcept>	// exeption throw
//# include <iostream>	// std::cout debug
//# include <limits>	// limits
# include "utils.hpp"	// node


namespace ft {

template < typename T, typename Alloc = std::allocator<T> >
class list
{
public:
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	//typedef Iterator<T>									iterator;
	//typedef Iterator<const T>							const_iterator;
	//typedef ReverseIterator<T>							reverse_iterator;
	//typedef ReverseIterator<const T>					const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

private:
	Node<T>				*_list;
	size_type			_size;
	size_type			_capacity;
	allocator_type		_alloc;
	
	typedef typename Alloc::template rebind<Node>::other node_alloc;

public:
	//	Constructor Destructor Assignator
	explicit list(const allocator_type &alloc = allocator_type());	//default (1)
	explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()); //fill (2)
	template <class InputIterator>
	list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()); //range (3)
	list(const list& x); //copy (4)
};

template <typename T, typename Alloc> //default (1)
list<T, Alloc>::list(const allocator_type &alloc) :
_list(NULL), _size(0), _capacity(0), _alloc(alloc)
{
}
template <typename T, typename Alloc> //fill (2)
list<T, Alloc>::list(size_type n, const value_type &val, const allocator_type &alloc) :
_size(n), _capacity(n), _alloc(alloc)
{
	for (size_type i = 0; i < _size; i++)
	//	node_alloc(, 1); need to fin expression to write  https://github.com/luismeyer95/ft_containers/blob/master/List.hpp
	//_alloc.node_alloc();
}

} // namespace

#endif
 