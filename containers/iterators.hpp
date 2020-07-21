/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:52:33 by froussel          #+#    #+#             */
/*   Updated: 2020/07/21 15:05:25 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include <memory>		// ptrdiff_t
# include "utils.hpp"

namespace ft {

/* list container iterator */
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
	Node<T> *as_node() const { return _ptr; };//why const 

	bool operator==(const ListBaseIt &rhs) { return (_ptr == rhs._ptr); };
	bool operator!=(const ListBaseIt &rhs) { return (_ptr != rhs._ptr); };
};

}

#endif
