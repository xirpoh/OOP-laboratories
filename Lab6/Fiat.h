#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
    Fiat();

    float test(int circ_len, Weather weather, bool& fin);
    char* get_name();
};
