#include "Fiat.h"

Fiat::Fiat()
{
    fuel_capacity = 52;
    fuel_consumption = 8.64;

    average_speed[Rain] = 137;
    average_speed[Sunny] = 157;
    average_speed[Snow] = 120;

    name = (char*)"Fiat"; 
}

float Fiat::test(int circ_len, Weather weather, bool& fin)
{
    float mx_dist = fuel_capacity / fuel_consumption * 100;
    fin = (mx_dist >= circ_len);

    return (fin ? circ_len : mx_dist) / average_speed[weather];
}

char* Fiat::get_name()
{
    return name;
}
