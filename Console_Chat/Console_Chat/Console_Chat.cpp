#include <iostream>
#include "User.h"

int actions()
{
    std::cout << "\n������� ��� ������� : 0 - �����������, 1 - �����, 2 - ��������� ���������,\n 3 - ������� ������������, 4 - ����� ���, 5 - ��������� ���,\n 6 - ������ �������������, q - �����" << std::endl;
    char* choice= new char;
    std::cin >> *choice;
    switch (*choice)
    {
        case '0':
        {
            std::cout << "\n����������� ����������� ������ ������������" << std::endl;
            break;
        }
        case '1':
        {
            std::cout << "\n�����������" << std::endl;
            break;
        }
        case '2':
        {
            std::cout << "\n������ ������ 2" << std::endl;
            break;
        }
        case '3':
        {
            std::cout << "\n������ ������ 3" << std::endl;
            break;
        }
        case '4':
        {
            std::cout << "\n������ ������ 4" << std::endl;
            break;
        }
        case '5':
        {
            std::cout << "\n������ ������ 5" << std::endl;
            break;
        }
        case '6':
        {
            std::cout << "\n������ ������ 6" << std::endl;
            break;
        }
        case 'q':
        {
            return 0;
        }
    }
    delete choice;
    actions();
}

int main()
{
    setlocale(LC_ALL, "");
    actions();
    return 0;
}


