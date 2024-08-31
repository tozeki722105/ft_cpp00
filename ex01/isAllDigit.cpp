#include <string>
#include <iostream>
#include <cctype>

bool isAllDigit(const std::string& str) {
  return std::all_of(str.begin(), str.end(), std::isdigit);
}

//""でもOKになる
int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	std::string str = argv[1];
	if (isAllDigit(str))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}