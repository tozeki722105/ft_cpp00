// #include <iostream>



// int main(int argc, char **argv)
// {
// 	for (int i = 0; i < argc; i++)
// 		std::cout << argv[i] << std::endl;
// 	return (0);
// }

#include <iostream>
#include <string>
#include <cctype>

namespace ft
{	
std::string toupper(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = static_cast<char>(std::toupper(str[i]));
	return (str);
}
} // namespace ft

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
		std::cout << ft::toupper(argv[i]);
	std::cout << std::endl;
	return 0;
}