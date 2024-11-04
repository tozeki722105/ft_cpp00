#include "interface.hpp"
#include "phonebook.hpp"

int main(void)
{
	std::string input;
	PhoneBook   phonebook;

	while (std::cin.good()) {
		if (!interface::getValidInput(input, "Enter ADD, SEARCH or EXIT: ") || input == "EXIT")
			break;
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
	}
}
