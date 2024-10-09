#pragma once
#include "Ship.h"
#include <string>

class Speedboat:public Ship
{
private:
    std::string type; // назначение
    std::string material; // материал корпуса
    std::string driving_qualities; // ходовые качества
    std::string speed; // скорость
    std::string count_people; // кол-во людей на борту


public:
    Speedboat(); // конструктор по умолчанию
    Speedboat(std::string type, std::string material, std::string driving_qualities, std::string speed, std::string count_people); // конструктор с параметром
    Speedboat(const Speedboat &speed); // конструктор копирования
    ~Speedboat(); // деструктор

    void Change() override;
    int GetID() const override;
    std::ostream& Print(std::ostream& os) const override;

    std::string GetType() const override;
    std::string GetMaterial() const override;
    std::string GetDriving() const override;
    std::string GetSpeed() const override;
    std::string GetCount() const override;

    //friend std::ostream& operator<<(std::ostream &os, const Speedboat &speed);
};
