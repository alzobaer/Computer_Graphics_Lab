//#include <iostream>
#include<bits/stdc++.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

#define round(a) ((int)(a+0.5))

#define left_edge 1
#define right_edge 2
#define bottom_edge 4
#define top_edge 8

#define inside(a) (!a)
#define reject(a,b) (a&b)
#define accept(a,b) (!(a|b))

struct point{
    int x;
    int y;
};

int encode(point pt,point winMin,point winMax)
{
    int code = 0;
    if(pt.x < winMin.x) code |= left_edge;
    if(pt.x > winMax.x) code |= right_edge;
    if(pt.y < winMin.y) code |= bottom_edge;
    if(pt.y > winMax.y) code |= top_edge;

    return code;
}


void cohenSutherland(point winMin,point winMax,point point1,point point2)
{
    int code1,code2;
    bool done = FALSE, draw = FALSE;
    float m;
    while(!done)
    {
        code1 = encode(point1,winMin,winMax);
        code2 = encode(point2,winMin,winMax);

        if(accept(code1,code2))
        {
            done = TRUE;
            draw = TRUE;
            break;
        }
        else if(reject(code1,code2))
        {
            done = TRUE;
        }
        else
        {
            // Ensure that point1 is outside of window
            if(inside(code1))
            {
                swap(point1,point2);
                swap(code1,code2);
            }
            // calculate slope m with point1 and point2
            if((point2.x-point1.x))
            {
                m = (point2.y-point1.y)/(point2.x-point1.x);
            }
            if(code1 & left_edge)
            {
                point1.y += (winMin.x-point1.x)*m;
                point1.x = winMin.x;
            }
            else if(code1 & right_edge)
            {
                point1.y += (winMax.x - point1.x)*m;
                point1.x = winMax.x;
            }
            else if(code1 & bottom_edge)
            {
                // we will update point1.x only for lines those are non-vertical only.
                // because for vertical line value of m is undefined. And we also cannot use
                // prev value of m because that will lead us to wrong output
                if(point1.x != point2.x)
                    point1.x += (winMin.y - point1.y)/m;
                point1.y = winMin.y;
            }
            else if(code1 & top_edge)
            {
                // we will update point1.x only for lines those are non-vertical only.
                // because for vertical line value of m is undefined. And we also cannot use
                // prev value of m because that will lead us to wrong output
                if(point1.x != point2.x)
                    point1.x += (winMax.y - point1.y)/m;
                point1.y = winMax.y;
            }
        }
    }
    if(draw)
        line(ceil(point1.x),ceil(point1.y),ceil(point2.x),ceil(point2.y));
}

void showWindow(int xmin,int ymin,int xmax,int ymax)
{
    rectangle(xmin,ymin,xmax,ymax);

    char xy[50];
    sprintf(xy,"(%d,%d)",xmin,ymin);
    outtextxy(xmin-20,ymin-20,xy);

    sprintf(xy,"(%d,%d)",xmax,ymin);
    outtextxy(xmax-20,ymin-20,xy);

    sprintf(xy,"(%d,%d)",xmin,ymax);
    outtextxy(xmin-20,ymax+20,xy);

    sprintf(xy,"(%d,%d)",xmax,ymax);
    outtextxy(xmax-20,ymax+20,xy);

}

int main()
{
//    cout << "Hello world!" << endl;
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"");

    int xmin = 100,ymin = 100,xmax = 400,ymax = 400;

    showWindow(xmin,ymin,xmax,ymax);
    int numOfLine;
    printf("Enter number of line: ");
    scanf("%d",&numOfLine);
    int pointNumber = 1;
    setcolor(YELLOW);
    while(numOfLine--)
    {
        printf("Enter point 1 for line %d: ",pointNumber);
        point point1,point2;
        scanf("%d %d",&point1.x,&point1.y);
        printf("Enter point 2 for line %d: ",pointNumber);
        scanf("%d %d",&point2.x,&point2.y);
        point winMin,winMax;
        winMin.x = xmin, winMin.y = ymin;
        winMax.x = xmax, winMax.y = ymax;
        cohenSutherland(winMin,winMax,point1,point2);
        pointNumber++;
    }


    getch();
    //delay(500000);
    closegraph();
    return 0;
}
