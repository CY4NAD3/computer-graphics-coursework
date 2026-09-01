#include <windows.h>
#include <GL/glut.h>
#include <math.h>

int colorIndex = 0;

// Array of background colors (RGB values 0-1)
float colors[3][3] = {
    { 1.0f, 0.0f, 0.0f },  // Red
    { 0.0f, 1.0f, 0.0f },  // Green
    { 0.0f, 0.0f, 1.0f }   // Blue
};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void changeBackgroundColor(int value)
{
    colorIndex = (colorIndex + 1) % 3;

    glClearColor(colors[colorIndex][0], colors[colorIndex][1], colors[colorIndex][2], 1.0f);

    glutPostRedisplay();
    glutTimerFunc(20, changeBackgroundColor, 0);
}

void init()
{
    glClearColor(colors[colorIndex][0], colors[colorIndex][1], colors[colorIndex][2], 1.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Background Color Change");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(20, changeBackgroundColor, 0);

    glutMainLoop();
    return 0;
}
