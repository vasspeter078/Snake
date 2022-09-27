#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED

#include "direction.hpp"
#include "list.hpp"
#include "fruit.hpp"
#include "point.hpp"


class Snake {
    List<Point> l;
    Direction dir;
public:
    Snake();
    void moveSnake(int fSize);
    Direction getDirection() const;
    void changeDirection(Direction dir);
    void increaseSize();
    bool bumps();
    bool contains(Point p);
    bool ateFruit(Fruit f);
};

#endif // SNAKE_HPP_INCLUDED
