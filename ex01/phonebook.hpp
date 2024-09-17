#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

class PhoneBook
{
	public:
	void	PhoneBook::search_id(unsigned int id);
	void	PhoneBook::print_contact(Contact *contact, unsigned int id);
	bool	PhoneBook::is_all_of(const std::string str, int(*bool_func)(int));
	void	PhoneBook::add_con();

	private:
	const size_t	max = 8;
	size_t			now = 0;
	Contact contacts[8];


};

#endif