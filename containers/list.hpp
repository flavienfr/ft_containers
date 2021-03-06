/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:49:22 by froussel          #+#    #+#             */
/*   Updated: 2020/08/06 16:32:38 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>			// allocator
# include <iostream>		// std::cout debug
# include "utils.hpp"		// node
# include "iterators.hpp"	// iterators


namespace ft {

template <typename T, typename CT>
class ListIt : public ListBaseIt<T>
{
public:
	typedef T			value_type;
	typedef ptrdiff_t	difference_type;
	typedef CT *		pointer;
	typedef CT &		reference;

	ListIt() : ListBaseIt<T>(NULL) { };
	ListIt(Node<T> *ptr) : ListBaseIt<T>(ptr) { };
	ListIt(const ListBaseIt<T> &it) : ListBaseIt<T>(it.as_node()) { };
	ListIt &operator=(const ListIt &it) { this->_ptr = it._ptr; return (*this); };
	virtual ~ListIt() { };

	reference operator*() { return (this->_ptr->value); };
	pointer operator->() { return (&this->_ptr->value); };

	ListIt &operator++() { this->_ptr = this->_ptr->next; return (*this); };
	ListIt operator++(int) { ListIt tmp = *this; this->_ptr = this->_ptr->next; return (tmp);};

	ListIt &operator--() { this->_ptr = this->_ptr->prev; return (*this); };
	ListIt operator--(int) { ListIt tmp = *this; this->_ptr = this->_ptr->prev; return (tmp); };
};

template <typename T, typename CT>
class ReverseListIt : public ListBaseIt<T>
{
public:
	typedef T				value_type;
	typedef ptrdiff_t		difference_type;
	typedef CT *			pointer;
	typedef CT &			reference;

	ReverseListIt() : ListBaseIt<T>(NULL) { };
	ReverseListIt(Node<T> *ptr) : ListBaseIt<T>(ptr) { };
	ReverseListIt(const ListBaseIt<T> &it) : ListBaseIt<T>(it.as_node()) { };
	ReverseListIt &operator=(const ReverseListIt &it) { this->_ptr = it._ptr; return (*this); };
	virtual ~ReverseListIt() { };

	reference operator*() { return (this->_ptr->value); };
	pointer operator->() { return (&this->_ptr->value); };

	ReverseListIt &operator++() { this->_ptr = this->_ptr->prev; return (*this); };
	ReverseListIt operator++(int) {	ReverseListIt tmp = *this; this->_ptr = this->_ptr->prev; return (tmp);};

	ReverseListIt &operator--() { this->_ptr = this->_ptr->next; return (*this); };
	ReverseListIt operator--(int) {	ReverseListIt tmp = *this; this->_ptr = this->_ptr->next; return (tmp); };
};

template < typename T, typename Alloc = std::allocator<T> >
class list
{
public:
	typedef T											value_type;
	typedef Node<value_type>							_Node;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef ListIt<T, T>								iterator;
	typedef ListIt<T, const T>							const_iterator;
	typedef ReverseListIt<T, T>							reverse_iterator;
	typedef ReverseListIt<T, const T>					const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

private:
	_Node						*_head;
	_Node						*_tail;
	size_type					_size;
	allocator_type				_alloc;
	
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
	list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator()) :
	_size(0), _alloc(alloc)
	{
		(void)isIter;
		init_list();
		for (InputIterator it = first; it != last; ++it)
			push_back(*it);
	}
	list(const list& x)
	{
		_alloc = x._alloc;
		_size = x._size;
		init_list();
		for (iterator it = x.begin(); it != x.end(); ++it)
			push_back(*it);
	}
	list& operator= (const list &x)
	{
		clear();
		for (iterator it = x.begin(); it != x.end(); ++it)
			push_back(*it);
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
		++_size;
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
		_tail->next = _head;
		_head->prev = _tail;
		++_size;
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
		++_size;
		return (iterator(new_node));
	}
    void insert(iterator position, size_type n, const value_type& val)
	{
		while (n-- > 0)
			insert(position, val);
	}
	template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator())
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
		_size -= n;
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
		splice(position, x, x.begin(), x.end());
	}
	void splice(iterator position, list &x, iterator i)
	{
		iterator last = i;
		splice(position, x, i, ++last);
	}
	void splice(iterator position, list &x, iterator first, iterator last)
	{
		if (first == last)
			return ;
		if (position == _head)
			_head = first.as_node();
		if (first == x._head && &x != this)
			x._head = last.as_node();

		size_type count = 0;
		for (iterator it = first; it != last; ++it, ++count);
		_size += count;
		x._size -= count;

		_Node *new_first = first.as_node()->prev;
		_Node *new_last = last.as_node();

		link(position.as_node()->prev, first.as_node());
		link(last.as_node()->prev, position.as_node());
		
		link(new_first, new_last);
	}
	void remove(const value_type &val)
	{
		for (iterator it = begin(); it != end(); ++it)
			if (*it == val)
				erase(it);
	}
	template <class Predicate>
	void remove_if(Predicate pred)
	{
		for (iterator it = begin(); it != end(); ++it)
			if (pred(*it))
				erase(it);
	}
	void unique()
	{
		unique(equal_to<T>());
	}
	template <class BinaryPredicate>
	void unique(BinaryPredicate binary_pred)
	{
		iterator it = ++begin();
		while (it != end())
		{
			iterator tmp = it;
			if (binary_pred(*it, *(--tmp)))
			{
				++tmp;++tmp;
				erase(it);
				it = tmp;
			}
			else
				++it;
		}
	}
	void merge(list& x)
	{
		merge(x, less<T>());
	}
	template <class Compare>
	void merge(list &x, Compare comp)
	{
		if (&x == this)
			return ;
		iterator first_x = x.begin();
		iterator last_x = x.begin();
		for (iterator it = begin(); it != end(); ++it)
		{
			while (comp(*last_x, *it) && last_x != x.end())
				last_x++;
			splice (it, x, first_x, last_x);
			first_x = last_x;
			if (first_x == x.end())
				break ;
		}
		splice (end(), x, first_x, x.end());
	}
	void sort()
	{
		sort(less<T>());
	}
	template <class Compare>
	void sort(Compare comp)
	{
		int is_sort = 0;
		while (!is_sort)
		{
			iterator it1 = begin();
			iterator it2 = ++begin();
			is_sort = 1;
			while (it2 != end())
			{
				if (comp(*it2, *it1))
				{
					if (it1.as_node() == _head)
						_head = it2.as_node();
					swap_node(it1.as_node(), it2.as_node());
					is_sort = 0;
					template_swap(it1, it2);
				}
				++it1;
				++it2;
			}
		}
	}
	void reverse()
	{
		iterator begin = this->begin();
		iterator end = --this->end();
		_head = end.as_node();
		for (size_t i = 0; i < (_size / 2); ++i, ++begin, --end)
		{
			swap_node(begin.as_node(), end.as_node());
			template_swap(begin, end);
		}
	}
};

//	Non-member function overloads
template <class T, class Alloc>
void swap(list<T,Alloc> &x, list<T,Alloc> &y)
{
	x.swap(y);
}
template <class T, class Alloc>
bool	operator== (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	return (equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template <class T, class Alloc>
bool	operator!= (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
{
	return (!(lhs == rhs));
}
template <class T, class Alloc>
bool	operator<  (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
{
	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
template <class T, class Alloc>
bool	operator<= (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
{
	return (!(rhs < lhs));
}
template <class T, class Alloc>
bool	operator>  (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
{
	return (rhs < lhs);
}
template <class T, class Alloc>
bool	operator>= (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
{
	return (!(lhs < rhs));
}

} // namespace

#endif
