#include <iostream>

int main()
{
	int a, b;
	std::string input;

	std::cout << "整数で入力してください: ";
	std::cin >> a;
	std::cin.clear(); //エラーフラグをリセット
	std::cin.ignore(); //ここまでに入っている標準入力を無視(消す)
	std::getline(std::cin, input);
	std::cout << "input=" << input << ';' << std::endl;
}
	// std::cout << "b を整数で入力してください。 b = ";
	// for (std::cin >> b ; !std::cin ; std::cin >> b){
	// 	std::cin.clear();
	// 	std::cin.ignore();
	// 	std::cout << "入力が間違ってます。" << std::endl;
	// }
	// std::cout << a << b << std::endl;