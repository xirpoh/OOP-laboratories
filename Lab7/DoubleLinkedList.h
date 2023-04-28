#pragma once
#include "Node.h"

template<typename T>
class DoubleLinkedList
{
private:
	Node<T>* start;
    int cnt;

public:
	DoubleLinkedList() {
		this->start = nullptr;
        cnt = 0;
	}

    ~DoubleLinkedList() {
        while (start != nullptr) {
            Node<T>* next = start->next;
            delete start;
            start = next;
        }
    }

    DoubleLinkedList& PushOnFront(T elem) {
        Node<T>* new_node = new Node<T>(elem);

        if (start == nullptr)
            start = new_node;
        else {
            new_node->next = start;
            start->prec = new_node;
            start = new_node;
        }

        cnt++;
        return *this;
    }

    T PopFromFront() {
        if (cnt) {
            Node<T>* tmp = start;
            start = start->next;

            cnt--;
            T res = tmp->value;
            delete tmp;

            return res;
        }
    }

    DoubleLinkedList& PushOnBack(T elem) {
        Node<T>* new_node = new Node<T>(elem);

        if (start == nullptr)
            start = new_node;
        else {
            Node<T>* tmp = start;
            while (tmp->next != nullptr)
                tmp = tmp->next;
            tmp->next = new_node;
            new_node->prec = tmp;
        }

        cnt++;
        return *this;
    }

    T PopFromBack() {
        if (cnt) {
            Node<T>* tmp = start;
            while (tmp->next != nullptr)
                tmp = tmp->next;

            if (tmp->prec)
                tmp->prec->next = nullptr;
        
            cnt--;
            T res = tmp->value;
            delete tmp;

            return res;
        }
    }

    void PrintAll(void (*printFunc)(const T&)) {
        Node<T>* tmp = start;
        while (tmp != nullptr) {
            printFunc(tmp->value);
            tmp = tmp->next;
        }
        std::cout << '\n';
    }

    int GetCount() {
        return cnt;
    }
};
