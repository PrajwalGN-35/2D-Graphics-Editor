#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_SHAPES 100

// Canvas Grid Array
char canvas[HEIGHT][WIDTH];

// Shape types for object tracking
typedef enum { LINE, RECTANGLE, TRIANGLE, CIRCLE } ShapeType;

// Structure to track drawn objects
typedef struct {
    int id;
    ShapeType type;
    int x1, y1; // Point 1 / Center for Circle
    int x2, y2; // Point 2 / Width & Height for Rectangle
    int x3, y3; // Point 3 for Triangle
    int radius; // For Circle
} Object;

Object shapeList[MAX_SHAPES];
int shapeCount = 0;
int nextId = 1;

// --- CANVAS MANAGEMENT ---

// Clears the buffer array with empty spaces
void clearCanvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }
}

// Renders the buffer grid to the actual terminal screen
void displayCanvas() {
    // Top Border
    for (int j = 0; j < WIDTH + 2; j++) printf("-");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        printf("|"); // Left Border
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("|\n"); // Right Border
    }

    // Bottom Border
    for (int j = 0; j < WIDTH + 2; j++) printf("-");
    printf("\n");
}

// Internal pixel plotter that respects canvas boundaries
void setPixel(int x, int y) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = '*';
    }
}

// --- RENDER ALGORITHMS ---

// Bresenham's Line Algorithm
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

// Rectangle using 4 straight lines
void drawRectangle(int x, int y, int w, int h) {
    drawLine(x, y, x + w - 1, y);             // Top
    drawLine(x, y + h - 1, x + w - 1, y + h - 1); // Bottom
    drawLine(x, y, x, y + h - 1);             // Left
    drawLine(x + w - 1, y, x + w - 1, y + h - 1); // Right
}

// Triangle using 3 interconnected lines
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

// Midpoint Circle Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    
    while (y >= x) {
        setPixel(xc + x, yc + y);
        setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y);
        setPixel(xc - x, yc - y);
        setPixel(xc + y, yc + x);
        setPixel(xc - y, yc + x);
        setPixel(xc + y, yc - x);
        setPixel(xc - y, yc - x);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

// --- CORE OBJECT MANAGER ---

// Clears grid and loops over tracked array to assemble final layout
void redrawCanvas() {
    clearCanvas();
    for (int i = 0; i < shapeCount; i++) {
        switch (shapeList[i].type) {
            case LINE:
                drawLine(shapeList[i].x1, shapeList[i].y1, shapeList[i].x2, shapeList[i].y2);
                break;
            case RECTANGLE:
                drawRectangle(shapeList[i].x1, shapeList[i].y1, shapeList[i].x2, shapeList[i].y2);
                break;
            case TRIANGLE:
                drawTriangle(shapeList[i].x1, shapeList[i].y1, shapeList[i].x2, shapeList[i].y2, shapeList[i].x3, shapeList[i].y3);
                break;
            case CIRCLE:
                drawCircle(shapeList[i].x1, shapeList[i].y1, shapeList[i].radius);
                break;
        }
    }
}

// Lists active shapes with their unique IDs
void printObjects() {
    printf("\n--- Active Vector Objects ---\n");
    if (shapeCount == 0) {
        printf("None (Canvas Empty)\n");
        return;
    }
    for (int i = 0; i < shapeCount; i++) {
        printf("ID: %d | ", shapeList[i].id);
        switch (shapeList[i].type) {
            case LINE:      printf("Line [(%d,%d) to (%d,%d)]\n", shapeList[i].x1, shapeList[i].y1, shapeList[i].x2, shapeList[i].y2); break;
            case RECTANGLE: printf("Rectangle [Pos:(%d,%d), W:%d, H:%d]\n", shapeList[i].x1, shapeList[i].y1, shapeList[i].x2, shapeList[i].y2); break;
            case TRIANGLE:  printf("Triangle [(%d,%d), (%d,%d), (%d,%d)]\n", shapeList[i].x1, shapeList[i].y1, shapeList[i].x2, shapeList[i].y2, shapeList[i].x3, shapeList[i].y3); break;
            case CIRCLE:    printf("Circle [Center:(%d,%d), Radius:%d]\n", shapeList[i].x1, shapeList[i].y1, shapeList[i].radius); break;
        }
    }
    printf("-----------------------------\n");
}

