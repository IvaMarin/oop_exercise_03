#include "octagon.hpp"

Octagon::Octagon() {
    vertices.resize(8);
    type = "Octagon";
}

Octagon::~Octagon() {}

Vertex Octagon::CalculateGeometricMedian() {
    double sum_x = 0, sum_y = 0;
    for (Vertex &vertex : vertices) {
        sum_x += vertex.x;
        sum_y += vertex.y;
    }
    return Vertex(sum_x / 6.0, sum_y / 6.0);
}

void Octagon::DisplayFigureCoordinates() {
    for (int i = 0; i < 8; ++i) {
        cout << vertices[i];
        if(i != 7) cout << ", ";
    }
    cout << '\n';
}

double Octagon::CalculateFigureArea() {
    double side = vertices[0].distance(vertices[1]);
    return 2 * pow(side, 2) * (1 + sqrt(2));
}