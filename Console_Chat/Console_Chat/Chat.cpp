#include "Chat.h"

Chat::Chat()
{
	std::cout << "\n��� �������" << "\n\n";
}

void Chat::regUser(bool* user_exist)
{
	User user;
	*user_exist = true;
	std::string temp;
	std::cout << "\n������� ���: ";
	std::getline(std::cin, temp);
	user.setName(temp);

	std::cout << "\n������� �����: ";
	std::getline(std::cin, temp);
	user.setLogin(temp);

	std::cout << "\n������� ������: ";
	std::getline(std::cin, temp);
	user.setPassword(temp);

	_userList.push_back(user);
	std::cout << "\n�� ���������������� ���:\n";
	user.showUser();
}
