#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <string>
#include <iomanip>

bool is_all_of(const std::string str, int(*bool_func)(int));
void print_fixed_width(std::string str, int width);

#endif