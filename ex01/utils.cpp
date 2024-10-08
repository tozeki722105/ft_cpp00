#include "utils.hpp"

bool is_all_of(const std::string str, int(*bool_func)(int))
{
	size_t len = str.length();
	for(size_t i = 0; i < len; i++)
	{
		if (!bool_func(str[i]))
			return (false);
	}
	return (true);
}

void print_fixed_width(std::string str, int width)
{
	if (width < 0)
	{
		std::cout << str;
		return ;
	}
	unsigned int uwidth = static_cast<unsigned int>(width);
	if (str.length() > uwidth)
	{
		std::cout << str.substr(0, uwidth) << '.';
		return ;
	}
	if (str.length() < uwidth)
	{
		std::cout << std::setw(width) << str;
		return ;
	}
	std::cout << str;
}