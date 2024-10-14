#include <iostream>
#include <fstream>
#include "Keeper.h"
#include "Submarine.h"
#include "Sailboat.h"
#include "Speedboat.h"

Keeper::Keeper()
{
    std::cout << "Вызван конструктор по умолчанию класса Keeper" << std::endl;

    this->count_el = 0;
    this->len = 100;
    this->ptr_arr = new Ship*[100];
}

Keeper::Keeper(int count)
{
    std::cout << "Вызван конструктор с параметром класса Keeper" << std::endl;

    this->count_el = 0;
    this->len = count;
    this->ptr_arr = new Ship*[count];
}

Keeper::Keeper(const Keeper &keep)
{
    std::cout << "Вызван конструктор копирования класса Keeper" << std::endl;

    this->count_el = keep.count_el;
    this->len = keep.len;
    this->ptr_arr = new Ship*[keep.count_el];

    for (int i = 0; i < keep.count_el; i++) ptr_arr[i] = keep.ptr_arr[i];
}

Keeper::~Keeper()
{
    std::cout << "Вызван деструктор класса Keeper" << std::endl;

    for (int i = 0; i < this->count_el; i++) delete ptr_arr[i];

    delete [] ptr_arr;
}

void Keeper::Set()
{
    int choice = -1;
    std::cout << "Что вы хотите добавить:\n"
              << "1 - подводную лодку\n2 - парусник\n3 - катер\nВвод: ";

    try
    {
        std::cin >> choice;
        std::cin.ignore(256, '\n');
        if (choice > 3 || choice < 1) throw("Неверный ввод");
    }
    catch(const char* error_message)
    {
        std::cerr << error_message << '\n';
        exit(0);
    }

    if (choice == 1)
    {
        std::cout << "Введите данные:" << std::endl;

        std::string length; // длина
        std::string width; // ширина
        std::string crew; // экипаж
        std::string time; // время под водой в минутах
        std::string max_speed; // максимальная скорость
        std::string weapons; // вооружение

        std::cout << "Длина m = ";
        std::getline(std::cin, length);
        std::cout << "Ширина m = ";
        std::getline(std::cin, width);
        std::cout << "Экипаж: ";
        std::getline(std::cin, crew);
        std::cout << "Время под водой h= ";
        std::getline(std::cin, time);
        std::cout << "Максимальная скорость km/h = ";
        std::getline(std::cin, max_speed);
        std::cout << "Вооружение = ";
        std::getline(std::cin, weapons);

        if (this->count_el == len)
        {
            this->len *= 2;
            Ship **buf_ptr_arr = new Ship*[this->len];

            for (int i = 0; i < this->len/2; i++) buf_ptr_arr[i] = this->ptr_arr[i];

            delete [] this->ptr_arr;
            ptr_arr = buf_ptr_arr;
        }

        this->ptr_arr[count_el++] = new Submarine(length, width, crew, time, max_speed, weapons);
    }
    else if (choice == 2)
    {
        std::cout << "Введите данные:" << std::endl;

        std::string type; // тип парусника
        std::string name; // название
        std::string millitary; // военный или мирный
        std::string length; // длина
        std::string speed; // скорость
        std::string crew; // экипаж

        std::cout << "Тип парусника = ";
        std::getline(std::cin, type);
        std::cout << "Название = ";
        std::getline(std::cin, name);
        std::cout << "Военный (1) или мирный (0): ";
        std::getline(std::cin, millitary);
        std::cout << "Длина m = ";
        std::getline(std::cin, length);
        std::cout << "Скорость km/h = ";
        std::getline(std::cin, speed);
        std::cout << "Экипаж = ";
        std::getline(std::cin, crew);

        if (this->count_el == len)
        {
            this->len *= 2;
            Ship **buf_ptr_arr = new Ship*[this->len];

            for (int i = 0; i < this->len/2; i++) buf_ptr_arr[i] = this->ptr_arr[i];

            delete [] this->ptr_arr;
            ptr_arr = buf_ptr_arr;
        }

        this->ptr_arr[count_el++] = new Sailboat(type, name, millitary, length, speed, crew);
    }
    else
    {
        std::cout << "Введите данные:" << std::endl;

        std::string type; // назначение
        std::string material; // материал корпуса
        std::string driving_qualities; // ходовые качества
        std::string speed; // скорость
        std::string count_people; // кол-во людей на борту

        std::cout << "Назначение: ";
        std::getline(std::cin, type);
        std::cout << "Материал корпуса: ";
        std::getline(std::cin, material);
        std::cout << "Ходовые качества: ";
        std::getline(std::cin, driving_qualities);
        std::cout << "Скорость km/h = ";
        std::getline(std::cin, speed);
        std::cout << "Кол-во людей = ";
        std::getline(std::cin, count_people);

        if (this->count_el == len)
        {
            this->len *= 2;
            Ship **buf_ptr_arr = new Ship*[this->len];

            for (int i = 0; i < this->len/2; i++) buf_ptr_arr[i] = this->ptr_arr[i];

            delete [] this->ptr_arr;
            ptr_arr = buf_ptr_arr;
        }

        this->ptr_arr[count_el++] = new Speedboat(type, material, driving_qualities, speed, count_people);
    }


}

