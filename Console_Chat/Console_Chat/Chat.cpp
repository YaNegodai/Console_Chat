#include "Chat.h"
#include <conio.h>

Chat::Chat()
{
	std::cout << "\n��� �������" << "\n\n";
}

Chat::~Chat()
{

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


void Chat::createMessage(User user)
{
	Message message(user.getName());
	message.writeMessage();
	return message.showMessage();
}

void Chat::privateChat(User user)
{
	std::cout << "Welcome to private chat" << std::endl;
	void ShowUserList();
	std::cout << "Please, selecte recipient ID. You have a few seconds" << endl;
	std::cout << "�f you want to exit click ENTER" << endl;
	_sleep(3000);
	int res_id = _getch();
	if (res_id == 13) { break; }
	else if (res_id < 1 || res_id > _userList.size())
	{
		std::cout << "Please, re-enter ID your recipient" << endl;
		return;
	}
	else
	{
		res_id -= 1;
		std::string name_recipient = _userList.at(res_id);
		std::cout << "This message for: " << name_recipient << endl;
		createMessage(user);
	}
}

void Chat::generalChat(User user) 
{
	user.getName();
	std::cout << "This is general chat" << std::endl;
	std::cout << "User" << "==========" << user.getName << "==========" << "writes: " << endl;
	createMessage(user);
}
