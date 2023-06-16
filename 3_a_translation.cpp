#include <graphics.h>
#include <iostream>
#include <vector>
using namespace std;

int v, xsh, ysh; // number of vertices
vector <int> x, y;

void drawpolygon(){
	for(int i = 0; i < v; i++){
		line(x[i], y[i], x[(i+1)%v], y[(i+1)%v]);
	}
}

void translation(){
	for(int i = 0; i < v; i++){
		line(x[i] + xsh, y[i] + ysh, x[(i+1)%v] + xsh, y[(i+1)%v] + ysh);
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

	cout << "Enter Shift factor: \n";
	cout << "(Xsh, Ysh): ";
	cin >> xsh >> ysh;

	drawpolygon();
	setcolor(YELLOW);
	translation();
	setcolor(GREEN);

	getch();
	return 0;
}

/*
	4
	50 50
    100 50
    100 100
    50 100
    25 25

*/
