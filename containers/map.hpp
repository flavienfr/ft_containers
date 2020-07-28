/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:09:13 by froussel          #+#    #+#             */
/*   Updated: 2020/07/28 18:23:52 by froussel         ###   ########.fr       */
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

	MapIt &operator++()
	{
		BST_node<T> *prev = NULL;

		while (1)
		{
			if (this->_ptr->right != prev)
			{
				prev = this->_ptr;
				this->_ptr = this->_ptr->right;
				if (this->_ptr->left != NULL && this->_ptr->left != prev)
					while (this->_ptr->left != NULL)
						this->_ptr = this->_ptr->left;
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
				if (this->_ptr->right != NULL && this->_ptr->right != prev)//prev protect why here
					while (this->_ptr->right != NULL)
						this->_ptr = this->_ptr->right;
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

template <typename T, typename CT>// add compare !
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
				if (this->_ptr->right != NULL && this->_ptr->right != prev)//prev protect why here
					while (this->_ptr->right != NULL)
						this->_ptr = this->_ptr->right;
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
				if (this->_ptr->left != NULL && this->_ptr->left != prev)
					while (this->_ptr->left != NULL)
						this->_ptr = this->_ptr->left;
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

private:
	_Node			*_root;
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
		_head =_tail = create_node();
		_root = NULL;//pas utile
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
	{// Warning dirty copy construct like list
		init_BST();
		insert(iterator(x._head), iterator(x._tail));
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
		return (reverse_iterator(_tail->parent));
	}
	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(_tail->parent));
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
	{//define spcefic condition for empty map
		return (my_insert(position, val).first);//can make strange thing ??
	}
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last)
	{
		for (InputIterator it = first; it != last; ++it)
			my_insert(iterator(_root), *it);
	}
private://put that in static in btree node
	pair<iterator,bool> my_insert(iterator position, const value_type &val)
	{
		_Node *node;

		if (_size == 0)//ou root == NULL
		{
			node = _root = _head = create_node(val, _tail);
			is_new_tail(node);
			//std::cout << "size=0" << std::endl;
		}
		else if (key_compare()(val.first, position->first))
		{//std::cout << "val.first < position->first:" << val.first <<" < "<< position->first << std::endl;
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
		{//std::cout << "val.first > position->first: " << val.first <<" > "<< position->first << std::endl;
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
		{//std::cout << "equality" << std::endl;
			return (ft::pair<iterator, bool>(position, false));
		}
		//std::cout << "end" << std::endl;
		_size++;
		return (ft::pair<iterator, bool>(iterator(node), true));
	}
	void	is_new_tail(_Node *node)
	{
		if (_tail->parent == NULL || _tail->parent->item.first < node->item.first) // comp
		{
			_tail->parent = node;
			_tail->left = node;
			_tail->right = _root;//mettre ici ? root ou head ?
			node->right = _tail;
		}
	}

public: 
	void erase(iterator position)
	{
		_Node *pos = position.as_node();
		_Node *new_node;
		
		if ((pos->right == NULL || pos->right == _tail)
			&& (pos->left == NULL || pos->left == _tail))
		{
		//std::cout << "!!! NULL NULL !!!" <<std::endl;
			new_node = pos->parent;
			if (new_node->right == pos)
				new_node->right = pos->right;
			else
				new_node->left = NULL;
		}
		else if (((pos->right == NULL || pos->right == _tail) && pos->left != NULL)
			|| ((pos->left == NULL || pos->left == _tail) && pos->right != NULL && pos->right != _tail))
		{
		//std::cout << "!!! NULL NODE !!!" <<std::endl;
			new_node = (pos->right != NULL && pos->right != _tail) ? pos->right : pos->left;			
			new_node->parent = pos->parent;
			if (pos->parent->right == pos)
				pos->parent->right = new_node;
			else
				pos->parent->left = new_node;
		}
		else //two children => select the nearest less node
		{
		//std::cout << "!!! NODE NODE !!!" <<std::endl;
			new_node = (--iterator(pos)).as_node();
			new_node->right = pos->right;
			pos->right->parent = new_node;
			new_node->parent = pos->parent;
			if (pos->parent->right == pos)
				pos->parent->right = new_node;
			else
				pos->parent->left = new_node;
		}
		if (_tail->left == pos)//sure its nez node ?
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
		iterator it = first;
		while (it != last)
			erase(it++);
	}
	void swap (map &x)
	{
		template_swap(_root, x._root);
		template_swap(_head, x._head);
		template_swap(_tail, x._tail);
		template_swap(_size, x._size);
	}

//	Operations
iterator find(const key_type &k)
{
	iterator it;
	for (it = _head; it != _tail; ++it)//root ou head
		if (!key_compare()(it->first, k)  && !key_compare()(k, it->first))
			break ;
	return (it);
}
const_iterator find(const key_type &k) const
{
	const_iterator it;
	for (it = _head; it != _tail; ++it)//root ou head
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

};

} // namespace

#endif
