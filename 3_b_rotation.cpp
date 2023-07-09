#include <graphics.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int v; // number of vertices
double angle; // rotation angle

vector <int> x, y;

void drawpolygon(){
	// Draw the polygon based on the vertices
	setcolor(MAGENTA);
	for(int i = 0; i < v; i++){
		line(x[i], y[i], x[(i+1)%v], y[(i+1)%v]);
	}
}

void rotation(){
	// Perform rotation on the polygon by applying rotation matrix
	for(int i = 0; i < v; i++){
		// Apply rotation matrix to each vertex
		double rotatedX = (x[i]*cos(angle) - y[i]*sin(angle));
		double rotatedY = (x[i]*sin(angle) + y[i]*cos(angle));
		double nextRotatedX = (x[(i+1)%v]*cos(angle) - y[(i+1)%v]*sin(angle));
		double nextRotatedY = (x[(i+1)%v]*sin(angle) + y[(i+1)%v]*cos(angle));

		// Draw line segment between rotated vertices
		line(rotatedX, rotatedY, nextRotatedX, nextRotatedY);
	}
}

int main(){
	int gd = DETECT;
    int gm = 0;
    initgraph(&gd,&gm,"");

	int a, b;
	cout << "Enter Number of vertices: ";
	cin >> v;
        cout << "Enter vertices in clockwise direction: \n";
	for(int i = 0; i < v; i++){
		cout << "(x" << i << ", y" << i << ") coordinate: ";
 		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}

	cout << "Enter rotation angle in degrees: \n";
	cout << "Theta: ";
	cin >> angle;

	// Convert the angle from degrees to radians
	angle = (angle*3.1416)/180;

	setcolor(WHITE);
	drawpolygon();

	setcolor(YELLOW);
	rotation();

	getch();
	closegraph();
	return 0;
}


/*
	Sample input:
		4
		200 100
		400 100
		400 300
		200 300
		30
	*/

