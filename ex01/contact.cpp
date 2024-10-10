#include "contact.hpp"

void Contact::set_first_name(std::string str)
{
    this->first_name = str;
}

void Contact::set_last_name(std::string str)
{
    this->last_name = str;
}

void Contact::set_nickname(std::string str)
{
    this->nickname = str;
}

void Contact::set_phone_number(std::string str)
{
    this->phone_number = str;
}

void Contact::set_password(std::string str)
{
    this->password = str;
}

void Contact::print_formatted(int width, char delim, size_t id)
{
	std::cout << delim;
	print_fixed_width("id", width / 2);
	std::cout << delim;
	print_fixed_width("first_name", width);
	std::cout << delim;
	print_fixed_width("last_name", width);
	std::cout << delim;
	print_fixed_width("nickname", width);
	std::cout << delim;
	print_fixed_width("phone_number", width);
	std::cout << delim;
	print_fixed_width("password", width);
	std::cout << delim << std::endl;

	std::cout << delim << std::setw(width / 2) << id << delim;
	print_fixed_width(this->first_name, width);
	std::cout << delim;
	print_fixed_width(this->last_name, width);
	std::cout << delim;
	print_fixed_width(this->nickname, width);
	std::cout << delim;
	print_fixed_width(this->phone_number, width);
	std::cout << delim;
	print_fixed_width(this->password, width);
	std::cout << delim << std::endl;
}