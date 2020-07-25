/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:09:13 by froussel          #+#    #+#             */
/*   Updated: 2020/07/25 18:28:05 by froussel         ###   ########.fr       */
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

template <typename T, typename CT>// add compare !
class MapIt : public MapBaseIt<T>
{
public:
	typedef T			value_type;
	typedef ptrdiff_t	difference_type;
	typedef CT *		pointer;
	typedef CT &		reference;

	MapIt() : MapBaseIt<T>(NULL) { };
	MapIt(BST_node<T> *ptr) : MapBaseIt<T>(ptr) { };
	MapIt(const MapBaseIt<T> &it) : MapBaseIt<T>(it.as_node()) { };
	MapIt &operator=(const MapIt &it) { this->_ptr = it._ptr; return (*this); };
	virtual ~MapIt() { };

	reference operator*() { return (this->_ptr->item); };
	pointer operator->() { return (&this->_ptr->item); };

	MapIt &operator++()//etablir une récursive
	{
		BST_node<T> *prev = NULL;

		while (!(this->_ptr->left == this->_ptr->parent && this->_ptr->left != NULL))
		{
			if (this->_ptr->right != prev)
			{
				if (this->_ptr->left != NULL)
					while (this->_ptr->left != NULL)
						this->_ptr = this->_ptr->left;
				else
					this->_ptr = this->_ptr->right;
				return (*this);
			}
			else
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->parent;
				if (this->ptr->right != prev)
					return (*this);
			}
		}
		return (*this);
	}
	MapIt operator++(int)
	{ MapIt tmp = *this; ++*this; return (tmp);};
	MapIt &operator--()
	{
		BST_node<T> *prev = NULL;

		do
		{
			if (this->_ptr->left != prev)
			{
				this->_ptr = this->_ptr->left;
				return (*this);
			}
			prev = this->_ptr;
			this->_ptr = this->_ptr->parent;
		} while (this->_ptr->parent != NULL);
		return (*this);
	}
	MapIt operator--(int)
	{ MapIt tmp = *this; --*this; return (tmp);};
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
	typedef MapIt<value_type, value_type>				iterator;
	//typedef ListIt<T, const T>						const_iterator;
	//typedef ReverseListIt<T, T>						reverse_iterator;
	//typedef ReverseListIt<T, const T>					const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

private:
	_Node			*_head;
	_Node			*_tail;
	key_compare 	comp;
	allocator_type	_alloc;
	size_type		_size;

	typedef typename Alloc::template rebind<_Node>::other node_alloc;
//put that in BST_NODE
	_Node	*create_node(const value_type &val, _Node *parent, _Node *left, _Node *right)
	{
		_Node *node = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(node, _Node(val, parent, left, right));
		return (node);
	}
	_Node	*create_node(const value_type &val, _Node *parent)
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
		_tail = create_node();
		_head = _tail;
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
		insert(first, last);
	}
	map(const map &x) :
	comp(x.comp), _alloc(x._alloc), _size(x._size)
	{
		init_BST();
		insert(iterator(x._head), iterator(x._tail));
	}

	//	Iterators
	iterator begin()
	{
		return (iterator(_head));
	}
	//const_iterator begin() const;
	iterator end()
	{
		return (iterator(_tail));
	}
	//const_iterator end() const;
	//reverse_iterator rbegin();
	//const_reverse_iterator rbegin() const;

	//	Modifiers
	pair<iterator,bool> insert(const value_type &val)
	{
		return (my_insert(iterator(_head), val));
	}
	iterator insert(iterator position, const value_type &val)
	{//define spcefic condition for empty map
		return (my_insert(position, val).first);
	}
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last)
	{
		for (InputIterator it = first; it != last; ++it)
			my_insert(iterator(_head), *it);
	}
private://put that in static in btree node
	pair<iterator,bool> my_insert(iterator position, const value_type &val)
	{
		if (_size == 0)
		{
			_head = create_node(val, NULL);//add tail
			is_new_tail(_head);
			_size++;
			return (ft::pair<iterator, bool>(iterator(_head), true));
		}
		else if (val.first < position->first)//comp
		{
			if (position.as_node()->left == NULL)
			{
				_Node *node = create_node(val, position.as_node());
				is_new_tail(node);//impossible ?
				_size++;
				return (ft::pair<iterator, bool>(iterator(node), true));
			}
			else
				insert(--position, val);
		}
		else if (val.first > position->first)//comp
		{
			if (position.as_node()->right == NULL || position.as_node()->right == _tail)
			{
				_Node *node = create_node(val, position.as_node());
				position.as_node()->right = node;
				is_new_tail(node);
				_size++;
				return (ft::pair<iterator, bool>(iterator(node), true));
			}
			else
				insert(++position, val);
		}
		return (ft::pair<iterator, bool>(position, false));
	}
	void	is_new_tail(_Node *node)
	{
		if (_tail->parent == NULL || _tail->parent->item.first < node->item.first) // comp
		{
			_tail->parent = node;
			_tail->left = node;
			_tail->right = _head;//mettre ici ?
			node->right = _tail;
		}
	}
public:

};

} // namespace

#endif
