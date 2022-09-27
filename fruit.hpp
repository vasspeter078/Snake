#ifndef FRUIT_HPP_INCLUDED
#define FRUIT_HPP_INCLUDED

#include <stdlib.h>

#include "point.hpp"

class Fruit {
    Point p;
public:
    void newPositionGenerate(int fieldSize);
    Point getP() const;
};

#endif // FRUIT_HPP_INCLUDED
