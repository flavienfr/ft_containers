/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:34:50 by user42            #+#    #+#             */
/*   Updated: 2020/08/08 12:24:07 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#define PRINT_SIZE_CAPACITY(vec) std::cout << "Size= " << vec.size() << " Capacity= " << vec.capacity();
#define PRINT_VECTOR(vec) for (size_t i = 0; i < vec.size(); ++i) std::cout <<vec[i]<< " ";
#define PRINT_VECTOR_CONST(type, vec) for (type::const_iterator it = vec.begin(); it != vec.end(); ++it) std::cout <<*it<< " ";
#define PRINT_VECTOR_REVERSE(type, vec) for (type::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) std::cout <<*it<< " ";
#define PRINT_VECTOR_REVERSE_CONST(type, vec) for (type::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) std::cout <<*it<< " ";
#define NEW_LINE std::cout << std::endl;

//	Constructor Destructor Assignator
static void	std_constructor()
{
	{
		std::vector<int>vect;  
		vect.push_back(10); 
		vect.push_back(20); 
		vect.push_back(30); 

		for (size_t i = 0; i < vect.size(); i++)
			std::cout << vect[i] << " ";
	}
	{
		int n = 3;
		std::vector<int> vect(n, 10); 

		for (size_t i = 0; i < vect.size(); i++)
			std::cout << vect[i] << " ";
	}
	{
		int arr[] = { 10, 20, 30 }; 
		int n = sizeof(arr) / sizeof(arr[0]); 

		std::vector<int> vect(arr, arr + n);

		for (size_t i = 0; i < vect.size(); i++)
			std::cout << vect[i] << " "; 
	}
	{
		std::vector<int> vect1;
		vect1.push_back(10);
		vect1.push_back(20);
		vect1.push_back(30);
		std::vector<int> vect2(vect1.begin(), vect1.end());

		for (size_t i = 0; i < vect2.size(); i++)
			std::cout << vect2[i] << " ";
	}
}
static void	ft_constructor()
{
	{
		ft::vector<int>vect;  
		vect.push_back(10); 
		vect.push_back(20); 
		vect.push_back(30); 

		for (size_t i = 0; i < vect.size(); i++)
			std::cout << vect[i] << " ";
	}
	{
		int n = 3;
		ft::vector<int> vect(n, 10); 

		for (size_t i = 0; i < vect.size(); i++)
			std::cout << vect[i] << " ";
	}
	{
		int arr[] = { 10, 20, 30 }; 
		int n = sizeof(arr) / sizeof(arr[0]); 

		ft::vector<int> vect(arr, arr + n);

		for (size_t i = 0; i < vect.size(); i++)
			std::cout << vect[i] << " "; 
	}
	{
		ft::vector<int> vect1;
		vect1.push_back(10);
		vect1.push_back(20);
		vect1.push_back(30);
		ft::vector<int> vect2(vect1.begin(), vect1.end());

		for (size_t i = 0; i < vect2.size(); i++)
			std::cout << vect2[i] << " ";
	}
}
static void	std_assignation()
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
static void	ft_assignation()
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
		ft::vector<int>foo(3,0);
  		ft::vector<int>bar(5,0);

  		bar = foo;
  		foo = ft::vector<int>();

  		std::cout << "Size of foo: " << int(foo.size()) << '\n';
  		std::cout << "Size of bar: " << int(bar.size());
	}
}
static void	Constructor_Destructor_Assignator()
{
	tester(std_constructor, ft_constructor, "Constructor");
	tester(std_assignation, ft_assignation, "assignation");
}

//	Capacity
static void	std_max_size()
{
	std::vector<int>vec;
	std::cout << vec.max_size() << std::endl;	
	std::vector<char>vec2;
	std::cout << vec2.max_size() << std::endl;
	std::vector<float>vec3;
	std::cout << vec3.max_size() << std::endl;
	std::vector<std::string>vec4;
	std::cout << vec4.max_size() << std::endl;
}
static void	ft_max_size()
{
	ft::vector<int>vec;
	std::cout << vec.max_size() << std::endl;	
	ft::vector<char>vec2;
	std::cout << vec2.max_size() << std::endl;
	ft::vector<float>vec3;
	std::cout << vec3.max_size() << std::endl;
	ft::vector<std::string>vec4;
	std::cout << vec4.max_size() << std::endl;
}
static void	std_resize()
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
static void	ft_resize()
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
static void	std_capacity()
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
static void	ft_capacity()
{
	{
		std::vector<int> myvector(215);
		std::cout << myvector.capacity();
	}
	std::cout << std::endl;
	{
		ft::vector<int> myvector;

		for (int i=0; i<100; i++)
			myvector.push_back(i);
		std::cout << "size: " << myvector.size() << '\n';
		std::cout << "capacity: " << myvector.capacity() << '\n';
		std::cout << "max_size: " << myvector.max_size() << '\n';
	}
}
static void	std_empty()
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
static void	ft_empty()
{
	ft::vector<int> myvector;
	int sum (0);
	for (int i=1;i<=10;i++) myvector.push_back(i);
	while (!myvector.empty())
	{
	   sum += myvector.back();
	   myvector.pop_back();
	}
	std::cout << "total: " << sum;
}
static void	std_reserve()
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
			std::cout << "Length error: " << le.what();
  		}
	}
}
static void	ft_reserve()
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
			std::cout << "Length error: " << le.what();
  		}
	}
}
static void	Capacity()
{
	tester(std_max_size, ft_max_size, "max_size");
	tester(std_capacity, ft_capacity, "capacity");
	tester(std_resize, ft_resize, "resize");
	tester(std_empty, ft_empty, "empty");
	tester(std_reserve, ft_reserve, "reserve");
}

//	Element access
static void	std_operator_selection()
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
static void	ft_operator_selection()
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
static void	std_at()
{
	std::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:";
	try
	{
		std::cout << ' ' << myvector.at(15);
	}
	catch(const std::exception& e)
	{
		std::cout  << '\n' << e.what();
	}
}
static void	ft_at()
{
	ft::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:";
	try
	{
		std::cout << ' ' << myvector.at(15);	
	}
	catch(const std::exception& e)
	{
		std::cout  << '\n' << e.what();
	}
}
static void	std_font_back()
{
	{
		std::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);
		// now front equals 78, and back 16
		myvector.front() -= myvector.back();
		std::cout << "myvector.front() is now " << myvector.front();
	}
	std::cout << '\n';
	{
		std::vector<int> myvector;	
		myvector.push_back(10);	
		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}	
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
	}
}
static void	ft_font_back()
{
	{
		ft::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);
		// now front equals 78, and back 16
		myvector.front() -= myvector.back();
		std::cout << "myvector.front() is now " << myvector.front();
	}
	std::cout << '\n';
	{
		ft::vector<int> myvector;	
		myvector.push_back(10);	
		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}	
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
	}
}
static void	Element_access()
{
	tester(std_operator_selection, ft_operator_selection, "operator_selection");
	tester(std_at, ft_at, "at");
	tester(std_font_back, ft_font_back, "font_back");
}

//	Iterators
static void	std_begin()
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
		std::vector<int>::iterator it1 = myvector.end() - 1;

		std::cout << *it  << " == "<< *it1 << " it == it1 " << (it == it1);
	}
}
static void	ft_begin()
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
		ft::vector<int>::iterator it1 = myvector.end() - 1;

		std::cout << *it  << " == "<< *it1 << " it == it1 " << (it == it1);
	}
}
static void	std_const_iterator_2()
{
	std::vector<double>vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	PRINT_VECTOR_CONST(std::vector<double>, vec);NEW_LINE;
	PRINT_VECTOR(vec);NEW_LINE;
	PRINT_VECTOR_REVERSE_CONST(std::vector<double>, vec);NEW_LINE;
	PRINT_VECTOR_REVERSE(std::vector<double>, vec);
}
static void	ft_const_iterator_2()
{
	ft::vector<double>vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	PRINT_VECTOR_CONST(ft::vector<double>, vec);NEW_LINE;
	PRINT_VECTOR(vec);NEW_LINE;
	PRINT_VECTOR_REVERSE_CONST(ft::vector<double>, vec);NEW_LINE;
	PRINT_VECTOR_REVERSE(ft::vector<double>, vec);
}
static void	Iterators()
{
	tester(std_begin, ft_begin, "begin");
	tester(std_const_iterator_2, ft_const_iterator_2, "const_iterator_2");
}

//	ClassIterator
static void	std_construct_assign()
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
static void	ft_construct_assign()
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
static void	std_equivalent()
{
	std::vector<double>vec;
	vec.push_back(15.6);
	std::vector<double>::iterator it = vec.begin();
	std::vector<double>::iterator it2 = vec.end();

	std::cout<< "it == it2: "<< (it == it2) << std::endl;
	std::cout<< "it != it2: "<< (it != it2) << std::endl;
	it2 = vec.begin();
	std::cout<< "it == it2: "<< (it == it2) << std::endl;
	std::cout<< "it != it2: "<< (it != it2);

}
static void	ft_equivalent()
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
static void	std_access()
{
	std::vector<int>vecint;
	vecint.push_back(15);
	vecint.push_back(15);
	std::vector<std::vector<int> >vec;
	vec.push_back(vecint);

	std::vector<std::vector<int> >::iterator it = vec.begin();

	std::cout << "it->: " << it->capacity();
}
static void	ft_access()
{
	ft::vector<int>vecint;
	vecint.push_back(15);
	vecint.push_back(15);
	ft::vector<ft::vector<int> >vec;
	vec.push_back(vecint);

	ft::vector<ft::vector<int> >::iterator it = vec.begin();

	std::cout << "it->: " << it->capacity();
}
static void	std_operator_increment_decrement()
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
static void	ft_operator_increment_decrement()
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
static void	std_addition_soustraction()
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
	{
		std::vector<float>vec;
		vec.push_back(10.3);
		vec.push_back(15.4);
		vec.push_back(23.5);
		std::vector<float>::iterator it = vec.begin();
		std::vector<float>::iterator it2 = vec.end() - 1;

		std::cout << " it2 - it: " << it2 - it;
		std::cout << " it - it2: " << it - it2;
		std::cout << " it - it: " << it - it;
	}
}
static void	ft_addition_soustraction()
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
	{
		ft::vector<float>vec;
		vec.push_back(10.3);
		vec.push_back(15.4);
		vec.push_back(23.5);
		ft::vector<float>::iterator it = vec.begin();
		ft::vector<float>::iterator it2 = vec.end() - 1;

		std::cout << " it2 - it: " << it2 - it;
		std::cout << " it - it2: " << it - it2;
		std::cout << " it - it: " << it - it;
	}
}
static void	std_compare()
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
static void	ft_compare()
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
static void	std_selector()
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
		std::cout<< "vector[" << i << "] = " << *it << " ";
		i++;
	}
}
static void	ft_selector()
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
static void	std_const_iterator()
{
	{
		std::vector<std::string>vec;
		
		vec.push_back("Coucou");
		vec.push_back("je");
		vec.push_back("suis");
		vec.push_back("ovale");

		const std::vector<std::string>vec_const(vec);
		//std::vector<std::string>vec_const(vec); not possible with ft why ?


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
static void	ft_const_iterator()
{
	{
		ft::vector<std::string>vec;
		
		vec.push_back("Coucou");
		vec.push_back("je");
		vec.push_back("suis");
		vec.push_back("ovale");

		const ft::vector<std::string>vec_const(vec);
		//ft::vector<std::string>vec_const(vec); not possible with ft why ?

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
static void	std_reverse_iterator()
{
  	std::vector<int> myvector (5);  // 5 default-constructed ints

  	std::vector<int>::reverse_iterator rit = myvector.rbegin();

  	int i=0;
  	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
  		*rit = ++i;
  	std::cout << "myvector contains:";
  	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  		std::cout << ' ' << *it;
}
static void	ft_reverse_iterator()
{
  	ft::vector<int> myvector (5);  // 5 default-constructed ints

  	ft::vector<int>::reverse_iterator rit = myvector.rbegin();

  	int i=0;
  	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
  		*rit = ++i;
  	std::cout << "myvector contains:";
  	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  		std::cout << ' ' << *it;
}
static void	ClassIterator()
{
	tester(std_construct_assign, ft_construct_assign, "construct_assign");
	tester(std_equivalent, ft_equivalent, "equivalent");
	tester(std_access, ft_access, "access");
	tester(std_operator_increment_decrement, ft_operator_increment_decrement, "operator_increment_decrement");
	tester(std_addition_soustraction, ft_addition_soustraction, "addition_soustraction");
	tester(std_compare, ft_compare, "compare");
	tester(std_selector, ft_selector, "selector");
	tester(std_const_iterator, ft_const_iterator, "const_iterator");
	tester(std_reverse_iterator, ft_reverse_iterator, "reverse_iterator");
}

//	Modifiers
static void	std_assign()
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);

	std::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign(it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << " capacity: " << first.capacity() << '\n';
	std::cout << "Size of second: " << int (second.size()) << " capacity: " << second.capacity() << '\n';
	std::cout << "Size of third: " << int (third.size()) << " capacity: " << third.capacity() << '\n';

	PRINT_VECTOR(first);
	PRINT_VECTOR(second);
	PRINT_VECTOR(third);
}
static void	ft_assign()
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);

	ft::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign(it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << " capacity: " << first.capacity() << '\n';
	std::cout << "Size of second: " << int (second.size()) << " capacity: " << second.capacity() << '\n';
	std::cout << "Size of third: " << int (third.size()) << " capacity: " << third.capacity() << '\n';

	PRINT_VECTOR(first);
	PRINT_VECTOR(second);
	PRINT_VECTOR(third);
}
static void	std_clear()
{
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	myvector.push_back (300);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	//size_t post_size = myvector.size();
	std::cout <<"pre clear, _size: " << myvector.size() << " _capacity: " << myvector.capacity()<<std::endl;
	myvector.clear();
	std::cout <<"post clear, _size: " << myvector.size() << " _capacity: " << myvector.capacity()<<std::endl;
	
	//std::cout << "my clear vector contains:";
	//for (size_t i=0; i<post_size; i++)
	//	std::cout << ' ' << myvector[i];
	//std::cout << '\n';

	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	  std::cout << ' ' << myvector[i];
}
static void	ft_clear()
{
	ft::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	myvector.push_back (300);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	//size_t post_size = myvector.size();
	std::cout <<"pre clear, _size: " << myvector.size() << " _capacity: " << myvector.capacity()<<std::endl;
	myvector.clear();
	std::cout <<"post clear, _size: " << myvector.size() << " _capacity: " << myvector.capacity()<<std::endl;
	
	//std::cout << "my clear vector contains:";
	//for (size_t i=0; i<post_size; i++)
	//	std::cout << ' ' << myvector[i];
	//std::cout << '\n';

	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	  std::cout << ' ' << myvector[i];
}
static void	std_pop_back()
{
	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
	  sum+=myvector.back();
	  myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << std::endl;
	std::cout << "myvector.empty(): " << myvector.empty() << " size " << myvector.size();
}
static void	ft_pop_back()
{
	ft::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
	  sum+=myvector.back();
	  myvector.pop_back();
	}
	std::cout << "The elements of myvector add up to " << sum << std::endl;
	std::cout << "myvector.empty(): " << myvector.empty() << " size " << myvector.size();
}
static void	std_erase()
{
	{
		std::vector<int> myvector;

		for (int i=1; i<=10; i++) myvector.push_back(i);

		std::vector<int>::iterator ret;
		ret = myvector.erase (myvector.begin()+5);
		std::cout << "ret= " << *ret << std::endl;
		ret = myvector.erase (myvector.begin(),myvector.begin()+3);
		std::cout << "ret= " << *ret << std::endl;

		PRINT_SIZE_CAPACITY(myvector);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
	}
	std::cout<< std::endl;
	{
		std::vector<int>test(1000);
		std::vector<std::vector<int> > myvector;
	
		for (int i=1; i<=10; i++) myvector.push_back(test);
	
		myvector.erase (myvector.begin()+5);
		myvector.erase (myvector.begin(),myvector.begin()+3);

		PRINT_SIZE_CAPACITY(myvector);
	
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i][0];
	}
}
static void	ft_erase()
{
	{
		ft::vector<int> myvector;

		for (int i=1; i<=10; i++) myvector.push_back(i);

		ft::vector<int>::iterator ret;
		ret = myvector.erase (myvector.begin()+5);
		std::cout << "ret= " << *ret << std::endl;
		ret = myvector.erase (myvector.begin(),myvector.begin()+3);
		std::cout << "ret= " << *ret << std::endl;

		PRINT_SIZE_CAPACITY(myvector);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
	}
	std::cout<< std::endl;
	{
		std::vector<int>test(1000);
		ft::vector<std::vector<int> > myvector;
	
		for (int i=1; i<=10; i++) myvector.push_back(test);
	
		myvector.erase (myvector.begin()+5);
		myvector.erase (myvector.begin(),myvector.begin()+3);

		PRINT_SIZE_CAPACITY(myvector);
	
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i][0];
	}
}
static void	std_insert()
{
	{
		std::vector<int>vec(4);

		PRINT_SIZE_CAPACITY(vec);NEW_LINE;
		vec.insert(vec.end() , 40);
		PRINT_SIZE_CAPACITY(vec);NEW_LINE;

		PRINT_VECTOR(vec);
	}
	NEW_LINE;
	{
		std::vector<int>vec(5);
		
		vec.insert(vec.end()-3 ,2 , 42);
		PRINT_SIZE_CAPACITY(vec);NEW_LINE;

		PRINT_VECTOR(vec);
	}
	NEW_LINE;
	{
  		std::vector<int> myvector (3,100);
  		std::vector<int>::iterator it;

  		it = myvector.begin();
		std::cout << "it= " << *it << std::endl;
  		it = myvector.insert(it , 200 );
		std::cout << "it= " << *it << std::endl;

  		myvector.insert (it,2,300);
  		it = myvector.begin();

  		std::vector<int> anothervector (2,400);
  		myvector.insert (it+2,anothervector.begin(),anothervector.end());

  		int myarray [] = { 501,502,503 };
  		myvector.insert (myvector.begin(), myarray, myarray+3);

		PRINT_SIZE_CAPACITY(myvector);NEW_LINE;
  		std::cout << "myvector contains:";
  		PRINT_VECTOR(myvector);
	}
}
static void	ft_insert()
{
	{
		ft::vector<int>vec(4);
	
		PRINT_SIZE_CAPACITY(vec);NEW_LINE;
		vec.insert(vec.end() , 40);
		PRINT_SIZE_CAPACITY(vec);NEW_LINE;

		PRINT_VECTOR(vec);
	}
	NEW_LINE;
	{
		ft::vector<int>vec(5);
		
		vec.insert(vec.end() -3 ,2 , 42);
		PRINT_SIZE_CAPACITY(vec);NEW_LINE;;

		PRINT_VECTOR(vec);
	}
	NEW_LINE;
	{
  		ft::vector<int> myvector (3,100);
  		ft::vector<int>::iterator it;

  		it = myvector.begin();
		std::cout << "it= " << *it << std::endl;
  		it = myvector.insert ( it , 200 );
		std::cout << "it= " << *it << std::endl;

  		myvector.insert (it,2,300);
  		it = myvector.begin();

  		ft::vector<int> anothervector (2,400);
  		myvector.insert (it+2,anothervector.begin(),anothervector.end());

  		int myarray [] = { 501,502,503 };
  		myvector.insert (myvector.begin(), myarray, myarray+3);
		
		PRINT_SIZE_CAPACITY(myvector);NEW_LINE;
  		std::cout << "myvector contains:";
  		PRINT_VECTOR(myvector);

	}
}
static void	std_swap()
{
	{
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		NEW_LINE;
		PRINT_SIZE_CAPACITY(foo);NEW_LINE;

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		NEW_LINE;
		PRINT_SIZE_CAPACITY(bar);
	}
}
static void	ft_swap()
{
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200
	
		foo.swap(bar);
	
		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		NEW_LINE;
		PRINT_SIZE_CAPACITY(foo);NEW_LINE;
	
		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		NEW_LINE;
		PRINT_SIZE_CAPACITY(bar);
	}
}

static void	Modifiers()
{
	tester(std_assign, ft_assign, "assign");
	tester(std_clear, ft_clear, "clear");
	tester(std_pop_back, ft_pop_back, "pop_back");
	tester(std_erase, ft_erase, "erase");//18 vs 43  push 18 vs 33 -> need test on mac
	tester(std_insert, ft_insert, "insert");//need memory test
	tester(std_swap, ft_swap, "swap");
}

//	Non_member
static void	std_swap2()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200

	swap(foo, bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	NEW_LINE;
	PRINT_SIZE_CAPACITY(foo);NEW_LINE;

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	NEW_LINE;
	PRINT_SIZE_CAPACITY(bar);
}
static void	ft_swap2()
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	swap(foo, bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	NEW_LINE;
	PRINT_SIZE_CAPACITY(foo);NEW_LINE;

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	NEW_LINE;
	PRINT_SIZE_CAPACITY(bar);
}
static void	std_relational_operators()
{
	std::vector<int> foo (2,100);   // three ints with a value of 10
	std::vector<int> bar (4,100);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}
static void	ft_relational_operators()
{
	ft::vector<int> foo (2,100);   // three ints with a value of 10
	ft::vector<int> bar (4,100);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}
static void	Non_member()
{
	tester(std_swap2, ft_swap2, "swap2");
	tester(std_relational_operators, ft_relational_operators, "relational_operators");
}

void vector_test()
{
	Constructor_Destructor_Assignator();
	Element_access();
	Capacity();
	Iterators();
	ClassIterator();
	Modifiers();
	Non_member();
}
