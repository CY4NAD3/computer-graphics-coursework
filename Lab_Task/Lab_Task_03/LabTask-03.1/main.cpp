#include <GL/freeglut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

// Box function
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

    // 1. Building
    glColor3f(0.85f, 0.85f, 0.85f);
    box(200, 50, 400, 550);

    // 2. front door Brown
    glColor3f(0.5f, 0.35f, 0.2f);
    box(275, 50, 325, 140);

    // 3. all window Blue color
    glColor3f(0.4f, 0.7f, 1.0f);

    // Floor 2 Windows
    box(230, 170, 270, 210); // Left
    box(330, 170, 370, 210); // Right

    // Floor 3 Windows
    box(230, 260, 270, 300); // Left
    box(330, 260, 370, 300); // Right

    // Floor 4 Windows
    box(230, 350, 270, 390); // Left
    box(330, 350, 370, 390); // Right

    // Floor 5 Windows
    box(230, 440, 270, 480); // Left
    box(330, 440, 370, 480); // Right

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Five Storied Building");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
