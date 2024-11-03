#include "interface.hpp"

namespace inner
{
std::string strtrim(const std::string &str, const std::string &trimed_set)
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
bool isValidLine(const std::string &line, int (*bool_func)(int))
{
	return (!line.empty() && inner::isAllOf(line, bool_func));
}
}  // namespace inner

bool interface::getLine(std::string &input, const std::string &prompt, const std::string &trim_set)
{
	std::string line;

	std::cout << prompt;
	if (!std::getline(std::cin, line))
		return (false);
	input = inner::strtrim(line, trim_set);
	return (true);
}

void interface::search::err()
{
	if (std::cin.eof())
		return;
	if (std::cin.bad()) {
		std::cerr << "The stream is corrupted" << std::endl;
		std::exit(1);
	}
	if (std::cin.fail()) {
		std::cerr << "cin failed" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		return;
	}
}

void interface::search::handle(PhoneBook *phonebook)
{
	std::string input;
	if (!interface::getLine(input, "Enter id: ")) {
		search::err();
		return;
	}

	std::stringstream ss(input);
	unsigned int      id;
	if (!(ss >> id)) {
		std::cerr << "Invalid ID format" << std::endl;
		return;
	}
	phonebook->search(id);
}

void interface::add::err()
{
	if (std::cin.good())
		std::cerr << "The input string is invalid or empty" << std::endl;
	if (std::cin.bad()) {
		std::cerr << "The stream is corrupted" << std::endl;
		std::exit(1);
	}
	if (std::cin.eof())
		return;
	if (std::cin.fail()) {
		std::cerr << "cin failed" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		return;
	}
}

void interface::add::handle(PhoneBook *phonebook)
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	if (!getLine(first_name, "Enter first_name: ") ||
			!inner::isValidLine(first_name, std::isalnum) ||
			!getLine(last_name, "Enter last_name: ") ||
			!inner::isValidLine(last_name, std::isalnum) ||
			!getLine(nickname, "Enter nickname: ") || !inner::isValidLine(nickname, std::isalnum) ||
			!getLine(phone_number, "Enter phone_number: ") ||
			!inner::isValidLine(phone_number, std::isdigit) ||
			!getLine(darkest_secret, "Enter darkest_secret: ") ||
			!inner::isValidLine(darkest_secret, std::isalnum)) {
		add::err();
		return;
	}
	Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	phonebook->add(new_contact);
}