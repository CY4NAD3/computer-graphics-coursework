#include <windows.h>
#include <GL/glut.h>


void initGL() {
    // Set background color to white and opaque
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Grid limits set to Left=-10, Right=10, Bottom=-10, Top=10
    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer


    // X & Y AXIS (Black Lines)

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color

    // X-Axis
    glVertex2i(-8,  0);
    glVertex2i( 8,  0);

    // Y-Axis
    glVertex2i( 0, -8);
    glVertex2i( 0,  8);
    glEnd();


    // 2. QUADRANT II: RED SQUARE (Top-Left)

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2i(-5,  2);
    glVertex2i(-1,  2);
    glVertex2i(-1,  6);
    glVertex2i(-5,  6);
    glEnd();


    // 3. QUADRANT I: GREEN ARROW (Top-Right)

    glColor3f(0.0f, 0.6f, 0.2f); // Green

    // Arrow Tail (Rectangle)
    glBegin(GL_QUADS);
    glVertex2i( 2,  2);
    glVertex2i( 5,  2);
    glVertex2i( 5,  4);
    glVertex2i( 2,  4);
    glEnd();

    // Arrow Head (Triangle)
    glBegin(GL_TRIANGLES);
    glVertex2i( 5,  1);
    glVertex2i( 7,  3);
    glVertex2i( 5,  5);
    glEnd();


    // 4. QUADRANT III: PURPLE TRIANGLE (Bottom-Left)

    glBegin(GL_TRIANGLES);
    glColor3ub(102, 36, 131);
    glVertex2i(-1, -2);
    glVertex2i(-1, -6);
    glVertex2i(-5, -4);
    glEnd();


    // 5. QUADRANT IV: YELLOW TRIANGLE (Bottom-Right)

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex2i( 2, -5);
    glVertex2i( 6, -5);
    glVertex2i( 4, -1);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Lab Task 1 - Object 3");
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}
