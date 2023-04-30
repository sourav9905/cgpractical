#include <iostream>
#include <graphics.h>
using namespace std;

void drawCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 1 - r;
    putpixel(xc + x, yc + y, WHITE);

    while (y > x)
    {
        if (d < 0)
        {
            x++;
            d += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            d += 2 * (x - y) + 1;
        }

        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
}

int main()
{
    int xc, yc, r;
    cout<<"Enter Radius of Circle: ";
    cin>> r;
    cout<<"Enter x-coordinate: ";
    cin>> xc;
    cout<<"Enter y-coordinate: ";
    cin>>yc;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawCircle(xc, yc, r);
    getch();
    return 0;
}