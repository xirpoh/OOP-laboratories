#pragma once

template <class K, class V>
class Node 
{
public:
    K key;
    V value;
    unsigned long raw_key = 0;
    Node<K, V>* next = nullptr;

    Node(unsigned long raw_key) : raw_key(raw_key) {};
    Node(unsigned long raw_key, K key, V value) : raw_key(raw_key), key(key), value(value) {};
    ~Node() {
        if (next)
            delete next;
    }

    void operator=(V value) {
        this->value = value;
    }
};
