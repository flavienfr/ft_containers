/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:49:37 by froussel          #+#    #+#             */
/*   Updated: 2020/07/13 17:52:45 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft {

template <typename T>
class Node
{
public:
	typedef T	value_type;

	value_type		value; // call default constructor ?
	Node			*prev;
	Node			*next;

	Node() : value(value_type()), prev(NULL), next(NULL) {};
	Node(value_type value) : value(value), prev(NULL), next(NULL) {};
	Node(const Node &x) { this = x; };
	Node &operator=(const Node &x) { value = x.value; prev = x.prev; next = x.next; return (*this); };
	~Node();
};

}

#endif
