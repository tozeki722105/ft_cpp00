#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

void fill(Contact *contact)
{
	std::string input;

	if (!std::getline(std::cin, input))
		return ;
	contact->set_first_name(input);
	if (!std::getline(std::cin, input))
		return ;
	contact->set_last_name(input);
	if (!std::getline(std::cin, input))
		return ;
	contact->set_nickname(input);
	if (!std::getline(std::cin, input))
		return ;
	contact->set_phone_number(input);
	if (!std::getline(std::cin, input))
		return ;
	contact->set_password(input);
}

void PhoneBook::add_con()
{
	fill(&(this->contacts[this->now]));
	this->now++;
	if (this->now > 8)
		this->now = 0;
}

int main()
{
	std::string input;

	while (1)
	{
		if (!std::getline(std::cin, input))//標準入力から1行読み込む
			break;
		std::cout << "入力された文字列: " << input << std::endl;
	}
  	return 0;
}