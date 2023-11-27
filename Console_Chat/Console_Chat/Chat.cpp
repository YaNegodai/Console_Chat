﻿#include "Chat.h"
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

	_userList.push_back(user);
	std::cout << "\nВы зарегистрированны как:\n";
	user.showUser();
}


void Chat::createMessage(User user)
{
	Message message(user.getName());
	message.writeMessage();
	return message.showMessage();
}

void Chat::privateChat(User user, User user2)
{
	std::cout << "Welcome to private chat" << std::endl;
	void ShowUserList();
	std::cout << "Please, selecte recipient ID. You have a few seconds" << std::endl;
	std::cout << "if you want to exit click ENTER" << std::endl;
	Sleep(3000);
	int res_id = _getch();
	if (res_id == 13) { exit(0); }  // должен выполнять выход
	else if (res_id < 1 || res_id > _userList.size())
	{
		std::cout << "Please, re-enter ID of your recipient" << std::endl;
		return;
	}
	else
	{
		res_id -= 1;
		//std::string name_recipient = _userList.at(res_id);
		//std::cout << "This message for: " << name_recipient << std::endl;
		createMessage(user);
	}
}

void Chat::generalChat(User user) 
{
	user.getName();
	std::cout << "This is general chat" << std::endl;
	std::cout << "User" << "==========" << user.getName() << "==========" << "writes: " << std::endl;
	createMessage(user);
}