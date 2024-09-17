#include <iostream>
#include <string>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main(void)
{
	std::string input;
	std::string old_input;

	while (1)
	{
		std::getline(std::cin, input);  //標準入力から1行読み込む
		if (input.empty())
			break;
		std::cout << "入力された文字列: " << input << std::endl;
		old_input = input;
	}
  	return 0;
}