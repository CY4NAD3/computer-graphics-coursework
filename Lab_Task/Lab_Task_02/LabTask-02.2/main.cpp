#include <GL/freeglut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 950.0, 0.0, 200.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // FLAG-1: Germany (x: 30-180)
    // Black stripe (top)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(30, 116.67);
        glVertex2f(180, 116.67);
        glVertex2f(180, 150);
        glVertex2f(30, 150);
    glEnd();

    // Red stripe (middle)
    glColor3f(0.80, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(30, 83.33);
        glVertex2f(180, 83.33);
        glVertex2f(180, 116.67);
        glVertex2f(30, 116.67);
    glEnd();

    // Gold stripe (bottom)
    glColor3f(1.0, 0.8, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(30, 50);
        glVertex2f(180, 50);
        glVertex2f(180, 83.33);
        glVertex2f(30, 83.33);
    glEnd();

    // Outline
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(30, 50);
        glVertex2f(180, 50);
        glVertex2f(180, 150);
        glVertex2f(30, 150);
    glEnd();

    // FLAG-2: Indonesia (x: 210-360)
    // Red stripe (top)
    glColor3f(0.80, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(210, 100);
        glVertex2f(360, 100);
        glVertex2f(360, 150);
        glVertex2f(210, 150);
    glEnd();

    // White stripe (bottom)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(210, 50);
        glVertex2f(360, 50);
        glVertex2f(360, 100);
        glVertex2f(210, 100);
    glEnd();

    // Outline
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(210, 50);
        glVertex2f(360, 50);
        glVertex2f(360, 150);
        glVertex2f(210, 150);
    glEnd();

    // FLAG-3: Peru (x: 390-540)
    // Red stripe (left)
    glColor3f(0.80, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(390, 50);
        glVertex2f(440, 50);
        glVertex2f(440, 150);
        glVertex2f(390, 150);
    glEnd();

    // White stripe (middle)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(440, 50);
        glVertex2f(490, 50);
        glVertex2f(490, 150);
        glVertex2f(440, 150);
    glEnd();

    // Red stripe (right)
    glColor3f(0.80, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(490, 50);
        glVertex2f(540, 50);
        glVertex2f(540, 150);
        glVertex2f(490, 150);
    glEnd();

    // Outline
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(390, 50);
        glVertex2f(540, 50);
        glVertex2f(540, 150);
        glVertex2f(390, 150);
    glEnd();

    // FLAG-4: Monaco (x: 570-720)
    // Red stripe (top)
    glColor3f(0.80, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(570, 100);
        glVertex2f(720, 100);
        glVertex2f(720, 150);
        glVertex2f(570, 150);
    glEnd();

    // White stripe (bottom)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(570, 50);
        glVertex2f(720, 50);
        glVertex2f(720, 100);
        glVertex2f(570, 100);
    glEnd();

    // Outline
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(570, 50);
        glVertex2f(720, 50);
        glVertex2f(720, 150);
        glVertex2f(570, 150);
    glEnd();

    // FLAG-5: Poland (x: 750-900)
    // White stripe (top)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(750, 100);
        glVertex2f(900, 100);
        glVertex2f(900, 150);
        glVertex2f(750, 150);
    glEnd();

    // Red stripe (bottom)
    glColor3f(0.80, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(750, 50);
        glVertex2f(900, 50);
        glVertex2f(900, 100);
        glVertex2f(750, 100);
    glEnd();

    // Outline
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(750, 50);
        glVertex2f(900, 50);
        glVertex2f(900, 150);
        glVertex2f(750, 150);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(950, 200);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("5 Country Flags - Question 2");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
