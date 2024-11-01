#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <string>

#include "contact.hpp"
#include "phonebook.hpp"
#include "validate.hpp"

namespace interface
{
bool getValidInput(std::string &input, const std::string &prompt);
namespace add
{
	void handle(PhoneBook *phonebook);
}  // namespace add
namespace search
{
	void handle(PhoneBook *phonebook);
}
}  // namespace interface

#endif