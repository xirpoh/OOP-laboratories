#include <stdio.h>
#include "Math.h"

int main()
{
    printf("%d\n",   Math::Add(2, 3));
    printf("%d\n",   Math::Add(2, 3, 4));
    printf("%d\n",   Math::Add(1.2, 0.5));
    printf("%d\n\n", Math::Add(1.2, 0.5, 0.6));

    printf("%d\n",   Math::Mul(2, 3));
    printf("%d\n",   Math::Mul(2, 3, 4));
    printf("%d\n",   Math::Mul(1.2, 0.5));
    printf("%d\n\n", Math::Mul(1.2, 0.5, 3.5));

    printf("%d\n", Math::Add(4, 1, 2, 3, 4));
    
    char * c = Math::Add("99", "5");
    printf("%s", c);
    delete[] c;

    return 0;
}
