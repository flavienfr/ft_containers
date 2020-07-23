/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:52:33 by froussel          #+#    #+#             */
/*   Updated: 2020/07/23 18:57:19 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include <memory>		// ptrdiff_t
# include "utils.hpp"

namespace ft {

//	map container iterator
template <typename T>
class MapBaseIt
{
private:
	MapBaseIt();

protected:
	BST_node<T> *_ptr;

public:
	MapBaseIt(BST_node<T> *ptr) : _ptr(ptr){};
	virtual ~MapBaseIt(){};

	BST_node<T> *as_node() const { return _ptr; };

	bool operator==(const MapBaseIt &rhs) { return (_ptr == rhs._ptr); };
	bool operator!=(const MapBaseIt &rhs) { return (_ptr != rhs._ptr); };
};

//	list container iterator
template <typename T>
class ListBaseIt
{
private:
	ListBaseIt();

protected:
	Node<T> *_ptr;

public:
	ListBaseIt(Node<T> *ptr) : _ptr(ptr){};
	virtual ~ListBaseIt(){};

	Node<T> *as_node() const { return _ptr; };

	bool operator==(const ListBaseIt &rhs) { return (_ptr == rhs._ptr); };
	bool operator!=(const ListBaseIt &rhs) { return (_ptr != rhs._ptr); };
};

//	vector container iterator
template <typename T>
class VectBaseIt
{
private:
	VectBaseIt();

protected:
	T *_ptr;

public:
	VectBaseIt(T *ptr) : _ptr(ptr){};
	virtual ~VectBaseIt(){};

	T *as_ptr() const { return _ptr; };

	bool operator==	(const VectBaseIt &rhs) { return (_ptr == rhs._ptr); };
	bool operator!=	(const VectBaseIt &rhs) { return (_ptr != rhs._ptr); };
	bool operator<	(const VectBaseIt &rhs) const { return (_ptr < rhs._ptr); };
	bool operator>	(const VectBaseIt &rhs) const { return (_ptr > rhs._ptr); };
	bool operator<=	(const VectBaseIt &rhs) const { return (_ptr <= rhs._ptr); };
	bool operator>=	(const VectBaseIt &rhs) const { return (_ptr >= rhs._ptr); };

	//put friend here
};

}

#endif
