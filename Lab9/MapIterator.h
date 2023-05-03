#pragma once
#include "Node.h"
#include <iostream>

template <class K, class V>
struct KV
{
    K key;
    V value;
    int idx;
};

template <class K, class V>
class MapIterator
{
public:
    Node<K, V>** elems;
    int idx = 0, cap, end;

    MapIterator(Node<K, V>** elems, int cap, int end) : elems(elems), cap(cap), end(end) {};

    MapIterator& operator++() {
        idx++;
        return *this;
    }

    KV<K, V> operator*() {
        KV<K, V> strct = {
            elems[idx]->key,
            elems[idx]->value,
            idx
        };

        return strct;
    }

    bool operator!=(const MapIterator it) {
        return idx < end;
    }
};
