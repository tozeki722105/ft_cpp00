#include "contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
	: first_name(fn), last_name(ln), nickname(nn), phone_number(pn), darkest_secret(ds)
{
}

Contact::~Contact() {}

std::string Contact::fixed_width(const std::string &str, unsigned int width)
{
	if (width == 0)
		return ("");
	if (str.length() == width)
		return (str);
	if (str.length() > width)
		return (str.substr(0, width - 1) + '.');
	std::stringstream ss;
	ss << std::setw(static_cast<int>(width)) << std::right << str;
	return (ss.str());
}

void Contact::print_formatted(unsigned int width, char delim, unsigned int id)
{
	std::cout << delim << this->fixed_width("index", width / 2) << delim
			  << this->fixed_width("first_name", width) << delim
			  << this->fixed_width("last_name", width) << delim
			  << this->fixed_width("nickname", width) << delim << std::endl;

	std::cout << delim << std::setw(static_cast<int>(width / 2)) << std::right << id << delim
			  << this->fixed_width(this->first_name, width) << delim
			  << this->fixed_width(this->last_name, width) << delim
			  << this->fixed_width(this->nickname, width) << delim << std::endl;
}
