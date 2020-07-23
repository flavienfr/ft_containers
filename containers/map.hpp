/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:09:13 by froussel          #+#    #+#             */
/*   Updated: 2020/07/23 15:40:59 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>			// allocator
//# include <stdexcept>		// exeption throw
# include <iostream>		// std::cout debug
//# include <limits>		// limits
# include "utils.hpp"		// node
# include "iterators.hpp"	// iterators

namespace ft {

template <typename T, typename CT>// add compare
class MapIt : public MapBaseIt<T>
{
public:
	typedef T			value_type;
	typedef ptrdiff_t	difference_type;
	typedef CT *		pointer;
	typedef CT &		reference;

	MapIt() : MapBaseIt<T>(NULL) { };
	MapIt(Node<T> *ptr) : MapBaseIt<T>(ptr) { };
	MapIt(const MapBaseIt<T> &it) : MapBaseIt<T>(it.as_node()) { };
	MapIt &operator=(const MapIt &it) { this->_ptr = it._ptr; return (*this); };
	virtual ~MapIt() { };

	reference operator*() { return (this->_ptr->item); };
	pointer operator->() { return (&this->_ptr->item); };

	MapIt &operator++()
	{
		if (this->_ptr->parent == NULL)
			return (iterator(this->_ptr));
		if (this->_ptr->right == NULL)
			return (iterator(this->_ptr));
		
		//this->_ptr = this->_ptr->next; return (*this); 
	}
	MapIt operator++(int) { MapIt tmp = *this; this->_ptr = this->_ptr->next; return (tmp);};

	MapIt &operator--() { this->_ptr = this->_ptr->prev; return (*this); };
	MapIt operator--(int) { MapIt tmp = *this; this->_ptr = this->_ptr->prev; return (tmp); };
};

template < class Key,											// map::key_type
           class T,												// map::mapped_type
           class Compare = less<Key>,							// map::key_compare
           class Alloc = std::allocator<pair<const Key, T> >	// map::allocator_type
           >
class map
{
public:
	typedef Key											key_type;
	typedef T											mapped_type;
	typedef pair<const key_type, mapped_type>			value_type;
	typedef BST_node<value_type>						_Node;
	typedef Compare										key_compare;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef MapIt<T, T>									iterator;
	//typedef ListIt<T, const T>						const_iterator;
	//typedef ReverseListIt<T, T>						reverse_iterator;
	//typedef ReverseListIt<T, const T>					const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

private:
	_Node			*_head;
	_Node			*_tail;
	key_compare 	*comp;
	allocator_type	_alloc;
	size_type		_size;

	typedef typename Alloc::template rebind<_Node>::other node_alloc;
//put that in BST_NODE
	_Node	*create_node(const T &val, _Node *parent, _Node *left, _Node *right)
	{
		_Node *node = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(node, _Node(val, parent, left, right));
		return (node);
	}
	_Node	*create_node(const T &val, _Node *parent)
	{
		_Node *node = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(node, _Node(val, parent, NULL, NULL));
		return (node);
	}
	_Node	*create_node()
	{
		_Node *node = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(node, _Node());
		return (node);
	}
	void	init_BST()
	{
		_head = create_node();
		_tail = _head;
	}


public:
	//	Allocation
	explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
	comp(comp), _alloc(alloc), _size(0)
	{
		init_BST();
	}
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
	const allocator_type &alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator()) :
	comp(comp), _alloc(alloc), _size(0)
	{
		init_BST();
		insert(first, last);///to dev
	}
	map(const map &x) :
	comp(x.comp), _alloc(x._alloc), _size(x._size)
	{
		init_BST();
		insert(x._head, x._tail);///to dev
	}

	//	Modifiers
	pair<iterator,bool> insert(const value_type &val)
	{
		insert(_head, val);
	}
	iterator insert(iterator position, const value_type &val)//create private function with input iterator
	{
		if (val->first < position->first)
		{
			iterator tmp = position;
			if ((--position).first == NULL)
				return (create_node(val, tmp.as_node()));
			else
				insert(position, val);
		}
		else if (val->first > val->first)
		{
			iterator tmp = position;
			if ((++position).first == NULL)
				return (create_node(val, tmp.as_node()));
			else
				insert(position, val);
		}
		return (position);
	}
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last)
	{
		for (InputIterator it = first; it != last; ++it)
			insert(it, *it); //call the private function 
	}

};

} // namespace

#endif
