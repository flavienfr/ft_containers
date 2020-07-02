/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: froussel <froussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:34:50 by user42            #+#    #+#             */
/*   Updated: 2020/07/02 21:19:31 by froussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#include "vector.hpp"
#include <vector>

void	std_constructor();
void	ft_constructor();
void	Constructor_Destructor_Assignator();

void	std_max_size();
void	ft_max_size();
void	Capacity();

void	std_operator_selection();
void	ft_operator_selection();
void	Element_access();

int main()
{
	//SEGFAULT
	//std::vector<int>test;
	//std::cout << test[0] << std::endl;
	//test_constructor();
	
	//Constructor_Destructor_Assignator();
	Element_access();

	Capacity();

	return 0;
}

void	tester(void (*pf_1)(), void (*pf_2)(), std::string text)
{
	std::cout.fill( '-' );

	std::cout << std::setw(50) << centered(text) << std::endl;
	pf_1();
	std::cout << std::endl;
	std::cout << std::setw(50) << centered("STD vs FT") << std::endl;
	pf_2();
	std::cout << std::endl;
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

		for (int x : vect) 
			std::cout << x << " ";
	}
	{
		int n = 3;
		std::vector<int> vect(n, 10); 

		for (int x : vect) 
			std::cout << x << " "; 
	}
	{
		std::vector<int> vect{ 10, 20, 30 }; 

    	for (int x : vect) 
    		std::cout << x << " "; 
	}
	{
		int arr[] = { 10, 20, 30 }; 
		int n = sizeof(arr) / sizeof(arr[0]); 

		std::vector<int> vect(arr, arr + n); 

		for (int x : vect) 
			std::cout << x << " "; 
	}
	{
		std::vector<int> vect1{ 10, 20, 30 }; 
		std::vector<int> vect2(vect1.begin(), vect1.end());

		for (int x : vect2) 
			std::cout << x << " ";
	}
}
void	ft_constructor()
{
	/*{
		ft::vector<int> vect;  
		vect.push_back(10); 
		vect.push_back(20); 
		vect.push_back(30); 

		for (int x : vect) 
			std::cout << x << " ";
	}
	{
		int n = 3;
		ft::vector<int> vect(n, 10); 

		for (int x : vect) 
			std::cout << x << " "; 
	}
	{
		ft::vector<int> vect{ 10, 20, 30 }; 

    	for (int x : vect) 
    		std::cout << x << " "; 
	}
	{
		int arr[] = { 10, 20, 30 }; 
		int n = sizeof(arr) / sizeof(arr[0]); 

		ft::vector<int> vect(arr, arr + n); 

		for (int x : vect) 
			std::cout << x << " "; 
	}
	{
		ft::vector<int> vect1{ 10, 20, 30 }; 
		ft::vector<int> vect2(vect1.begin(), vect1.end());

		for (int x : vect2) 
			std::cout << x << " "; 
	}*/
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
void	Capacity()
{
	tester(std_max_size, ft_max_size, "max_size");
	tester(std_capacity, ft_capacity, "capacity");
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
ID test:
- capavity
- dans test diff les resultat print en vert ok rouge bad
- template au lieu de deux fonction casi identique
*/