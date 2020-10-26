#ifndef OCTAGON_HPP
#define OCTAGON_HPP

#include "figure.hpp"

class Octagon: public Figure { //Класс восьмиугольник
public:
    Octagon(); //Конструктор
    ~Octagon(); //Деструктор

    Vertex CalculateGeometricMedian() override; //Метод вычисления геометрического центра восьмиугольника
    void DisplayFigureCoordinates() override; //Метод вывода координат вершин восьмиугольника
    double CalculateFigureArea() override; //Метод вычисления площади восьмиугольника
};

#endif /* OCTAGON_HPP */