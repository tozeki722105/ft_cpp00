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

void Contact::print()
{
	std::cout << std::setw(10) << "first_name" << '|' 
		<< std::setw(10) << "last_name" << '|'
		<< std::setw(10) << "nickname" << '|'
		<< std::setw(10) << "phone_num" << '|'
		<< std::setw(10) << "password" << '|' << std::endl;
	print_fixed_width(this->first_name, 10);
	std::cout << '|';
	print_fixed_width(this->last_name, 10);
	std::cout << '|';
	print_fixed_width(this->nickname, 10);
	std::cout << '|';
	print_fixed_width(this->phone_number, 10);
	std::cout << '|';
	print_fixed_width(this->password, 10);
	std::cout << '|' << std::endl;
}