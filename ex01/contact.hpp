#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "utils.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	public:
	void set_first_name(std::string str);
	void set_last_name(std::string str);
	void set_nickname(std::string str);
	void set_phone_number(std::string str);
	void set_password(std::string str);
	void	print();

	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	password;
};

#endif