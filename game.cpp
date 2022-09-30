#include "game.hpp"

void Game::menu() {
    std::cout<<"SNAKE GAME"<<std::endl<<std::endl;
    std::cout<<"Move with w, a, s, d buttons"<<std::endl<<std::endl;
    std::cout<<"Press any button to start"<<std::endl;
    getch();
    system("cls");
}
void Game::start() {
    srand(time(NULL));
    bool gameOver = false;
    score = 0;
    int c;
    fr.newPositionGenerate(fi.getFSize());
    while (!gameOver) {
        if (kbhit()) {
            c = getch();
            if (c == 'w') {
                if (s.getDirection() != down) {
                    s.changeDirection(up);
                }
            } else {
                if (c == 'd') {
                    if (s.getDirection() != left) {
                        s.changeDirection(right);
                    }
                } else {
                    if (c == 's') {
                        if (s.getDirection() != up) {
                            s.changeDirection(down);
                        }
                    } else {
                        if (c == 'a') {
                            if (s.getDirection() != right) {
                                s.changeDirection(left);
                            }
                        }
                    }
                }
            }
        }
        s.moveSnake(fi.getFSize());
        if (s.bumps()) {
            gameOver = true;
        } else {
            if (s.ateFruit(fr)) {
                s.increaseSize();
                fr.newPositionGenerate(fi.getFSize());
                ++score;
            }
        }
        draw();
        Sleep(50);
        system("cls");
    }
}
void Game::draw() {
    for (int i = 0; i < fi.getFSize() + 2; ++i) {
        for (int j = 0; j < fi.getFSize() + 2; ++j) {
            Point p(j, i);
            if (s.contains(p)) {
                std::cout<<"o";
            } else {
                if (fr.getP().getX() == j && fr.getP().getY() == i) {
                    std::cout<<"#";
                } else {
                    std::cout<<fi.getField()[i][j];
                }
            }
        }
        std::cout<<std::endl;
    }
}
void Game::gameOver() {
    std::cout<<"GAME OVER"<<std::endl;
    std::cout<<"Your score is "<<score<<std::endl;
}
