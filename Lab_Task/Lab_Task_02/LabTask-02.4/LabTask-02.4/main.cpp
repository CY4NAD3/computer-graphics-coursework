#include <GL/freeglut.h>
#include <math.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 250.0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 250.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    // SUN (circle outline, template)
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 100; i++) {
            float pi = 3.1416;
            float A = (i * 2 * pi) / 100;
            float r = 20.0;
            float cx = 320, cy = 190;
            float x = cx + r * cos(A);
            float y = cy + r * sin(A);
            glVertex2f(x, y);
        }
    glEnd();

    //  MOUNTAIN 1 (left, outline)
    glBegin(GL_LINE_LOOP);
        glVertex2f(130, 180);
        glVertex2f(200, 80);
        glVertex2f(60, 80);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(118, 160);
        glVertex2f(124, 170);
        glVertex2f(130, 180);
        glVertex2f(136, 170);
        glVertex2f(142, 160);
    glEnd();

    //  MOUNTAIN 2 (middle, tallest, outline)
    glBegin(GL_LINE_LOOP);
        glVertex2f(220, 220);
        glVertex2f(310, 80);
        glVertex2f(130, 80);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(204, 195);
        glVertex2f(212, 205);
        glVertex2f(220, 220);
        glVertex2f(228, 205);
        glVertex2f(236, 195);
    glEnd();

    //  MOUNTAIN 3 (right, outline)
    glBegin(GL_LINE_LOOP);
        glVertex2f(330, 170);
        glVertex2f(400, 80);
        glVertex2f(260, 80);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(318, 150);
        glVertex2f(324, 160);
        glVertex2f(330, 170);
        glVertex2f(336, 160);
        glVertex2f(342, 150);
    glEnd();

    //  GROUND (wavy outline only, NOT filled)
    glBegin(GL_LINE_STRIP);
        glVertex2f(0, 65);
        glVertex2f(40, 75);
        glVertex2f(80, 60);
        glVertex2f(120, 78);
        glVertex2f(160, 65);
        glVertex2f(200, 80);
        glVertex2f(240, 62);
        glVertex2f(280, 77);
        glVertex2f(320, 63);
        glVertex2f(360, 76);
        glVertex2f(400, 65);
    glEnd();

    //  TREE A (x - 100)
    glBegin(GL_QUADS);
        glVertex2f(97, 65);   glVertex2f(103, 65);  glVertex2f(103, 75);  glVertex2f(97, 75);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(82, 75);   glVertex2f(118, 75);  glVertex2f(100, 100);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(86, 95);   glVertex2f(114, 95);  glVertex2f(100, 115);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(90, 110);  glVertex2f(110, 110); glVertex2f(100, 128);
    glEnd();

    //  TREE B (x - 180)
    glBegin(GL_QUADS);
        glVertex2f(177, 63);  glVertex2f(183, 63);  glVertex2f(183, 73);  glVertex2f(177, 73);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(162, 73);  glVertex2f(198, 73);  glVertex2f(180, 98);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(166, 93);  glVertex2f(194, 93);  glVertex2f(180, 113);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(170, 108); glVertex2f(190, 108); glVertex2f(180, 126);
    glEnd();

    //  TREE C (x - 260)
    glBegin(GL_QUADS);
        glVertex2f(257, 62);  glVertex2f(263, 62);  glVertex2f(263, 72);  glVertex2f(257, 72);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(242, 72);  glVertex2f(278, 72);  glVertex2f(260, 97);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(246, 92);  glVertex2f(274, 92);  glVertex2f(260, 112);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(250, 107); glVertex2f(270, 107); glVertex2f(260, 125);
    glEnd();

    //  TREE D (x - 340)
    glBegin(GL_QUADS);
        glVertex2f(337, 64);  glVertex2f(343, 64);  glVertex2f(343, 74);  glVertex2f(337, 74);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(322, 74);  glVertex2f(358, 74);  glVertex2f(340, 99);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(326, 94);  glVertex2f(354, 94);  glVertex2f(340, 114);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(330, 109); glVertex2f(350, 109); glVertex2f(340, 127);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mountain Scene - Question 4");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
