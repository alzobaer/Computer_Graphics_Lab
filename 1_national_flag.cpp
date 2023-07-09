#include <graphics.h>

int main() {
    int driver = DETECT, mode = 0;
    initgraph(&driver, &mode, "");

    // Set common color
    setcolor(WHITE);              // Set the drawing color to white

    // Displaying bamboo
    setfillstyle(1, BLUE);        // Set the fill pattern to solid fill with blue color
    rectangle(100, 50, 110, 450); // Draw a rectangle for bamboo stem
    floodfill(105, 55, WHITE);    // Fill the bamboo stem with white color

    // Flag rectangle
    setfillstyle(1, GREEN);       // Set the fill pattern to solid fill with green color
    rectangle(110, 60, 410, 240); // Draw a rectangle for the flag
    floodfill(150, 150, WHITE);   // Fill the flag with white color

    // Circle for the sun
    setfillstyle(1, RED);         // Set the fill pattern to solid fill with red color
    circle(245, 150, 60);         // Draw a circle for the sun
    floodfill(240, 150, WHITE);   // Fill the sun with white color

    getch();
    closegraph();                 // Close the graphics mode and release resources
    return 0;
}
