#include "interface.hpp"
#include "phonebook.hpp"

int main(void)
{
	std::string line;
	PhoneBook   phonebook;

	while (1) {
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, line) || line == "EXIT")
			break;
		if (line == "ADD")
			interface::add::handle(&phonebook);
		else if (line == "SEARCH")
			interface::search::handle(&phonebook);
	}
}