void Keeper::Get()
{
    int id = -1;
    std::cout << "Введите id элемента для получения: ";

    try
    {
        std::cin >> id;
        std::cin.ignore(256, '\n');
        if (id > this->count_el || id < 0) throw("Ошибка ввода id");
    }
    catch(const char* error_message)
    {
        std::cerr << error_message << '\n';
        exit(0);
    }

    if (this->ptr_arr[id] != nullptr) std::cout << *this->ptr_arr[id] << std::endl;
    else std::cout << "Empty" << std::endl;

}

void Keeper::Pop()
{
    int id = -1;
    std::cout << "Введите id элемента для получения: ";

    try
    {
        std::cin >> id;
        std::cin.ignore(256, '\n');
        if (id > this->count_el || id < 0) throw("Ошибка ввода id");
    }
    catch(const char* error_message)
    {
        std::cerr << error_message << '\n';
        exit(0);
    }

    for (int i = id; i < this->count_el - 1; i++) this->ptr_arr[i] = this->ptr_arr[i+1];

    this->count_el--;
    this->ptr_arr[this->count_el] = nullptr;

}

void Keeper::Show_all()
{
    if (this->ptr_arr[0] == nullptr) std::cout << "Empty" << std::endl;
    else for (int i = 0; i < this->count_el; i++) std::cout << *this->ptr_arr[i] << std::endl;
}

void Keeper::Save()
{
    std::ofstream file_sub, file_sail, file_speed;

    file_sub.open("sub_info.txt");
    file_sail.open("sail_info.txt");
    file_speed.open("speed_info.txt");

    if (file_sub.is_open() && file_sail.is_open() && file_speed.is_open())
    {
        for (int i = 0; i < this->count_el; i++)
        {
            if (this->ptr_arr[i]->GetID() == 0)
            {
                file_sub << this->ptr_arr[i]->GetLength() << "\n";
                file_sub << this->ptr_arr[i]->GetWidth() << "\n";
                file_sub << this->ptr_arr[i]->GetCrew() << "\n";
                file_sub << this->ptr_arr[i]->GetTime() << "\n";
                file_sub << this->ptr_arr[i]->GetSpeed() << "\n";
                file_sub << this->ptr_arr[i]->GetWeapons() << "\n";
            }
            else if (this->ptr_arr[i]->GetID() == 1)
            {
                file_sail << this->ptr_arr[i]->GetType() << "\n";
                file_sail << this->ptr_arr[i]->GetName() << "\n";
                file_sail << this->ptr_arr[i]->GetMillitary() << "\n";
                file_sail << this->ptr_arr[i]->GetLength() << "\n";
                file_sail << this->ptr_arr[i]->GetSpeed() << "\n";
                file_sail << this->ptr_arr[i]->GetCrew() << "\n";
            }
            else
            {
                file_speed << this->ptr_arr[i]->GetType() << "\n";
                file_speed << this->ptr_arr[i]->GetMaterial() << "\n";
                file_speed << this->ptr_arr[i]->GetDriving() << "\n";
                file_speed << this->ptr_arr[i]->GetSpeed() << "\n";
                file_speed << this->ptr_arr[i]->GetCount() << "\n";
            }
        }
    }

    file_sub.close();
    file_sail.close();
    file_speed.close();
}

