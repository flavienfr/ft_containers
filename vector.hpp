/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:34:52 by froussel          #+#    #+#             */
/*   Updated: 2020/07/11 18:43:36 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>		//allocator
# include <stdexcept>	//exeption throw
#include <iostream>		// std::cout debug

namespace ft {
//symplify iterator const 
template <typename T>
class Iterator
{
private:
	T *_ptr;
public:

	typedef T				value_type;
	typedef ptrdiff_t		difference_type;
	typedef T *				pointer;
	typedef T &				reference;

	Iterator() : _ptr(NULL) { };
	Iterator(T *ptr) : _ptr(ptr) { };// in std is private(friend ?)
	Iterator(const Iterator &it) : _ptr(it._ptr) { };
	Iterator &operator=(const Iterator &it) { _ptr = it._ptr; return (*this); };
	~Iterator() { };

	friend bool operator==(const Iterator &lhs, const Iterator &rhs) { return (lhs._ptr == rhs._ptr); };
	friend bool operator!=(const Iterator &lhs, const Iterator &rhs) { return (lhs._ptr != rhs._ptr); };

	reference operator*() { return (*_ptr); };
	pointer operator->() { return (_ptr); };

	Iterator &operator++() {++_ptr; return (*this); };
	Iterator operator++(int) {	Iterator tmp = *this; ++_ptr; return (tmp);};

	Iterator &operator--() { --_ptr; return (*this); };
	Iterator operator--(int) {	Iterator tmp = *this; --_ptr; return (tmp); };

	Iterator operator+(difference_type n)  { return (Iterator(_ptr + n)); };
	friend Iterator operator+(difference_type n, const Iterator &rhs) { return (Iterator(rhs._ptr + n)); };
	Iterator operator-(difference_type n)  { return (Iterator(_ptr - n)); };
	friend Iterator operator-(difference_type n, const Iterator &rhs) { return (Iterator(rhs._ptr - n)); };

	friend difference_type operator-(const Iterator &lhs, const Iterator &rhs) { return (lhs._ptr - rhs._ptr); };

	bool operator<(const Iterator &rhs) const { return (_ptr < rhs._ptr); };
	bool operator>(const Iterator &rhs) const { return (_ptr > rhs._ptr); };
	bool operator<=(const Iterator &rhs) const { return (_ptr <= rhs._ptr); };
	bool operator>=(const Iterator &rhs) const { return (_ptr >= rhs._ptr); };

	Iterator &operator+=(difference_type n) { _ptr += n; return (*this); };//change
	Iterator &operator-=(difference_type n) { _ptr -= n; return (*this); };//change

	T &operator[](difference_type n) { return (_ptr[n]); };
};

template <typename T>
class const_Iterator
{
private:
	T *_ptr;
public:
	typedef T				value_type;
	typedef ptrdiff_t		difference_type;
	typedef const T *		pointer;
	typedef const T &		reference;

	const_Iterator() : _ptr(NULL) { };
	const_Iterator(T *ptr) : _ptr(ptr) { };// in std is private(friend ?)
	const_Iterator(const const_Iterator &it) : _ptr(it._ptr) { };
	const_Iterator &operator=(const const_Iterator &it) { _ptr = it._ptr; return (*this); };
	~const_Iterator() { };

	friend bool operator==(const const_Iterator &lhs, const const_Iterator &rhs) { return (lhs._ptr == rhs._ptr); };
	friend bool operator!=(const const_Iterator &lhs, const const_Iterator &rhs) { return (lhs._ptr != rhs._ptr); };

	reference operator*() { return (*_ptr); };
	pointer operator->() { return (_ptr); };
	//Petit check retour referemce poitneur...
	const_Iterator &operator++() {++_ptr; return (*this); };
	const_Iterator operator++(int) {	const_Iterator tmp = *this; ++_ptr; return (tmp);};

	const_Iterator &operator--() { --_ptr; return (*this); };
	const_Iterator operator--(int) {	const_Iterator tmp = *this; --_ptr; return (tmp); };

	const_Iterator operator+(difference_type n) const { return (const_Iterator(_ptr + n)); };
	friend const_Iterator operator+(difference_type n, const const_Iterator &rhs) { return (const_Iterator(rhs._ptr + n)); };
	const_Iterator operator-(difference_type n) const { return (const_Iterator(_ptr - n)); };
	friend const_Iterator operator-(difference_type n, const const_Iterator &rhs) { return (const_Iterator(rhs._ptr - n)); };

	friend difference_type operator-(const const_Iterator &lhs, const const_Iterator &rhs) { return (lhs._ptr - rhs._ptr); };

	bool operator<(const const_Iterator &rhs) const { return (_ptr < rhs._ptr); };
	bool operator>(const const_Iterator &rhs) const { return (_ptr > rhs._ptr); };
	bool operator<=(const const_Iterator &rhs) const { return (_ptr <= rhs._ptr); };
	bool operator>=(const const_Iterator &rhs) const { return (_ptr >= rhs._ptr); };

	const_Iterator &operator+=(difference_type n) { _ptr += n; return (*this); };
	const_Iterator &operator-=(difference_type n) { _ptr -= n; return (*this); };

	T &operator[](difference_type n) { return (_ptr[n]); };
};

template <typename T>
class ReverseIterator
{
private:
	T *_ptr;
public:
	typedef T				value_type;
	typedef ptrdiff_t		difference_type;
	typedef T *				pointer;
	typedef T &				reference;

	ReverseIterator() : _ptr(NULL) { };
	ReverseIterator(T *ptr) : _ptr(ptr) { };// in std is private(friend ?)
	ReverseIterator(const ReverseIterator &it) : _ptr(it._ptr) { };
	ReverseIterator &operator=(const ReverseIterator &it) { _ptr = it._ptr; return (*this); };
	~ReverseIterator() { };

	friend bool operator==(const ReverseIterator &lhs, const ReverseIterator &rhs) { return (lhs._ptr == rhs._ptr); };
	friend bool operator!=(const ReverseIterator &lhs, const ReverseIterator &rhs) { return (lhs._ptr != rhs._ptr); };

	reference operator*() { return (*_ptr); };
	pointer operator->() { return (_ptr); };
	//Petit check retour referemce poitneur...
	ReverseIterator &operator++() {--_ptr; return (*this); };
	ReverseIterator operator++(int) {	ReverseIterator tmp = *this; --_ptr; return (tmp);};

	ReverseIterator &operator--() { ++_ptr; return (*this); };
	ReverseIterator operator--(int) {	ReverseIterator tmp = *this; ++_ptr; return (tmp); };

	ReverseIterator operator+(difference_type n) const { return (ReverseIterator(_ptr - n)); };
	friend ReverseIterator operator+(difference_type n, const ReverseIterator &rhs) { return (ReverseIterator(rhs._ptr - n)); };
	ReverseIterator operator-(difference_type n) const { return (ReverseIterator(_ptr + n)); };
	friend ReverseIterator operator-(difference_type n, const ReverseIterator &rhs) { return (ReverseIterator(rhs._ptr + n)); };

	friend difference_type operator-(const ReverseIterator &lhs, const ReverseIterator &rhs) { return (lhs._ptr - rhs._ptr); };	

	bool operator<(const ReverseIterator &rhs) const { return (_ptr > rhs._ptr); };
	bool operator>(const ReverseIterator &rhs) const { return (_ptr < rhs._ptr); };
	bool operator<=(const ReverseIterator &rhs) const { return (_ptr >= rhs._ptr); };
	bool operator>=(const ReverseIterator &rhs) const { return (_ptr <= rhs._ptr); };

	ReverseIterator &operator+=(difference_type n) { _ptr -= n; return (*this); };
	ReverseIterator &operator-=(difference_type n) {  _ptr += n; return (*this); };

	T &operator[](difference_type n) { return (_ptr[n]); };
};

template <typename T>
class ConstReverseIterator
{
private:
	T *_ptr;
public:
	typedef T				value_type;
	typedef ptrdiff_t		difference_type;
	typedef const T *		pointer;
	typedef const T &		reference;

	ConstReverseIterator() : _ptr(NULL) { };
	ConstReverseIterator(T *ptr) : _ptr(ptr) { };// in std is private(friend ?)
	ConstReverseIterator(const ConstReverseIterator &it) : _ptr(it._ptr) { };
	ConstReverseIterator &operator=(const ConstReverseIterator &it) { _ptr = it._ptr; return (*this); };
	~ConstReverseIterator() { };

	friend bool operator==(const ConstReverseIterator &lhs, const ConstReverseIterator &rhs) { return (lhs._ptr == rhs._ptr); };
	friend bool operator!=(const ConstReverseIterator &lhs, const ConstReverseIterator &rhs) { return (lhs._ptr != rhs._ptr); };

	reference operator*() { return (*_ptr); };
	pointer operator->() { return (_ptr); };
	//Petit check retour referemce poitneur...
	ConstReverseIterator &operator++() {--_ptr; return (*this); };
	ConstReverseIterator operator++(int) {	ConstReverseIterator tmp = *this; --_ptr; return (tmp);};

	ConstReverseIterator &operator--() { ++_ptr; return (*this); };
	ConstReverseIterator operator--(int) {	ConstReverseIterator tmp = *this; ++_ptr; return (tmp); };

	ConstReverseIterator operator+(difference_type n) const { return (ConstReverseIterator(_ptr - n)); };
	friend ConstReverseIterator operator+(difference_type n, const ConstReverseIterator &rhs) { return (ConstReverseIterator(rhs._ptr - n)); };
	ConstReverseIterator operator-(difference_type n) const { return (ConstReverseIterator(_ptr + n)); };
	friend ConstReverseIterator operator-(difference_type n, const ConstReverseIterator &rhs) { return (ConstReverseIterator(rhs._ptr + n)); };

	friend difference_type operator-(const ConstReverseIterator &lhs, const ConstReverseIterator &rhs) { return (lhs._ptr - rhs._ptr); };	

	bool operator<(const ConstReverseIterator &rhs) const { return (_ptr > rhs._ptr); };
	bool operator>(const ConstReverseIterator &rhs) const { return (_ptr < rhs._ptr); };
	bool operator<=(const ConstReverseIterator &rhs) const { return (_ptr >= rhs._ptr); };
	bool operator>=(const ConstReverseIterator &rhs) const { return (_ptr <= rhs._ptr); };

	ConstReverseIterator &operator+=(difference_type n) { _ptr -= n; return (*this); };
	ConstReverseIterator &operator-=(difference_type n) {  _ptr += n; return (*this); };

	T &operator[](difference_type n) { return (_ptr[n]); };
};

template <typename T, typename Alloc = std::allocator<T> >
class vector
{
public:
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef Iterator<T>									iterator;
	typedef const_Iterator<T>							const_iterator;
	typedef ReverseIterator<T>							reverse_iterator;
	typedef ConstReverseIterator<T>						const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

private:
	static const size_type	_memGrowth =  2;

	T				*_vector;
	size_type		_size;
	size_type		_capacity;
	allocator_type	_alloc;

public:
	/*
	**	Constructor Destructor Assignator
	*/
	explicit vector(const allocator_type &alloc = allocator_type()); //default (1)
	explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()); //fill (2)
	vector(iterator first, iterator last, const allocator_type& alloc = allocator_type()); //range (3)
	vector(const vector &x); //copy (4)
	vector &operator=(const vector &x);
	~vector();

	/*
	**	Iterators
	*/
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	/*
	**	Capacity
	*/
	size_type	size() const;
	size_type	max_size() const;
	void		resize(size_type n, value_type val = value_type());
	size_type	capacity() const;
	bool		empty() const;
	void		reserve(size_type n);

	/*
	**	Element access
	*/
	reference		operator[](size_type n);
	const_reference	operator[](size_type n) const;
	reference 		at(size_type n);
	const_reference at(size_type n) const;
	reference 		front();
	const_reference front() const;
	reference		back();
	const_reference	back() const;

	/*
	**	Modifiers
	*/
	void		assign(iterator first, iterator last);
	void		assign(size_type n, const value_type& val);
	void		push_back(const value_type& val);
	void		pop_back();
	iterator	insert(iterator position, const value_type& val);
    void		insert(iterator position, size_type n, const value_type& val);
    void		insert(iterator position, iterator first, iterator last);
	iterator	erase(iterator position);
	iterator	erase(iterator first, iterator last);
	void		swap(vector& x);
	void		clear();

};

