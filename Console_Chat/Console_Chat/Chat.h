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
	std::string readInput(); //��������� ���� � ������� � ���������� ����� ���� String
	void regUser(bool* user_exist); // ����������� ������ ������������
	void regChatForAll(); //����������� ������ ����
	void logInUser();
	void logOutUser();

	void setActiveUser(int id, std::string name, std::string login); //������ ID, ��� � ����� ��������� ������������
	std::string getActiveUserName();
	std::string getActiveUserLogin();
	std::string getActiveResLogin(); //����� ����������

	void showUserList(); //���������� ������ ������������������ �������������
	void addUserToList(User* user); //��������� ������ ������������ � ������
	int listSize();

	void createMessage(User user);
	void privateChat(User user1, User user2);
	void generalChat(User user);
	void getResipient(int idResipient); // ������������� ���������� ���������


private:
	std::vector<User> _userList; //������ �������������
	std::vector<Message> _messageList; //������ ���������
	std::string _activeUserLogin; //����� ������������, ������������� ��� � ������ ������ 
	std::string _activeUserName; //��� ��������� ������������
	std::string _activeResLogin; //����� ����������

	int userID;
	int resID;
	
};
