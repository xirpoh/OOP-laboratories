#pragma once
#include "Car.h"

#define CIRC_CAP 32

class Circuit
{
private:
    float lenght;
    
    Car* car_arr[CIRC_CAP];
    int car_cnt;

    Weather weather;
    float finish_time[CIRC_CAP];
    bool finish[CIRC_CAP];

public:
    Circuit();

    void SetLength(int lenght);
    void SetWeather(Weather weather);

    void AddCar(Car* car);
    void Race();

    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
