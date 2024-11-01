#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Contact
{
public:
	Contact();
	Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	~Contact();
	void print_formatted(unsigned int width, char delim, unsigned int id);

private:
	std::string        first_name;
	std::string        last_name;
	std::string        nickname;
	std::string        phone_number;
	std::string        darkest_secret;
	static std::string fixed_width(const std::string &str, unsigned int width);
};

#endif