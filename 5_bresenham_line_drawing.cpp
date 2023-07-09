#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iostream>

int main() {
    int gd = DETECT, gm = 0;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2, x, y; // two coordinates (x1,y1) and (x2, y2)
    int dx, dy;
    int p; // decision parameter

    // Take user input
    puts("Enter starting and ending points");
    printf("(x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("(x2, y2): ");
    scanf("%d %d", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    // Calculate decision parameter
    p = 2*dy - dx;

    x = x1;
    y = y1;

    for(int i = 0; i <= dx; i++){
        putpixel(x, y, YELLOW); // Plot the current point

        if(p < 0){
            if(x1 < x2)
                x = x + 1; // Move x in positive direction
            else
                x = x - 1; // Move x in negative direction

            p = p + 2 * dy; // Update decision parameter
        }
        else{
            if(x1 < x2)
                x = x + 1; // Move x in positive direction
            else
                x = x - 1; // Move x in negative direction

            if(y1 < y2)
                y = y + 1; // Move y in positive direction
            else
                y = y - 1; // Move y in negative direction

            p = p + 2 * dy - 2 * dx; // Update decision parameter
        }
    }

    getch();
    closegraph();
    return 0;
}

/*
Sample input:
100 100
300 300
*/

