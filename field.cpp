#include "field.hpp"

Field::Field(int fSize) :fSize(fSize) {
    field = new char*[fSize + 2];
    for (int i = 0; i < fSize + 2; ++i) {
        field[i] = new char[fSize + 2];
    }
    for (int i = 0; i < fSize + 2; ++i){
        for (int j = 0; j < fSize + 2; ++j){
            if (i == 0 || i == (fSize + 2 - 1)) {
                field[i][j] = '-';
            } else {
                if (j == 0 || j == (fSize + 2 - 1)) {
                    field[i][j] = '|';
                } else {
                    field[i][j] = ' ';
                }
            }
        }
    }
}
int Field::getFSize() const {
    return fSize;
}
char **Field::getField() const {
    return field;
}
Field::~Field() {
    for (int i = 0; i < fSize + 2; ++i) {
        delete[] field[i];
    }
    delete[] field;
}
