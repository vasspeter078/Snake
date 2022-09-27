#include "fruit.hpp"

void Fruit::newPositionGenerate(int fieldSize) {
        p.setX(rand() % fieldSize + 1);
        p.setY(rand() % fieldSize + 1);
    }
    Point Fruit::getP() const {
        return p;
    }
