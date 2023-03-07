#include "Math.h"
#include <stdarg.h>
#include <string.h>
#include <algorithm>
#include <stdio.h>

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return a + b;
}

int Math::Add(double a, double b, double c)
{
    return a + b + c;
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return a * b;
}

int Math::Mul(double a, double b, double c)
{
    return a * b * c;
}

int Math::Add(int count, ...)
{
    va_list ptr;
    va_start(ptr, count);

    int res = 0;
    while (count--)
        res += va_arg(ptr, int);

    va_end(ptr);
    return res;
}

char * Math::Add(const char * a, const char * b)
{
    if (a == nullptr || b == nullptr)
        return nullptr;

    int sum = atoi(a) + atoi(b), len = 0;
    for (int c = sum; c; c /= 10, len++);

    char * c = new char[len + 1];
    sprintf(c, "%d", sum);

    return c;
}
