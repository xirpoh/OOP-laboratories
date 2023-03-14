#pragma once

class Sort
{
    int size, *list;
    void _Reverse();
    void _QuickSort(int left, int right);

public:
    Sort(int _size, int min_val, int max_val);
    Sort(int _size, int *_list): size(_size), list(_list) {};
    Sort(int vect[], int _size);
    Sort(int _size, ...); 
    Sort(const char *str);
    ~Sort()
    {
        delete[] list;
    }

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementCount();
    int GetElementFromIndex(int index);
};

