2D Graphics Editor

Description

This project is a simple 2D Graphics Editor implemented in C using ASCII characters.

The editor uses a 2D character array as a canvas and allows users to create and manage graphical objects.

Features

- Draw Line
- Draw Rectangle
- Draw Circle
- Draw Triangle
- Add Objects
- Delete Objects
- Modify Objects
- Display Canvas

Data Structures Used

- 2D Character Array ("char canvas[HEIGHT][WIDTH]")
- Structure for storing shape information
- Array of Shape objects

Algorithms Used

Line Drawing

Bresenham Line Drawing Algorithm

Circle Drawing

Midpoint Circle Algorithm

Rectangle Drawing

Four connected lines

Triangle Drawing

Three connected lines

Compilation

gcc main.c graphics.c -o editor

Execution

./editor

Windows:

editor.exe

Menu Options

1. Add Rectangle
2. Add Circle
3. Add Triangle
4. Add Line
5. Display Canvas
6. Delete Object
7. Modify Object
8. Exit

Author

Prajwal G N