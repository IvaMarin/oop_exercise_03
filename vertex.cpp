#include "vertex.hpp"

double Vertex::distance(Vertex &v) const {
    return sqrt(pow(v.x - x, 2) + pow(v.y - y, 2));
}

Vertex::Vertex(): x(0.0), y(0.0) {}
Vertex::Vertex(double x, double y) : x(x), y(y) {}
Vertex::~Vertex() {}

ostream &operator<<(ostream &out, Vertex vertex) {
    cout.precision(3);
    out << "(" << vertex.x << ";" << vertex.y << ")";
    return out;
}

istream &operator>>(istream &in, Vertex &vertex) {
    in >> vertex.x >> vertex.y;
    return in;
}