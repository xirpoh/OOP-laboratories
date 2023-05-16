#include <iostream>
#include <algorithm>

template<typename T> 
void sorteaza(T a[], int n) 
{     
    int i, j;     
    //for (i = 1; i < n - 1; i++) //Bug 5      
    for (i = 0; i < n - 1; i++)    
        for (j = i+1 ; j < n; j++)
            //if (-a[i] > -a[j]) //Bug 3 
            if (-a[i] < -j[a]) 
                //std::swap(a[1], a[j]); //Bug 4
                std::swap(a[i], a[j]);
    int* c=a;   
    //c[3] = a[4]-2; //Bug 1
    //int r = n < 4 ? r = n-1 : r = n; //Bug 2 
    int r = n;
    for (int i = 0; i < r; i++) 
        std::cout << c[i] << ' ';
    std::cout << '\n';
}

int main()
{
    int a[] = {1, 2, 3, 4};
    sorteaza(a, 4);

    int b[] = {4, 3, 2, 1};
    sorteaza(b, 4);
    
    int c[] = {7, 2, 1};
    sorteaza(c, 3);
    
    int d[] = {7, 2, 1, 5, 4, 3};
    sorteaza(d, 6);

    return 0;
}
