#include <graphics.h>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int N, a, b;
double  Sx, Sy;
vector <double> x, y, xprime, yprime;

void drawpolygon(){
	// Draw the original polygon based on the vertices
	setcolor(MAGENTA);
	for(int i = 0; i < N; i++){
		line(x[i], y[i], x[(i+1)%N], y[(i+1)%N]);
	}
}

void scaling(){
	// Perform scaling on the polygon by multiplying each vertex with scaling factors
	for(int i = 0; i < N; i++){
		// Compute the scaled coordinates for each vertex
		a = Sx * x[i];
		b = Sy * y[i];
		xprime.push_back(a);
		yprime.push_back(b);
	}
}

void drawScalingPolygon(){
	// Draw the scaled polygon based on the scaled vertices
	setcolor(YELLOW);
	for(int i = 0; i < N; i++){
		line(xprime[i], yprime[i], xprime[(i+1)%N], yprime[(i+1)%N]);
	}
}

int main(){
	int driver = DETECT, mode = 0;
	initgraph(&driver, &mode, "");

	cout << "Enter number of vertices: ";
	cin >> N;
	cout << "Vertices in clockwise direction:\n";
	for(int i = 0; i < N; i++){
		cout << "(x" << i << ", y" << i << "): ";
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
	cout << "Enter Scaling factor \n(Sx, Sy): ";
	cin >> Sx >> Sy;

	setcolor(YELLOW);
	drawpolygon();

	setcolor(GREEN);
	scaling();
	drawScalingPolygon();

	getch();
	closegraph();
	return 0;
}

/*
Sample input:
3
100 100
200 100
150 200
1.5 1.5
*/

