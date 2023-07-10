#include<graphics.h>
#include<bits/stdc++.h> // Include necessary header files
using namespace std;

void koch(int x1, int y1, int x2, int y2, int it){
    float angle = 60*3.1416/180; // Calculate the angle in radians
    int x3 = (2*x1+x2)/3; // Calculate the coordinates of the first dividing point
    int y3 = (2*y1+y2)/3;

    int x4 = (x1+2*x2)/3; // Calculate the coordinates of the second dividing point
    int y4 = (y1+2*y2)/3;
    // third point

    int x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle); // Calculate the coordinates of the third point
    int y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);

    if(it > 1){ // Recursive case: perform further iterations
		setcolor(YELLOW); // Set color to yellow
        koch(x1, y1, x3, y3, it-1); // Recursively call koch function for the first segment
        koch(x3, y3, x, y, it-1); // Recursively call koch function for the second segment
        koch(x, y, x4, y4, it-1); // Recursively call koch function for the third segment
        koch(x4, y4, x2, y2, it-1); // Recursively call koch function for the fourth segment
    }
    else{ // Base case: draw the line segments
        line(x1, y1, x3, y3); // Draw the first segment
        line(x3, y3, x, y); // Draw the second segment
        line(x, y, x4, y4); // Draw the third segment
        line(x4, y4, x2, y2); // Draw the fourth segment
    }
}

int main(void){
    int driver = DETECT, mode = 0;
    initgraph(&driver, &mode, ""); // Initialize graphics mode

    int gen = 8; // Number of generations
    koch(50, 200, 250, 200, gen); // Initial line segment coordinates and number of generations

    getch(); // Wait for user input
    closegraph(); // Close graphics mode
    return 0;
}
