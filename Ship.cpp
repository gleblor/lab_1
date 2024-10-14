#include <iostream>
#include "Ship.h"

Ship::Ship()
{
    std::cout << "Вызван конструктор по умолчанию класса Ship" << std::endl;
}
Ship::Ship(int count)
{
    std::cout << "Вызван конструктор с параметром класса Ship" << std::endl;
}
Ship::Ship(const Ship &ship)
{
    std::cout << "Вызван конструктор копирования класса Ship" << std::endl;
}
Ship::~Ship()
{
    std::cout << "Вызван деструктор класса Ship" << std::endl;
}

std::string Ship::GetLength() const {return "none";}
std::string Ship::GetWidth() const {return "none";}
std::string Ship::GetCrew() const {return "none";}
std::string Ship::GetTime() const {return "none";}
std::string Ship::GetSpeed() const {return "none";}
std::string Ship::GetWeapons() const {return "none";}
std::string Ship::GetType() const {return "none";}
std::string Ship::GetName() const {return "none";}
std::string Ship::GetMillitary() const {return "none";}
std::string Ship::GetMaterial() const {return "none";}
std::string Ship::GetDriving() const {return "none";}
std::string Ship::GetCount() const {return "none";}

std::ostream& operator<<(std::ostream& os, const Ship& ship)
{
    return ship.Print(os);
}
