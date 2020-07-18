/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:49:22 by froussel          #+#    #+#             */
/*   Updated: 2020/07/18 18:13:34 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Allocation node par node ou tableau de node quand possible 

/*
** 	set _tail with value size_t;
**	stop give tail valur of size, warning with obj like string
*/

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>		// allocator
//# include <stdexcept>	// exeption throw
# include <iostream>	// std::cout debug
//# include <limits>	// limits
# include "utils.hpp"	// node


namespace ft {

template <typename T>
class ListIt
{
public:
	typedef Node<T>			value_type;
	typedef ptrdiff_t		difference_type;
	typedef T *				pointer;
	typedef T &				reference;
private:
	Node<T> *_ptr;
public:
	ListIt() : _ptr(NULL) { };
	ListIt(Node<T> *ptr) : _ptr(ptr) { };
	ListIt(const ListIt &it) : _ptr(it._ptr) { };
	ListIt &operator=(const ListIt &it) { _ptr = it._ptr; return (*this); };
	~ListIt() { };

	friend bool operator==(const ListIt &lhs, const ListIt &rhs) { return (lhs._ptr == rhs._ptr); };
	friend bool operator!=(const ListIt &lhs, const ListIt &rhs) { return (lhs._ptr != rhs._ptr); };

	reference operator*() { return (_ptr->value); };
	pointer operator->() { return (&_ptr->value); };

	ListIt &operator++() { _ptr = _ptr->next; return (*this); };
	ListIt operator++(int) {	ListIt tmp = *this; _ptr = _ptr->next; return (tmp);};

	ListIt &operator--() { _ptr = _ptr->prev; return (*this); };
	ListIt operator--(int) {	ListIt tmp = *this; _ptr = _ptr->prev; return (tmp); };

	Node<T> *as_node() { return (_ptr); };
};

template <typename T>
class ReverseListIt
{
public:
	typedef Node<T>			value_type;
	typedef ptrdiff_t		difference_type;
	typedef T *				pointer;
	typedef T &				reference;
private:
	Node<T> *_ptr;
public:
	ReverseListIt() : _ptr(NULL) { };
	ReverseListIt(Node<T> *ptr) : _ptr(ptr) { };
	ReverseListIt(const ReverseListIt &it) : _ptr(it._ptr) { };
	ReverseListIt &operator=(const ReverseListIt &it) { _ptr = it._ptr; return (*this); };
	~ReverseListIt() { };

	friend bool operator==(const ReverseListIt &lhs, const ReverseListIt &rhs) { return (lhs._ptr == rhs._ptr); };
	friend bool operator!=(const ReverseListIt &lhs, const ReverseListIt &rhs) { return (lhs._ptr != rhs._ptr); };

	reference operator*() { return (_ptr->value); };
	pointer operator->() { return (&_ptr->value); };

	ReverseListIt &operator++() { _ptr = _ptr->prev; return (*this); };
	ReverseListIt operator++(int) {	ReverseListIt tmp = *this; _ptr = _ptr->prev; return (tmp);};

	ReverseListIt &operator--() { _ptr = _ptr->next; return (*this); };
	ReverseListIt operator--(int) {	ReverseListIt tmp = *this; _ptr = _ptr->next; return (tmp); };

	Node<T> *as_node() { return (_ptr); };
};

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
	typedef ListIt<T>									iterator;
	typedef ListIt<const T>								const_iterator;
	typedef ReverseListIt<T>							reverse_iterator;
	typedef ReverseListIt<const T>						const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

private:
	typedef Node<T>		_Node;
	_Node				*_head;
	_Node				*_tail;
	size_type			_size;
	allocator_type		_alloc;
	
	typedef typename Alloc::template rebind<_Node>::other node_alloc;

