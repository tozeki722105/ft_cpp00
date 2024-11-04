#include "contact.hpp"

namespace inner
{
std::string fixed_width(const std::string &str, unsigned int width)
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
}  // namespace inner

Contact::Contact() {}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
	: first_name(fn), last_name(ln), nickname(nn), phone_number(pn), darkest_secret(ds)
{
}

Contact::~Contact() {}

void Contact::printInfo(bool secret_print, unsigned int id, unsigned int width, char delim) const
{
	std::cout << delim << std::setw(static_cast<int>(width)) << std::right << id << delim
			  << inner::fixed_width(first_name, width) << delim
			  << inner::fixed_width(last_name, width) << delim
			  << inner::fixed_width(nickname, width) << delim;
	if (secret_print) {
		std::cout << inner::fixed_width(phone_number, width) << delim
				  << inner::fixed_width(darkest_secret, width) << delim;
	}
	std::cout << std::endl;
}

void Contact::printHeader(bool secret_print, unsigned int width, char delim)
{
	std::cout << delim << inner::fixed_width("index", width) << delim
			  << inner::fixed_width("first_name", width) << delim
			  << inner::fixed_width("last_name", width) << delim
			  << inner::fixed_width("nickname", width) << delim;
	if (secret_print) {
		std::cout << inner::fixed_width("phone_number", width) << delim
				  << inner::fixed_width("darkest_secret", width) << delim;
	}
	std::cout << std::endl;
}