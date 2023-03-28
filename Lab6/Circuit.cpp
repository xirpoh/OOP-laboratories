#include "Circuit.h"
#include <stdio.h>
#include <algorithm>

Circuit::Circuit()
{
    lenght = 0;
    car_cnt = 0;
    weather = Sunny;
}

void Circuit::SetLength(int lenght)
{
    this->lenght = lenght;
}

void Circuit::SetWeather(Weather weather)
{
    this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
    if (car_cnt < CIRC_CAP)
        car_arr[car_cnt++] = car;
}

void Circuit::Race()
{
    for (int i = 0; i < car_cnt; i++) {
        bool fin;
        finish_time[i] = car_arr[i]->test(lenght, weather, fin);
        finish[i] = fin;
    }
}

void Circuit::ShowFinalRanks()
{
    for (int i = 0; i < car_cnt - 1; i++)
        for (int j = i + 1; j < car_cnt; j++)
            if (finish_time[i] > finish_time[j]) {
                std::swap(car_arr[i], car_arr[j]);
                std::swap(finish_time[i], finish_time[j]);
                std::swap(finish[i], finish[j]);
            }

    printf("circ_len: %.2fkm\n", lenght);
    printf("weather_cond: %s\n\n", weather_str[weather]);
    printf("--FinalRanks--\n");
    for (int i = 0, j = 1; i < car_cnt; i++) {
        if (finish[i])
            printf("%d. %s - %.2fh\n", j++, car_arr[i]->get_name(), finish_time[i]);
    }
    printf("\n");
}

void Circuit::ShowWhoDidNotFinish()
{
    printf("--DidNotFinish--\n");
    for (int i = 0, j = 1; i < car_cnt; i++) {
        if (!finish[i])
            printf("%d. %s - %.2fh\n", j++, car_arr[i]->get_name(), finish_time[i]);
    }
    printf("\n");
}
