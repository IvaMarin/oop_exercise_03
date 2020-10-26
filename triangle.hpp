#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "figure.hpp"

class Triangle: public Figure { //Класс треугольник
public:
    Triangle(); //Конструктор
    ~Triangle(); //Деструктор

    Vertex CalculateGeometricMedian() override; //Метод вычисления геометрического центра треугольника
    void DisplayFigureCoordinates() override; //Метод вывода координат вершин треугольника
    double CalculateFigureArea() override; //Метод вычисления площади треугольника
};

#endif /* TRIANGLE_HPP */