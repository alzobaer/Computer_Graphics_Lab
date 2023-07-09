#include <graphics.h>
int main(){
    int gd = DETECT, gm = 0;
    initgraph(&gd, &gm, "");

    // Code for triangle
    setcolor(WHITE);  // Set color for the triangle
    // Draw triangle
    line(40, 150, 160, 160);  // Draw the below line of the triangle
    line(40, 150, 100, 40);   // Draw the left line of the triangle
    line(100, 40, 160, 160);  // Draw the right line of the triangle
    setfillstyle(1, GREEN);   // Set fill pattern and color for the triangle
    floodfill(80, 148, WHITE);  // Fill the triangle with white color

    // Code for circle
    setcolor(CYAN);  // Set color for the circle
    // Draw circle
    circle(170, 170, 80);  // Draw the circle
    setfillstyle(1, RED);  // Set fill pattern and color for the circle
    floodfill(171, 171, CYAN);  // Fill the circle with cyan color

    // Code for rectangle
    setcolor(YELLOW);  // Set color for the rectangle
    // Draw rectangle
    rectangle(170, 170, 290, 290);  // Draw the rectangle
    setfillstyle(1, BLUE);  // Set fill pattern and color for the rectangle
    floodfill(289, 289, YELLOW);  // Fill the rectangle with yellow color

    getch();
    closegraph();
    return 0;
}
