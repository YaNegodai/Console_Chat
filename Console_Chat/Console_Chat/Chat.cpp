#include "Chat.h"

Chat::Chat()
{
	std::cout << "\nЧат запущен" << "\n\n";
}

void Chat::regUser(bool* user_exist)
{
	User user;
	*user_exist = true;
	std::string temp;
	std::cout << "\nВведите имя: ";
	std::getline(std::cin, temp);
	user.setName(temp);

	std::cout << "\nВведите логин: ";
	std::getline(std::cin, temp);
	user.setLogin(temp);

	std::cout << "\nВведите пароль: ";
	std::getline(std::cin, temp);
	user.setPassword(temp);

	_userList.push_back(user);
	std::cout << "\nВы зарегистрированы как:\n";
	user.showUser();
}
