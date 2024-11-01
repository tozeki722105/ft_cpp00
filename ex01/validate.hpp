#ifndef VALIDATE_HPP
#define VALIDATE_HPP

#include <iostream>
#include <string>

namespace validation
{
bool isAllOf(const std::string &str, int (*bool_func)(int));
bool isValidLine(const std::string &line, int (*bool_func)(int));
}  // namespace validation

#endif