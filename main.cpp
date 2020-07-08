/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:34:50 by user42            #+#    #+#             */
/*   Updated: 2020/07/08 17:30:17 by froussel         ###   ########.fr       */
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
void	std_assignation()
{
	{
		std::vector<int> vec1;
		vec1.reserve(100);
		vec1.push_back(10);
		vec1.push_back(20);
		vec1.push_back(30);
		vec1.push_back(40);
		vec1.push_back(456);
		vec1.push_back(45460);
		//std::vector<int> vec2 = vec1; Like that is copy constructor
		std::vector<int> vec2;
		vec2 = vec1;
		std::cout<< "capacity: " << vec1.capacity() << " size: " << vec1.size();
		std::cout << " vec1.begin() = " << *vec1.begin() << " vec1.end() = " << *(vec1.end() - 1) << std::endl;
		vec1.resize(3);
		std::cout<< "capacity: " << vec2.capacity() << " size: " << vec2.size();
		std::cout << " vec2.begin() = " << *vec2.begin() << " vec2.end() = " << *(vec2.end() - 1) << std::endl;
		int i = 0;
		for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
		{
			std::cout << "vector[" << i << "] = " << *it << " ";
			i++;
		}
		i = 0;
		std::cout << std::endl;
		for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
		{
			std::cout << "vector[" << i << "] = " << *it << " ";
			i++;
		}
	}
	std::cout << std::endl;
	{
		std::vector<int> foo (3,0);
  		std::vector<int> bar (5,0);

  		bar = foo;
  		foo = std::vector<int>();

  		std::cout << "Size of foo: " << int(foo.size()) << '\n';
  		std::cout << "Size of bar: " << int(bar.size());
	}
}
void	ft_assignation()
{
	{
		ft::vector<int> vec1;
		vec1.reserve(100);
		vec1.push_back(10);
		vec1.push_back(20);
		vec1.push_back(30);
		vec1.push_back(40);
		vec1.push_back(456);
		vec1.push_back(45460);
		//ft::vector<int> vec2 = vec1; Like that is copy constructor
		ft::vector<int> vec2;
		vec2 = vec1;
		std::cout<< "capacity: " << vec1.capacity() << " size: " << vec1.size();
		std::cout << " vec1.begin() = " << *vec1.begin() << " vec1.end() = " << *(vec1.end() - 1) << std::endl;
		vec1.resize(3);
		std::cout<< "capacity: " << vec2.capacity() << " size: " << vec2.size();
		std::cout << " vec2.begin() = " << *vec2.begin() << " vec2.end() = " << *(vec2.end() - 1) << std::endl;
		int i = 0;
		for (ft::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
		{
			std::cout << "vector[" << i << "] = " << *it << " ";
			i++;
		}
		i = 0;
		std::cout << std::endl;
		for (ft::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
		{
			std::cout << "vector[" << i << "] = " << *it << " ";
			i++;
		}
	}
	std::cout << std::endl;
	{
		ft::vector<int> foo (3,0);
  		ft::vector<int> bar (5,0);

  		bar = foo;
  		foo = ft::vector<int>();

  		std::cout << "Size of foo: " << int(foo.size()) << '\n';
  		std::cout << "Size of bar: " << int(bar.size());
	}
}
void	Constructor_Destructor_Assignator()
{
	//tester(std_constructor, ft_constructor, "Constructor");
	tester(std_assignation, ft_assignation, "assignation");
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
void	Iterators()
{
	//tester(std_Iterators, ft_Iterators, "Iterators");
	//tester(std_Iterators, ft_Iterators, "Iterators");
	//tester(std_begin, ft_begin, "begin");
}


/*
**	ClassIterator
*/
void	std_construct_assign()
{
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
}
void	ft_construct_assign()
{
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
}
void	std_equivalent()
{
	std::vector<double>vec;
	vec.push_back(15.6);
	std::vector<double>::iterator it = vec.begin();
	std::vector<double>::iterator it2 = vec.end();

	std::cout<< "it == it2: "<< (it == it2) << std::endl;
	std::cout<< "it != it2: "<< (it != it2) << std::endl;
	it2 = vec.begin();
	std::cout<< "it == it2: "<< (it == it2) << std::endl;
	std::cout<< "it != it2: "<< (it != it2) << std::endl;

}
void	ft_equivalent()
{
	ft::vector<double>vec;
	vec.push_back(15.6);
	ft::vector<double>::iterator it = vec.begin();
	ft::vector<double>::iterator it2 = vec.end();

	std::cout<< "it == it2: "<< (it == it2) << std::endl;
	std::cout<< "it != it2: "<< (it != it2) << std::endl;
	it2 = vec.begin();
	std::cout<< "it == it2: "<< (it == it2) << std::endl;
	std::cout<< "it != it2: "<< (it != it2);

}
void	std_access()
{
	std::vector<int>vecint;
	vecint.push_back(15);
	vecint.push_back(15);
	std::vector<std::vector<int> >vec;
	vec.push_back(vecint);

	std::vector<std::vector<int> >::iterator it = vec.begin();


	std::cout << "it->: " << it->capacity();
}
void	ft_access()
{
	ft::vector<int>vecint;
	vecint.push_back(15);
	vecint.push_back(15);
	ft::vector<ft::vector<int> >vec;
	//vec.push_back(vecint);

	//ft::vector<ft::vector<int> >::iterator it = vec.begin();


	//std::cout << "it->: " << it->capacity();
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

		std::cout << *it++ << " ";
		std::cout << *++it << " ";
		std::cout << *it-- << " ";
		std::cout << *--it << " ";
	}
}
void	ft_operator_increment_decrement()
{
	{
		ft::vector<float>vec;
		ft::vector<float>::iterator it;

		vec.push_back(10.3);
		vec.push_back(15.4);
		vec.push_back(23.5);
		it = vec.begin();

		std::cout << *it++ << " ";
		std::cout << *++it << " ";
		std::cout << *it-- << " ";
		std::cout << *--it << " ";
	}
}
void	std_addition_soustraction()
{
	std::vector<float>vec;
	vec.push_back(10.3);
	vec.push_back(15.4);
	vec.push_back(23.5);
	std::vector<float>::iterator it = vec.begin();
	std::vector<float>::iterator it2 = it + 1;
	std::cout << "it: " << *it << " it2 : " << *it2;
	it += 1;
	std::cout << " it: " << *it << " *(it2 + 1): " << *(it2 + 1) << " *it2 + 1: " << *it2 + 1 << std::endl;
	it2 += 2;
	std::cout << " it - 1: " << *(it - 1) << " it2 - 2: " << *(it2 - 2);
}
void	ft_addition_soustraction()
{
	ft::vector<float>vec;
	vec.push_back(10.3);
	vec.push_back(15.4);
	vec.push_back(23.5);
	ft::vector<float>::iterator it = vec.begin();
	ft::vector<float>::iterator it2 = it + 1;
	std::cout << "it: " << *it << " it2 : " << *it2;
	it += 1;
	std::cout << " it: " << *it << " *(it2 + 1): " << *(it2 + 1) << " *it2 + 1: " << *it2 + 1 << std::endl;
	it2 += 2;
	std::cout << " it - 1: " << *(it - 1) << " it2 - 2: " << *(it2 - 2);

}
void	std_compare()
{
	std::vector<int>vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(4);
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator it2 = it + 1;
	std::cout<< "it < it2= " << (it < it2) << " it > it2= " << (it > it2) << std::endl;
	it2 = it2 - 1; 
	std::cout<< "it <= it2= " << (it <= it2) << " it >= it2= " << (it >= it2);
}
void	ft_compare()
{
	ft::vector<int>vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(4);
	ft::vector<int>::iterator it = vec.begin();
	ft::vector<int>::iterator it2 = it + 1;
	std::cout<< "it < it2= " << (it < it2) << " it > it2= " << (it > it2) << std::endl;
	it2 = it2 - 1; 
	std::cout<< "it <= it2= " << (it <= it2) << " it >= it2= " << (it >= it2);
}
void	std_selector()
{
	std::vector<float>vec;
	std::vector<float>::iterator it;

	vec.push_back(10.3);
	vec.push_back(15.4);
	vec.push_back(23.5);
	vec.push_back(2131.5);
	vec.push_back(110.5);
	it = vec.begin();
	int i = 0;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout<< "vecttor[" << i << "] = " << *it << " ";
		i++;
	}
}
void	ft_selector()
{
	ft::vector<float>vec;
	ft::vector<float>::iterator it;

	vec.push_back(10.3);
	vec.push_back(15.4);
	vec.push_back(23.5);
	vec.push_back(2131.5);
	vec.push_back(110.5);
	it = vec.begin();
	int i = 0;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout<< "vector[" << i << "] = " << *it << " ";
		i++;
	}
}
void	std_const_iterator()
{
	{
		std::vector<std::string>vec;
		
		vec.push_back("Coucou");
		vec.push_back("je");
		vec.push_back("suis");
		vec.push_back("ovale");

		const std::vector<std::string>vec_const(vec);

		int i = 0;
		for (std::vector<std::string>::const_iterator iter = vec_const.begin(); iter != vec_const.end(); ++iter)
		{
			//*iter = "changement"; Impossible cause const
			std::cout<< "vector[" << i << "] = " << *iter << " ";
			i++;
		}
	}
	{
		std::vector<std::string>vec;
		
		vec.push_back("Coucou");
		vec.push_back("je");
		vec.push_back("suis");
		vec.push_back("ovale");

		int i = 0;
		for (std::vector<std::string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
		{
			*iter = "changement";
			std::cout<< "vector[" << i << "] = " << *iter << " ";
			i++;
		}
	}
}
void	ft_const_iterator()
{
	{
		ft::vector<std::string>vec;
		
		vec.push_back("Coucou");
		vec.push_back("je");
		vec.push_back("suis");
		vec.push_back("ovale");

		const ft::vector<std::string>vec_const(vec);

		int i = 0;
		for (ft::vector<std::string>::const_iterator iter = vec_const.begin(); iter != vec_const.end(); ++iter)
		{
			//*iter = "changement"; Impossible cause const
			std::cout<< "vector[" << i << "] = " << *iter << " ";
			i++;
		}
	}
	{
		ft::vector<std::string>vec;
		
		vec.push_back("Coucou");
		vec.push_back("je");
		vec.push_back("suis");
		vec.push_back("ovale");

		int i = 0;
		for (ft::vector<std::string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
		{
			*iter = "changement";
			std::cout<< "vector[" << i << "] = " << *iter << " ";
			i++;
		}
	}
}
void	ClassIterator()
{
	//tester(std_construct_assign, ft_construct_assign, "construct_assign");
	//tester(std_equivalent, ft_equivalent, "equivalent");
	//tester(std_access, NULL, "access");
	//tester(std_operator_increment_decrement, ft_operator_increment_decrement, "operator_increment_decrement");
	//tester(std_addition_soustraction, ft_addition_soustraction, "addition_soustraction");
	//tester(std_compare, ft_compare, "compare");
	//tester(std_selector, ft_selector, "selector");
	tester(std_const_iterator, ft_const_iterator, "const_iterator");
}

int main()
{
	//Constructor_Destructor_Assignator();
	//Element_access();
	//Capacity();
	//Iterators();
	ClassIterator();

	return 0;
}

/*
ID test:
- test vc.end() after push back 
- test throw expetion for each function
- dans test diff les resultat print en vert ok rouge bad
- template au lieu de deux fonction casi identique

Need more explication:
- begin return object(comment ca marche)
- typename
*/