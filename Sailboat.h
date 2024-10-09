#pragma once
#include "Ship.h"
#include <string>

class Sailboat:public Ship
{
private:
    std::string type; // тип парусника
    std::string name; // название
    std::string millitary; // военный или мирный
    std::string length; // длина
    std::string speed; // скорость
    std::string crew; // экипаж

public:
    Sailboat(); // конструктор по умолчанию
    Sailboat(std::string type, std::string name, std::string millitary, std::string length, std::string speed, std::string crew); // конструктор с параметром
    Sailboat(const Sailboat &sail); // конструктор копирования
    ~Sailboat(); // деструктор

    void Change() override;
    int GetID() const override;
    std::ostream& Print(std::ostream& os) const override;

    std::string GetType() const override;
    std::string GetName() const override;
    std::string GetMillitary() const override;
    std::string GetLength() const override;
    std::string GetSpeed() const override;
    std::string GetCrew() const override;

    //friend std::ostream& operator<<(std::ostream &os, const Sailboat &sail);
};
