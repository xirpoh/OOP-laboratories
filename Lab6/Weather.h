#pragma once

enum Weather
{
    Rain, 
    Sunny,
    Snow
};

#define WEATHER_COND_CNT 3
const char weather_str[WEATHER_COND_CNT][10] = {
    "Rain",
    "Sunny",
    "Snow"
};
