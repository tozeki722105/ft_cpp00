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
	for (size_t j = 0; j < str.length(); ++j)
	{
		str[j] = static_cast<char>(std::toupper(str[j]));	
	}
	return (str);
}
} // namespace ft

int main(int argc, char* argv[])
{
  for (int i = 1; i < argc; ++i)
	std::cout << ft::toupper(argv[i]) << " ";
  std::cout << std::endl;
  return 0;
}