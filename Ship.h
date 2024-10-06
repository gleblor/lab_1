#pragma once

// Создаем абстрактный класс Ship, который хранит данные о подводных лодках,
// парусниках и катерах.
class Ship
{
public:
    Ship(); // конструктор по умолчанию
    Ship(int count); // конструктор с параметром
    Ship(const Ship &ship); // конструктор копирования
    ~Ship(); // деструктор

    virtual void Change() = 0; // создаем чистую виртуальную функцию изменения параметров техники
    virtual int GetID() const = 0;

    virtual std::string GetLength() const;
    virtual std::string GetWidth() const;
    virtual std::string GetCrew() const;
    virtual std::string GetTime() const;
    virtual std::string GetSpeed() const;
    virtual std::string GetWeapons() const;
    virtual std::string GetType() const;
    virtual std::string GetName() const;
    virtual std::string GetMillitary() const;
    virtual std::string GetMaterial() const;
    virtual std::string GetDriving() const;
    virtual std::string GetCount() const;

    virtual std::ostream& Print(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream &os, const Ship &ship);

};