/*
**	Constructor Destructor Assignator
*/
template <typename T, typename Alloc>	// default
vector<T, Alloc>::vector(const allocator_type &alloc) :
_vector(NULL), _size(0), _capacity(0), _alloc(alloc)
{
}
template <typename T, typename Alloc>	// fill
vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc) :
_size(n), _capacity(n), _alloc(alloc)
{
	_vector = _alloc.allocate(_capacity);

	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_vector + i, val);
}
template <typename T, typename Alloc>	// range
vector<T, Alloc>::vector(iterator first, iterator last, const allocator_type &alloc) : _alloc(alloc)
{
	_size = last - first;//cast ??? 
	_capacity = _size;
	_vector = _alloc.allocate(_capacity);
	int i = 0;
	for (iterator it = first; it != last; ++it)
	{
		_alloc.construct(_vector + i, *it);
		i++;
	}
}
template <typename T, typename Alloc>	// copy
vector<T, Alloc>::vector(const vector &x) :
_size(x._size), _capacity(x._size), _alloc(x._alloc)
{
	_vector = _alloc.allocate(_capacity);

	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_vector + i, x._vector[i]);
}
template <typename T, typename Alloc>	// assign
vector<T, Alloc> &vector<T, Alloc>::operator=(const vector &x)
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_vector + i);
	_alloc.deallocate(_vector, _capacity);

	_size = x._size;
	_capacity = _size;
	_vector = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_vector + i, x._vector[i]);
	return (*this);
}
template <typename T, typename Alloc>	// destructor
vector<T, Alloc>::~vector()
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_vector + i);
	_alloc.deallocate(_vector, _capacity);
}

