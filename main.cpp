/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:34:50 by user42            #+#    #+#             */
/*   Updated: 2020/07/05 19:42:04 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#include "vector.hpp"
#include <vector>

void	tester(void (*pf_1)(), void (*pf_2)(), std::string text)
{
	std::cout.fill( '-' );

	if (pf_1)
	{
		std::cout << std::setw(50) << centered(text) << std::endl;
		pf_1();
		std::cout << std::endl;
	}
	if (pf_2)
	{
		std::cout << std::setw(50) << centered("STD vs FT") << std::endl;
		pf_2();
		std::cout << std::endl;
	}
}

/*
**	Constructor Destructor Assignator
*/
void	std_constructor()
{
	{
		std::vector<int> vect;  
		vect.push_back(10); 
		vect.push_back(20); 
		vect.push_back(30); 

		for (size_t i = 0; i < vect.max_size(); i++)
			std::cout << vect[i] << " ";
	}
	{
		int n = 3;
		std::vector<int> vect(n, 10); 

		for (size_t i = 0; i < vect.max_size(); i++)
			std::cout << vect[i] << " ";
	}
	{
		int arr[] = { 10, 20, 30 }; 
		int n = sizeof(arr) / sizeof(arr[0]); 

		std::vector<int> vect(arr, arr + n);

		for (size_t i = 0; i < vect.max_size(); i++)
			std::cout << vect[i] << " "; 
	}
	{
		std::vector<int> vect1;
		vect1.push_back(10);
		vect1.push_back(20);
		vect1.push_back(30);
		std::vector<int> vect2(vect1.begin(), vect1.end());

		for (size_t i = 0; i < vect2.max_size(); i++)
			std::cout << vect2[i] << " ";
	}
}
void	ft_constructor()
{
}
void	Constructor_Destructor_Assignator()
{
	tester(std_constructor, ft_constructor, "Constructor");
}

