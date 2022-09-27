#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "listelement.hpp"

template <typename T>
class List {
    ListElement<T> *first;
public:
    List() :first(NULL) {}
    void addEmptyElement() {
        ListElement<T> *le = new ListElement<T>();
        le->setNext(first);
        first = le;
    }
    void addListElement(ListElement<T> &le) {
        le.setNext(first);
        first = &le;
    }
    void shiftElements(T data) {
        ListElement<T> *iter = first;
        while (iter->getNext() != NULL) {
            iter->setData(iter->getNext()->getData());
            iter = iter->getNext();
        }
        iter->setData(data);
    }
    bool identicalElements() {
        for (ListElement<T> *iter1 = first; iter1 != NULL; iter1 = iter1->getNext()) {
            for (ListElement<T> *iter2 = iter1->getNext(); iter2 != NULL; iter2 = iter2->getNext()) {
                if (*iter1 == *iter2) {
                    return true;
                }
            }
        }
        return false;
    }
    bool contains(T data) {
        for (ListElement<T> *iter = first; iter != NULL; iter = iter->getNext()) {
            if (iter->getData() == data) {
                return true;
            }
        }
        return false;
    }
    ListElement<T> *getFirst() const {
        return first;
    }
    ~List() {
        ListElement<T> *iter = first;
        while (iter != NULL) {
            ListElement<T> *temp = iter->getNext();
            delete iter;
            iter = temp;
        }
    }
};

#endif // LIST_HPP_INCLUDED
