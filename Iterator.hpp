/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:00:01 by froussel          #+#    #+#             */
/*   Updated: 2020/07/04 19:09:36 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
// https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait

template <class T>
struct iterator_traits
{
	typedef typename T::value_type value_type
	typedef typename T::difference_type difference_type
	typedef typename T::iterator_category iterator_category
	typedef typename T::pointer pointer
	typedef typename T::reference reference
};

/*
template <typename T>
struct iterator_traits<T *>
{
	typedef std::random_access_iterator_tag iterator_category;
	typedef T                               value_type;
	typedef T*                              pointer;
	typedef T&                              reference;
	typedef std::ptrdiff_t                  difference_type;
};
*/

#endif
