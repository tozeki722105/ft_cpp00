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
	void search();
	void add();

	private:
	Contact contacts[8];
	size_t now;
	bool fill_flag;
};

#endif