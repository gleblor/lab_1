#include <iostream>
#include "Submarine.h"

Submarine::Submarine()
{
    std::cout << "Вызван конструктор по умолчанию класса Submarine" << std::endl;

    // устанавливаем параметры
    this->length = "None";
    this->width = "None";
    this->crew = "None";
    this->time = "None";
    this->max_speed = "None";
    this->weapons = "None";
}

Submarine::Submarine(std::string length, std::string width, std::string crew, std::string time, std::string max_speed, std::string weapons)
{
    std::cout << "Вызван конструктор с параметром класса Submarine" << std::endl;

    // устанавливаем параметры
    this->length = length;
    this->width = width;
    this->crew = crew;
    this->time = time;
    this->max_speed = max_speed;
    this->weapons = weapons;
}

Submarine::Submarine(const Submarine &sub)
{
    std::cout << "Вызван конструктор копирования класса Submarine" << std::endl;

     // устанавливаем параметры
    this->length = sub.length;
    this->width = sub.width;
    this->crew = sub.crew;
    this->time = sub.time;
    this->max_speed = sub.max_speed;
    this->weapons = sub.weapons;
}

Submarine::~Submarine()
{
    std::cout << "Вызван деструктор класса Submarine" << std::endl;
}

void Submarine::Change()
{
    int choice = -1;
    std::cout << "Введите параметр, который вы хотите изменить: \n"
              << "1 - длина\n2 - ширина\n3 - экипаж\n4 - время под водой\n5 - максимальная скорость\n6 - вооружение\nВвод: ";
    try
    {
        std::cin >> choice;
        std::cin.ignore(256, '\n');
        if (choice > 6 || choice < 1) throw("Неверный ввод");
    }
    catch(const char* error_message)
    {
        std::cerr << error_message << '\n';
        exit(0);
    }

    if (choice == 1)
    {
        std::cout << "Новая длина = ";
        std::getline(std::cin, this->length);
    }
    else if (choice == 2)
    {
        std::cout << "Новая ширина = ";
        std::getline(std::cin, this->width);
    }
    else if (choice == 3)
    {
        std::cout << "Новый экипаж = ";
        std::getline(std::cin, this->crew);
    }
    else if (choice == 4)
    {
        std::cout << "Новое время = ";
        std::getline(std::cin, this->time);
    }
    else if (choice == 5)
    {
        std::cout << "Новая скорость = ";
        std::getline(std::cin, this->max_speed);
    }
    else
    {
        std::cout << "Новое вооружние = ";
        std::getline(std::cin, this->weapons);
    }

}

int Submarine::GetID() const { return 0; }

std::string Submarine::GetLength() const {return this->length;}
std::string Submarine::GetWidth() const {return this->width;}
std::string Submarine::GetCrew() const {return this->crew;}
std::string Submarine::GetTime() const {return this->time;}
std::string Submarine::GetSpeed() const {return this->max_speed;}
std::string Submarine::GetWeapons() const {return this->weapons;}

std::ostream& Submarine::Print(std::ostream& os) const {
    return os << "Параметры подводной лодки:\n"
              << "Длина m = " << this->length << "\n"
              << "Ширина m = " << this->width << "\n"
              << "Экипаж: " << this->crew << "\n"
              << "Время под водой h = " << this->time << "\n"
              << "Максимальная скорость km/h = " << this->max_speed << "\n"
              << "Вооружение: " << this->weapons << std::endl;
}

std::ostream& operator << (std::ostream &os, const Submarine &sub)
{
    return sub.Print(os);
}
