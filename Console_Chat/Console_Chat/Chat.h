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
	void regUser(bool* user_exist);
	void logInUser();
	void logOutUser();

	void showUserList();
	void addUserToList();

	void createMessage(User user);
	void privateChat(User user1, User user2);
	void generalChat(User user);


private:
	std::vector<User> _userList;
	std::vector<Message> _messageList;
	std::string _activeUserLogin;
	std::string _activeUserName;
	std::string _activeResLogin;

	int userID;
	int resID;
	
};
