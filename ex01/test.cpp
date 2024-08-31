#include <iostream>
#include <string>
#include "test.hpp"


int main(void)
{
	std::string input;

	while (1)
	{
		if (!std::getline(std::cin, input))//標準入力から1行読み込む
			break;
		std::cout << "入力された文字列: " << input << std::endl;
	}
  	return 0;
}