	//	Allocation
	_Node	*create_node(const T &val, _Node *prev, _Node *next)
	{
		_Node *node = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(node, _Node(val, prev, next));
		return (node);
	}
	_Node	*create_node(const T &val)
	{
		_Node *node = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(node, _Node(val));
		return (node);
	}
	_Node	*create_node()
	{
		_Node *node = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(node, _Node());
		return (node);
	}
	void	init_list()
	{
		_head = create_node();
		_tail = _head;
		_tail->next =_head;//maybe useless
		_tail->prev =_head;//maybe useless
		_head->next = _tail;//maybe useless
		_head->prev = _tail;//maybe useless
	}
	void	link(_Node *n1, _Node *n2)
	{
		n1->next = n2;
		n2->prev = n1;
	}
public:
	//	Constructor Destructor Assignator
	explicit list(const allocator_type &alloc = allocator_type()) :
	_size(0), _alloc(alloc)
	{
		init_list();
	}
	explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) :
	_size(0), _alloc(alloc)
	{
		init_list();
		for (size_type i = 0; i < n; i++)
			push_back(val);
	}
	template <class InputIterator>
	list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
	typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator()) :
	_size(0), _alloc(alloc) // issus if iterate on vector
	{
		(void)isIter;
		init_list();
		for (InputIterator it = first; it != last; ++it)
			push_back(*it);//test withi *it
	}
	list(const list& x)
	{
		_alloc = x._alloc;
		_size = x._size;
		init_list();
		for (iterator it = x.begin(); it != x.end(); ++it)
			push_back(*it);//test withi *it
	}
	list& operator= (const list& x)
	{
		//std::cout << "sup\n";

		clear();
		_size = x._size;
		for (iterator it = x.begin(); it != x.end(); ++it)
			push_back(*it);//test withi *it
		return (*this);
	}
	~list()
	{
		_size++;
		clear();
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
		return (reverse_iterator(_tail->prev));
	}
	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(_tail->prev));
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
		return (_size == 0 ? true : false);
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
	reference front()
	{
		return (_head->value);
	}
	const_reference front() const
	{
		return (_head->value);
	}
	reference back()
	{
		return (_tail->prev->value);
	}
	const_reference back() const
	{
		return (_tail->prev->value);
	}

	//	Modifiers
	template <class InputIterator>
	void assign(InputIterator first, InputIterator last,
	typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator())
	{
		(void)isIter;
		clear();
		for (InputIterator it = first; it != last; ++it)
			push_back(*it);
	}
	void assign(size_type n, const value_type &val)
	{
		clear();
		for (size_type i = 0; i < n; i++)
			push_back(val);
	}
	void push_front(const value_type &val)
	{
		_Node *tmp;
	
		if (_size == 0)
		{
			_head = create_node(val, _tail, _tail);
			_tail->prev = _head;
			_tail->next = _head;
		}
		else
		{
			tmp = create_node(val, _tail, _head);
			_tail->next = tmp;
			_head->prev = tmp;
			_head = tmp;
		}
		_tail->value = ++_size;
	}
	void pop_front()
	{
		erase(iterator(_head), iterator(_head->next));
	}
	void push_back(const value_type &val)
	{
		_Node *tmp;
	
		if (_size == 0)
		{
			_head = create_node(val, _tail, _tail);
			_tail->prev = _head;
		}
		else
		{
			tmp = create_node(val, _tail->prev, _tail);
			_tail->prev->next = tmp;
			_tail->prev = tmp;
		}
		_tail->next = _head;//add
		_head->prev = _tail;//add
		_tail->value = ++_size;
	}
	void pop_back()
	{
		erase(iterator(_tail->prev), iterator(_tail));
	}
	iterator insert(iterator position, const value_type &val)
	{
		_Node *new_node;

		new_node = create_node(val, position.as_node()->prev, position.as_node());
		position.as_node()->prev->next = new_node;
		position.as_node()->prev = new_node;
		if (position == _head)
			_head = new_node;
		_tail->value = ++_size;
		return (iterator(new_node));
	}
    void insert(iterator position, size_type n, const value_type& val)
	{
		while (n-- > 0)
			insert(position, val);
	}
	template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last,
	typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator())
	{
		for (InputIterator it = first; it != last; ++it)
			insert(position, *it);
	}
	iterator erase(iterator position)
	{
		iterator next = position;
		return (erase(position, ++next));
	}
	iterator erase(iterator first, iterator last)
	{
		size_type n = 0;
		iterator it;

		if (first == _head)
			_head = last.as_node();
		link(first.as_node()->prev, last.as_node());
		for (it = first; it != last; ++it, ++n)
		{
			node_alloc(_alloc).destroy(it.as_node());
			node_alloc(_alloc).deallocate(it.as_node(), 1);
		}
		_tail->value = _size -= n;
		return (last);
	}
	void swap(list& x)
	{
		template_swap(_head, x._head);
		template_swap(_tail, x._tail);
		template_swap(_size, x._size);
		template_swap(_alloc, x._alloc);
	}
	void resize (size_type n, value_type val = value_type())
	{
		iterator it = _head;
		if (n < _size)
		{
			for (size_type i = 0; i < n; ++i, ++it);
			erase(it, iterator(_tail));
		}
		else
		{
			for (size_type i = _size; i < n; ++i, ++it)
				push_back(val);
		}
	}
	void clear()
	{
		for (size_type i = 0; i < _size; i++)
		{
			node_alloc(_alloc).destroy(_head);
			node_alloc(_alloc).deallocate(_head, 1);
			_head = _head->next;
		}
		_size = 0;
	}

	//	Operations
	void splice(iterator position, list &x)
	{
	/*for (iterator it = begin(); it != end(); ++it)
		std::cout <<*it<< " ";
	std::cout <<"\n";
	for (iterator it = x.begin(); it != x.end(); ++it)
		std::cout <<*it<< " ";
	std::cout <<"\n";
	*/
		splice(position, x, x.begin(), x.end());
	}
	void splice(iterator position, list &x, iterator i)
	{
		iterator last = i;
		splice(position, x, i, ++last);
	}
	void splice(iterator position, list &x, iterator first, iterator last)
	{
		if (position == _head)
			_head = first.as_node();
		if (first == x._head)
			x._head = last.as_node();

		size_type count = 0;
		for (iterator it = first; it != last; ++it, ++count);
		_size += count; //-size sans tail
		x._size -= count; //-size sans tail

		_Node *save_first = first.as_node();
		_Node *save_last = last.as_node();

		link(position.as_node()->prev, first.as_node());
		link(last.as_node()->prev, position.as_node());
		link(save_first->prev, save_last);

		std::cout << "_size: " << _size << " x._size: " << x._size << std::endl;
	}

};

} // namespace

#endif
