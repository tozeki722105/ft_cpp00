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
	void printInfo(
			bool secret_print, unsigned int id, unsigned int width = 10, char delim = '|') const;
	static void printHeader(bool secret_print, unsigned int width = 10, char delim = '|');

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif