#pragma once
#include <iostream>
#include <string>
class Message
{
private:
	std::string _message; //����� ���������
	const std::string _name; //��� �����������
	const std::string _login; //����� �����������
public:
	Message(const std::string login, const std::string name, std::string message);
	Message(std::string name, std::string message);
	Message(std::string name);
	~Message();

	void writeMessage(); //��������, �� ���� ������ ��� ������ �� ����
	std::string getMessage(); //���� ����� void �� �� ����� ������� ���������, ������ �������.
	virtual void showMessage(); //������� ����� cout ��� ������ � ���������. 
	};

