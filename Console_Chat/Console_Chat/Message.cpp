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

Message::~Message()
{

}

void Message::createMessage()
{
	std::getline(std::cin >> std::ws, _message); // вроде поправила
	std::cout << "Sender: " << _name << std::endl << "send message: " << _message << std::endl;
}

std::string Message::getMessage()
{
	return _message;
}