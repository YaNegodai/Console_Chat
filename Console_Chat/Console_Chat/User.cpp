#include "User.h"

User::User(const std::string& name, const std::string& login, const std::string& password)
{
	std::string* _name = new std::string(name);
	std::string* _login = new std::string(login);
	std::string* _password = new std::string(password);
}


User::~User()
{
	delete _name;
	delete _login;
	delete _password;
}

std::string User::getName()
{
	return *_name;
}

void User::setName(std::string& name)
{
	*_name = name;
}

std::string User::getLogin()
{
	return *_login;
}

void User::setLogin(std::string& login)
{
	*_login = login;
}

std::string User::getPassword()
{
	return *_password;
}

void User::setPassword(std::string& password)
{
	*_password = password;
}
