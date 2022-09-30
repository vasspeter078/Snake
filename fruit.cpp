#include "fruit.hpp"

void Fruit::newPositionGenerate(int fieldSize) {
        x = rand() % fieldSize + 1;
        y = rand() % fieldSize + 1;
    }
    Point Fruit::getP() const {
        return Point(x, y);
    }
