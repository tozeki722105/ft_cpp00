#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <sstream>

class PhoneBook
{
	private:
	static const size_t MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	size_t now_id;
	bool fill_flag;

	public:
	PhoneBook() : now_id(0), fill_flag(false) {};
	void search(size_t id);
	void add(Contact *contact);
	bool get_fill_flag();
	size_t get_now_id();
	size_t get_MAX_CONTACTS();
};

#endif