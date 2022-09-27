#ifndef FIELD_HPP_INCLUDED
#define FIELD_HPP_INCLUDED

class Field {
    int fSize;
    char **field;
public:
    Field(int fSize = 20);
    int getFSize() const;
    char **getField() const;
    ~Field();
};

#endif // FIELD_HPP_INCLUDED
