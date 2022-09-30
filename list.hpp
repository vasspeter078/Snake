#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "listelement.hpp"

template <typename T>
class List {
    ListElement<T> *first;
public:
    class iterator;
    iterator begin() {
        return iterator(*this);
    }
    iterator end() {
        return iterator();
    }
    iterator last() {
        ListElement<T> *iter = first;
        int idx = 0;
        while (iter->getNext() != NULL) {
            iter = iter->getNext();
            ++idx;
        }
        return iterator(*this, idx);
    }
    List() :first(NULL) {}
    void addEmptyElement() {
        ListElement<T> *le = new ListElement<T>();
        le->setNext(first);
        first = le;
    }
    void addListElement(ListElement<T>& le) {
        le.setNext(first);
        first = &le;
    }
    void shiftElements(T data) {
        iterator i = begin();
        for (i = begin(); i != last(); ++i) {
            (*i).setData((*i).getNext()->getData());
        }
        (*i).setData(data);
    }
    bool identicalElements() {
        for (iterator i1 = begin(); i1 != last(); ++i1) {
                iterator i2 = i1;
                ++i2;
            for (; i2 != end(); ++i2) {
                if (*i1 == *i2) {
                    return true;
                }
            }
        }
        return false;
    }
    bool contains(T data) {
        for (iterator i = begin(); i != end(); ++i) {
            if ((*i).getData() == data) {
                return true;
            }
        }
        return false;
    }
    ListElement<T> *getFirst() const {
        return first;
    }
    ~List() {
        iterator i = begin();
        while (i != end()) {
            iterator temp = i;
            ++temp;
            delete &(*i);
            i = temp;
        }
    }
    class iterator {
        ListElement<T> *p;
    public:
        iterator() :p(NULL) {}
        iterator(List &l, int idx = 0) {
            ListElement<T> *iter = l.first;
            for (int i = 0; i < idx; ++i) {
                iter = iter->getNext();
            }
            p = iter;
        }
        iterator& operator++() {
            p = p->getNext();
            return *this;
        }
        bool operator!=(const iterator& i) {
            return p != i.p;
        }
        ListElement<T>& operator*() {
            return *p;
        }
    };
};

#endif // LIST_HPP_INCLUDED
