#include "snake.hpp"

Snake::Snake() {
    Point p1(1, 1);
    Point p2(2, 1);
    Point p3(3, 1);
    ListElement<Point> *le1 = new ListElement<Point>;
    ListElement<Point> *le2 = new ListElement<Point>;
    ListElement<Point> *le3 = new ListElement<Point>;
    le1->setData(p1);
    le2->setData(p2);
    le3->setData(p3);
    l.addListElement(*le3);
    l.addListElement(*le2);
    l.addListElement(*le1);
    dir = right;
}
void Snake::moveSnake(int fSize) {
    List<Point>::iterator i = l.last();
    Point p = (*i).getData();
    if (dir == up) {
        if (p.getY() == 1) {
            p.setY(fSize);
        } else {
            p.setY(p.getY() - 1);
        }
    } else {
        if (dir == right) {
            if (p.getX() == fSize) {
                p.setX(1);
            } else {
                p.setX(p.getX() + 1);
            }
        } else {
            if (dir == down) {
                if (p.getY() == fSize) {
                    p.setY(1);
                } else {
                    p.setY(p.getY() + 1);
                }
            } else {
                if (dir == left) {
                    if (p.getX() == 1) {
                        p.setX(fSize);
                    } else {
                        p.setX(p.getX() - 1);
                    }
                }
            }
        }
    }
    l.shiftElements(p);
}
Direction Snake::getDirection() const {
    return dir;
}
void Snake::changeDirection(Direction dir) {
    this->dir = dir;
}
void Snake::increaseSize() {
    l.addEmptyElement();
}
bool Snake::bumps() {
    if (l.identicalElements()) {
        return true;
    }
    return false;
}
bool Snake::contains(Point p) {
    if (l.contains(p)) {
        return true;
    }
    return false;
}
bool Snake::ateFruit(Fruit f) {
    if (l.contains(f.getP())) {
        return true;
    }
    return false;
}
