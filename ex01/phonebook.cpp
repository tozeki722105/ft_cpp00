#include "test.hpp"

// 文字列をadd,search,exitごとに処理を分ける

// add
// 	firstを受け取り、validate
// 	lastを受け取り、validate
// 	nickを受け取り、validate
// 	phoneを受け取り、validate
// 	passを受け取り、validate
// 	new USERし、値を入れる
// 	add_last

// search
// 	indexを探す
// 	indexエラーならreturn
// 	見つかったら、出力
// 	パイプを出力
// 	1.stringの長さを測る
// 	2.10文字を超えたら、substr
// 	3.10文字なら、そのまま出力
// 	4.10文字以下なら、10-size分スペースを出力してから、stringを出力
// 	5.パイプを出力
// 	index、first,last,nickで1~5を繰り返す

void	PhoneBook::add_contact(Contact *contact, std::string first_name, std::string last_name, std::string nickname,
			std::string phone_number, std::string password)
{
	contact->set_first_name(first_name);
	contact->set_last_name(last_name);
	contact->set_nickname(nickname);
	contact->set_phone_number(phone_number);
	contact->set_password(password);
}

void	PhoneBook::add()
{
	
}

size_t	PhoneBook::find_empty_or_last_id()
{
	size_t i = 0;
	while(i < 8)
	{
		if (this->contacts[i].get_first_name().empty())
			return (i);
		i++;
	}
	return (9);
}

bool PhoneBook::is_all_of(const std::string str, int(*bool_func)(int))
{
	size_t len = str.length();
	for(size_t i = 0; i < len; i++)
	{
		if (!bool_func(str[i]))
			return (false);
	}
	return (true);
}

static void	print_over10(std::string str)
{
	for (size_t i = 0; i < 9; i++)
		std::cout << str[i];
	std::cout << '.';
}

static void	print_less10(std::string str)
{
	size_t space_len = 10 - str.length();
	for (size_t i = 0; i < space_len; i++)
		std::cout << ' ';
	for (size_t i = space_len; i < 10; i++)
		std::cout << str[i];
}

static void	print_str(std::string str)
{
	size_t len = str.length();
	if (len > 10)
		print_over10(str);
	else if (len < 10)
		print_less10(str);
	else
		std::cout << str;
}

void	PhoneBook::print_contact(Contact *contact, unsigned int id)
{
	std::cout << '|';
	std::cout << id;
	std::cout << '|';
	print_str(contact->get_first_name());
	std::cout << '|';
	print_str(contact->get_last_name());
	std::cout << '|';
	print_str(contact->get_nickname());
	std::cout << '|' << std::endl;
}

void	PhoneBook::search_id(unsigned int id)
{
	if (id < 1 || id > 8)
		return ;
	print_contact(&(this->contacts[id]), id);
}
