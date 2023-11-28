#pragma once
#include <iostream>
#include <string>
class Message
{
private:
	std::string _message; //����� ���������
	std::string _name; //��� �����������
	std::string _login; //����� �����������
	std::string _name_recipient;

public:
	Message(std::string login, std::string name, std::string _name_recipient, std::string _message);
	Message(std::string login, std::string name, std::string message);
	Message(std::string name, std::string message);
	Message(std::string name);
	~Message();

	void createMessage();
	std::string getMessage();
	};

