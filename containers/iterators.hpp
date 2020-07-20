/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:52:33 by froussel          #+#    #+#             */
/*   Updated: 2020/07/20 18:54:38 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include <memory>		// ptrdiff_t

template <typename T, typename N>
class BaseListIt
{
public:
	typedef T				value_type;
	typedef ptrdiff_t		difference_type;
	typedef T *				pointer;
	typedef T &				reference;
protected:
	N	*_ptr;
public:
	BaseListIt() : _ptr(NULL) { };
	BaseListIt(N *ptr) : _ptr(ptr) { };
	BaseListIt(const BaseListIt &it) : _ptr(it._ptr) { };
	BaseListIt &operator=(const BaseListIt &it) { _ptr = it._ptr; return (*this); };
	virtual ~BaseListIt() { };

	N *as_node() { return (_ptr); };
};

#endif
