#include <windows.h>
#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.2f, 0.2f);  // Red fan

    float centerX = 0.0f;
    float centerY = 0.0f;
    float radius = 0.5f;

    glBegin(GL_TRIANGLE_FAN);
        // Center point of the fan
        glVertex2f(centerX, centerY);

        // Create points along a quarter-circle arc (0 to 90 degrees)
        for (int i = 0; i <= 20; ++i) {
            float angle = (3.1416f / 2.0f) * i / 20.0f;  // 0 to π/2
            float x = centerX + radius * cosf(angle);
            float y = centerY + radius * sinf(angle);
            glVertex2f(x, y);
        }
    glEnd();

    glutSwapBuffers();
}

void init() {
    glClearColor(1, 1, 1, 1);  // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);  // 2D view
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Simple Fan Shape Using Triangle Fan");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
