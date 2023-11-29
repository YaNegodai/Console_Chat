#include "Chat.h"
#include <conio.h>
#include <Windows.h> 

Chat::Chat()
{
	std::cout << "\nЧат запущен" << "\n\n";
}

Chat::~Chat()
{

}

std::string Chat::readInput()
{
	std::string input;
	std::getline(std::cin >> std::ws, input);
	return input;
}



void Chat::regUser(bool* user_exist)
{
	User user;
	*user_exist = true;
	
	std::cout << "Введите имя: ";
	
	user.setName(readInput());

	std::cout << "Введите логин: ";
	user.setLogin(readInput());

	std::cout << "Введите пароль: ";
	user.setPassword(readInput());

	addUserToList(user);
	std::cout << "\nВы зарегистрированны как:\n";
	user.showUser();
	size_t size = _userList.size() - 1;
	setActiveUser(size, _userList.at(size).getName(), _userList.at(size).getLogin());
}

void Chat::regChatForAll()
{
	User user;
	user.setName("Общий чат");
	user.setLogin("AllUsers");
	user.setPassword("password");
	addUserToList(user);
}

void Chat::logInUser()
{

}

void Chat::logOutUser()
{
	userID = 0;
	_activeUserName = '\0';
	_activeUserLogin = '\0';
}


void Chat::setActiveUser(int id, std::string name, std::string login)
{
	userID = id;
	_activeUserName = name;
	_activeUserLogin = login;
}

std::string Chat::getActiveUserName()
{
	return _activeUserName;
}

std::string Chat::getActiveUserLogin()
{
	return _activeUserLogin;
}

std::string Chat::getActiveResLogin()
{
	return _activeResLogin;
}

void Chat::showUserList()
{
	int id{ 0 };
	std::cout << "\nСписок участников чата:\n";
	
	for (User user : _userList)
	{
		id++;
		std::cout << id << " - ";
		user.showUserName();
	}
}

void Chat::addUserToList(User user)
{
	_userList.push_back(user);
}

size_t Chat::listSize()
{
	return _userList.size();
}

void Chat::privateChat(User user) // можно попробовать без юзера, а может и не можно
{
	Message message(user.getName());
	std::cout << "Welcome to private chat" << std::endl;
	void ShowUserList();
	std::cout << "Please, selecte recipient ID. You have a few seconds" << std::endl;
	std::cout << "if you want to exit click ENTER" << std::endl;
	Sleep(3000);
	int res_id = _getch();
	if (res_id == 13) { exit(0); }  // должен выполнять выход с консоли
	else if (res_id < 1 || res_id > listSize())
	{
		std::cout << "Please, re-enter ID of your recipient" << std::endl;
		return;
	}
	else
	{
		res_id -= 1;
		std::cout << "This message for: " << getResipient(res_id) << std::endl;
		message.createMessage();
		_messageList_priv.push_back(message);
	}
}

void Chat::generalChat(User user) 
{
	Message message(user.getName());
	std::cout << "This is general chat" << std::endl;
	std::cout << "User" << "==========" << user.getName() << "==========" << "writes: " << std::endl;
	message.createMessage();
	_messageList.push_back(message);
}

std::string Chat::getResipient(int idResipient)
{
	return _userList.at(idResipient).getName();
}
