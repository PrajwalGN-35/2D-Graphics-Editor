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
 


Author

Prajwal G N
