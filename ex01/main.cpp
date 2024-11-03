#include "interface.hpp"
#include "phonebook.hpp"

int main(void)
{
	std::string input;
	PhoneBook   phonebook;

	while (std::cin.good()) {
		if (!interface::getLine(input, "Enter ADD, SEARCH or EXIT: ") || input == "EXIT")
			break;
		if (input == "ADD")
			interface::add::handle(&phonebook);
		else if (input == "SEARCH")
			interface::search::handle(&phonebook);
	}
}
