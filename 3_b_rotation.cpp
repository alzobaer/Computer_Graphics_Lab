#include <graphics.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int v, xf, yf; // number of vertices
double angle; // rotation angle
vector <double> x, y, xprime, yprime;


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
		double a = xf + ((x[i]-xf)*cos(angle) - (y[i]-yf)*sin(angle));
		double b = yf + ((x[i]-xf)*sin(angle) + (y[i]-yf)*cos(angle));
		xprime.push_back(a);
		yprime.push_back(b);
	}
}

void drawRotatedPolygon(){
	// Draw the scaled polygon based on the scaled vertices
	setcolor(YELLOW);
	for(int i = 0; i < v; i++){
		line(xprime[i], yprime[i], xprime[(i+1)%v], yprime[(i+1)%v]);
	}
}

int main(){
	int driver = DETECT, mode = 0;
    initgraph(&driver,&mode, "");

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

	cout << "Enter Fixed point (xf, yf): ";
	cin >> xf >> yf;

	// Convert the angle from degrees to radians
	angle = (angle*3.1416)/180;

	setcolor(WHITE);
	drawpolygon();

	setcolor(YELLOW);
	rotation();
	drawRotatedPolygon();

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
		200 100
	*/

