#include "Number.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <utility>

Number::Number(const char *value, int base)
{
    if (base < 2 || base > 16)
        return;

    this->base = base;
    sign = (value[0] == '-');
    this->value = new char[strlen(value) + 1 - sign];

    strncpy(this->value, value + sign, strlen(value) + !sign);
}

Number::~Number()
{
    delete[] value;
}

void Number::Print() const
{
    if (sign) printf("%c", '-');
    printf("%s\n", value);
}

int Number::GetDigitsCount() const
{
    return strlen(value);
}

int Number::GetBase() const
{
    return base;
}

int conv_dig2int(char d)
{
    return d >= 'A' ? 10 + d - 'A' : d - '0';
}

char conv_dig2chr(int d)
{
    return d > 9 ? 'A' + d - 10 : d + '0';
}

int Number::get_int() const
{
    int res = 0, pw = 1;
    for (int i = strlen(value) - 1; i >= 0; --i, pw *= base)
        res += pw * conv_dig2int(value[i]);

    return sign ? -res : res;
}

void Number::SwitchBase(int newBase)
{
    if (base == newBase || newBase < 2 || newBase > 16) return;

    char *newValue = new char[64];
    
    int i = 0;
    for (int n = abs(get_int()); n; n /= newBase)
        newValue[i++] = conv_dig2chr(n % newBase);
    newValue[i] = '\0';

    for (int j = 0; j < i / 2; j++)
        std::swap(newValue[j], newValue[i - j - 1]);

    delete[] value;
    value = new char[i + 1];
    memcpy(value, newValue, i + 1);
    delete[] newValue;
    base = newBase;
}

Number::Number(const Number &n) 
{
    memcpy(value, n.value, n.GetDigitsCount() + 1);
    base = n.base;
    sign = n.sign;
}

Number::Number(Number &&n)
{
    value = n.value;
    n.value = nullptr;

    base = n.base;
    sign = n.sign;
}

Number::Number(int n) 
{
    base = 10;
    sign = (n < 0);
    n = abs(n);
    int cnt = 0;
    for (int c = n; c; c /= 10, cnt++);

    value = new char[cnt + 1];
    sprintf(value, "%d", n);
}

char Number::operator[] (int idx)
{
    return value[idx];
}

Number operator+ (const Number &x, const Number &y)
{
    Number res(x.get_int() + y.get_int());
    res.SwitchBase(std::max(x.GetBase(), y.GetBase()));

    return res;
}

Number operator- (const Number &x, const Number &y)
{
    Number res(x.get_int() - y.get_int());
    res.SwitchBase(std::max(x.GetBase(), y.GetBase()));

    return res;
}

bool Number::operator> (const Number &n)
{
    return get_int() > n.get_int();
}

bool Number::operator< (const Number &n)
{
    return get_int() < n.get_int();
}

bool Number::operator== (const Number &n)
{
    return get_int() == n.get_int();
}

Number& Number::operator= (const Number &n) 
{
    if (&n == this) return *this;

    memcpy(value, n.value, n.GetDigitsCount() + 1);
    base = n.base;
    sign = n.sign;

    return *this;
}

Number& Number::operator= (Number &&n)
{
    if (&n == this) return *this;

    delete[] value;
    value = n.value;
    n.value = nullptr;
    base = n.base;
    sign = n.sign;

    return *this;
}

Number& Number::operator= (const int n)
{
    Number tmp(n);
    tmp.SwitchBase(base);
    return *this = std::move(tmp);
}

Number& Number::operator= (const char *s)
{
    Number tmp(s, base);
    return *this = std::move(tmp);
}

void Number::operator-- ()
{
    //value++;
    strcpy(value, value + 1);
}

void Number::operator-- (int)
{
    value[GetDigitsCount() - 1] = '\0';
}

Number& Number::operator+= (const Number &n)
{
    Number res(get_int() + n.get_int());
    res.SwitchBase(base);

    return *this = std::move(res);
}
