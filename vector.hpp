/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:34:52 by froussel          #+#    #+#             */
/*   Updated: 2020/07/03 21:48:29 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>	//allocator

namespace ft {

//template < class T, class Alloc = std::allocator<T> >
template <typename T, typename Alloc = std::allocator<T>>
class vector
{
public:
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	//typedef iterator
	//typedef const_iterator
	//typedef reverse_iterator
	//typedef const_reverse_iterator
	typedef ptrdiff_t									difference_type;
	typedef size_t										size_type;
	//typedef typename allocator_type::size_type       size_type;
	//typedef typename allocator_type::difference_type difference_type;

private:
	const size_type	_memGrowth =  2;

	T				*_vector;
	size_type		_size;
	size_type		_capacity;
	allocator_type	_alloc;

public:
	/*
	**	Constructor Destructor Assignator
	*/
	//default (1)
	explicit vector(const allocator_type &alloc = allocator_type());
	//fill (2)
	explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
	//range (3)
	/*template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());*/
	//copy (4)
	vector(const vector &x);
	//Assignat
	vector &operator=(const vector &x);
	//destruct
	~vector();

	/*
	**	Capacity
	*/
	size_type	size() const;
	size_type	max_size() const;
	void		resize(size_type n, value_type val = value_type());
	size_type	capacity() const;
	/*bool		empty() const;
	void		reserve (size_type n);*/

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

template <typename T, typename Alloc> // copy (4)
vector<T, Alloc>::vector(const vector &x) :
_size(x._size), _capacity(x._capacity), _alloc(x._alloc)
{
	_vector = _alloc.allocate(_capacity);

	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_vector + i, x.vector + i);
}

template <typename T, typename Alloc> // destructor
vector<T, Alloc>::~vector()
{
	//delete _vector;
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_vector + i);
	_alloc.deallocate(_vector, _capacity);
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

/*bool		empty() const;
void		reserve (size_type n);*/

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

		_capacity = (_capacity != 0) ? (_capacity * 2) : 1;
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
