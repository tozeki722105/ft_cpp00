#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "contact.hpp"

class PhoneBook
{
private:
	static const unsigned int MAX_CONTACTS = 8;
	Contact                   contacts[MAX_CONTACTS];
	unsigned int              nowId;
	bool                      fillFlag;

public:
	PhoneBook();
	void         search(unsigned int id);
	void         add(const Contact &contact);
	bool         getFillFlag();
	unsigned int getNowId();
	unsigned int getMAX_CONTACTS();
};

#endif