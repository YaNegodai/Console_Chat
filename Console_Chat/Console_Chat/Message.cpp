#include "Message.h"
 
Message::Message(const std::string login, const std::string name, std::string message) : _login(login), _name(name), _message(message)
{

}

Message::Message(std::string name, std::string message) : _name(name), _message(message)
{

}

Message::Message(std::string name) : _name(name)
{

}

Message::~Message()
{

}

void Message::writeMessage()
{
	std::getline(std::cin, _message);
}

void Message::showMessage()
{
	std::cout << "Sender: " << _name << std::endl  << "send message: " << _message << std::endl;
}

std::string Message::getMessage()
{
	return _message;
}