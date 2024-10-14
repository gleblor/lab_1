#include <iostream>
#include "Speedboat.h"

Speedboat::Speedboat()
{
    std::cout << "Вызван конструктор по умолчанию класса Speedboat" << std::endl;

    // устанавливаем параметры
    this->type = "None";
    this->material = "None";
    this->driving_qualities = "None";
    this->speed = "None";
    this->count_people = "None";
}

Speedboat::Speedboat(std::string type, std::string material, std::string driving_qualities, std::string speed, std::string count_people)
{
    std::cout << "Вызван конструктор с параметром класса Speedboat" << std::endl;

    // устанавливаем параметры
    this->type = type;
    this->material = material;
    this->driving_qualities = driving_qualities;
    this->speed = speed;
    this->count_people = count_people;
}

Speedboat::Speedboat(const Speedboat &speed)
{
    std::cout << "Вызван конструктор копирования класса Speedboat" << std::endl;

     // устанавливаем параметры
    this->type = speed.type;
    this->material = speed.material;
    this->driving_qualities = speed.driving_qualities;
    this->speed = speed.speed;
    this->count_people = speed.count_people;
}

Speedboat::~Speedboat()
{
    std::cout << "Вызван деструктор класса Speedboat" << std::endl;
}

void Speedboat::Change()
{
    int choice = -1;
    std::cout << "Введите параметр, который вы хотите изменить: \n"
              << "1 - назначение\n2 - материал корпуса\n3 - ходовые качества\n4 - скорость\n5 - кол-во людей максимальное\nВвод: ";
    try
    {
        std::cin >> choice;
        std::cin.ignore(256, '\n');
        if (choice > 5 || choice < 1) throw("Неверный ввод");
    }
    catch(const char* error_message)
    {
        std::cerr << error_message << '\n';
        exit(0);
    }

    if (choice == 1)
    {
        std::cout << "Назначение: ";
        std::getline(std::cin, this->type);
    }
    else if (choice == 2)
    {
        std::cout << "Материал корпуса: ";
        std::getline(std::cin, this->material);
    }
    else if (choice == 3)
    {
        std::cout << "Ходовые качества: ";
        std::getline(std::cin, this->driving_qualities);
    }
    else if (choice == 4)
    {
        std::cout << "Скорость = ";
        std::getline(std::cin, this->speed);
    }
    else
    {
        std::cout << "Кол-во людей  максимальное= ";
        std::getline(std::cin, this->count_people);
    }

}

int Speedboat::GetID() const { return 2; }

std::string Speedboat::GetType() const {return this->type;}
std::string Speedboat::GetMaterial() const {return this->material;}
std::string Speedboat::GetDriving() const {return this->driving_qualities;}
std::string Speedboat::GetSpeed() const {return this->speed;}
std::string Speedboat::GetCount() const {return this->count_people;}

std::ostream& Speedboat::Print(std::ostream& os) const {
    return os << "Параметры катера:\n"
              << "Назначение: " << this->type << "\n"
              << "Материал корпуса = " << this->material << "\n"
              << "Ходовые качества: " << this->driving_qualities << "\n"
              << "Скорость km/h = " << this->speed << "\n"
              << "Кол-во людей максимальное = " << this->count_people << "\n" << std::endl;
}

std::ostream& operator << (std::ostream &os, const Speedboat &speed)
{
    return speed.Print(os);
}
