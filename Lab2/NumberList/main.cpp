#include "NumberList.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    NumberList l;
    l.Init(1);

    srand(time(0));
    for (int i = 0; i < 20; i++) 
        l.Add(rand() % 100);

    l.Print();
    l.Sort();
    l.Print();

    return 0;
}
