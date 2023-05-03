#pragma once
#include "Node.h"

template <class K, class V>
class List
{
public:
    int size;
    Node<K, V> *first, *last;

    List() {
        size = 0;
        first = nullptr;
        last = nullptr;
    }

    ~List() {
        delete first;
    }

    void add(Node<K, V>* n) {
        size++;
        if (first == nullptr) {
            first = n;
            last = n;
            return;
        }

        last->next = n;
        last = last->next;
    }
};

