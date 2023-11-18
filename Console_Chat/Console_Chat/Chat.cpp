#include "Chat.h"

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
	//user.getName();
	message.writeMessage();
	return message.showMessage();
}

void Chat::privateChat(User user1, User user2)
{
	std::cout << "Welcome to private chat" << std::endl;
	//userList();
	// 
	//user1.selekteUser(); //�������, �����������
	//user2.selekteUser(); //��������� ���� �� �� � ������


}

void Chat::generalChat(User user) //()
{
	user.getName();
	std::cout << "This is general chat" << std::endl;
	createMessage(user);

}
