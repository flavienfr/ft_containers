/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:34:52 by froussel          #+#    #+#             */
/*   Updated: 2020/07/05 19:40:36 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>		//allocator
//# include <stdexcept>	//exeption throw

//# include "BaseIterator.hpp"

namespace ft {

template <typename T>
class VectorIterator //inherate from baseIterator
{
private:
	T *_ptr;
public:
	// metre dans iterator trai
	typedef T			value_type;
	typedef ptrdiff_t	difference_type;
	typedef T *			pointer;
	typedef T &			reference;

	VectorIterator(); //null ptr ?
	VectorIterator(T *ptr);// in std is private(friend ?)
	VectorIterator(const VectorIterator &it);
	VectorIterator<T> &operator=(const VectorIterator &it);
	~VectorIterator();

	T *ptr() const;//is exist in true iteraro, lake of security ?

	T &operator*();//what it retrun ?
	VectorIterator<T> operator++();
	VectorIterator<T> operator++(int);
};

template <typename T>
VectorIterator<T>::VectorIterator()
{
}

template <typename T>
VectorIterator<T>::VectorIterator(T *ptr) : _ptr(ptr)
{
}

template <typename T>
VectorIterator<T>::VectorIterator(const VectorIterator &it) : _ptr(it._ptr)
{
}

template <typename T>
VectorIterator<T> &VectorIterator<T>::operator=(const VectorIterator &it)
{
	_ptr = it._ptr;
	return (*this);
}

template <typename T>
VectorIterator<T>::~VectorIterator()
{
}

template <typename T>
T *VectorIterator<T>::ptr() const
{ return (_ptr); }

template <typename T>
T &VectorIterator<T>::operator*()
{ return (*_ptr); }

template <typename T>
VectorIterator<T> VectorIterator<T>::operator++()
{
	++_ptr;
	return (*this);
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator++(int)
{
	VectorIterator<T> tmp = *this;//* ou pas
    ++_ptr;
    return (tmp);
}

template <typename T>//friend it ?
bool operator==(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
{ return (lhs.ptr() == rhs.ptr()); }

template <typename T>//friend it ?
bool operator!=(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
{ return (lhs.ptr() != rhs.ptr()); }




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
	typedef VectorIterator<T>							iterator;
	//typedef const_iterator
	//typedef reverse_iterator
	//typedef const_reverse_iterator
	typedef ptrdiff_t									difference_type;//typedef typename allocator_type::size_type       size_type;
	typedef size_t										size_type;//typedef typename allocator_type::difference_type difference_type;

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
	template <class InputIterator> //range (3)
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	vector(const vector &x); //copy (4)
	vector &operator=(const vector &x);
	~vector();

	/*
	**	Iterators
	*/
	iterator begin();
	//const_iterator begin() const;
	iterator end();
	//const_iterator end() const;

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
	/*reference 		at(size_type n);
	const_reference at(size_type n) const;
	reference 		front();
	const_reference front() const;
	reference		back();
	const_reference	back() const;*/

	/*
	**	Modifiers
	*/
	//assign
	void	push_back(const value_type& val);

};

/*
**	Constructor Destructor Assignator
*/
template <typename T, typename Alloc> // default (1)
vector<T, Alloc>::vector(const allocator_type &alloc) :
_vector(NULL), _size(0), _capacity(0), _alloc(alloc)
{
}

template <typename T, typename Alloc> // fill (2)
vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc) :
_size(n), _capacity(n), _alloc(alloc)
{
	_vector = _alloc.allocate(_capacity);

	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_vector + i, val);
}

//template <class InputIterator> //range (3)
//vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

template <typename T, typename Alloc> // copy (4)
vector<T, Alloc>::vector(const vector &x) :
_size(x._size), _capacity(x._capacity), _alloc(x._alloc)
{
	_vector = _alloc.allocate(_capacity);

	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_vector + i, x.vector + i);
}

//template <typename T, typename Alloc>
//vector &operator=(const vector &x);

template <typename T, typename Alloc> // destructor
vector<T, Alloc>::~vector()
{
	//delete _vector;
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_vector + i);
	_alloc.deallocate(_vector, _capacity);
}

/*
**	Iterators
*/
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::begin()
{
	return (iterator(_vector));
}
//constiterator
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
{
	return (iterator(_vector + _size));
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
void	vector<T, Alloc>::resize(size_type n, value_type val)//iterator
{
	if (n > _size)
	{
		if (n > _capacity)
		{
			//an automatic reallocation of the allocated storage space takes place.
			T *tmp;

			tmp = _alloc.allocate(n);//is size = capacity when resize ?
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(tmp + i, _vector[i]);
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
			//the content is expanded by inserting at the end as many elements as needed 
			//to reach a size of n. If val is specified, the new elements are initialized
			//as copies of val, otherwise, they are value-initialized.
			for (size_type i = _size; i < n; i++)
				_alloc.construct(_vector + i, val);
			_size = n;
		}
	}
	else
	{
		//the content is reduced to its first n elements, removing those beyond (and destroying them).
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
bool	vector<T, Alloc>::empty() const
{
	return (_size == 0 ? true : false);
}

template <typename T, typename Alloc>
void	vector<T, Alloc>::reserve(size_type n)//iterator
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
/*reference 		at(size_type n);
const_reference at(size_type n) const;
reference 		front();
const_reference front() const;
reference		back();
const_reference	back() const;*/

/*
**	Modifiers
*/
//assign
template <typename T, typename Alloc>
void	vector<T, Alloc>::push_back(const value_type &val)//iterator
{
	if (_size + 1 > _capacity)
	{
		T *tmp;

		_capacity = (_capacity != 0) ? (_capacity * _memGrowth) : 1;
		tmp = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
		{
			_alloc.construct(tmp + i, _vector[i]);
			_alloc.destroy(_vector + i);
		}
		_alloc.construct(tmp + _size, val);
		_alloc.deallocate(_vector, _capacity);
		_size++;
		_vector = tmp;
	}
	else
	{
		_alloc.construct(_vector + _size, val);
		_size++;
	}
}


} // namespace

#endif
