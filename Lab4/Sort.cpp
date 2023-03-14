#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stdarg.h>

int Sort::GetElementFromIndex(int index)
{
    return list[index];
}

void Sort::Print()
{
    for (int i = 0; i < size; i++)
        printf("%d ", GetElementFromIndex(i));
    printf("\n");
}

int Sort::GetElementCount()
{
    return size;
}

void Sort::_Reverse()
{
    for (int i = 0, j = size - 1; i < j; i++, j--)
        std::swap(list[i], list[j]);
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < size - 1; i++)
        for(int j = i + 1; j < size; j++)
            if (list[i] > list[j])
                std::swap(list[i], list[j]);

    if (ascendent == false) _Reverse();
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < size; i++) {
        int key = list[i], j = i;
        while (j > 0 && list[j - 1] > key)
            list[j] = list[j - 1], --j;
        list[j] = key;
    }

    if (ascendent == false) _Reverse();
}

void Sort::_QuickSort(int left, int right)
{
    if (left < right) {
        int i = left;

        for (int j = left; j < right; j++)
            if (list[j] < list[right])
                std::swap(list[i++],list[j]);

        std::swap(list[i], list[right]);

        _QuickSort(left, i - 1);
        _QuickSort(i + 1, right);
    }
}

void Sort::QuickSort(bool ascendent)
{
    _QuickSort(0, size - 1);

    if (ascendent == false) _Reverse();
}

Sort::Sort(int _size, int min_val, int max_val)
{
    list = new int[size = _size];

    for (int i = 0; i < size; i++)
        list[i] = min_val + rand() % (max_val - min_val + 1);
}

Sort::Sort(int vect[], int _size)
{
    list = new int[size = _size];

    for (int i = 0; i < size; i++)
        list[i] = vect[i];
}

Sort::Sort(int _size, ...)
{
    list = new int[size = _size];

    va_list ptr;
    va_start(ptr, _size);

    for (int i = 0; i < size; i++)
        list[i] = va_arg(ptr, int);

    va_end(ptr);
}

Sort::Sort(const char *str)
{
    size = 1;
    for (int i = 0; str[i]; i++)
        if (str[i] == ',') ++size;
    list = new int[size];

    int elem = 0, j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ',')
            elem = elem * 10 + (str[i] - '0');
        else
            list[j++] = elem, elem = 0;
    }

    list[j] = elem;
}
