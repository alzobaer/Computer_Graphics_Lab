#include <graphics.h>
#include <iostream>
#include <vector>
using namespace std;

int v, xsh, ysh; // number of vertices
vector <int> x, y;

void drawpolygon(){
	// Draw the polygon based on the vertices
	for(int i = 0; i < v; i++){
		setcolor(GREEN);
		line(x[i], y[i], x[(i+1)%v], y[(i+1)%v]);

		// labeling the coordinate points of the original polygon
		char xy[50];
		sprintf(xy,"(%d,%d)",x[i],y[i]);
		outtextxy(x[i]-20,y[i]-20,xy);
	}
}

void translation(){
	// Perform translation on the polygon by shifting its vertices
	for(int i = 0; i < v; i++){
		line(x[i] + xsh, y[i] + ysh, x[(i+1)%v] + xsh, y[(i+1)%v] + ysh);

		// labeling the coordinate points of the translated polygon
		char xy[50];
		sprintf(xy,"(%d,%d)",x[i]+xsh,y[i]+xsh);
		outtextxy(x[i]+xsh-20, y[i]+ysh-20,xy);
	}
}

int main(){
	int driver = DETECT, mode = 0;
    initgraph(&driver, &mode, "");

	int a, b;
	cout << "Enter Number of vertices: ";
	cin >> v;
	cout << "Enter vertices in clockwise direction: \n";
	// Take input of vertices from user
	for(int i = 0; i < v; i++){
		cout << "(x" << i << ", y" << i << ") coordinate: ";
 		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}

	cout << "Enter Shift factor: \n";
	cout << "(Xsh, Ysh): ";
	cin >> xsh >> ysh;

	// Draw the original polygon
	drawpolygon();
	setcolor(YELLOW); // Set color for translation
	// Perform translation and draw the translated polygon
	translation();
	setcolor(GREEN); // Set color for original polygon

	getch();
	return 0;
}


/*  4
	50 50
    300 50
    300 300
    50 300
    80 30


*/