// Modifies metadata coordinates for a targeted unique ID
void modifyShape() {
    int targetId, foundIndex = -1;
    printObjects();
    printf("Enter the Object ID you want to MODIFY: ");
    if (scanf("%d", &targetId) != 1) return;

    for (int i = 0; i < shapeCount; i++) {
        if (shapeList[i].id == targetId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Error: Object ID not found.\n");
        return;
    }

    printf("Enter new primary coordinates (x1 y1): ");
    scanf("%d %d", &shapeList[foundIndex].x1, &shapeList[foundIndex].y1);

    if (shapeList[foundIndex].type == LINE) {
        printf("Enter new end coordinates (x2 y2): ");
        scanf("%d %d", &shapeList[foundIndex].x2, &shapeList[foundIndex].y2);
    } else if (shapeList[foundIndex].type == RECTANGLE) {
        printf("Enter new properties (Width Height): ");
        scanf("%d %d", &shapeList[foundIndex].x2, &shapeList[foundIndex].y2);
    } else if (shapeList[foundIndex].type == TRIANGLE) {
        printf("Enter second coordinates (x2 y2): ");
        scanf("%d %d", &shapeList[foundIndex].x2, &shapeList[foundIndex].y2);
        printf("Enter third coordinates (x3 y3): ");
        scanf("%d %d", &shapeList[foundIndex].x3, &shapeList[foundIndex].y3);
    } else if (shapeList[foundIndex].type == CIRCLE) {
        printf("Enter new Radius: ");
        scanf("%d", &shapeList[foundIndex].radius);
    }

    printf("Object %d updated successfully.\n", targetId);
    redrawCanvas();
}

// Drops an element from the tracker array and compacts data indices
void deleteShape() {
    int targetId, foundIndex = -1;
    printObjects();
    printf("Enter the Object ID you want to DELETE: ");
    if (scanf("%d", &targetId) != 1) return;

    for (int i = 0; i < shapeCount; i++) {
        if (shapeList[i].id == targetId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Error: Object ID not found.\n");
        return;
    }

    for (int i = foundIndex; i < shapeCount - 1; i++) {
        shapeList[i] = shapeList[i + 1];
    }
    shapeCount--;

    printf("Object %d removed successfully.\n", targetId);
    redrawCanvas();
}

// --- MAIN RUNTIME TERMINAL SYSTEM ---

int main() {
    int choice;
    clearCanvas();

    while (1) {
        printf("\n=== 2D VECTOR GRAPHICS ENGINE ===\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Modify an Object\n");
        printf("6. Delete an Object\n");
        printf("7. Wipe Canvas Clean\n");
        printf("8. Exit Application\n");
        printObjects();
        printf("Select menu operation (1-8): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            exit(0);
        }

        if (choice == 8) {
            printf("Exiting Vector Engine. Goodbye!\n");
            break;
        }

        // Handle structural limits before appending
        if (choice >= 1 && choice <= 4 && shapeCount >= MAX_SHAPES) {
            printf("Error: Max shape storage limit reached!\n");
            continue;
        }

        switch (choice) {
            case 1:
                shapeList[shapeCount].type = LINE;
                printf("Enter Line Coordinates (x1 y1 x2 y2): ");
                scanf("%d %d %d %d", &shapeList[shapeCount].x1, &shapeList[shapeCount].y1, &shapeList[shapeCount].x2, &shapeList[shapeCount].y2);
                shapeList[shapeCount].id = nextId++;
                shapeCount++;
                redrawCanvas();
                displayCanvas();
                break;

            case 2:
                shapeList[shapeCount].type = RECTANGLE;
                printf("Enter Rectangle Specs (x1 y1 Width Height): ");
                scanf("%d %d %d %d", &shapeList[shapeCount].x1, &shapeList[shapeCount].y1, &shapeList[shapeCount].x2, &shapeList[shapeCount].y2);
                shapeList[shapeCount].id = nextId++;
                shapeCount++;
                redrawCanvas();
                displayCanvas();
                break;

            case 3:
                shapeList[shapeCount].type = TRIANGLE;
                printf("Enter Triangle Vertices (x1 y1 x2 y2 x3 y3): ");
                scanf("%d %d %d %d %d %d", &shapeList[shapeCount].x1, &shapeList[shapeCount].y1, &shapeList[shapeCount].x2, &shapeList[shapeCount].y2, &shapeList[shapeCount].x3, &shapeList[shapeCount].y3);
                shapeList[shapeCount].id = nextId++;
                shapeCount++;
                redrawCanvas();
                displayCanvas();
                break;

            case 4:
                shapeList[shapeCount].type = CIRCLE;
                printf("Enter Circle Specs (xc yc Radius): ");
                scanf("%d %d %d", &shapeList[shapeCount].x1, &shapeList[shapeCount].y1, &shapeList[shapeCount].radius);
                shapeList[shapeCount].id = nextId++;
                shapeCount++;
                redrawCanvas();
                displayCanvas();
                break;

            case 5:
                modifyShape();
                displayCanvas();
                break;

            case 6:
                deleteShape();
                displayCanvas();
                break;

            case 7:
                shapeCount = 0;
                nextId = 1;
                clearCanvas();
                displayCanvas();
                printf("Canvas wiped clean.\n");
                break;

            default:
                printf("Invalid selection. Choose 1-8.\n");
        }
    }
    return 0;
}
