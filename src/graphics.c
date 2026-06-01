#include <stdio.h>
#include "graphics.h"
#include<stdlib.h>
char canvas[HEIGHT][WIDTH];

void clearCanvas()
{
    for(int i=0;i<HEIGHT;i++)
        for(int j=0;j<WIDTH;j++)
            canvas[i][j]='_';
}

void displayCanvas()
{
    for(int i=0;i<HEIGHT;i++)
    {
        for(int j=0;j<WIDTH;j++)
            printf("%c",canvas[i][j]);
        printf("\n");
    }
}
void putPixel(int x,int y)
{
    if(x>=0 && x<WIDTH &&
       y>=0 && y<HEIGHT)
    {
        canvas[y][x]='*';
    }
}
void drawLine(int x1,int y1,int x2,int y2)
{
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);

    int sx=(x1<x2)?1:-1;
    int sy=(y1<y2)?1:-1;

    int err=dx-dy;

    while(1)
    {
        putPixel(x1,y1);

        if(x1==x2 && y1==y2)
            break;

        int e2=2*err;

        if(e2>-dy)
        {
            err-=dy;
            x1+=sx;
        }

        if(e2<dx)
        {
            err+=dx;
            y1+=sy;
        }
    }
}
void drawRectangle(int x1,int y1,int x2,int y2)
{
    drawLine(x1,y1,x2,y1);
    drawLine(x2,y1,x2,y2);
    drawLine(x2,y2,x1,y2);
    drawLine(x1,y2,x1,y1);
}
void drawTriangle(
int x1,int y1,
int x2,int y2,
int x3,int y3)
{
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x1,y1);
}
void drawCircle(int xc,int yc,int r)
{
    int x=0;
    int y=r;
    int d=1-r;

    while(x<=y)
    {
        putPixel(xc+x,yc+y);
        putPixel(xc-x,yc+y);
        putPixel(xc+x,yc-y);
        putPixel(xc-x,yc-y);

        putPixel(xc+y,yc+x);
        putPixel(xc-y,yc+x);
        putPixel(xc+y,yc-x);
        putPixel(xc-y,yc-x);

        if(d<0)
            d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            y--;
        }

        x++;
    }
}
Shape objects[MAX_OBJECTS];
int objectCount = 0;
void addObject(Shape s)
{
    if(objectCount < MAX_OBJECTS)
   
    {
        objects[objectCount++] = s;
    }
}
void deleteObject(int id)
{
    for(int i=0;i<objectCount;i++)
    {
        if(objects[i].id == id)
        {
            for(int j=i;j<objectCount-1;j++)
            {
                objects[j] = objects[j+1];
            }

            objectCount--;
            break;
        }
    }

    redrawScene();
}
void modifyObject(int id)
{
    for(int i=0;i<objectCount;i++)
    {
        if(objects[i].id == id)
        {
            printf("Enter new x1 y1 x2 y2 : ");

            scanf("%d%d%d%d",
                  &objects[i].x1,
                  &objects[i].y1,
                  &objects[i].x2,
                  &objects[i].y2);

            break;
        }
    }

    redrawScene();
}
void redrawScene()
{
    clearCanvas();

    for(int i=0;i<objectCount;i++)
    {
        Shape s = objects[i];

        switch(s.type)
        {
            case LINE:
                drawLine(
                    s.x1,s.y1,
                    s.x2,s.y2);
                break;

            case RECTANGLE:
                drawRectangle(
                    s.x1,s.y1,
                    s.x2,s.y2);
                break;

            case CIRCLE:
                drawCircle(
                    s.x1,s.y1,
                    s.radius);
                break;

            case TRIANGLE:
                drawTriangle(
                    s.x1,s.y1,
                    s.x2,s.y2,
                    s.x3,s.y3);
                break;
        }
    }
}