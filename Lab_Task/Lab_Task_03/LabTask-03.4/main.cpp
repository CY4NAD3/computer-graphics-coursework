#include <GL/freeglut.h>
#include <cmath>

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White canvas background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);    // Coordinate landscape matching grid
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

// Wheel drawing function circle loop code template
void drawWheel(float centerX, float centerY, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float pi = 3.14159f;
        float angle = (i * 2 * pi) / 200;
        float x = centerX + (radius * cos(angle));
        float y = centerY + (radius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. CAR roof or cabin Red
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(220, 230);
        glVertex2f(380, 230);
        glVertex2f(350, 310);
        glVertex2f(250, 310);
    glEnd();

    // 2. Main body of car Dark Blue
    glColor3f(0.1f, 0.2f, 0.6f);
    box(150, 150, 450, 230);

    // 3. WHEELS Grey kinda color
    glColor3f(0.15f, 0.15f, 0.15f);
    drawWheel(220, 150, 35); // Left Wheel (Center X=220, Y=150, Radius=35)
    drawWheel(380, 150, 35); // Right Wheel (Center X=380, Y=150, Radius=35)

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Question 4 - Car Model");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
