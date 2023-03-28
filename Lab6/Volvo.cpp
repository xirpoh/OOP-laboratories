#include "Volvo.h"

Volvo::Volvo()
{
    fuel_capacity = 50;
    fuel_consumption = 9.3;

    average_speed[Rain] = 75;
    average_speed[Sunny] = 94;
    average_speed[Snow] = 58;

    name = (char*)"Volvo";
}

float Volvo::test(int circ_len, Weather weather, bool& fin)
{
    float mx_dist = fuel_capacity / fuel_consumption * 100;
    fin = (mx_dist >= circ_len);

    return (fin ? circ_len : mx_dist) / average_speed[weather];
}

char* Volvo::get_name()
{
    return name;
}
