#include "Seat.h"

Seat::Seat()
{
    fuel_capacity = 50;
    fuel_consumption = 4.9;

    average_speed[Rain] = 128;
    average_speed[Sunny] = 143;
    average_speed[Snow] = 113;

    name = (char*)"Seat";
}

float Seat::test(int circ_len, Weather weather, bool& fin)
{
    float mx_dist = fuel_capacity / fuel_consumption * 100;
    fin = (mx_dist >= circ_len);

    return (fin ? circ_len : mx_dist) / average_speed[weather];
}

char* Seat::get_name()
{
    return name;
}
