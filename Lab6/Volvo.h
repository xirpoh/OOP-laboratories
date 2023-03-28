#pragma once
#include "Car.h"

class Volvo : public Car
{
public:
    Volvo();

    float test(int circ_len, Weather weather, bool& fin);
    char* get_name();
};
