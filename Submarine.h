#pragma once
#include "Ship.h"
#include <string>

class Submarine:public Ship
{
private:
    std::string length; // длина
    std::string width; // ширина
    std::string crew; // экипаж
    std::string time; // время под водой в минутах
    std::string max_speed; // максимальная скорость
    std::string weapons; // вооружение

public:
    Submarine(); // конструктор по умолчанию
    Submarine(std::string length, std::string width, std::string crew, std::string time, std::string max_speed, std::string weapons); // конструктор с параметром
    Submarine(const Submarine &sub); // конструктор копирования
    ~Submarine(); // деструктор

    void Change() override;
    int GetID() const override;
    std::ostream& Print(std::ostream& os) const override;

    std::string GetLength() const override;
    std::string GetWidth() const override;
    std::string GetCrew() const override;
    std::string GetTime() const override;
    std::string GetSpeed() const override;
    std::string GetWeapons() const override;

    //friend std::ostream& operator<<(std::ostream &os, const Submarine &sub);

};
