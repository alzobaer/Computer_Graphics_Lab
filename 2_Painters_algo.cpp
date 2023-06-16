#include<graphics.h>
#include<stdio.h>
#include<conio.h>

int main()
{
    int gd = DETECT;
    int gm = 0;
    initgraph(&gd,&gm,"");

    //code for triangle
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,BLACK);
    line(40,150,160,160);//Below line
    line(40,150,100,40);// left line
    line(100,40,160,160);//right line
    setfillstyle(1, GREEN);
    floodfill(80,148,WHITE);
    //circle draw

    setcolor(CYAN);
    circle(170,170,80);
    setfillstyle(SOLID_FILL,BLACK);
    setfillstyle(1,RED);
    floodfill(171,171,CYAN);

    // for rectangle
    setcolor(WHITE);
    rectangle(170,170,290,290);
    setfillstyle(SOLID_FILL,BLACK);
    setfillstyle(1, BLUE);
    floodfill(289,289,WHITE);

    getch();
    return 0;
}
