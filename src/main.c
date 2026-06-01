#include <stdio.h>
#include "graphics.h"

int main()
{
    int choice;

    clearCanvas();

    while(1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Add Rectangle\n");
        printf("2. Add Circle\n");
        printf("3. Add Triangle\n");
        printf("4. Add Line\n");
        printf("5. Display Canvas\n");
        printf("6. Delete Object\n");
        printf("7. Modify Object\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                Shape s;

                s.id = objectCount + 1;
                s.type = RECTANGLE;

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",
                      &s.x1, &s.y1,
                      &s.x2, &s.y2);

                addObject(s);
                redrawScene();

                printf("Rectangle Added. ID = %d\n", s.id);
                break;
            }

            case 2:
            {
                Shape s;

                s.id = objectCount + 1;
                s.type = CIRCLE;

                printf("Enter centerX centerY radius: ");
                scanf("%d%d%d",
                      &s.x1,
                      &s.y1,
                      &s.radius);

                addObject(s);
                redrawScene();

                printf("Circle Added. ID = %d\n", s.id);
                break;
            }

            case 3:
            {
                Shape s;

                s.id = objectCount + 1;
                s.type = TRIANGLE;

                printf("Enter x1 y1 x2 y2 x3 y3: ");

                scanf("%d%d%d%d%d%d",
                      &s.x1,&s.y1,
                      &s.x2,&s.y2,
                      &s.x3,&s.y3);

                addObject(s);
                redrawScene();

                printf("Triangle Added. ID = %d\n", s.id);
                break;
            }

            case 4:
            {
                Shape s;

                s.id = objectCount + 1;
                s.type = LINE;

                printf("Enter x1 y1 x2 y2: ");

                scanf("%d%d%d%d",
                      &s.x1,&s.y1,
                      &s.x2,&s.y2);

                addObject(s);
                redrawScene();

                printf("Line Added. ID = %d\n", s.id);
                break;
            }

            case 5:
            {
                displayCanvas();
                break;
            }

            case 6:
            {
                int id;

                printf("Enter object ID to delete: ");
                scanf("%d", &id);

                deleteObject(id);

                printf("Object Deleted.\n");
                break;
            }

            case 7:
            {
                int id;

                printf("Enter object ID to modify: ");
                scanf("%d", &id);

                modifyObject(id);

                printf("Object Modified.\n");
                break;
            }

            case 8:
            {
                printf("Exiting...\n");
                return 0;
            }

            default:
            {
                printf("Invalid Choice!\n");
            }
        }
    }

    return 0;
}