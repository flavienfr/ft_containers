/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:34:52 by froussel          #+#    #+#             */
/*   Updated: 2020/06/30 20:32:47 by froussel         ###   ########.fr       */
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
	/*size_type	size() const;
	size_type	max_size() const;
	void		resize(size_type n, value_type val = value_type());
	size_type	capacity() const;
	bool		empty() const;
	void		reserve (size_type n);*/

	/*
	**	Element access
	*/
	/*reference		operator[](size_type n);
	const_reference	operator[](size_type n) const;
	reference 		at(size_type n);
	const_reference at(size_type n) const;
	reference 		front();
	const_reference front() const;
	reference		back();
	const_reference	back() const;*/

};

/*
**	Constructor Destructor Assignator
*/
template <typename T, typename Alloc> // default (1)
vector<T, Alloc>::vector(const allocator_type &alloc) :
_size(0), _capacity(0), _alloc(alloc),_vector(NULL)
{
}

template <typename T, typename Alloc> // fill (2)
vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc) :
_size(n), _capacity(n * _memGrowth), _alloc(alloc)
{
	_vector = _alloc.allocate(_capacity);

	for (int i = 0; i < _size; i++)
		_vector[i] = val;
}

template <typename T, typename Alloc> // copy (4)
vector<T, Alloc>::vector(const vector &x) :
_size(x._size), _capacity(x._capacity), _alloc(x._alloc)//is that correct get private value without geter ?
{
	_vector = _alloc.allocate(_capacity);

	for (int i = 0; i < _size; i++)
		_vector[i] = x._vector[i];
}

template <typename T, typename Alloc> // destructor
vector<T, Alloc>::~vector()
{
}

} // namespace

#endif
