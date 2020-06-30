/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:38:19 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 18:17:54 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class List
{
private:
	
public:
	List();
	List(const List &);
	List &operator=(const List &);
	~List();
};

List::List()
{

}

}

#endif
