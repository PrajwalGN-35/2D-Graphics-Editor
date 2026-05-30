#include <stdio.h>
#include "graphics.h"

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