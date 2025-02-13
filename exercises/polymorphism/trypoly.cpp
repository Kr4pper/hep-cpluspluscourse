#include "Polygons.hpp"
#include <iostream>

int main()
{
    // create a Pentagon, call its perimeter method
    Pentagon pentagon = Pentagon(1);
    pentagon.computePerimeter();

    // create a Hexagon, call its perimeter method
    Hexagon hexagon = Hexagon(1);
    hexagon.computePerimeter();

    // create a Hexagon, call the perimeter method through a reference to Polygon
    RegularPolygon hexagon2 = Hexagon(1);
    hexagon2.computePerimeter();

    // retry virtual method
}