/*
**	Iterators
*/
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator					vector<T, Alloc>::begin()
{
	return (iterator(_vector));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::begin() const
{
	return (const_iterator(_vector));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator					vector<T, Alloc>::end()
{
	return (iterator(_vector + _size));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::end() const
{
	return (const_iterator(_vector + _size));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator 		vector<T, Alloc>::rbegin()
{
	return (reverse_iterator(_vector + _size - 1));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rbegin() const
{
	return (const_reverse_iterator(_vector + _size - 1));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator			vector<T, Alloc>::rend()
{
	return (reverse_iterator(_vector - 1));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rend() const
{
	return (const_reverse_iterator(_vector - 1));
}

/*
**	Capacity
*/
template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::size() const
{
	return (_size);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::max_size() const
{
	return (_alloc.max_size());
}
template <typename T, typename Alloc>
void									vector<T, Alloc>::resize(size_type n, value_type val)//iterator
{
	if (n > _size)
	{
		if (n > _capacity)
		{
			T *tmp;

			tmp = _alloc.allocate(n);//is size = capacity when resize ?
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(tmp + i, _vector[i]);
				if (_size > i)
					_alloc.destroy(_vector + i);
			}
			for (size_type i = _size; i < n; i++)
				_alloc.construct(tmp + i, val);
			_alloc.deallocate(_vector, _capacity);
			_capacity = n;//is size = capacity when resize ?
			_size = n;
			_vector = tmp;
		}
		else
		{
			for (size_type i = _size; i < n; i++)
				_alloc.construct(_vector + i, val);
			_size = n;
		}
	}
	else
	{
		for (size_type i = n; i < _capacity; i++)
			_alloc.destroy(_vector + i);
		_size = n;
	}
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity() const
{
	return (_capacity);
}
template <typename T, typename Alloc>
bool									vector<T, Alloc>::empty() const
{
	return (_size == 0 ? true : false);
}
template <typename T, typename Alloc>
void									vector<T, Alloc>::reserve(size_type n)//iterator
{
	//if (n > max_size())
	//	throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
	if (n > _capacity)
	{
		T *tmp;

		tmp = _alloc.allocate(n);
		for (size_type i = 0; i < _size; i++)
		{
			_alloc.construct(tmp + i, _vector[i]);
			if (i < _size)
				_alloc.destroy(_vector + i);
		}
		_alloc.deallocate(_vector, _capacity);
		_capacity = n;
		_vector = tmp;
	}
}

/*
**	Element access
*/
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference		vector<T, Alloc>::operator[](size_type n)
{
	return (_vector[n]);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::operator[](size_type n) const
{
	return (_vector[n]);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference		vector<T, Alloc>::at(size_type n)
{
	if (n >= _size)
		throw std::out_of_range("vector: Out of Range");
	return (_vector[n]);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::at(size_type n) const
{
	if (n >= _size)
		throw std::out_of_range("vector: Out of Range");
	return (_vector[n]);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference		vector<T, Alloc>::front()
{ return (*_vector); }
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::front() const
{ return (*_vector); }
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference		vector<T, Alloc>::back()
{ return (_vector[_size - 1]); }
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::back() const
{ return (_vector[_size - 1]); }

/*
**	Modifiers
*/
/*template <typename T, typename Alloc>
void	vector<T, Alloc>::assign(iterator first, iterator last)
{//modify Capacity
	if (last - first > _capacity)
	{
		for (iterator it = first; it != last; ++it)
		{
			
		}
		_size = last - first;
	}
	else
	{
		for (iterator it = first; it != last; ++it)
		{

		}
	}
	
}*/
//void	assign (size_type n, const value_type& val);

template <typename T, typename Alloc>
void								vector<T, Alloc>::push_back(const value_type &val)
{
	if (_size + 1 > _capacity)
	{
		T *tmp;

		size_type tmp_capacity = (_capacity != 0) ? (_capacity * _memGrowth) : 1;
		tmp = _alloc.allocate(tmp_capacity);
		for (size_type i = 0; i < _size; i++)
		{
			_alloc.construct(tmp + i, _vector[i]);
			_alloc.destroy(_vector + i);
		}
		_alloc.construct(tmp + _size, val);
		_alloc.deallocate(_vector, _capacity);
		_size++;
		_capacity = tmp_capacity;
		_vector = tmp;
	}
	else
	{
		_alloc.construct(_vector + _size, val);
		_size++;
	}
}
template <typename T, typename Alloc>
void								vector<T, Alloc>::pop_back()
{
	_alloc.destroy(_vector + _size - 1);
	_size--;
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator position, const value_type &val)
{
	T *ret;
	if (_size + 1 > _capacity)
	{
		T *tmp;
		int i = 0;

		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_vector + i);
		_alloc.deallocate(_vector, _capacity);
		_capacity = (_capacity != 0) ? (_capacity * _memGrowth) : 1;
		tmp = _alloc.allocate(_capacity);
		for (iterator it = begin(); it != end() + 1; ++it, ++i)
		{
			if (it == position)
			{
				_alloc.construct(tmp + i, val);
				ret = tmp + i;
				i++;
			}
			if (it != end ())
				_alloc.construct(tmp + i, *it);
		}
		_vector = tmp;
	}
	else
	{
		for (iterator it = end(); it != position - 1; --it)
		{
			if (it != end ())
			{
				_alloc.construct(&*(it + 1), *it);
				_alloc.destroy(&*it);
			}
			if (it == position)
			{
				_alloc.construct(&*it, val);
				ret = &*it;
			}
		} 
	}
	_size++;
	return (iterator(ret));
}
template <typename T, typename Alloc>
void 								vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
{
	if (_size + 1 > _capacity)
	{
		T *tmp;

		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_vector + i);
		_alloc.deallocate(_vector, _capacity);
		_capacity = (_capacity != 0) ? (_capacity * _memGrowth) : 1;
		if (_capacity < _size + n)
			_capacity = _size + n;
		tmp = _alloc.allocate(_capacity);
		size_t pos = 0;
		for (iterator it = begin(); it != end() + 1; ++it, ++pos)
		{
			if (it == position)
			{
				for (size_t i = 0; i < n; i++)
					_alloc.construct(tmp + pos + i, val);
				pos += n;
			}
			_alloc.construct(tmp + pos, *it);
		}
		_vector = tmp;
	}
	else
	{
		iterator itp = end() - 1; 
		for (iterator it = end() - 1 + n; it != position - 1; --it, --itp)//itp hors zone danger ?
		{
			if (it >= position && it < position + n)
				_alloc.construct(&*it, val);
			else
			{
				_alloc.construct(&*it, *itp);
				_alloc.destroy(&*itp);
			}	
		}
	}
	_size += n;
}
template <typename T, typename Alloc>
void 								vector<T, Alloc>::insert(iterator position, iterator first, iterator last)
{
	size_t n = last - first;

	if (_size + 1 > _capacity)
	{
		T *tmp;

		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_vector + i);
		_alloc.deallocate(_vector, _capacity);
		_capacity = (_capacity != 0) ? (_capacity * _memGrowth) : 1;
		if (_capacity < _size + n)
			_capacity = _size + n;
		tmp = _alloc.allocate(_capacity);
		size_t pos = 0;
		for (iterator it = begin(); it != end() + 1; ++it, ++pos)
		{
			if (it == position)
			{
				int i = 0;
				for (iterator it = first; it != last; ++it, ++i)
					_alloc.construct(tmp + pos + i, *it);
				pos += n;
			}
			_alloc.construct(tmp + pos, *it);
		}
		_vector = tmp;
	}
	else
	{
		iterator itp = end() - 1; 
		iterator val = first; 
		for (iterator it = end() - 1 + n; it != position - 1; --it, --itp)//itp hors zone danger ?
		{
			if (it >= position && it < position + n)
				_alloc.construct(&*it, *(val++));
			else
			{
				_alloc.construct(&*it, *itp);
				_alloc.destroy(&*itp);
			}	
		}
	}
	_size += n;
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator position)
{
	return (erase(position, position + 1));
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last)
{
	for (iterator it = first; it != last; ++it)
	{
		_alloc.destroy(&*it);
	}
	iterator pos = first;
	for (iterator it = last; it != end(); ++it, ++pos)
	{
		_alloc.construct(&*pos, *it);
		_alloc.destroy(&*it);
	}
	_size -= (last - first);
	return (first);
}
template <typename T, typename Alloc>
void								vector<T, Alloc>::clear()
{
	//if (!(std::is_trivially_destructible<T>::value))
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_vector + i);
	_size = 0;
}


} // namespace

#endif
