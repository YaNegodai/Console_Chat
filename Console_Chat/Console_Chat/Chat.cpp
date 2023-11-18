#include "Chat.h"

Chat::Chat()
{
	std::cout << "\nЧат запущен" << "\n\n";
}

Chat::~Chat()
{

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
	//user1.selekteUser(); //главный, отправитель
	//user2.selekteUser(); //проверяем есть ли он в списке


}

void Chat::generalChat(User user) //()
{
	user.getName();
	std::cout << "This is general chat" << std::endl;
	createMessage(user);

}
