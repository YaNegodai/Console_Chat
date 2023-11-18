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
	void regUser(bool* user_exist);
	void logInUser();
	void logOutUser();

	void showUserList();
	void addUserToList();


private:
	std::vector<User> _userList;
	std::vector<Message> _messageList;
	std::string _activeUserLogin;
	std::string _activeUserName;
	
};
