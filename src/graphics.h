#ifndef GRAPHICS_H
#define GRAPHICS_H

#define WIDTH 80
#define HEIGHT 25

extern char canvas[HEIGHT][WIDTH];

void clearCanvas();
void displayCanvas();
void putPixel(int x,int y);
void drawLine(int x1,int y1,int x2,int y2);
void drawRectangle(int x1,int y1,int x2,int y2);
#endif