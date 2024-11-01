#include <iostream>
#include <string>

int main()
{
	std::string input;
	while (1) {
		if (!std::getline(std::cin, input))
			return (1);
		std::cout << input << ';' << '\n' << std::endl;
	}
}