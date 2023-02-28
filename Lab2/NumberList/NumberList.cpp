#include "NumberList.h"
#include <stdio.h>

void NumberList::Init(int s)
{
    count = 0;
    capacity = s;
    numbers = new int[capacity];
}

bool NumberList::Add(int x)
{
    if (count >= capacity) {
        int *tmp = new int[++capacity];
        for (int i = 0; i < count; i++)
            tmp[i] = numbers[i];

        delete[] numbers;
        numbers = tmp;
    }

    numbers[count++] = x;
    return true;
}

void NumberList::Sort()
{
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (numbers[i] > numbers[j]) {
                int tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
}

void NumberList::Print()
{
    for (int i = 0; i < count; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}
