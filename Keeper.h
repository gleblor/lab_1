#pragma once
#include "Ship.h"

class Keeper
{
private:
    int count_el;
    int len;
    Ship **ptr_arr;

public:
    Keeper(); // конструктор по умолчанию
    Keeper(int count); // конструктор с параметром
    Keeper(const Keeper &keep); // конструктор копирования
    ~Keeper(); // деструктор

    void Set(); // метод добавления элементов
    void Get(); // метод получения элемента
    void Pop(); // метод удаления элемента
    void Show_all(); // метод для вывода информации о всех элементов
    void Save(); // сохранение в файл
    void Load(); // восстановление из файла
    void Change();
};
