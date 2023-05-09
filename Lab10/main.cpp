#include <iostream>
#include "Array.h"

int main()
{
    Array<int> v(10);
    v += 5;
    v += 1;
    v += 2;
    v += 7;
    v.Delete(1);

    //std::cout << v[-1];
    //v.Insert(5, 8);
    //v.Delete(-1);
    std::cout << v[0] << '\n';
    
    ArrayIterator<int> it = v.GetBeginIterator();
    while (it != v.GetEndIterator()) {
        std::cout << *(it.GetElement()) << " ";
        ++it;
    }

    return 0;
}
