#include "interface.hpp"

namespace inner
{
std::string strTrim(const std::string &str, const std::string &trimed_set)
{
	size_t start = str.find_first_not_of(trimed_set);
	size_t end = str.find_last_not_of(trimed_set);

	if (end == std::string::npos || start == std::string::npos || end < start)
		return ("");
	return (str.substr(start, end - start + 1));
}
bool isAllOf(const std::string &str, int (*bool_func)(int))
{
	size_t len = str.length();
	for (size_t i = 0; i < len; i++) {
		if (!bool_func(str[i]))
			return (false);
	}
	return (true);
}
}  // namespace inner

bool interface::isValidLine(const std::string &line, int (*bool_func)(int))
{
	return (!line.empty() && inner::isAllOf(line, bool_func));
}

bool interface::getValidInput(
		std::string &input, const std::string &prompt, const std::string &trim_set)
{
	std::string line;

	std::cout << prompt;
	if (!std::getline(std::cin, line))
		return (false);
	input = inner::strTrim(line, trim_set);
	return (true);
	// std::getline(std::cin, line);
	// if (std::cin.eof())
	// 	return (false);
	// if (std::cin.bad()) {
	// 	std::cerr << "The stream is corrupted" << std::endl;
	// 	std::exit(1);
	// }
	// if (std::cin.fail()) {
	// 	std::cerr << "cin failed" << std::endl;
	// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// 	std::cin.clear();
	// 	return (false);
	// }
}