#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <sstream>

class PhoneBook
{
	public:
	PhoneBook();
	void search(size_t id);
	void add(Contact *contact);
	bool get_fill_flag();
	size_t get_now_id();

	private:
	Contact contacts[8];
	size_t now_id;
	bool fill_flag;
};

#endif