#include "phonebook.hpp"

namespace inner
{
void addErr()
{
	if (std::cin.good()) {
		std::cerr << "The input string is invalid or empty" << std::endl;
		return;
	}
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
void searchErr()
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
}  // namespace inner

PhoneBook::PhoneBook() : contact_count(0) {}

void PhoneBook::addContact()
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;
	if (!interface::getValidInput(first_name, "Enter first_name: ") ||
			!interface::isValidLine(first_name, std::isprint) ||
			!interface::getValidInput(last_name, "Enter last_name: ") ||
			!interface::isValidLine(last_name, std::isprint) ||
			!interface::getValidInput(nickname, "Enter nickname: ") ||
			!interface::isValidLine(nickname, std::isprint) ||
			!interface::getValidInput(phone_number, "Enter phone_number: ") ||
			!interface::isValidLine(phone_number, std::isprint) ||
			!interface::getValidInput(darkest_secret, "Enter darkest_secret: ") ||
			!interface::isValidLine(darkest_secret, std::isprint)) {
		inner::addErr();
		return;
	}
	Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	this->contacts[contact_count++ % MAX_CONTACTS] = new_contact;
}

void PhoneBook::searchContact()
{
	this->printContacts();

	std::string input;
	if (!interface::getValidInput(input, "Enter id: ")) {
		inner::searchErr();
		return;
	}

	std::stringstream ss(input);
	unsigned int      id;
	if (!(ss >> id)) {
		std::cerr << "Invalid ID format" << std::endl;
		return;
	}
	if (id >= this->MAX_CONTACTS ||
			(this->contact_count < this->MAX_CONTACTS && id >= this->contact_count)) {
		std::cerr << "The id is out of range or has not been added yet" << std::endl;
		return;
	}
	Contact::printHeader(true);
	this->contacts[id].printInfo(true, id);
}

void PhoneBook::printContacts()
{
	if (this->contact_count == 0) {
		std::cout << "Phone book is empty" << std::endl;
		return;
	}
	std::cout << "---------------------------------------------\n"
			  << std::setw(40) << "Display contacts in order of newest\n"
			  << "---------------------------------------------" << std::endl;
	Contact::printHeader(false);
	for (size_t i = 0; i < contact_count && i < MAX_CONTACTS; i++) {
		this->contacts[(contact_count - i - 1) % MAX_CONTACTS].printInfo(
				false, (contact_count - i - 1) % MAX_CONTACTS);
	}
}
