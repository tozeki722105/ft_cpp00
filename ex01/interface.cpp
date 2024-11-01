#include "interface.hpp"

namespace ft
{
std::string strtrim(const std::string &str, const std::string &trimed_set);
}  // namespace ft

std::string ft::strtrim(const std::string &str, const std::string &trimed_set)
{
	size_t start = str.find_first_not_of(trimed_set);
	size_t end = str.find_last_not_of(trimed_set);

	if (end == std::string::npos || start == std::string::npos || end < start)
		return ("");
	return (str.substr(start, end - start + 1));
}

bool interface::getValidInput(std::string &input, const std::string &prompt)
{
	std::string line;

	std::cout << prompt;
	std::getline(std::cin, line);
	if (std::cin.bad()) {
		std::cerr << "The stream is corrupted" << std::endl;
		std::exit(1);
	}
	if (std::cin.eof()) {
		std::cerr << "EOF" << std::endl;
		return (false);
	}
	if (std::cin.fail()) {
		std::cerr << "cin failed" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		return (false);
	}
	input = ft::strtrim(line, "\t ");
	return (true);
}

void interface::search::handle(PhoneBook *phonebook)
{
	std::string input;
	if (!interface::getValidInput(input, "Enter id: "))
		return;

	std::stringstream ss(input);
	unsigned int      id;
	if (!(ss >> id)) {
		std::cerr << "Invalid ID format" << std::endl;
		return;
	}
	if (id >= phonebook->getMAX_CONTACTS() ||
			(!phonebook->getFillFlag() && id >= phonebook->getNowId())) {
		std::cerr << "The id is out of range or has not been added yet" << std::endl;
		return;
	}
	phonebook->search(id);
}

void interface::add::handle(PhoneBook *phonebook)
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	if (!getValidInput(first_name, "Enter first_name: ") ||
			!validation::isValidLine(first_name, std::isalnum) ||
			!getValidInput(last_name, "Enter last_name: ") ||
			!validation::isValidLine(last_name, std::isalnum) ||
			!getValidInput(nickname, "Enter nickname: ") ||
			!validation::isValidLine(nickname, std::isalnum) ||
			!getValidInput(phone_number, "Enter phone_number: ") ||
			!validation::isValidLine(phone_number, std::isdigit) ||
			!getValidInput(darkest_secret, "Enter darkest_secret: ") ||
			!validation::isValidLine(darkest_secret, std::isalnum)) {
		if (std::cin.good())
			std::cerr << "The input string is invalid or empty" << std::endl;
		return;
	}
	Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	phonebook->add(new_contact);
}