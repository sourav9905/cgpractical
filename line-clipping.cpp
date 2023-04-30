//Ctrl+Shift+B to build the code and run executable for run

#include <iostream>
#include <graphics.h>

using namespace std;

const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
const int x_max = 400, y_max = 300, x_min = 100, y_min = 100;

int getCode(int x, int y)
{
    int code = 0;
    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;
    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2)
{
    int code1 = getCode(x1, y1);
    int code2 = getCode(x2, y2);
    bool accept = false;
    while (true)
    {
        if (code1 == 0 && code2 == 0)
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int x, y;
            int outcode = code1 ? code1 : code2;

            if (outcode & TOP)
            {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (outcode & BOTTOM)
            {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (outcode & RIGHT)
            {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else
            {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (outcode == code1)
            {
                x1 = x;
                y1 = y;
                code1 = getCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = getCode(x2, y2);
            }
        }
    }

    if (accept)
    {
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    rectangle(x_min, y_min, x_max, y_max);
    line(200, 50, 300, 400);
    delay(5000);
    clearviewport();
    rectangle(x_min, y_min, x_max, y_max);
    cohenSutherland(200, 50, 300, 400);
    getch();
    closegraph();
    return 0;
}
