#include "validate.hpp"

bool validation::isAllOf(const std::string &str, int (*bool_func)(int))
{
	size_t len = str.length();
	for (size_t i = 0; i < len; i++) {
		if (!bool_func(str[i]))
			return (false);
	}
	return (true);
}

bool validation::isValidLine(const std::string &line, int (*bool_func)(int))
{
	return (!line.empty() && isAllOf(line, bool_func));
}
