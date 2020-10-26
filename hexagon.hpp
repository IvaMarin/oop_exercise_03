#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include "figure.hpp"

class Hexagon: public Figure { //Класс шестиугольник
public:
    Hexagon(); //Конструктор
    ~Hexagon(); //Деструктор

    Vertex CalculateGeometricMedian() override; //Метод вычисления геометрического центра шестиугольника
    void DisplayFigureCoordinates() override; //Метод вывода координат вершин шестиугольника
    double CalculateFigureArea() override; //Метод вычисления площади шестиугольника
};

#endif /* HEXAGON_HPP */