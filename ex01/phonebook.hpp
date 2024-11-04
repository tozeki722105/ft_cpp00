#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "contact.hpp"
#include "interface.hpp"

class PhoneBook
{
private:
	static const unsigned int MAX_CONTACTS = 8;
	Contact                   contacts[MAX_CONTACTS];
	unsigned int              contact_count;

public:
	PhoneBook();
	void addContact();
	void searchContact();
	void printContacts();
};

#endif