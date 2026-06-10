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
Development Approach

The project was developed by studying the problem statement and implementing the required features step by step in C.

During development, I referred to programming documentation, online resources, and AI-assisted tools to understand concepts such as:

- 2D character arrays as a drawing canvas
- Drawing lines, rectangles, circles, and triangles
- Using structures to store graphical objects
- Menu-driven program design
- Object addition, deletion, and modification
- Redrawing the canvas after updates

The implementation was tested and refined by experimenting with different inputs and understanding how each function worked. The code was reviewed and modified to match the assignment requirements, and the final version was organized into a GitHub repository with proper documentation.

Through this project, I gained practical experience with:

- C programming
- Arrays and structures
- Functions
- Menu-driven applications
- Basic graphics representation using character arrays
- Git and GitHub version control

Author

Prajwal G N
