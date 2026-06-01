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
void drawTriangle(
int x1,int y1,
int x2,int y2,
int x3,int y3);
void drawCircle(int xc,int yc,int r);
typedef enum
{
    LINE,
    RECTANGLE,
    CIRCLE,
    TRIANGLE
} ShapeType;

typedef struct
{
    int id;
    ShapeType type;

    int x1,y1;
    int x2,y2;
    int x3,y3;

    int radius;
} Shape;
extern Shape objects[MAX_OBJECTS];
extern int objectCount;

void clearCanvas();
void displayCanvas();

void putPixel(int x,int y);

void drawLine(int x1,int y1,int x2,int y2);
void drawRectangle(int x1,int y1,int x2,int y2);
void drawCircle(int xc,int yc,int r);
void drawTriangle(
    int x1,int y1,
    int x2,int y2,
    int x3,int y3);

void addObject(Shape s);
void deleteObject(int id);
void modifyObject(int id);
void redrawScene();
#endif