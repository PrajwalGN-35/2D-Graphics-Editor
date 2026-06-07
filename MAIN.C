#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 50
#define HEIGHT 20

// Global 2D array canvas
char canvas[HEIGHT][WIDTH];

// Initialize canvas with underscores
void initCanvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = '_';
        }
    }
}

// Display the canvas
void displayCanvas() {
    // Clears terminal screen for a smooth frame update
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

// Set a single pixel safely within array boundaries
void setPixel(int x, int y) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = '*'; // Row is y, Column is x
    }
}

// Draw a line using Bresenham's Line Algorithm
void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        setPixel(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// Draw a rectangle using the line function
void drawRectangle(int x, int y, int w, int h) {
    drawLine(x, y, x + w - 1, y);                 // Top
    drawLine(x, y + h - 1, x + w - 1, y + h - 1); // Bottom
    drawLine(x, y, x, y + h - 1);                 // Left
    drawLine(x + w - 1, y, x + w - 1, y + h - 1); // Right
}

// Draw a circle using Midpoint Circle Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    
    while (y >= x) {
        setPixel(xc + x, yc + y); setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y); setPixel(xc - x, yc - y);
        setPixel(xc + y, yc + x); setPixel(xc - y, yc + x);
        setPixel(xc + y, yc - x); setPixel(xc - y, yc - x);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

// Draw a triangle by connecting 3 vertices
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

int main() {
    int choice;
    initCanvas();

    while (1) {
        displayCanvas();
        printf("\n--- 2D Graphics Editor Menu ---\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Circle\n");
        printf("4. Draw Triangle\n");
        printf("5. Clear Canvas\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int x1, y1, x2, y2, x3, y3, r, w, h;

        switch (choice) {
            case 1:
                printf("Enter coordinates (x0 y0 x1 y1): ");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                drawLine(x1, y1, x2, y2);
                break;
            case 2:
                printf("Enter (top-left x, top-left y, width, height): ");
                scanf("%d %d %d %d", &x1, &y1, &w, &h);
                drawRectangle(x1, y1, w, h);
                break;
            case 3:
                printf("Enter center and radius (xc yc r): ");
                scanf("%d %d %d", &x1, &y1, &r);
                drawCircle(x1, y1, r);
                break;
            case 4:
                printf("Enter 3 points (x1 y1 x2 y2 x3 y3): ");
                scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
                drawTriangle(x1, y1, x2, y2, x3, y3);
                break;
            case 5:
                initCanvas();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Press Enter to try again.");
                getchar(); getchar();
        }
    }
    return 0;
}