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

void Chat::userDataInput(User& user)
{
	std::cout << "Введите имя: ";

	user.setName(readInput());

	std::cout << "Введите логин: ";
	user.setLogin(readInput());

	std::cout << "Введите пароль: ";
	user.setPassword(readInput());
}

void Chat::logInInput(User& user)
{
	std::cout << "Введите логин: ";
	user.setLogin(readInput());

	std::cout << "Введите пароль: ";
	user.setPassword(readInput());
}



void Chat::regUser(bool* userExist)
{
	User user;
	*userExist = true;
	
	userDataInput(user);
	bool check = true;
	isAvailable(user, check);
	if (check)
	{
		addUserToList(user);
		std::cout << "\nВы зарегистрированны как:\n";
		user.showUser();
		logInUser(userExist);
		size_t size = _userList.size() - 1;
		if (userExist) 
		{
			setActiveUser(size, _userList.at(size).getName(), _userList.at(size).getLogin());
		}
		else
			return;
	}
}

void Chat::regChatForAll()
{
	User user;
	user.setName("Общий чат");
	user.setLogin("AllUsers");
	user.setPassword("password");
	addUserToList(user);
}

void Chat::logInUser(bool* userExist)
{
	User userDataCheck;
	logInInput(userDataCheck);
	*userExist = false;
	size_t counter = 0;
	for (User all : _userList)
	{
		if ((userDataCheck.getLogin() == all.getLogin()) && (userDataCheck.getPassword() == all.getPassword()))
		{
			setActiveUser(counter, all.getName(), all.getLogin());
			std::cout << "\n\nВы вошли как:\n\n";
			_userList.at(counter).showUser();
			*userExist = true;
		}
		counter++;
	}
	if (!userExist)
	{
		std::cout << "\nНеверный логин или пароль\n";
		return;
	}
}

void Chat::logOutUser()
{
	userID = 0;
	_activeUserName = '\0';
	_activeUserLogin = '\0';
}

void Chat::isAvailable(User& user, bool& check)
{

	for (User all : _userList)
	{
		if (user.getName() == all.getName())
		{
			user.clearName();
			std::cout << "Данное имя занято, выберете другое\n";
			check = false;
			break;
		}else if (user.getLogin() == all.getLogin())
		{
			user.clearLogin();
			std::cout << "Данный логин занят, выберете другой\n";
			check = false;
			break;
		}
		else
			check = true;
	}
	if (!check)
	{
			userDataInput(user);
			isAvailable(user, check);
	}
			
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

int Chat::getActiveUserID()
{
	return userID;
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

void Chat::privateChat() // можно попробовать без юзера, а может и не можно
{

	Message message;
	std::cout << "Welcome to private chat" << std::endl;
	showUserList();
	std::cout << "Please, select recipient ID. You have a few seconds" << std::endl;
	std::cout << "if you want to exit click Esc" << std::endl;
	//Sleep(3000);
	//int res_id = _getch();
	int res_id;
	std::cin >> res_id;
	if (res_id == 99) { exit(0); }  // должен выполнять выход с консоли
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
		_messageList_priv[res_id] = message; // не знаю можно ли так. Записывать в вектор на нужное место, в соответствии с номером получателя
		//_messageList_priv.push_back(message);
	}
}

void Chat::generalChat() 
{
	Message message;
	std::cout << "This is general chat" << std::endl;
	message.createMessage();
	message.showMessage();
	_messageList.push_back(message);
}

std::string Chat::getResipient(int idResipient)
{
	return _userList.at(idResipient).getName();
}

void Chat::receive_priv_Message(int ID_user)
{
	_userList.at(ID_user).showUserName();
	for (Message mes : _messageList_priv)
		return mes.showMessage();
}

void Chat::recive_Message()
{
	for (Message mes : _messageList)
		return mes.showMessage();
}
