#include <iostream>
#include "Sailboat.h"

Sailboat::Sailboat()
{
    std::cout << "Вызван конструктор по умолчанию класса Sailboat" << std::endl;

    // устанавливаем параметры
    this->type = "None";
    this->name = "None";
    this->millitary = "None";;
    this->length = "None";
    this->speed = "None";
    this->crew = "None";
}

Sailboat::Sailboat(std::string type, std::string name, std::string millitary, std::string length, std::string speed, std::string crew)
{
    std::cout << "Вызван конструктор с параметром класса Sailboat" << std::endl;

    // устанавливаем параметры
    this->type = type;
    this->name = name;
    this->millitary = millitary;
    this->length = length;
    this->speed = speed;
    this->crew = crew;
}

Sailboat::Sailboat(const Sailboat &sail)
{
    std::cout << "Вызван конструктор копирования класса Sailboat" << std::endl;

     // устанавливаем параметры
    this->type = sail.type;
    this->name = sail.name;
    this->millitary = sail.millitary;
    this->length = sail.length;
    this->speed = sail.speed;
    this->crew = sail.crew;
}

Sailboat::~Sailboat()
{
    std::cout << "Вызван деструктор класса Sailboat" << std::endl;
}

void Sailboat::Change()
{
    int choice = -1;
    std::cout << "Введите параметр, который вы хотите изменить: \n"
              << "1 - тип парусника\n2 - название\n3 - военный или мирный\n4 - длина\n5 - скорость\n6 - экипаж\nВвод: ";
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
        std::cout << "Тип парусника: ";
        std::getline(std::cin, this->type);
    }
    else if (choice == 2)
    {
        std::cout << "Название: ";
        std::getline(std::cin, this->name);
    }
    else if (choice == 3)
    {
        std::cout << "Военный или мирный (0 - мирный, 1 - военный): ";
        std::getline(std::cin, this->millitary);
    }
    else if (choice == 4)
    {
        std::cout << "Длина = ";
        std::getline(std::cin, this->length);
    }
    else if (choice == 5)
    {
        std::cout << "Новая скорость = ";
        std::getline(std::cin, this->speed);
    }
    else
    {
        std::cout << "Новый экпипаж = ";
        std::getline(std::cin, this->crew);
    }

}

int Sailboat::GetID() const { return 1; }

std::string Sailboat::GetType() const {return this->type;}
std::string Sailboat::GetName() const {return this->name;}
std::string Sailboat::GetMillitary() const {return this->millitary;}
std::string Sailboat::GetLength() const {return this->length;}
std::string Sailboat::GetSpeed() const {return this->speed;}
std::string Sailboat::GetCrew() const {return this->crew;}

std::ostream& Sailboat::Print(std::ostream& os) const {
    return os << "Параметры парусника:\n"
              << "Тип парусника: " << this->type << "\n"
              << "Название: " << this->name<< "\n"
              << "Военнный или мирный (0 - мирный, 1 - военный): " << this->millitary << "\n"
              << "Длина m = " << this->length << "\n"
              << "Скоорость km/h = " << this->speed << "\n"
              << "Экипаж: " << this->crew << std::endl;
}

std::ostream& operator << (std::ostream &os, const Sailboat &sail)
{
    return sail.Print(os);
}
