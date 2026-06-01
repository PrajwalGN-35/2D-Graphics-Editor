#include "graphics.h"

int main()
{
    clearCanvas();
    drawLine(5,5,40,15);
    drawRectangle(40,5,65,15);
    displayCanvas();
    drawTriangle(
    20,2,
    5,18,
    35,18);
    return 0;
}