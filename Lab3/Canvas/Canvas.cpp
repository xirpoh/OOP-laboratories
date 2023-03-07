#include "Canvas.h"
#include <stdio.h>
#include <algorithm>

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && y >= 0 && x < width && y < height)
        table[y][x] = ch;
}

void Canvas::Clear()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            SetPoint(j, i, ' ');
}

Canvas::Canvas(int w, int h)
{
    width = w;
    height = h;

    table = new char*[height];
    for (int i = 0; i < height; i++) 
        table[i] = new char[width];

    Clear();
}

void Canvas::Print()
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            printf("%c", table[i][j]);
        printf("\n");
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int xk = 0, yk = ray, p = 1 - ray;

    while (xk <= yk) {
        SetPoint(x + xk, y - yk, ch);
        SetPoint(x + xk, y + yk, ch);
        SetPoint(x - xk, y - yk, ch);
        SetPoint(x - xk, y + yk, ch);

        SetPoint(x + yk, y - xk, ch);
        SetPoint(x + yk, y + xk, ch);
        SetPoint(x - yk, y - xk, ch);
        SetPoint(x - yk, y + xk, ch);

        if (p < 0)
            p += 3 + 2 * xk;
        else 
            p += 5 + 2 * (xk - yk), --yk;
        ++xk;
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = y - ray; i <= y + ray; i++)
        for (int j = x - ray; j <= x + ray; j++) {
            int dx = abs(j - x), dy = abs(i - y);
            if (dx * dx + dy * dy <= ray * ray)
                SetPoint(j, i, ch);
        }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left; i <= right; i++) {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }

    for (int i = top + 1; i <= bottom - 1; i++) {
        SetPoint(left, i, ch);
        SetPoint(right, i, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left; i <= right; i++)
        for (int j = top; j <= bottom; j++)
            SetPoint(i, j, ch);
}

void Canvas::DrawLineLow(int x1, int y1, int x2, int y2, char ch)
{
    int dx = x2 - x1, dy = y2 - y1, yi = 1;
    if (dy < 0)
        yi = -1, dy = -dy;
    int D = 2 * dy - dx;

    for (int x = x1, y = y1; x <= x2; x++) {
        SetPoint(x, y, ch);

        if (D > 0) {
            y += yi;
            D -= 2 * dx;
        }
        D += 2 * dy;
    }
}

void Canvas::DrawLineHigh(int x1, int y1, int x2, int y2, char ch)
{
    int dx = x2 - x1, dy = y2 - y1, xi = 1;
    if (dx < 0)
        xi = -1, dx = -dx;
    int D = 2 * dx - dy;
    
    for (int y = y1, x = x1; y <= y2; y++) {
        SetPoint(x, y, ch);

        if (D > 0) {
            x += xi;
            D -= 2 * dy;
        }
        D += 2 * dx;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    if (abs(x1 - x2) > abs(y1 - y2)) {
        if (x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        DrawLineLow(x1, y1, x2, y2, ch);
    }
    else { 
        if (y1 > y2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        DrawLineHigh(x1, y1, x2, y2, ch);
    }
}
