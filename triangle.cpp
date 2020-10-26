#include "triangle.hpp"

Triangle::Triangle() {
    vertices.resize(3);
    type = "Triangle";
}

Triangle::~Triangle() {}

Vertex Triangle::CalculateGeometricMedian() {
    double sum_x = 0, sum_y = 0;
    for (Vertex &vertex : vertices) {
        sum_x += vertex.x;
        sum_y += vertex.y;
    }
    return Vertex(sum_x / 3.0, sum_y / 3.0);
}

void Triangle::DisplayFigureCoordinates() {
    for (int i = 0; i < 3; ++i) {
        cout << vertices[i];
        if(i != 2) cout << ", ";
    }
    cout << '\n';
}

double Triangle::CalculateFigureArea() {
    double side = vertices[0].distance(vertices[1]);
    return (pow(side, 2) * sqrt(3) ) / 4;
}