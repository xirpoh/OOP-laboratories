#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
    RangeRover();

    float test(int circ_len, Weather weather, bool& fin);
    char* get_name();
};
