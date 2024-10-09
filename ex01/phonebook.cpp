#include "phonebook.hpp"

void PhoneBook::add(Contact *contact)
{
	contacts[now_id++] = *contact;
	if (this->now_id == this->MAX_CONTACTS)
	{
		this->now_id = 0;
		this->fill_flag = true;
	}
}

void PhoneBook::search(size_t id)
{
	if (id >= this->MAX_CONTACTS || (!this->fill_flag && id > this->now_id))
		return ;
	this->contacts[id].print_formatted(10, '|', id);
}

bool PhoneBook::get_fill_flag()
{
	return (this->fill_flag);
}

size_t PhoneBook::get_now_id()
{
	return (this->now_id);
}

size_t PhoneBook::get_MAX_CONTACTS()
{
	return (this->MAX_CONTACTS);
}
