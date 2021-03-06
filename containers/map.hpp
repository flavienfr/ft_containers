/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:09:13 by froussel          #+#    #+#             */
/*   Updated: 2020/08/06 14:35:43 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check limits
//seg fault mac test dsanitize
//reconsolité tial->parent 

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>			// allocator
# include <iostream>		// std::cout debug
# include "utils.hpp"		// node
# include "iterators.hpp"	// iterators

namespace ft {

template <typename T, typename CT>
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

	MapIt &operator++()
	{
		BST_node<T> *prev = NULL;

		while (1)
		{
			if (this->_ptr->right != prev)
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->right;
				while (this->_ptr->left != NULL && this->_ptr->left != prev)
					prev = this->_ptr = this->_ptr->left;
				return (*this);
			}
			else
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->parent;
				if (this->_ptr->right != prev)
					return (*this);
			}
		}
	}
	MapIt operator++(int)
	{ MapIt tmp = *this; ++*this; return (tmp);};
	MapIt &operator--()
	{
		BST_node<T> *prev = NULL;

		while (1)
		{
			if (this->_ptr->left != prev)
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->left;
				while (this->_ptr->right != NULL && this->_ptr->right != prev)
					prev = this->_ptr = this->_ptr->right;
				return (*this);
			}
			else
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->parent;
				if (/*this->_ptr->right == NULL || */this->_ptr->right == prev)
					return (*this);
			}
		}
	}
	MapIt operator--(int)
	{ MapIt tmp = *this; --*this; return (tmp);};
};

template <typename T, typename CT>
class ReverseMapIt : public MapBaseIt<T>
{
public:
	typedef T			value_type;
	typedef ptrdiff_t	difference_type;
	typedef CT *		pointer;
	typedef CT &		reference;

	ReverseMapIt() : MapBaseIt<T>(NULL) { };
	ReverseMapIt(BST_node<T> *ptr) : MapBaseIt<T>(ptr) { };
	ReverseMapIt(const MapBaseIt<T> &it) : MapBaseIt<T>(it.as_node()) { };
	ReverseMapIt &operator=(const ReverseMapIt &it) { this->_ptr = it._ptr; return (*this); };
	virtual ~ReverseMapIt() { };

	reference operator*() { return (this->_ptr->item); };
	pointer operator->() { return (&this->_ptr->item); };

	ReverseMapIt &operator++()
	{
		BST_node<T> *prev = NULL;

		while (1)
		{
			if (this->_ptr->left != prev)
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->left;
				while (this->_ptr->right != NULL && this->_ptr->right != prev)
					prev = this->_ptr = this->_ptr->right;
				return (*this);
			}
			else
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->parent;
				if (/*this->_ptr->right == NULL || */this->_ptr->right == prev)
					return (*this);
			}
		}
	}
	ReverseMapIt operator++(int)
	{ ReverseMapIt tmp = *this; ++*this; return (tmp);};
	ReverseMapIt &operator--()
	{
		BST_node<T> *prev = NULL;

		while (1)
		{
			if (this->_ptr->right != prev)
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->right;
				while (this->_ptr->left != NULL && this->_ptr->left != prev)
					prev = this->_ptr = this->_ptr->left;
				return (*this);
			}
			else
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->parent;
				if (this->_ptr->right != prev)
					return (*this);
			}
		}
	}
	ReverseMapIt operator--(int)
	{ ReverseMapIt tmp = *this; --*this; return (tmp);};
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
	typedef MapIt<value_type, const value_type>			const_iterator;
	typedef ReverseMapIt<value_type, value_type>		reverse_iterator;
	typedef ReverseMapIt<value_type, const value_type>	const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;
	class value_compare
	{
	friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
		  return comp(x.first, y.first);
		}
	};

