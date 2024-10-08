#include <iostream>
#include <sstream>
#include <limits>

int main() {
  std::string input;
  std::cout << "size_t型の値を入力してください: ";
  std::getline(std::cin, input);

  std::cout << input << ';' << std::endl;
  std::stringstream ss(input);
  size_t value;

 if (ss >> value && ss.eof() && value >= 0) { // 値が非負であることを確認
    std::cout << "入力された値は: " << value << std::endl;
  } else {
    std::cout << "不正な入力です。size_t型の値（非負の整数）を入力してください。\n";
    std::cin.clear(); // エラー状態をクリア
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // バッファをクリア
  }

  return 0;
}