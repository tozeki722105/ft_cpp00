#include <iostream>
#include <string>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

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