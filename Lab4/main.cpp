#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(0));
    Sort L1(10, 1, 100);
    L1.InsertSort();
    L1.Print();
    printf("%d\n", L1.GetElementFromIndex(0));

    
    Sort L2 = {5, new int[5]{4, 2, 1, 5, 3}};
    L2.QuickSort();
    L2.Print();


    int v[] = {4, 2, 1, 5, 3};
    Sort L3(v, 5);
    L3.BubbleSort();
    L3.Print();


    Sort L4(5, 4, 2, 1, 5, 3);
    L4.InsertSort();
    L4.Print();


    Sort L5("10,40,100,5,70");
    L5.QuickSort(true);
    printf("List size: %d\n", L5.GetElementCount());
    L5.Print();

    return 0;
}
