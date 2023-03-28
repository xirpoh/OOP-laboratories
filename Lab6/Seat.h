#pragma once
#include "Car.h"

class Seat : public Car
{
public:
    Seat();

    float test(int circ_len, Weather weather, bool& fin);
    char* get_name();
};
