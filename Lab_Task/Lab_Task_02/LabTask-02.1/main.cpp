#include <GL/freeglut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 350.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Stripe 1 - Purple
    glColor3f(0.42, 0.34, 0.60);
    glBegin(GL_QUADS);
        glVertex2f(50, 245);
        glVertex2f(450, 245);
        glVertex2f(450, 280);
        glVertex2f(50, 280);
    glEnd();

    // Stripe 2 - Blue
    glColor3f(0.30, 0.45, 0.65);
    glBegin(GL_QUADS);
        glVertex2f(50, 210);
        glVertex2f(450, 210);
        glVertex2f(450, 245);
        glVertex2f(50, 245);
    glEnd();

    // Stripe 3 - Teal
    glColor3f(0.30, 0.65, 0.70);
    glBegin(GL_QUADS);
        glVertex2f(50, 175);
        glVertex2f(450, 175);
        glVertex2f(450, 210);
        glVertex2f(50, 210);
    glEnd();

    // Stripe 4 - Green
    glColor3f(0.10, 0.65, 0.35);
    glBegin(GL_QUADS);
        glVertex2f(50, 140);
        glVertex2f(450, 140);
        glVertex2f(450, 175);
        glVertex2f(50, 175);
    glEnd();

    // Stripe 5 - Orange
    glColor3f(0.95, 0.65, 0.35);
    glBegin(GL_QUADS);
        glVertex2f(50, 105);
        glVertex2f(450, 105);
        glVertex2f(450, 140);
        glVertex2f(50, 140);
    glEnd();

    // Stripe 6 - Yellow
    glColor3f(1.00, 1.00, 0.00);
    glBegin(GL_QUADS);
        glVertex2f(50, 70);
        glVertex2f(450, 70);
        glVertex2f(450, 105);
        glVertex2f(50, 105);
    glEnd();

    // Stripe 7 - Red
    glColor3f(1.00, 0.00, 0.00);
    glBegin(GL_QUADS);
        glVertex2f(50, 35);
        glVertex2f(450, 35);
        glVertex2f(450, 70);
        glVertex2f(50, 70);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 350);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rainbow Flag - Question 1");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