private:
	_Node			*_root;
	_Node			*_head;
	_Node			*_tail;
	key_compare 	comp;
	allocator_type	_alloc;
	size_type		_size;

	typedef typename Alloc::template rebind<_Node>::other node_alloc;

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
		_root = _head = _tail = create_node();
		_tail->parent = _head;
		_root = NULL;//pas utile
	}
	pair<iterator,bool> my_insert(iterator position, const value_type &val)
	{
		_Node *node;

		if (_size == 0)
		{
			node = _root = _head = create_node(val, _tail);
			is_new_tail(node);
		}
		else if (key_compare()(val.first, position->first))
		{
			if (position.as_node()->left == NULL)
			{					
				node = create_node(val, position.as_node());
				position.as_node()->left = node;
				if (key_compare()(val.first, _head->item.first))
					_head = node;
			}
			else
				return (my_insert(iterator(position.as_node()->left), val));
		}
		else if (key_compare()(position->first, val.first))
		{
			if (position.as_node()->right == NULL || position.as_node()->right == _tail)
			{
				node = create_node(val, position.as_node());
				position.as_node()->right = node;
				is_new_tail(node);
			}
			else
				return (my_insert(iterator(position.as_node()->right), val));
		}
		else
			return (ft::pair<iterator, bool>(position, false));
		_size++;
		return (ft::pair<iterator, bool>(iterator(node), true));
	}
	void	is_new_tail(_Node *node)
	{
		if (_tail->parent == NULL || comp(_tail->parent->item.first, node->item.first))
		{
			_tail->parent = node;
			_tail->left = node;
			_tail->right = _root;
			node->right = _tail;
		}
	}
	void virtual_erase(_Node *pos)
	{
		_Node *new_node;

		if ((pos->right == NULL || pos->right == _tail)
			&& (pos->left == NULL || pos->left == _tail))
		{
			new_node = pos->parent;
			if (new_node->right == pos)
				new_node->right = pos->right;
			else
				new_node->left = NULL;
		}
		else if (((pos->right == NULL || pos->right == _tail) && pos->left != NULL)
			|| ((pos->left == NULL || pos->left == _tail) && pos->right != NULL && pos->right != _tail))
		{
			new_node = (pos->right != NULL && pos->right != _tail) ? pos->right : pos->left;			
			new_node->parent = pos->parent;
			if (pos->parent->right == pos)
				pos->parent->right = new_node;
			else
				pos->parent->left = new_node;
		}
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
	comp(x.comp), _alloc(x._alloc), _size(0)
	{
		init_BST();
		insert(iterator(x._head), iterator(x._tail));
	}
	~map()
	{
		clear();
		node_alloc(_alloc).destroy(_tail);
		node_alloc(_alloc).deallocate(_tail, 1);
	}
	map &operator= (const map& x)
	{
		_size = 0;
		comp = x.comp;
		init_BST();
		insert(iterator(x._head), iterator(x._tail));
	}

	//	Iterators
	iterator begin()
	{
		return (iterator(_head));
	}
	const_iterator begin() const
	{
		return (const_iterator(_head));
	}
	iterator end()
	{
		return (iterator(_tail));
	}
	const_iterator end() const
	{
		return (const_iterator(_tail));	
	}
	reverse_iterator rbegin()
	{
		return (reverse_iterator(_tail->left));
	}
	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(_tail->left));
	}
	reverse_iterator rend()
	{
		return (reverse_iterator(_tail));
	}
	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(_tail));
	}

	//	Capacity
	bool empty() const
	{
		return (_size == 0 ? true: false);
	}
	size_type size() const
	{
		return (_size);
	}
	size_type max_size() const
	{
		return (node_alloc(_alloc).max_size());
	}

	//	Element access
	mapped_type &operator[] (const key_type &k)
	{
		return ((*((insert(ft::make_pair(k,mapped_type()))).first)).second);
	}
	
	//	Modifiers
	pair<iterator,bool> insert(const value_type &val)
	{
		return (my_insert(iterator(_root), val));
	}
	iterator insert(iterator position, const value_type &val)
	{
		return (my_insert(position, val).first);
	}
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last)
	{
		for (InputIterator it = first; it != last; ++it)
			my_insert(iterator(_root), *it);
	}
	void erase(iterator position)
	{
		_Node *pos = position.as_node();
		_Node *new_node;
		
		if ((pos->right == NULL || pos->right == _tail)
			&& (pos->left == NULL || pos->left == _tail))
		{
			new_node = pos->parent;
			if (new_node->right == pos)
				new_node->right = pos->right;
			else
				new_node->left = NULL;
		}
		else if (((pos->right == NULL || pos->right == _tail) && pos->left != NULL)
			|| ((pos->left == NULL || pos->left == _tail) && pos->right != NULL && pos->right != _tail))
		{
			new_node = (pos->right != NULL && pos->right != _tail) ? pos->right : pos->left;			
			new_node->parent = pos->parent;
			if (pos->parent->right == pos)
				pos->parent->right = new_node;
			else
				pos->parent->left = new_node;
		}
		else
		{
			new_node = (--iterator(pos)).as_node();
			virtual_erase(new_node);
			new_node->right = pos->right;
			pos->right->parent = new_node;
			new_node->parent = pos->parent;
			if (pos->parent->right == pos)
				pos->parent->right = new_node;
			else
				pos->parent->left = new_node;
			new_node->left = pos->left;
			if (pos->left)
				pos->left->parent = new_node;
		}
		if (_tail->left == pos)
		{
			_tail->left = new_node;
			new_node->right = _tail;
		}
		if (pos == _root)
			_root = new_node;
		if (pos == _head)
			_head = (++iterator(_head)).as_node();
		node_alloc(_alloc).destroy(pos);
		node_alloc(_alloc).deallocate(pos, 1);
		--_size;
	}
	size_type erase(const key_type &k)
	{
		iterator it = find(k);
		
		if (it == _tail)
			return (0);
		erase(it);
		return (1);
	}
	void erase(iterator first, iterator last)
	{
		while (first != last)
			erase(first++);
	}
	void swap (map &x)
	{
		template_swap(_root, x._root);
		template_swap(_head, x._head);
		template_swap(_tail, x._tail);
		template_swap(_size, x._size);
	}
	void clear()
	{
		erase(iterator(_head), end());
	}

	//	Observers
	key_compare key_comp() const
{
	return (comp);
}
	value_compare value_comp() const
{
	return (value_compare(comp));
}

	//	Operations
	iterator find(const key_type &k)
{
	iterator it;
	for (it = _head; it != _tail; ++it)
		if (!key_compare()(it->first, k)  && !key_compare()(k, it->first))
			break ;
	return (it);
}
	const_iterator find(const key_type &k) const
{
	const_iterator it;
	for (it = _head; it != _tail; ++it)
		if (!key_compare()(it->first, k)  && !key_compare()(k, it->first))
			break ;
	return (it);
}
	size_type count (const key_type &k) const
{
	if (find(k).as_node() == _tail)
		return (0);
	return (1);
}
	iterator lower_bound (const key_type &k)
{
	iterator it;
	for (it = _head; it != _tail; ++it)
		if (comp(it->first, k) == false)
			break ;
	return (it);
}
	const_iterator lower_bound (const key_type &k) const
{
	const_iterator it;
	for (it = _head; it != _tail; ++it)
		if (comp(it->first, k) == false)
			break ;
	return (it);
}
	iterator upper_bound (const key_type &k)
{
	iterator it;
	for (it = _head; it != _tail; ++it)
		if (comp(k, it->first) == true)
			break ;
	return (it);
}
	const_iterator upper_bound (const key_type &k) const
{
	const_iterator it;
	for (it = _head; it != _tail; ++it)
		if (comp(k, it->first) == true)
			break ;
	return (it);
}
	pair<iterator,iterator>	equal_range (const key_type &k)
{
	return (make_pair(lower_bound(k), upper_bound(k)));
}
	pair<const_iterator,const_iterator>	equal_range (const key_type &k) const
{
	return (make_pair(lower_bound(k), upper_bound(k)));
}

};

} // namespace

#endif
