#include <iostream>
#include <string>

#include <iostream>
#include <string>
#include <algorithm>

std::string strtrim(std::string str, std::string trimed_set)
{
	size_t start = str.find_first_not_of(trimed_set);
	size_t end = str.find_last_not_of(trimed_set);

	if (end == std::string::npos || start == std::string::npos
		|| end < start)
		return ("");
	return (str.substr(start, end - start + 1));
}

int main() {
    // 基本的なケース
    assert(strtrim("  Hello, world!  ", " ") == "Hello, world!");

    // 空白文字のみのケース
    assert(strtrim("   ", " ") == "");

    // 先頭と末尾に空白文字があるケース
    assert(strtrim("   Hello, world!   ", " ") == "Hello, world!");

    // 空白文字以外をトリムするケース
    assert(strtrim("***Hello, world!***", "*") == "Hello, world!");

    // 複数のトリム文字セット
    assert(strtrim("  Hello, world!  ", " \t\r\n") == "Hello, world!");

    // 空文字列のケース
    assert(strtrim("", " ") == "");

    // すべての文字がトリム文字セットに含まれるケース
    assert(strtrim("***", "*") == "");

    // トリミングする文字セットに、トリム対象の文字が含まれていないケース
    assert(strtrim("Hello, world!", "*") == "Hello, world!");

    // トリミングする文字セットに、トリム対象の文字が重複して含まれるケース
    assert(strtrim("***Hello, world!***", "***") == "Hello, world!");

    // 複数のトリム文字セットで、トリム対象の文字が重複して含まれるケース
    assert(strtrim("  Hello, world!  ", " \t\r\n*") == "Hello, world!");

    // トリミングする文字セットに、トリム対象の文字以外の文字も含まれるケース
    assert(strtrim("  Hello, world!  ", " \t\r\n*abc") == "Hello, world!");

	// frontとbackでtrimed_setが違う場合、end < startのパターンもテストしなければならない

	std::cout << "すべてのテストケースに合格しました。" << std::endl;

    return 0;
}