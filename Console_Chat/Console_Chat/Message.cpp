#include "Message.h"

Message::Message(std::string login, std::string name,std::string name_recipient, std::string message) : _login(login), _name(name), _name_recipient(name_recipient), _message(message)
{

}
 
Message::Message(std::string login, std::string name, std::string message) : _login(login), _name(name), _message(message)
{

}

Message::Message(std::string name, std::string message) : _name(name), _message(message)
{

}

Message::Message(std::string name) : _name(name)
{

}

Message::Message()
{

}

Message::~Message()
{

}

void Message::createMessage(std::string name)
{
	_name = name;
	std::cin.clear();
	std::getline(std::cin >> std::ws, _message);
	std::cout << "Вы создали сообщение" << std::endl << "Отправитель:  " << _name << std::endl << "Текст сообщения: " << _message << std::endl;
}

void Message::showMessage()
{
	std::cout << "Отправитель: " << _name << std::endl << "Текст сообщения: " << _message << std::endl;
}

void Message::createMessage_priv(std::string name, std::string name_recipient)
{
	_name = name;
	_name_recipient = name_recipient;
	std::cin.clear();
	std::getline(std::cin >> std::ws, _message);
	std::cout << "Вы написали сообщение для: " << _name_recipient << std::endl << "Отправитель: " << _name << std::endl << "Текст сообщения: " << _message << std::endl;
}

void Message::showMessage_priv()
{
	std::cout << "Это сообщения для получателя " << _name_recipient << std::endl << "Отправитель: " << _name << std::endl << "Текст сообщения: " << _message << std::endl;
}

std::string Message::getMessage()
{
	return _message;
}