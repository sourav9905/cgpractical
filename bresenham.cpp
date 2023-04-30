#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
    
    // int x0=100, y0=150, x1=250, y1=200;
    int x0, y0, x1, y1;
    cout << "Enter the First Line Coordinates: ";
    cin >> x0 >> y0;
    cout << "Enter the Second Line Coordinates: ";
    cin >> x1 >> y1;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = 2 * dy - dx;
    int incrE = 2 * dy;
    int incrNE = 2 * (dy - dx);
    int x = x0;
    int y = y0;
    putpixel(x, y, WHITE);

    while (x < x1)
    {
        if (d <= 0)
        {
            d += incrE;
            x++;
        }
        else
        {
            d += incrNE;
            x++;
            y++;
        }
        putpixel(x, y, WHITE);
    }
    delay(5000);
    closegraph();
    return 0;
}