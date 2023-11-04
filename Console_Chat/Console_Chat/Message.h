#pragma once
#include <iostream>
#include <string>
class Message
{
private:
	std::string _message; //текст сообщения
	const std::string _name; //имя отправителя
	const std::string _login; //логин отправителя
public:
	Message(const std::string login, const std::string name, std::string message);
	Message(std::string name, std::string message);
	Message(std::string name);
	~Message();

	void writeMessage(); //наверное, не надо писать тут автора на вход
	std::string getMessage(); //если брать void то не можем вывести сообщение, разные форматы.
	virtual void showMessage(); //выводим через cout имя автора и сообщение. 
	};

