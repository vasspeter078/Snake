#ifndef LISTELEMENT_HPP_INCLUDED
#define LISTELEMENT_HPP_INCLUDED

#include <cstddef>

#include "point.hpp"

template <typename T>
class ListElement {
    T data;
    ListElement<T> *next;
public:
    ListElement() {
        next = NULL;
    }
    ListElement *getNext() const {
        return next;
    }
    void setNext(ListElement *le) {
        next = le;
    }
    T getData() const {
        return data;
    }
    void setData(T data) {
        this->data = data;
    }
    bool operator==(ListElement& le) const {
        if (data == le.getData()) {
            return true;
        }
        return false;
    }
};

#endif // LISTELEMENT_HPP_INCLUDED
