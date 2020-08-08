/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:34:52 by froussel          #+#    #+#             */
/*   Updated: 2020/08/08 12:24:06 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>			// allocator
# include <stdexcept>		// exeption throw
# include <sstream>			// ostringstream
# include <limits>			// limits
# include "utils.hpp"		// swap
# include "iterators.hpp"	// iterators

namespace ft {

template <typename T, typename CT>
class VectorIt : public VectBaseIt<T>
{
public:
	typedef T			value_type;
	typedef ptrdiff_t	difference_type;
	typedef CT *		pointer;
	typedef CT &		reference;

	VectorIt() : VectBaseIt<T>(NULL) { };
	VectorIt(T *ptr) : VectBaseIt<T>(ptr) { };
	VectorIt(const VectBaseIt<T> &it) : VectBaseIt<T>(it.as_ptr()) { };
	VectorIt &operator=(const VectorIt &it) { this->_ptr = it._ptr; return (*this); };
	virtual ~VectorIt() { };

	reference operator*() { return (*this->_ptr); };
	pointer operator->() { return (this->_ptr); };

	VectorIt &operator++() {++this->_ptr; return (*this); };
	VectorIt operator++(int) {	VectorIt tmp = *this; ++this->_ptr; return (tmp);};

	VectorIt &operator--() { --this->_ptr; return (*this); };
	VectorIt operator--(int) {	VectorIt tmp = *this; --this->_ptr; return (tmp); };

	VectorIt operator+(difference_type n)  { return (VectorIt(this->_ptr + n)); };
	friend VectorIt operator+(difference_type n, const VectorIt &rhs) { return (VectorIt(rhs._ptr + n)); };
	VectorIt operator-(difference_type n)  { return (VectorIt(this->_ptr - n)); };
	friend VectorIt operator-(difference_type n, const VectorIt &rhs) { return (VectorIt(rhs._ptr - n)); };

	friend difference_type operator-(const VectorIt &lhs, const VectorIt &rhs) { return (lhs._ptr - rhs._ptr); };

	VectorIt &operator+=(difference_type n) { this->_ptr += n; return (*this); };
	VectorIt &operator-=(difference_type n) { this->_ptr -= n; return (*this); };

	reference operator[](difference_type n) { return (this->_ptr[n]); };
};

template <typename T, typename CT>
class ReverseVectorIt : public VectBaseIt<T>
{
public:
	typedef T			value_type;
	typedef ptrdiff_t	difference_type;
	typedef CT *		pointer;
	typedef CT &		reference;

	ReverseVectorIt() : VectBaseIt<T>(NULL) { };
	ReverseVectorIt(pointer ptr) : VectBaseIt<T>(ptr) { };
	ReverseVectorIt(const VectBaseIt<T> &it) : VectBaseIt<T>(it.as_ptr()) { };
	ReverseVectorIt &operator=(const ReverseVectorIt &it) { this->_ptr = it._ptr; return (*this); };
	virtual ~ReverseVectorIt() { };

	reference operator*() { return (*this->_ptr); };
	pointer operator->() { return (this->_ptr); };

	ReverseVectorIt &operator++() {--this->_ptr; return (*this); };
	ReverseVectorIt operator++(int) {	ReverseVectorIt tmp = *this; --this->_ptr; return (tmp);};

	ReverseVectorIt &operator--() { ++this->_ptr; return (*this); };
	ReverseVectorIt operator--(int) {	ReverseVectorIt tmp = *this; ++this->_ptr; return (tmp); };

	ReverseVectorIt operator+(difference_type n) const { return (ReverseVectorIt(this->_ptr - n)); };
	friend ReverseVectorIt operator+(difference_type n, const ReverseVectorIt &rhs) { return (ReverseVectorIt(rhs._ptr - n)); };
	ReverseVectorIt operator-(difference_type n) const { return (ReverseVectorIt(this->_ptr + n)); };
	friend ReverseVectorIt operator-(difference_type n, const ReverseVectorIt &rhs) { return (ReverseVectorIt(rhs._ptr + n)); };

	friend difference_type operator-(const ReverseVectorIt &lhs, const ReverseVectorIt &rhs) { return (lhs._ptr - rhs._ptr); };	

	ReverseVectorIt &operator+=(difference_type n) { this->_ptr -= n; return (*this); };
	ReverseVectorIt &operator-=(difference_type n) {  this->_ptr += n; return (*this); };

	reference operator[](difference_type n) { return (this->_ptr[n]); };
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
	typedef VectorIt<T, T>								iterator;
	typedef VectorIt<T, const T>						const_iterator;
	typedef ReverseVectorIt<T, T>						reverse_iterator;
	typedef ReverseVectorIt<T, const T>					const_reverse_iterator;
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;

private:
	static const size_type	_memGrowth =  2;

	T				*_vector;
	size_type		_size;
	size_type		_capacity;
	allocator_type	_alloc;

public:
	//	Constructor Destructor Assignator
	explicit vector(const allocator_type &alloc = allocator_type()); //default (1)
	explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()); //fill (2)
	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator()); //range (3)
	vector(const vector &x); //copy (4)
	vector &operator=(const vector &x);
	~vector();

	//	Iterators
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	//	Capacity
	size_type	size() const;
	size_type	max_size() const;
	void		resize(size_type n, value_type val = value_type());
	size_type	capacity() const;
	bool		empty() const;
	void		reserve(size_type n);

	//	Element access
	reference		operator[](size_type n);
	const_reference	operator[](size_type n) const;
	reference 		at(size_type n);
	const_reference at(size_type n) const;
	reference 		front();
	const_reference front() const;
	reference		back();
	const_reference	back() const;

	//	Modifiers
	template <class InputIterator>
	void		assign(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
	void		assign(size_type n, const value_type& val);
	void		push_back(const value_type& val);
	void		pop_back();
	iterator	insert(iterator position, const value_type& val);
    void		insert(iterator position, size_type n, const value_type& val);
	template <class InputIterator>
    void		insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
	iterator	erase(iterator position);
	iterator	erase(iterator first, iterator last);
	void		swap(vector& x);
	void		clear();
};

//	Constructor Destructor Assignator
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
template <class InputIterator>
vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter) : _alloc(alloc)
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
template <typename T, typename Alloc>	// destroy
vector<T, Alloc>::~vector()
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_vector + i);
	_alloc.deallocate(_vector, _capacity);
}

//	Iterators
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

//	Capacity
template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::size() const
{
	return (_size);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::max_size() const
{
	return (_alloc.max_size());
	//return (min(static_cast<size_type>(std::numeric_limits<difference_type>::max()), std::numeric_limits<size_type>::max() / sizeof(value_type)));
}
template <typename T, typename Alloc>
void									vector<T, Alloc>::resize(size_type n, value_type val)
{
	if (n > _size)
	{
		if (n > _capacity)
		{
			T *tmp;

			tmp = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(tmp + i, _vector[i]);
				if (_size > i)
					_alloc.destroy(_vector + i);
			}
			for (size_type i = _size; i < n; i++)
				_alloc.construct(tmp + i, val);
			_alloc.deallocate(_vector, _capacity);
			_capacity = n;
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
void									vector<T, Alloc>::reserve(size_type n)
{
	if (n > max_size())
		throw std::length_error("vector::reserve");
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

//	Element access
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
	{
		std::ostringstream oss;
		oss << "vector::_M_range_check: __n (which is " << n <<") >= this->size() (which is "<< _size <<")";
		std::string str = oss.str();
		throw std::out_of_range(str.c_str());
	}
	return (_vector[n]);
}
template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::at(size_type n) const
{
	if (n >= _size)
		throw std::out_of_range("vector: out of range");
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

//	Modifiers
template <typename T, typename Alloc>
template <class InputIterator>
void								vector<T, Alloc>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter)
{
	size_type n = last - first;
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_vector + i);
	if (n > _capacity)
	{
		_alloc.deallocate(_vector, _capacity);
		_vector = _alloc.allocate(n);
		_capacity = n;
	}
	int i = 0;
	for (iterator it = first; it != last; ++it, ++i)
		_alloc.construct(_vector + i, *it);
	_size = n;
}
template <typename T, typename Alloc>
void								vector<T, Alloc>::assign(size_type n, const value_type& val)
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_vector + i);
	if (n > _capacity)
	{
		_alloc.deallocate(_vector, _capacity);
		_vector = _alloc.allocate(n);
		_capacity = n;
	}
	for (size_type i = 0; i < n; i++)
		_alloc.construct(_vector + i, val);
	_size = n;
}
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
	T *ret = NULL;

	if (_size + 1 > _capacity)
	{
		T *tmp;

		size_type tmp_capacity = (_capacity != 0) ? (_capacity * _memGrowth) : 1;
		tmp = _alloc.allocate(tmp_capacity);
		int i = 0;
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
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_vector + i);
		_alloc.deallocate(_vector, _capacity);
		_capacity = tmp_capacity;
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
				break ;
			}
		} 
	}
	_size++;
	return (iterator(ret));
}
template <typename T, typename Alloc>
void 								vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
{
	if (_size + n > _capacity)
	{
		T *tmp;

		size_type tmp_capacity = (_capacity != 0) ? (_capacity * _memGrowth) : 1;
		if (tmp_capacity < _size + n)
			tmp_capacity = _size + n;
		tmp = _alloc.allocate(tmp_capacity);
		size_t pos = 0;
		for (iterator it = begin(); it != end(); ++it, ++pos)
		{
			if (it == position)
			{
				for (size_t i = 0; i < n; i++)
					_alloc.construct(tmp + pos + i, val);
				pos += n;
			}
			_alloc.construct(tmp + pos, *it);
		}
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_vector + i);
		_alloc.deallocate(_vector, _capacity);
		_capacity = tmp_capacity;
		_vector = tmp;
	}
	else
	{
		iterator itp = end() - 1; 
		for (iterator it = end() - 1 + n; it != position - 1; --it, --itp)
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
template <class InputIterator>
void 								vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter)
{
	size_t n = last - first;

	if (_size + n > _capacity)
	{
		T *tmp;

		size_type tmp_capacity = (_capacity != 0) ? (_capacity * _memGrowth) : 1;
		if (tmp_capacity < _size + n)
			tmp_capacity = _size + n;
		tmp = _alloc.allocate(tmp_capacity);
		size_t pos = 0;
		for (iterator it = begin(); it != end(); ++it, ++pos)
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
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(_vector + i);
		_alloc.deallocate(_vector, _capacity);
		_capacity = tmp_capacity;
		_vector = tmp;
	}
	else
	{
		iterator itp = end() - 1; 
		iterator val = last; 
		for (iterator it = end() - 1 + n; it != position - 1; --it, --itp)
		{
			if (it >= position && it < position + n)
				_alloc.construct(&*it, *(--val));
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
void								vector<T, Alloc>::swap(vector &x)
{
	template_swap(_vector, x._vector);
	template_swap(_capacity, x._capacity);
	template_swap(_size, x._size);
	template_swap(_alloc, x._alloc);
}
template <typename T, typename Alloc>
void								vector<T, Alloc>::clear()
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_vector + i);
	_size = 0;
}

//	Non-member function overloads
template <class T, class Alloc>
void	swap(vector<T,Alloc> &x, vector<T,Alloc> &y)
{
	x.swap(y);
}
template <class T, class Alloc>
bool	operator== (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	return (equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template <class T, class Alloc>
bool	operator!= (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
	return (!(lhs == rhs));
}
template <class T, class Alloc>
bool	operator<  (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
template <class T, class Alloc>
bool	operator<= (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
	return (!(rhs < lhs));
}
template <class T, class Alloc>
bool	operator>  (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
	return (rhs < lhs);
}
template <class T, class Alloc>
bool	operator>= (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
{
	return (!(lhs < rhs));
}

} // namespace

#endif
