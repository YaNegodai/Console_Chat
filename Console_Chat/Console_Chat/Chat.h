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

	void privateChat(User user);
	void generalChat(User user);
	std::string getResipient(int idResipient); // ������������� ���������� ���������


private:
	std::vector<User> _userList; //������ �������������
	std::vector<Message> _messageList; //������ ���������
	std::vector<Message> _messageList_priv; // ��������� ������ ���������
	std::string _activeUserLogin; //����� ������������, ������������� ��� � ������ ������ 
	std::string _activeUserName; //��� ��������� ������������
	std::string _activeResLogin; //����� ����������

	int userID;
	int resID;
	
};