void Keeper::Load()
{
    std::ifstream file_sub, file_sail, file_speed;

    file_sub.open("sub_info.txt");

    if (file_sub.is_open())
    {
        std::string length; // длина
        std::string width; // ширина
        std::string crew; // экипаж
        std::string time; // время под водой в минутах
        std::string max_speed; // максимальная скорость
        std::string weapons; // вооружение

        while (std::getline(file_sub, length))
        {
            std::getline(file_sub, width);
            std::getline(file_sub, crew);
            std::getline(file_sub, time);
            std::getline(file_sub, max_speed);
            std::getline(file_sub, weapons);

            if (this->count_el == len)
            {
                this->len *= 2;
                Ship **buf_ptr_arr = new Ship*[this->len];

                for (int i = 0; i < this->len/2; i++) buf_ptr_arr[i] = this->ptr_arr[i];

                delete [] this->ptr_arr;
                ptr_arr = buf_ptr_arr;
            }

            this->ptr_arr[count_el++] = new Submarine(length, width, crew, time, max_speed, weapons);
        }

    }

    file_sub.close();

    file_sail.open("sail_info.txt");

    if (file_sail.is_open())
    {
        std::string type; // тип парусника
        std::string name; // название
        std::string millitary; // военный или мирный
        std::string length; // длина
        std::string speed; // скорость
        std::string crew; // экипаж

        while (std::getline(file_sail, type))
        {
            std::getline(file_sail, name);
            std::getline(file_sail, millitary);
            std::getline(file_sail, length);
            std::getline(file_sail, speed);
            std::getline(file_sail, crew);

            if (this->count_el == len)
            {
                this->len *= 2;
                Ship **buf_ptr_arr = new Ship*[this->len];

                for (int i = 0; i < this->len/2; i++) buf_ptr_arr[i] = this->ptr_arr[i];

                delete [] this->ptr_arr;
                ptr_arr = buf_ptr_arr;

            }

            this->ptr_arr[count_el++] = new Sailboat(type, name, millitary, length, speed, crew);
        }

    }

    file_sail.close();

    file_speed.open("speed_info.txt");

    if (file_speed.is_open())
    {
        std::string type; // назначение
        std::string material; // материал корпуса
        std::string driving_qualities; // ходовые качества
        std::string speed; // скорость
        std::string count_people; // кол-во людей на борту

        while (std::getline(file_speed, type))
        {
            std::getline(file_speed, material);
            std::getline(file_speed, driving_qualities);
            std::getline(file_speed, speed);
            std::getline(file_speed, count_people);

            if (this->count_el == len)
            {
                this->len *= 2;
                Ship **buf_ptr_arr = new Ship*[this->len];

                for (int i = 0; i < this->len/2; i++) buf_ptr_arr[i] = this->ptr_arr[i];

                delete [] this->ptr_arr;
                ptr_arr = buf_ptr_arr;

            }

            this->ptr_arr[count_el++] = new Speedboat(type, material, driving_qualities, speed, count_people);
        }

    }

    file_speed.close();
}

void Keeper::Change()
{
    int id = -1;
    std::cout << "Введите id элемента для получения: ";

    try
    {
        std::cin >> id;
        std::cin.ignore(256, '\n');
        if (id > this->count_el || id < 0) throw("Ошибка ввода id");
    }
    catch(const char* error_message)
    {
        std::cerr << error_message << '\n';
        exit(0);
    }

    this->ptr_arr[id]->Change();
}
