#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>

int main(){
	int x[4], y[4], i;
	double put_x, put_y, t;
	int driver = DETECT, mode = 0;
	initgraph(&driver,&mode,"");

	printf("** Bezier Curve for 4 control points **");
	printf("\nPlease enter x and y coordinates \n");

	// Input the coordinates of the control points
	for(i = 0; i < 4; i++){
		printf("(x%d, y%d): ", i, i);
		scanf("%d%d",&x[i],&y[i]);
		putpixel(x[i],y[i],RED);                // Mark the control points on the graph

		// Labeling the control points
		char xy[50];
		sprintf(xy,"(x%d, y%d)", i, i);
		outtextxy(x[i] - 20, y[i] - 20,xy);
	}

	// Calculate and draw the bezier curve
	for(t = 0.0; t <= 1.0; t = t + 0.001){             // t always lies between 0 and 1
		// Curve formula for 4 control points: sk(t) = (1−t)^3 * x[0] + 3*t*(1−t)^2 * x[1] + 3*t^2 (1−t) * x[2] + t^3 * x[3]
		put_x = pow(1-t, 3) * x[0] + 3 * t * pow(1-t, 2) * x[1] + 3 * t * t * (1-t)* x[2] + pow(t,3)* x[3];
		put_y =  pow(1-t,3)* y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
		putpixel(put_x, put_y, GREEN);            // Plot the points on the graph
	}

	getch();
	closegraph();
	return 0;
}

/*
Sample input:
100 100
300 100
100 300
300 300
*/

