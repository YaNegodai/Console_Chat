#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Message.h"
#include "User.h"

class Chat
{
public:
	Chat();
	~Chat();
	std::string readInput(); //считывает ввод с консоли и возвращает текст типа String
	void userDataInput(User& user); //ввод имени, логина и пароля пользователя4
	void logInInput(User& user); //ввод только имени и пароля, используется для входа в аккаунт 
	void regUser(bool* userExist); // регистрация нового пользователя
	void regChatForAll(); //регистрация общего чата
	void logInUser(bool* userExist);
	void logOutUser();
	void isAvailable(User& user, bool& check); // проверяет, заняты ли логин и пароль

	void setActiveUser(int id, std::string name, std::string login); //задает ID, имя и логин активного пользователя
	std::string getActiveUserName();
	std::string getActiveUserLogin();
	std::string getActiveResLogin(); //логин получателя
	int getActiveUserID();

	void showUserList(); //отображает список зарегистрированных пользователей
	void addUserToList(User user); //добавляет нового пользователя в список
	size_t listSize();

	void privateChat();
	void generalChat();
	std::string getResipient(int idResipient); // устанавливает получателя сообщения
	void receive_priv_Message();
	void recive_Message();


private:
	std::vector<User> _userList; //список пользователей
	std::vector<Message> _messageList; //список сообщений
	std::vector<Message> _messageList_priv; // приватный список сообщений
	std::string _activeUserLogin; //логин пользователя, используещего чат в данный момент 
	std::string _activeUserName; //имя активного пользователя
	std::string _activeResLogin; //логин получателя

	int userID = 0;
	int resID = 0;
	
};
