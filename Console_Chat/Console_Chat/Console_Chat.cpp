#include <iostream>
#include "User.h"

int actions()
{
    std::cout << "\nВведите код команды : 0 - регистрация, 1 - логин, 2 - отправить сообщение,\n 3 - сменить пользователя, 4 - общий чат, 5 - приватный чат,\n 6 - список пользователей, q - выход" << std::endl;
    char* choice= new char;
    std::cin >> *choice;
    switch (*choice)
    {
        case '0':
        {
            std::cout << "\nВыполняется регистрация нового пользователя" << std::endl;
            break;
        }
        case '1':
        {
            std::cout << "\nАвторизация" << std::endl;
            break;
        }
        case '2':
        {
            std::cout << "\nВыбран символ 2" << std::endl;
            break;
        }
        case '3':
        {
            std::cout << "\nВыбран символ 3" << std::endl;
            break;
        }
        case '4':
        {
            std::cout << "\nВыбран символ 4" << std::endl;
            break;
        }
        case '5':
        {
            std::cout << "\nВыбран символ 5" << std::endl;
            break;
        }
        case '6':
        {
            std::cout << "\nВыбран символ 6" << std::endl;
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


