#include "contact.hpp"
#include "phonebook.hpp"

int main(void)
{
	std::string input;
	Contact contact;
	PhoneBook phonebook;

	// phonebook.now = 0;
	// phonebook.fill_flag = false;
	while (1)
	{
		if (!std::getline(std::cin, input) || input == "EXIT")
			break;
		if (input == "ADD")
			phonebook.add();
		if (input == "SEARCH")
			phonebook.search();
	}
}