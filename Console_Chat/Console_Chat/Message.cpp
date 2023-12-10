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
	std::getline(std::cin >> std::ws, _message);
	std::cout << "Вы создали сообщение" << std::endl << "Отправитель: " << name << std::endl << "текст сообщения: " << _message << std::endl;
}

void Message::showMessage(std::string name)
{
	std::cout << "Отправитель: " << name << std::endl << "текст сообщения: " << _message << std::endl;
}

void Message::createMessage_priv(std::string name, std::string _name_recipient)
{
	std::getline(std::cin >> std::ws, _message);
	std::cout << "Вы написали сообщение для: " << _name_recipient << std::endl << "Отправитель: " << name << std::endl << "текст сообщения: " << _message << std::endl;
}

void Message::showMessage_priv(std::string name, std::string _name_recipient)
{
	std::cout << "Это сообщение для получателя:  " << _name_recipient << std::endl << "Отправитель: " << name << std::endl << "текст сообщения: " << _message << std::endl;
}

std::string Message::getMessage()
{
	return _message;
}