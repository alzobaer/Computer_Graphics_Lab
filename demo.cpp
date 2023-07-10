#include <graphics.h>
#include <math.h>

void koch(int x1, int y1, int x2, int y2, int gen){
	double angle = 60 * 3.1416 / 180; // Calculate the angle in radians
	// Calculate the coordinates of the first dividing point
	int x3 = (x2+2*x1) / 3;
	int y3 = (y2+2*y1) / 3;
	// Calculate the coordinates of the second dividing point
	int x4 = (2*x2+x1) / 3;
	int y4 = (2*y2+y1) / 3;
	// Calculate the coordinates of the third point
	int x5 = x3 + (x4 - x3)*cos(angle) + (y4 - y3)*sin(angle);
	int y5 = y3 - (x4 - x3)*sin(angle) + (y4 - y3)*cos(angle);

	if(gen > 1){ // Recursive case: perform further iterations
		koch(x1, y1, x3, y3, gen-1); // Recursively call koch function for the first segment
		koch(x3, y3, x5, y5, gen-1); // Recursively call koch function for the second segment
		koch(x5, y5, x4, y4, gen-1); // Recursively call koch function for the third segment
		koch(x4, y4, x2, y2, gen-1); // Recursively call koch function for the fourth segment
	}
	else{ // Base case: draw the line segments
		setcolor(YELLOW); // Set color to yellow
		line(x1, y1, x3, y3); // Draw the first segment
		line(x3, y3, x5, y5); // Draw the second segment
		line(x5, y5, x4, y4); // Draw the third segment
		line(x4, y4, x2, y2); // Draw the fourth segment
	}
}
int main(){
	int driver = DETECT, mode = 0;
	initgraph(&driver, &mode, ""); // Initialize graphics mode

	int gen = 3; // Number of generations or iterations
	// Initial line segment coordinates and number of generations
	koch(200, 200, 400, 200, gen);

	getch(); // Wait for user input
	closegraph(); // Close graphics mode
	return 0;
}
