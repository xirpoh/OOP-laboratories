#include "RangeRover.h"

RangeRover::RangeRover()
{
    fuel_capacity = 52;
    fuel_consumption = 8.64;

    average_speed[Rain] = 127;
    average_speed[Sunny] = 137;
    average_speed[Snow] = 110;

    name = (char*)"RangeRover"; 
}

float RangeRover::test(int circ_len, Weather weather, bool& fin)
{
    float mx_dist = fuel_capacity / fuel_consumption * 100;
    fin = (mx_dist >= circ_len);

    return (fin ? circ_len : mx_dist) / average_speed[weather];
}

char* RangeRover::get_name()
{
    return name;
}
