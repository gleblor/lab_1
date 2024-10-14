#include <iostream>
#include "Keeper.h"

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); 
    int choice;
    std::cout << "Как вы хотите начать работу?\n1 - Загрузить данные из файла\n2 - Ввести вручную\nВвод: ";
    try
    {
        std::cin >> choice;
        std::cin.ignore(256, '\n');
        if (choice > 2 || choice < 1) throw("Ошибка выбора");
    }
    catch (char * mssg)
    {
        std::cerr << mssg << std::endl;
    }

    Keeper k;

    if (choice == 1) k.Load();

    while(true)
        {
            int choice_w;
            std::cout << "ПАНЕЛЬ УПРАВЛЕНИЯ\n"
                      << "------------------\n"
                      << "1 - добавить элемент\n"
                      << "2 - вывести один элемент\n"
                      << "3 - вывести все элементы\n"
                      << "4 - удалить элемен\n"
                      << "5 - сохранить все данные в файл\n"
                      << "6 - изменить данные\n"
                      << "Ввод: ";
            std::cin >> choice_w;
            std::cin.ignore(256, '\n');

            if (choice_w == 1) k.Set();
            else if (choice_w == 2) k.Get();
            else if (choice_w == 3) k.Show_all();
            else if (choice_w == 4) k.Pop();
            else if (choice_w == 5) k.Save();
            else if (choice_w == 6) k.Change();
            else
            {
                std::cout << "Ошибка ввода" << std::endl;
                exit(0);
            }
        }



    return 0;
}
