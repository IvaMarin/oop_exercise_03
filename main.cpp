/* Мариничев Иван М8О-208Б-19
 *
 * github: IvaMarin
 *
 * Вариант 31:
 * Разработать классы 6-угольник, 8-угольник и треугольник, классы должны наследоваться от базового класса Figure. 
 * Фигуры являются выпуклыми равносторонними фигурами вращения. Все классы должны поддерживать набор общих методов:
 *  1. Вычисление геометрического центра фигуры;
 *  2. Вывод в стандартный поток вывода std::cout координат вершин фигуры; 
 *  3. Вычисление площади фигуры.
 * Создать программу, которая позволяет:
 *  • Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
 *  • Сохранять созданные фигуры в динамический массив std::vector<Figure*>.
 *  • Вызывать для всего массива общие функции (1-3 см. выше).
 *    Т.е. распечатывать для каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
 *  • Необходимо уметь вычислять общую площадь фигур в массиве.
 *  • Удалять из массива фигуру по индексу.
 */


#include <iostream>
#include <vector>
#include <string>

#include "figure.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "triangle.hpp"

using namespace std;

void Menu()
{
    cout << "1) Add figure\n";
    cout << "2) Remove figure\n";
    cout << "3) Calculate geometric median of the figure\n";
    cout << "4) Find coordinates of figure's vertices\n";
    cout << "5) Find area of figure\n";
    cout << "6) Find total area\n";
    cout << "7) Exit\n";
}

int main() {
    Menu();
    std::vector<Figure *> figures;
    double totalArea = 0;

    bool input = true;
    int option, figureType;
    unsigned int index;

    while (input) {
        cin >> option;
        switch (option) {
            case 1: {
                cout << "Enter the type of figure (1 - hexagon, 2 - octagon, 3 - triangle)" << endl;
                cin >> figureType;
                if (figureType == 1) {
                    auto *H = new Hexagon;
                    cout << "Enter vertices of this figure" << endl;
                    cin >> *H;
                    figures.push_back(H);
                } else if (figureType == 2) {
                    auto *O = new Octagon;
                    cout << "Enter vertices of this figure" << endl;
                    cin >> *O;
                    figures.push_back(O);
                } else if (figureType == 3) {
                    auto *T = new Triangle;
                    cout << "Enter vertices of this figure" << endl;
                    cin >> *T;
                    figures.push_back(T);
                }
                cout  << "Figure succesfully added at index " << figures.size() - 1 << '\n';
                totalArea += figures.back()->CalculateFigureArea();
                break;
            }
            case 2: {
                cout << "Enter index of figure you want to delete: " << endl;
                cin >> index;
                if (index > figures.size()) {
                    cout << "Index is out of reach!\n";
                }
                else {
                    totalArea -= figures[index]->CalculateFigureArea();
                    cout << "Figure successfully removed\n";
                    delete figures[index];
                    figures.erase(figures.begin() + index);
                }
                break;
            }
            case 3: {
                cout << "Enter index of the figure: " << endl;
                cin >> index;
                if (index > figures.size()) {
                    cout << "Index is out of reach!\n";
                }
                else {
                    cout << "Figure's  geometric median: " << figures[index]->CalculateGeometricMedian() << '\n';
                }
                break;
            }
            case 4: {
                cout << "Enter index of the figure: " << endl;
                cin >> index;
                if (index > figures.size()) {
                    cout << "Index is out of reach!\n";
                }
                else {
                    cout << "Coordinates of " << "Figure's vertices:\t";
                    figures[index]->DisplayFigureCoordinates();
                }
                break;
            }
            case 5: {
                cout << "Enter index of the figure: " << endl;
                cin >> index;
                if (index > figures.size()) {
                    cout << "Index is out of reach!\n";
                }
                else {
                    cout << "Figure's area: " << figures[index]->CalculateFigureArea() << '\n';
                }
                break;
                
            }
            case 6: {
                cout << "Total area: " << totalArea << endl;
                break;
            }
            case 7: {
                input = false;
                break;
            }

        }
    }

    for(auto &f : figures) {
        delete f;
    } 
    return 0;
}