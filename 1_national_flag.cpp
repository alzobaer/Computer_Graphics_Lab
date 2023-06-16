#include<graphics.h>
#include<stdio.h>
int main()
{
	int driver, mode;
	driver = DETECT;
	mode = 0;

	initgraph(&driver, &mode, "");

	// for bamboo
	setcolor(WHITE);
	rectangle(140,35,150,450);
	setfillstyle(1, BLUE);
	floodfill(145,40,WHITE);

	// for rectangle
	setcolor(WHITE);
	rectangle(150,40,450,220);
	setfillstyle(1,GREEN);
	floodfill(160,50,WHITE);

	//for circle
	setcolor(WHITE);
	circle(300,130,75);
	setfillstyle(1, RED);
	floodfill(300,130, WHITE);


	getch();
	closegraph();

	return 0;
}
