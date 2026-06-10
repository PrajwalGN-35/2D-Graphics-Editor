2D Graphics Editor in C

Description

This project is a menu-driven 2D Graphics Editor developed in C using a 2D character array as the drawing canvas. The canvas is initially filled with "_" (underscore) characters, and graphical objects are drawn using "*" (asterisk) characters.

The editor allows users to create, modify, and delete graphical objects while maintaining the drawing on the canvas. The project demonstrates the use of arrays, structures, functions, and basic computer graphics algorithms in C.

Features

- Draw Line
- Draw Rectangle
- Draw Circle
- Draw Triangle
- Add Objects to the Canvas
- Delete Existing Objects
- Modify Existing Objects
- Clear the Entire Canvas
- Redraw Scene After Modifications
- Display the Current Canvas
- Menu-Driven User Interface

How the Program Works

1. A 2D character array is used as the drawing canvas.
2. The canvas is initialized with "_" characters.
3. Graphical objects are drawn using "*" characters.
4. Users can select operations through a menu.
5. Every object is assigned an ID for modification and deletion.
6. After each operation, the canvas is redrawn to reflect the latest state.

Data Structures Used

- 2D Character Array
- Structures ("Shape")
- Enumeration ("ShapeType")
- Arrays of Structures for Object Storage

Shapes Supported

Line

Draws a straight line between two points.

Rectangle

Draws a rectangle using two corner coordinates.

Circle

Draws a circle using center coordinates and radius.

Triangle

Draws a triangle using three vertex coordinates.

Menu Options

1. Add Rectangle
2. Add Circle
3. Add Triangle
4. Add Line
5. Display Canvas
6. Delete Object
7. Modify Object
8. Clear Canvas
9. Exit

Concepts Demonstrated

- C Programming
- Arrays
- Structures
- Functions
- Menu-Driven Programming
- Basic Graphics Algorithms
- Object Management

Project Structure

MAIN.C
README.md
 
Prompts for Mini project 
Day 1 Prompt – Canvas Creation﻿
Create a C program for a 2D Graphics Editor using a 2D character array. Initialize a canvas of size 20x40 with underscore (_) characters and write a function to display the canvas on the screen. Keep the program simple and modular using separate functions for initialization and display.﻿

Day 2 Prompt – Line Drawing﻿
Extend the existing 2D Graphics Editor in C. Add a function called drawLine() that draws a horizontal line on the canvas using the '*' character. The function should accept row number, starting column and ending column as parameters. Display the updated canvas after drawing the line.﻿

Day 3 Prompt – Rectangle Drawing﻿
Improve the existing graphics editor by adding a drawRectangle() function. The rectangle should be drawn using '*' characters on the boundary only. The function should accept row, column, height and width as parameters. Keep the canvas stored in a 2D character array.﻿

Day 4 Prompt – Triangle and CircleCircle﻿
Enhance the graphics editor by adding functions to draw a triangle and a circle on the character canvas. Use '*' for drawing and '_' for empty space. Ensure that the shapes remain within the canvas boundaries. Display the canvas after drawing the shapes.﻿

Day 5 Prompt – Shape Storage﻿
Modify the graphics editor to support multiple graphical objects. Create a structure named Shape containing fields such as shape ID, shape type, coordinates and parameters. Store all shapes in an array of structures and implement a redrawCanvas() function that redraws all active shapes whenever the canvas is refreshed.﻿

Day 6 Prompt – Final Menu Driven Editor﻿
Complete the 2D Graphics Editor in C by creating a menu-driven interface. Allow users to add shapes, display the canvas, delete shapes, modify existing shapes, list all stored shapes and clear the canvas. Use unique IDs for shapes and maintain all graphical objects using structures and a redrawCanvas() function.

Author

Prajwal G N
