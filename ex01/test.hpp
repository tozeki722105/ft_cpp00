#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_password();
	void set_first_name(std::string str);
	void set_last_name(std::string str);
	void set_nickname(std::string str);
	void set_phone_number(std::string str);
	void set_password(std::string str);

	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	password;
};

class PhoneBook
{
	public:
	void	fill_info(Contact *contact, std::string first_name, std::string last_name, std::string nickname,
			std::string phone_number, std::string password);
	size_t	find_empty_or_last_id();
	size_t	find_();
	bool	is_all_of(std::string str, int (*bool_func)(int));
	void	search_contact();
	void	PhoneBook::print_contact(Contact *contact, unsigned int id);

	private:
	const size_t max = 8;
	Contact contacts[8];
};

#endif