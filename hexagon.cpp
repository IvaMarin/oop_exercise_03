#include "hexagon.hpp"

Hexagon::Hexagon() {
    vertices.resize(6);
    type = "Hexagon";
}

Hexagon::~Hexagon() {}

Vertex Hexagon::CalculateGeometricMedian() {
    double sum_x = 0, sum_y = 0;
    for (Vertex &vertex : vertices) {
        sum_x += vertex.x;
        sum_y += vertex.y;
    }
    return Vertex(sum_x / 6.0, sum_y / 6.0);
}

void Hexagon::DisplayFigureCoordinates() {
    for (int i = 0; i < 6; ++i) {
        cout << vertices[i];
        if(i != 5) cout << ", ";
    }
    cout << '\n';
}

double Hexagon::CalculateFigureArea() {
    double side = vertices[0].distance(vertices[1]);
    return pow(side, 2) * 3 * sqrt(3) / 2;
}