#include "phonebook.hpp"

void PhoneBook::add()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string password;

	std::cout << "Enter first_name: ";
	if (!std::getline(std::cin, first_name))// || !is_all_of(first_name, std::isalpha)
		return ;
	std::cout << "Enter last_name: ";
	if (!std::getline(std::cin, last_name))// || !is_all_of(last_name, std::isalpha)
		return ;
	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, nickname))// || !is_all_of(nickname, std::isalnum)
		return ;
	std::cout << "Enter phone_number: ";
	if (!std::getline(std::cin, phone_number))// || !is_all_of(phone_number, std::isdigit)
		return ;
	std::cout << "Enter password: ";
	if (!std::getline(std::cin, password))// || !is_all_of(password, std::isalnum)
		return ;
	this->contacts[this->now].set_first_name(first_name);
	this->contacts[this->now].set_last_name(last_name);
	this->contacts[this->now].set_nickname(nickname);
	this->contacts[this->now].set_phone_number(phone_number);
	this->contacts[this->now].set_password(password);
	if (++this->now == 8)
	{
		this->now = 0;
		this->fill_flag = true;
	}
}

void PhoneBook::search()
{
	//input
	std::string input;
	std::cout << "Enter id: ";
	if (!std::getline(std::cin, input))
		return ;

	//convert int
	std::stringstream ss(input);
	size_t id;
	if (!(ss >> id)|| id >= 8 || (!this->fill_flag && id >= this->now))
		return ;
	std::cout << id << ';' << std::endl;
	this->contacts[id].print();
}

PhoneBook::PhoneBook()
{
	this->now = 0;
	this->fill_flag = false;
}