#include <graphics.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int v; // number of vertices
double angle; // rotation angle

vector <int> x, y;

void drawpolygon(){
	for(int i = 0; i < v; i++){
		line(x[i], y[i], x[(i+1)%v], y[(i+1)%v]);
	}
}

void rotation(){
	for(int i = 0; i < v; i++){
		line((x[i]*cos(angle) - y[i]*sin(angle)), (x[i]*sin(angle) + y[i]*cos(angle)),
			(x[(i+1)%v]*cos(angle) - y[(i+1)%v]*sin(angle)), (x[(i+1)%v]*sin(angle) + y[(i+1)%v]*cos(angle)));
	}
}

int main(){
	int gd = DETECT;
    int gm = 0;
    initgraph(&gd,&gm,"");


	int a, b;
	cout << "Enter Number of vertex: ";
	cin >> v;
	for(int i = 0; i < v; i++){
		cout << "Enter vertices as clockwise direction: \n";
		cout << "(x" << i << ", y" << i << ") coordinate: ";
 		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}

	cout << "Enter rotation angle: \n";
	cout << "Theta: ";
	cin >> angle;

	angle = (angle*3.1416)/180;

	drawpolygon();
	setcolor(YELLOW);
	setfillstyle(1, GREEN);
	floodfill(x[0]+1, y[0]+1, WHITE);

	rotation();
	setcolor(YELLOW);

	getch();
	return 0;
}

/*
	4
	50 50
    100 50
    100 100
    50 100
    90

*/
