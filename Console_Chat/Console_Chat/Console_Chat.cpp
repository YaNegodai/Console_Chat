#include <iostream>
#include <windows.h>
#include "Chat.h"


int actions(Chat* chat, bool* user_exist)
{
    
    std::cout << "\nВведите код команды : \n1 - Регистрация \n2 - Логин \n3 - Логаут \n4 - Отправить личное сообщение \n5 - Общий чат \n6 - Список пользователей \n7 - Просмотр личных сообщений \n8 - Просмотр общего чата \nq - Выход" << std::endl;
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
            chat->logInUser(user_exist);
            break;
        }
        case '3':
        {
            std::cout << "\nЛогаут" << std::endl;
            chat->logOutUser();
            break;
        }
        case '4':
        {
            std::cout << "\nОтправка личного сообщения" << std::endl;
            chat->privateChat();
            break;
        }
        case '5':
        {
            std::cout << "\nОбщий чат" << std::endl;
            chat->generalChat();
            break;
        }
        case '6':
        {
            //std::cout << "\nСписок пользователей" << std::endl;
            chat->showUserList();
            break;
        }

        case '7':
        {
            std::cout << "Просмотр личных сообщений" << std::endl;
            chat->receive_priv_Message();
            break;

        }

        case '8':
        {
            std::cout << "Просмотр общего чата" << std::endl;
            chat->recive_Message();
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Chat chat;
    bool user_exist{ false };
    chat.regChatForAll();
    actions(&chat, &user_exist);
    return 0;
}


