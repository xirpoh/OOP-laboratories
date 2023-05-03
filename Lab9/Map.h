#pragma once
#include "List.h"
#include "MapIterator.h"
#include <functional>

template <class K, class V>
class Map
{
    int size, capacity;
    
    List<K, V>* container;
    Node<K, V>** elems;
    std::hash<K> getHash;

    void Resize()
    {
        List<K, V>* tmp = container;
        container = new List<K, V>[capacity *= 2];
        
        for (int i = 0; i < capacity / 2; i++) {
            Node<K, V>* it = tmp[i].first;

            while (it) {
                Node<K, V>* cp = it;
                container[it->raw_key % capacity].add(cp);
                it = it->next;
            }
        }

        delete[] tmp;
    }

public:
    Map()
    {
        size = 0;
        capacity = 10;

        container = new List<K, V>[capacity];
        elems = new Node<K, V>*[capacity];
    }

    void Set(K key, V value)
    {
        if (size + 1 > capacity)
            Resize();

        unsigned long rk = getHash(key);
        int key_idx = rk % capacity;

        Node<K, V>* nn = new Node<K, V>(rk, value, key);
        container[key_idx].add(nn);
        size++;
    }

    bool Get(const K& key, V& value)
    {
        unsigned long rk = getHash(key);
        int key_idx = rk % capacity;
        
        Node<K, V>* temp = container[key_idx].first;
        
        while (temp != nullptr) {
            if (temp->raw_key == rk) {
                value = temp->value;
                return 1;
            }
            temp = temp->next;
        }
        
        return 0;
    }

    int Count()
    {
        return size;
    }

    void Clear()
    {
        delete[] container;
        size = 0;
        capacity = 1;
        container = new List<K, V>[capacity];
    }

    void Delete(const K& key)
    {
        unsigned long rk = getHash(key);
        int key_idx = rk % capacity;

        Node<K, V>* tmp = container[key_idx].first;

        if (tmp->raw_key == rk) {
            Node<K, V>* cp = tmp;
            tmp = tmp->next;
            cp->next = nullptr;
            delete cp;
            size--;
            return;
        }

        while (tmp) {
            if (tmp->next && tmp->next->raw_key == rk) {
                tmp->next = tmp->next->next;
                tmp->next->next = nullptr;
                delete tmp->next;
                size--;
                return;
            }
            tmp = tmp->next;
        }
    }

    bool Includes(const Map<K, V>& map) 
    {
        int cnt = 0;
        for (auto [i, i_key, i_value] : map)
            for (auto [j, j_key, j_value] : *this)
                if (i_key == j_key && i_value == j_value)
                    cnt++;

        return cnt == map.Count();
    }

    Node<K, V>& operator[] (K key)
    {
        unsigned long rk = getHash(key);
        int key_idx = rk % capacity;

        Node<K, V>* tmp = container[key_idx].first;
        while (tmp) {
            if (tmp->raw_key == rk)
                return *tmp;
            tmp = tmp->next;
        }

        if (size + 1 > capacity)
            Resize();

        Node<K, V>* n = new Node<K, V>(rk);
        n->key = key;
        container[key_idx].add(n);
        size++;

        return *n;
    }


    MapIterator<K, V> begin()
    {
        elems = new Node<K, V>*[size];

        int l = 0;
        for (int i = 0; i < capacity; i++) {
            Node<K, V>* tmp = container[i].first;
            while (tmp != nullptr) {
                elems[l++] = tmp;
                tmp = tmp->next;
            }
        }

        MapIterator<K, V> it(elems, capacity, size);
        return it;
    }

    MapIterator<K, V> end()
    {
        MapIterator it(elems, capacity, size);
        return it;
    }
};
