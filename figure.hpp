#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <vector>

#include "vertex.hpp"

class Figure { //Базовый класс
public:

    virtual Vertex CalculateGeometricMedian() = 0; //Метод вычисления геометрического центра фигуры
    virtual void DisplayFigureCoordinates() = 0; //Метод вывода координат вершин фигуры
    virtual double CalculateFigureArea() = 0; //Метод вычисления площади фигуры

    friend std::istream &operator>>(std::istream &in, Figure &figure) {
        do {
            for (auto &vertex : figure.vertices) {
                in >> vertex;
            }
        } while (!figure.check_vertices());
            return in;
    }
  
    virtual ~Figure() {}

protected:

    std::vector<Vertex> vertices; //Вектор вершин
    std::string type;

    bool check_vertices() {
        double figure_distance = vertices[0].distance(vertices[vertices.size() - 1]);
        for (unsigned int i = 0; i < vertices.size() - 1; ++i) {
            double cur_length = vertices[i].distance(vertices[i + 1]);
            if (std::abs(cur_length - figure_distance) >= 1e-2) {
                std::cout << "Figure must have equal sides. Try again!" << std::endl;
                return false;
            }
            if (figure_distance == 0) { 
                std::cout << "Points should be different. Try again!" << std::endl;
                return false;
            }
        }
        return true;
    }
  
};

#endif /* FIGURE_HPP */