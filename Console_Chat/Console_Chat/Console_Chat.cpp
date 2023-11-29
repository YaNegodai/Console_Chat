#include <iostream>
#include "Chat.h"


int actions(Chat* chat, bool* user_exist)
{
    
    std::cout << "\nВведите код команды : \n1 - Регистрация \n2 - Логин \n3 - Логаут \n4 - Отправить личное сообщение \n5 - Общий чат \n6 - Список пользователей \nq - Выход" << std::endl;
    char* choice= new char;
    std::cin >> *choice;
    switch (*choice)
    {
        case '1':
        {
            std::cout << "\nРегистрация нового пользователя" << std::endl;
            chat->regUser(user_exist);
            break;
        }
        case '2':
        {
            std::cout << "\nАвторизация" << std::endl;
            break;
        }
        case '3':
        {
            std::cout << "\nЛогаут" << std::endl;
            break;
        }
        case '4':
        {
            std::cout << "\nОтправка личного сообщения" << std::endl;
            break;
        }
        case '5':
        {
            std::cout << "\nОбщий чат" << std::endl;
            break;
        }
        case '6':
        {
            //std::cout << "\nСписок пользователей" << std::endl;
            chat->showUserList();
            break;
        }

        case 'q':
        {
            std::cout << "\nЗакрытие чата...\nДо свидания!" << std::endl;
            exit(0);
        }
    }
    delete choice;
    actions(chat, user_exist);
}

int main()
{
    setlocale(LC_ALL, "");
    Chat chat;
    bool user_exist{ false };
    chat.regChatForAll();
    actions(&chat, &user_exist);
    return 0;
}


