#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

namespace interface
{
bool getValidInput(
		std::string &input, const std::string &prompt, const std::string &trim_set = "\t ");
bool isValidLine(const std::string &line, int (*bool_func)(int));
}  // namespace interface

#endif