/*
**	Capacity
*/
void	std_max_size()
{
	std::vector<int>vec;
	std::cout << vec.max_size() << std::endl;	
	std::vector<char>vec2;
	std::cout << vec2.max_size() << std::endl;
	std::vector<float>vec3;
	std::cout << vec3.max_size() << std::endl;
	std::vector<std::string>vec4;
	std::cout << vec4.max_size() << std::endl;
	std::vector<bool>vec5;//bool diff
	std::cout << vec5.max_size();
}
void	ft_max_size()
{
	ft::vector<int>vec;
	std::cout << vec.max_size() << std::endl;	
	ft::vector<char>vec2;
	std::cout << vec2.max_size() << std::endl;
	ft::vector<float>vec3;
	std::cout << vec3.max_size() << std::endl;
	ft::vector<std::string>vec4;
	std::cout << vec4.max_size() << std::endl;
	ft::vector<bool>vec5;//bool diff
	std::cout << vec5.max_size();
}
void	std_resize()
{
	std::vector<int> myvector;

	for (int i=1;i<10;i++) myvector.push_back(i);	
	//myvector.resize(5);
	//myvector.resize(8,100);
	myvector.resize(12);
	
	std::cout << "myvector contains:";
	for (size_t i=0; i < myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << std::endl<< "size:"<< myvector.size()<< " capacity:" << myvector.capacity();
}
void	ft_resize()
{
	ft::vector<int> myvector;

	for (int i=1;i<10;i++) myvector.push_back(i);	
	//myvector.resize(5);
	//myvector.resize(8,100);
	myvector.resize(12);
	
	std::cout << "myvector contains:";
	for (size_t i=0; i < myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << std::endl<< "size:"<< myvector.size()<< " capacity:" << myvector.capacity();
}
void	std_capacity()
{
	{
		std::vector<int> myvector(215);
		std::cout << myvector.capacity();
	}
	std::cout << std::endl;
	{
		std::vector<int> myvector;

		for (int i=0; i<100; i++)
			myvector.push_back(i);
		std::cout << "size: " << myvector.size() << '\n';
		std::cout << "capacity: " << myvector.capacity() << '\n';
		std::cout << "max_size: " << myvector.max_size() << '\n';
	}
}
void	ft_capacity()
{
	{
		std::vector<int> myvector(215);
		std::cout << myvector.capacity();
	}
	std::cout << std::endl;
	{
		ft::vector<int> myvector;

		//for (int i=0; i<100; i++)
		//	myvector.push_back(i);
		std::cout << "size: " << myvector.size() << '\n';
		std::cout << "capacity: " << myvector.capacity() << '\n';
		std::cout << "max_size: " << myvector.max_size() << '\n';
	}
}
void	std_empty()
{
	std::vector<int> myvector;
	int sum (0);
	for (int i=1;i<=10;i++) myvector.push_back(i);
	while (!myvector.empty())
	{
	   sum += myvector.back();
	   myvector.pop_back();
	}
	std::cout << "total: " << sum;
}
void	ft_empty()
{/*
	ft::vector<int> myvector;
	int sum (0);
	for (int i=1;i<=10;i++) myvector.push_back(i);
	while (!myvector.empty())
	{
	   sum += myvector.back();
	   myvector.pop_back();
	}
	std::cout << "total: " << sum;
*/}
void	std_reserve()
{
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i)
	{
		foo.push_back(i);
		if (sz!=foo.capacity())
		{
			sz = foo.capacity();
	    	std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i)
	{
		bar.push_back(i);
		if (sz!=bar.capacity())
		{
	    	sz = bar.capacity();
	    	std::cout << "capacity changed: " << sz << '\n';
	  }
	}
	std::cout << "Do a push_back" << '\n';
	bar.push_back(9);
	std::cout << "capacity changed: " << bar.capacity() << '\n';
	{
		try
		{
   			// vector throws a length_error if resized above max_size
    		std::vector<int> myvector;
    		myvector.reserve(myvector.max_size()+1);
  		}
		catch (const std::length_error& le)
		{
			std::cerr << "Length error: " << le.what();
  		}
	}
}
void	ft_reserve()
{
	ft::vector<int>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i)
	{
		foo.push_back(i);
		if (sz!=foo.capacity())
		{
			sz = foo.capacity();
	    	std::cout << "capacity changed: " << sz << '\n';
		}
	}

	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i)
	{
		bar.push_back(i);
		if (sz!=bar.capacity())
		{
	    	sz = bar.capacity();
	    	std::cout << "capacity changed: " << sz << '\n';
	  }
	}
	std::cout << "Do a push_back" << '\n';
	bar.push_back(9);
	std::cout << "capacity changed: " << bar.capacity() << '\n';
	{
		try
		{
   			// vector throws a length_error if resized above max_size
    		ft::vector<int> myvector;
    		myvector.reserve(myvector.max_size()+1);
  		}
		catch (const std::length_error& le)
		{
			std::cerr << "Length error: " << le.what();
  		}
	}
}
void	Capacity()
{
	//tester(std_max_size, ft_max_size, "max_size");
	//tester(std_capacity, ft_capacity, "capacity");
	//tester(std_resize, ft_resize, "resize");
	//tester(std_empty, ft_empty, "empty");
	tester(std_reserve, ft_reserve, "reserve");
}

/*
**	Element access
*/
void	std_operator_selection()
{
	{
		std::vector<int> myvector (10);
		std::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
	}
	std::cout << '\n';
	{
		const std::vector<int> myvector (10);
		std::vector<int>::size_type sz = myvector.size();

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
	}
}
void	ft_operator_selection()
{
	{
		ft::vector<int> myvector (10);
		ft::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
	}
	std::cout << '\n';
	{
		const ft::vector<int> myvector (10);
		ft::vector<int>::size_type sz = myvector.size();

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
	}
}
void	Element_access()
{
	tester(std_operator_selection, ft_operator_selection, "operator_selection");
}

