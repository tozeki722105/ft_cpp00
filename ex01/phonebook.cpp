#include "phonebook.hpp"

PhoneBook::PhoneBook() : nowId(0), fillFlag(false) {}

void PhoneBook::add(const Contact &contact)
{
	contacts[nowId++] = contact;
	if (this->nowId == this->MAX_CONTACTS) {
		this->nowId = 0;
		this->fillFlag = true;
	}
}

void PhoneBook::search(unsigned int id)
{
	if (id >= this->MAX_CONTACTS || (!this->fillFlag && id > this->nowId)) {
		std::cerr << "The id is out of range or has not been added yet" << std::endl;
		return;
	}
	this->contacts[id].print_formatted(10, '|', id);
}
