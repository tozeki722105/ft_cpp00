#ifndef CONTACT_HPP
# define CONTACT_HPP

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



#endif