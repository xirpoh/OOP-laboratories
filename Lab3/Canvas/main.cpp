#include "Canvas.h"
#include <stdlib.h>

#define cWIDTH 29
#define cHEIGHT 29
#define BOX 178

int main()
{
    Canvas c(cWIDTH, cHEIGHT);
    /*c.FillRect(2, 2, cWIDTH - 3, cHEIGHT - 3, '.');
    c.DrawCircle(cWIDTH / 2, cHEIGHT / 2, 10, BOX);
    c.FillCircle(cWIDTH / 2, cHEIGHT / 2, 7, '%');
    c.DrawLine(0, 0, cWIDTH, cHEIGHT, '|');
    c.DrawRect(1, 1, cWIDTH - 2, cHEIGHT - 2, BOX);
    c.SetPoint(0, 0, '@');*/

    c.DrawLine(1, 1, 1, 5, '%');
    c.DrawLine(1, 1, 6, 1, '*');
    c.DrawCircle(10, 10, 5, '#');

    c.Print();

    return 0;
}
