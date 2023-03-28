#pragma once
#include "Weather.h"

class Car
{
protected:
    float fuel_capacity;                   
    float fuel_consumption;                
    float average_speed[WEATHER_COND_CNT]; 

    char* name;

public:
    virtual float test(int circ_len, Weather weather, bool& fin) = 0;
    virtual char* get_name() = 0;
};
