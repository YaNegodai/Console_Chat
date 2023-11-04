#pragma once
#include <iostream>
#include <cstring>

class User
{
public:
	//Конструкторы
	explicit User(const std::string& name, const std::string& login, const std::string& password); // явное задание 
	//Деструктор
	~User(); // деструктор + освобождение выделенной памяти
	//Методы
	std::string getName();
	void setName(std::string& name);
	std::string getLogin();
	void setLogin(std::string& login);
	std::string getPassword();
	void setPassword(std::string& password);
protected:
	std::string* _name;
private:
	std::string* _login;
	std::string* _password;
};
