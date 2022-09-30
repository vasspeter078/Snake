#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#include "snake.hpp"
#include "fruit.hpp"
#include "field.hpp"

class Game {
    Snake s;
    Field fi;
    Fruit fr;
    int score;
public:
    void menu();
    void start();
    void draw();
    void gameOver();
};

#endif // GAME_HPP_INCLUDED
