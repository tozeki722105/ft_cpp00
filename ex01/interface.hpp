#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

#include "contact.hpp"
#include "phonebook.hpp"

namespace interface
{
bool getLine(std::string &input, const std::string &prompt, const std::string &trim_set = "\t ");
namespace add
{
	void handle(PhoneBook *phonebook);
	void err();
}  // namespace add
namespace search
{
	void handle(PhoneBook *phonebook);
	void err();
}  // namespace search
}  // namespace interface

#endif