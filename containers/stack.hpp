/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:09:19 by froussel          #+#    #+#             */
/*   Updated: 2020/08/04 12:30:43 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"

namespace ft {

template <class T, class Container = list<T> >
class stack
{
public:
	typedef T			value_type;
	typedef Container 	container_type;
	typedef size_t		size_type;

	//	Allocation
	explicit stack (const container_type& ctnr = container_type())
	{

	}

bool empty() const
{
	
}

};

} //namespace
