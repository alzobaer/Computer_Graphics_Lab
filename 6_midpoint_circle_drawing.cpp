#include <graphics.h>
#include <iostream>
#include <math.h>

int xc, yc; // coordinate (xc, yc) is the center of the circle
int r; // radius of the circle

void printPixel(int x, int y){
	// right part of circle
	putpixel(x+xc, y+yc, YELLOW);
	putpixel(y+xc, x+yc, YELLOW);
	putpixel(y+xc, -x+yc, YELLOW);
	putpixel(x+xc, -y+yc, YELLOW);

	// left part of circle
	putpixel(-x+xc, y+yc, YELLOW);
	putpixel(-y+xc, x+yc, YELLOW);
	putpixel(-y+xc, -x+yc, YELLOW);
	putpixel(-x+xc, -y+yc, YELLOW);
}

int main(){
	int gd = DETECT, gm = 0;
	initgraph(&gd, &gm, "");

	int p; // decision parameter

	puts("Enter Center Coordinate of the cirle:");
	printf("(xc, yc): ");
	scanf("%d %d", &xc, &yc);
	printf("Radius: ");
	scanf("%d", &r);

	int x, y;
	p = 1 - r;  // calculate decision parameter
	x = 0, y = r;   // initialize first point


	while(x <= y){
		printPixel(x, y);

		if(p < 0){
			x = x + 1;
			p = p + 2*x + 1;
		}
		else{
			x = x + 1;
			y= y - 1;
			p = p + 2*x + 1 - 2*y;
		}
	}

	getch();
	return 0;
}
