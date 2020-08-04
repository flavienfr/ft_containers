#ifndef MAIN_HPP
# define MAIN_HPP

# include "centered.hpp"
# include <fstream>

#include "list.hpp"
#include <list>
#include "vector.hpp"
#include <vector>
#include "map.hpp"
#include <map>
#include "stack.hpp"
#include <stack>

void	tester(void (*pf_1)(), void (*pf_2)(), std::string text);

void	vector_test();
void	list_test();
void	map_test();
void	stack_test();

#endif
