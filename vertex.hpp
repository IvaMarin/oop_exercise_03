#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Vertex { //Класс вершина
public:
    double x; //Координата x
    double y; //Координата y
	double distance(Vertex &v) const; //Расстояние между двумя вершинами

	Vertex(); //Конструктор по умолчанию
	Vertex(double x, double y); //Конструктор
	~Vertex(); //Деструктор
};

ostream &operator<<(ostream &out, Vertex vertex); //Перегрузка оператора вывода
istream &operator>>(istream &in, Vertex &vertex); //Перегрузка оператора ввода

#endif /* VERTEX_HPP */