/*
**	Iterators
*/
void	std_Iterators()
{
	{
		std::vector<int>vec;

		vec.push_back(10);
		vec.push_back(255);
		vec.push_back(456);
		std::vector<int>::iterator it;
		std::vector<int>::iterator it2 = vec.begin();
		std::cout << "it: " << *it << " it2: " << *it2;
	}
	std::cout << std::endl;
	{
		std::vector<int>vec;

		vec.push_back(10);
		vec.push_back(255);
		vec.push_back(456);
		std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator it2(it);
		std::vector<int>::iterator it3;
		it3 = it;
		std::cout << "it: " << *it << " it2: " << *it2 << " it3: " << *it3;
	}
	//int *tab;
	//std::vector<int>::iterator it3(tab);
}
void	ft_Iterators()
{
	{
		ft::vector<int>vec;

		vec.push_back(10);
		vec.push_back(255);
		vec.push_back(456);
		ft::vector<int>::iterator it;
		ft::vector<int>::iterator it2 = vec.begin();
		std::cout << "it: " << *it << " it2: " << *it2;
	}
	std::cout << std::endl;
	{
		ft::vector<int>vec;

		vec.push_back(10);
		vec.push_back(255);
		vec.push_back(456);
		ft::vector<int>::iterator it = vec.begin();
		ft::vector<int>::iterator it2(it);
		ft::vector<int>::iterator it3;
		it3 = it;
		std::cout << "it: " << *it << " it2: " << *it2 << " it3: " << *it3;
	}
	//int *tab;
	//ft::vector<int>::iterator it3(tab);
}
void	std_begin()
{
	{
		std::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	{
		std::vector<int> myvector;
		myvector.push_back(10);
		myvector.push_back(20);
		std::vector<int>::iterator it = myvector.begin();
		std::vector<int>::iterator it1 = myvector.end();//-2

		std::cout << *it  << " == "<< *it1 << " it == it1 " << (it == it1);
	}
}
void	ft_begin()
{
	{
		ft::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
	}
	std::cout << std::endl;
	{
		ft::vector<int> myvector;
		myvector.push_back(10);
		myvector.push_back(20);
		ft::vector<int>::iterator it = myvector.begin();
		ft::vector<int>::iterator it1 = myvector.end();//-2

		std::cout << *it  << " == "<< *it1 << " it == it1 " << (it == it1);
	}
}
void	std_operator_increment_decrement()
{
	{
		std::vector<float>vec;
		std::vector<float>::iterator it;

		vec.push_back(10.3);
		vec.push_back(15.4);
		vec.push_back(23.5);
		it = vec.begin();

		std::cout << *(it++) << " ";
		std::cout << *(++it) << " ";
	}
	/*std::cout << "\n";
	{
		std::vector<float>vec;
		std::vector<float>::iterator it;

		vec.push_back(10.3);
		vec.push_back(12.4);
		vec.push_back(13.5);
		it = vec.end();
		it--;
		std::cout << *it << " ";
	}*/
}void	ft_operator_increment_decrement()
{
	{
		ft::vector<float>vec;
		ft::vector<float>::iterator it;

		vec.push_back(10.3);
		vec.push_back(15.4);
		vec.push_back(23.5);
		it = vec.begin();

		std::cout << *(it++) << " ";
		std::cout << *(++it) << " ";
	}
	/*std::cout << "\n";
	{
		ft::vector<float>vec;
		ft::vector<float>::iterator it;

		vec.push_back(10.3);
		vec.push_back(12.4);
		vec.push_back(13.5);
		it = vec.end();
		it--;
		std::cout << *it << " ";
	}*/
}
void	Iterators()
{
	//tester(std_Iterators, ft_Iterators, "Iterators");
	//tester(std_Iterators, ft_Iterators, "Iterators");
	//tester(std_begin, ft_begin, "begin");
	tester(std_operator_increment_decrement, ft_operator_increment_decrement, "operator_increment_decrement");
}

int main()
{
	//Constructor_Destructor_Assignator();
	//Element_access();
	//Capacity();
	Iterators();

	return 0;
}

/*
ID test:
- test throw expetion for each function
- dans test diff les resultat print en vert ok rouge bad
- template au lieu de deux fonction casi identique

Need more explication:
- begin return object(comment ca marche)
- typename
*/