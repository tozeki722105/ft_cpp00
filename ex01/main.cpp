#include "contact.hpp"
#include "phonebook.hpp"

void	handle_search(PhoneBook *phonebook)
{
	//input
	std::string input;
	std::cout << "Enter id: ";
	if (!std::getline(std::cin, input))
		return ;

	//convert digit
	std::stringstream ss(input);
	size_t id;
	if (!(ss >> id)|| id >= phonebook->get_MAX_CONTACTS() 
		|| (!phonebook->get_fill_flag() && id >= phonebook->get_now_id()))
		return ;
	phonebook->search(id);
}

// void A(std::string prompt, std::string trim_chars)
// {
// 	std::string input;

// 	std::cout << prompt;
// 	if(!std::getline(std::cin, input))

	

// }

void	handle_add(PhoneBook *phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string password;

	std::cout << "Enter first_name: ";
	std::getline(std::cin, first_name);
	if (std::cin.eof() || std::cin.fail())
	if (!std::getline(std::cin, first_name) || first_name.empty() || !is_all_of(first_name, std::isprint))
		return ;
	std::cout << "Enter last_name: ";
	if (!std::getline(std::cin, last_name) || last_name.empty() || !is_all_of(last_name, std::isprint))
		return ;
	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, nickname) || nickname.empty() || !is_all_of(nickname, std::isprint))
		return ;
	std::cout << "Enter phone_number: ";
	if (!std::getline(std::cin, phone_number) || phone_number.empty() || !is_all_of(phone_number, std::isdigit))
		return ;
	std::cout << "Enter password: ";
	if (!std::getline(std::cin, password) || password.empty() || !is_all_of(password, std::isprint))
		return ;
	Contact		new_contact;
	new_contact.set_first_name(first_name);
	new_contact.set_last_name(last_name);
	new_contact.set_nickname(nickname);
	new_contact.set_phone_number(phone_number);
	new_contact.set_password(password);
	phonebook->add(&new_contact);
}

int main(void)
{
	std::string input;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, input) || input == "EXIT")
			break;
		if (input == "ADD")
			handle_add(&phonebook);
		else if (input == "SEARCH")
			handle_search(&phonebook);
	}
}
