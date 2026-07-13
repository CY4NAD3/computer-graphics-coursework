#include <GL/freeglut.h>

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

// Custom box function
void box(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. base of light pole green color
    glColor3f(0.1f, 0.4f, 0.2f);
    box(250, 50, 350, 70);

    // Light post pole silver color
    glColor3f(0.6f, 0.6f, 0.6f);
    box(290, 70, 310, 430);

    // Bright Glowing Yellow
    glColor3f(1.0f, 0.85f, 0.0f);
    box(270, 430, 330, 510);

    // Inner light bulb (White intense emission source)
    glColor3f(1.0f, 1.0f, 1.0f);
    box(285, 450, 315, 490);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Question 3 - Night Lamppost");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
