#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>

enum Command {
    CMD_ADD,
    CMD_SEARCH,
    CMD_EXIT
};

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string password;

public:
    Contact(const std::string& firstName, const std::string& lastName,
                 const std::string& nickname, const std::string& phoneNumber,
                 const std::string& password);

    void setFirstName(const std::string& str);
    void setLastName(const std::string& str);
    void setNickname(const std::string& str);
    void setPhoneNumber(const std::string& str);
    void setPassword(const std::string& str);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getPassword() const;

    void print(int width = 10, char separator = '|') const;
};

class PhoneBook {
private:
    Contact contacts[8];
    int currentSize;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void searchContact(int index) const;
    void displayContacts() const;
    int getContactCount() const;

    void printContact(int index) const;
    void printPhonebook() const;
};

// Contact メソッドの実装
Contact::Contact(const std::string& firstName, const std::string& lastName,
                         const std::string& nickname, const std::string& phoneNumber,
                         const std::string& password)
    : firstName(firstName),
      lastName(lastName),
      nickname(nickname),
      phoneNumber(phoneNumber),
      password(password) {}

void Contact::setFirstName(const std::string& str) {
    this->firstName = str;
}

void Contact::setLastName(const std::string& str) {
    this->lastName = str;
}

void Contact::setNickname(const std::string& str) {
    this->nickname = str;
}

void Contact::setPhoneNumber(const std::string& str) {
    this->phoneNumber = str;
}

void Contact::setPassword(const std::string& str) {
    this->password = str;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getPassword() const {
    return password;
}

void Contact::print(int width, char separator) const {
    std::cout << std::right << std::setw(width) << firstName << separator
              << std::right << std::setw(width) << lastName << separator
              << std::right << std::setw(width) << nickname << separator
              << std::right << std::setw(width) << phoneNumber << std::endl;
}

// PhoneBook メソッドの実装
PhoneBook::PhoneBook() : currentSize(0) {
	for (int i = 0; i < 8; ++i) {
		this->contacts[i] = Contact("", "", "", "", ""); // デフォルトコンストラクタで初期化
	}
}

void PhoneBook::addContact(const Contact& contact) {
    if (currentSize < 8) {
        contacts[currentSize++] = contact;
    } else {
        // 最古の連絡先を新しい連絡先で上書き
        contacts[0] = contact;
        currentSize = 8; // currentSize を 8 にリセット
    }
}

void PhoneBook::searchContact(int index) const {
    if (index >= 0 && index < currentSize) {
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name:  " << contacts[index].getLastName() << std::endl;
        std::cout << "Nickname:   " << contacts[index].getNickname() << std::endl;
        std::cout << "Phone:      " << contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Secret:      " << contacts[index].getPassword() << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void PhoneBook::displayContacts() const {
    std::cout << "Index | First Name | Last Name | Nickname" << std::endl;
    std::cout << "------|------------|-----------|----------" << std::endl;
    for (int i = 0; i < currentSize; i++) {
        std::cout << std::right << std::setw(5) << i << " | ";
        std::cout << std::right << std::setw(10) << contacts[i].getFirstName() << " | ";
        std::cout << std::right << std::setw(10) << contacts[i].getLastName() << " | ";
        std::cout << std::right << std::setw(10) << contacts[i].getNickname() << std::endl;
    }
}

int PhoneBook::getContactCount() const {
    return currentSize;
}

void PhoneBook::printContact(int index) const {
    if (index >= 0 && index < currentSize) {
        contacts[index].print();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void PhoneBook::printPhonebook() const {
    for (int i = 0; i < currentSize; i++) {
        std::cout << "Contact " << i << ": " << std::endl;
        contacts[i].print();
    }
}

// ユーティリティ関数
Command get_command() {
    std::string command;
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);

    if (command == "ADD") {
        return CMD_ADD;
    } else if (command == "SEARCH") {
        return CMD_SEARCH;
    } else if (command == "EXIT") {
        return CMD_EXIT;
    } else {
        return CMD_EXIT; // 他のコマンドは EXIT として扱う
    }
}

// ユーティリティ関数
void show_all_commands() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "ADD: Add a new contact" << std::endl;
    std::cout << "SEARCH: Search for a contact" << std::endl;
    std::cout << "EXIT: Exit the program" << std::endl;
}

// ユーティリティ関数
void handle_add_command(PhoneBook& phone_book) {
    std::string firstName, lastName, nickname, phoneNumber, password;
    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Password: ";
    std::getline(std::cin, password);

    Contact newContact(firstName, lastName, nickname, phoneNumber, password);
    phone_book.addContact(newContact);
}

// ユーティリティ関数
static void handle_search_command(PhoneBook& phone_book) {
    if (phone_book.getContactCount() == 0) {
        std::cout << "Phone book is empty" << std::endl;
        return;
    }

    phone_book.printPhonebook();

    int index;
    std::cout << "Enter an index: ";
    std::cin >> index;
    // ignore the rest of the line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail() || index < 0 || index >= phone_book.getContactCount()) {
        std::cout << "Invalid index" << std::endl;
        std::cin.clear();
        return;
    }
    phone_book.printContact(index);
}

int main() {
    PhoneBook phone_book;

    show_all_commands();
    while (true) {
        Command command = get_command();
        if (std::cin.eof())
            break;
        bool exit_flag = false;
        switch (command) {
            case CMD_ADD:
                handle_add_command(phone_book);
                break;
            case CMD_SEARCH:
                handle_search_command(phone_book);
                break;
            case CMD_EXIT:
                exit_flag = true;
                break;
            default:
                break;
        }
        if (exit_flag)
            break;
    }
    return 0;
}

#endif