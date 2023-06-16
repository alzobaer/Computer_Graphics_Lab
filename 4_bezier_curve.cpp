#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>
int main()
{
	int x[4], y[4], i;
	double put_x, put_y, t;
	int gr=DETECT,gm;
	initgraph(&gr,&gm,"");

	printf("\n****** Bezier Curve for 4 control point ***********");
	printf("\n Please enter x and y coordinates ");
	for(i = 0; i < 4; i ++)
	{
		scanf("%d%d",&x[i],&y[i]);
		putpixel(x[i],y[i],RED);                // 4 Control Points
	}

	for(t = 0.0; t <= 1.0; t = t + 0.00001)             // t always lies between 0 and 1
	{
		// courvr formulla for 3 control points: sk(t) = (1-t)^2 * x[0] + 2*t*(1-t) * x[1] + t^2 * x[2]
		// curve formula for 4 control points: sk(t) = (1−t)^3 * x[0] + 3*t*(1−t)^2 * x[1] + 3*t^2 (1−t) * x[2] + t^3 * x[3]

		put_x = pow(1-t, 3) * x[0] + 3 * t * pow(1-t, 2) * x[1] + 3 * t * t * (1-t)* x[2] + pow(t,3)* x[3]; // Formula to draw curve
		put_y =  pow(1-t,3)* y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
		putpixel(put_x, put_y, GREEN);            // putting pixel
	}

	getch();
	closegraph();
	return 0;
}

/*
100 200
200 200
100 300
200 300
*/
