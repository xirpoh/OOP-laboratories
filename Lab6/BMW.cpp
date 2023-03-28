#include "BMW.h"

BMW::BMW()
{
    fuel_capacity = 61;
    fuel_consumption = 10.8;

    average_speed[Rain] = 125;
    average_speed[Sunny] = 149;
    average_speed[Snow] = 117;

    name = (char*)"BMW";
}

float BMW::test(int circ_len, Weather weather, bool& fin)
{
    float mx_dist = fuel_capacity / fuel_consumption * 100;
    fin = (mx_dist >= circ_len);

    return (fin ? circ_len : mx_dist) / average_speed[weather];
}

char* BMW::get_name()
{
    return name;
}
