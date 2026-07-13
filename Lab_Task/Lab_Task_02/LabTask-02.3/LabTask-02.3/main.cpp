#include <GL/freeglut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // ROW 1 (y: 150-200)
    // Square 1 - Black
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(0, 150);
        glVertex2f(50, 150);
        glVertex2f(50, 200);
        glVertex2f(0, 200);
    glEnd();

    // Square 2 - White
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(50, 150);
        glVertex2f(100, 150);
        glVertex2f(100, 200);
        glVertex2f(50, 200);
    glEnd();

    // Square 3 - Black
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(100, 150);
        glVertex2f(150, 150);
        glVertex2f(150, 200);
        glVertex2f(100, 200);
    glEnd();

    // Square 4 - White
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(150, 150);
        glVertex2f(200, 150);
        glVertex2f(200, 200);
        glVertex2f(150, 200);
    glEnd();

    // ROW 2 (y: 100-150)
    // Square 5 - White
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(0, 100);
        glVertex2f(50, 100);
        glVertex2f(50, 150);
        glVertex2f(0, 150);
    glEnd();

    // Square 6 - Black
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(50, 100);
        glVertex2f(100, 100);
        glVertex2f(100, 150);
        glVertex2f(50, 150);
    glEnd();

    // Square 7 - White
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(100, 100);
        glVertex2f(150, 100);
        glVertex2f(150, 150);
        glVertex2f(100, 150);
    glEnd();

    // Square 8 - Black
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(150, 100);
        glVertex2f(200, 100);
        glVertex2f(200, 150);
        glVertex2f(150, 150);
    glEnd();

    // ROW 3 (y: 50-100)
    // Square 9 - Black
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(0, 50);
        glVertex2f(50, 50);
        glVertex2f(50, 100);
        glVertex2f(0, 100);
    glEnd();

    // Square 10 - White
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(50, 50);
        glVertex2f(100, 50);
        glVertex2f(100, 100);
        glVertex2f(50, 100);
    glEnd();

    // Square 11 - Black
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(100, 50);
        glVertex2f(150, 50);
        glVertex2f(150, 100);
        glVertex2f(100, 100);
    glEnd();

    // Square 12 - White
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(150, 50);
        glVertex2f(200, 50);
        glVertex2f(200, 100);
        glVertex2f(150, 100);
    glEnd();

    // ROW 4 (y: 0-50)
    // Square 13 - White
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(50, 0);
        glVertex2f(50, 50);
        glVertex2f(0, 50);
    glEnd();

    // Square 14 - Black
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(50, 0);
        glVertex2f(100, 0);
        glVertex2f(100, 50);
        glVertex2f(50, 50);
    glEnd();

    // Square 15 - White
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(100, 0);
        glVertex2f(150, 0);
        glVertex2f(150, 50);
        glVertex2f(100, 50);
    glEnd();

    // Square 16 - Black
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(150, 0);
        glVertex2f(200, 0);
        glVertex2f(200, 50);
        glVertex2f(150, 50);
    glEnd();

    // Outline around the whole board
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0, 0);
        glVertex2f(200, 0);
        glVertex2f(200, 200);
        glVertex2f(0, 200);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(200, 200);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("4x4 Chess Board - Question 3");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
