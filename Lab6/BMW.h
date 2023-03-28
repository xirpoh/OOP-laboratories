#pragma once
#include "Car.h"

class BMW : public Car
{
public:
    BMW();

    float test(int circ_len, Weather weather, bool& fin);
    char* get_name();
};
