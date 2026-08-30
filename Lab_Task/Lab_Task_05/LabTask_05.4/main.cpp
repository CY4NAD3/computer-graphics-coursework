#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

float _angle1 = 0.0f;  // blade rotation angle

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++)
    {
        glColor3ub(r,g,b);
        float pi=3.1416f;
        float A=(i*2*pi)/100;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x+xc,y+yc);
    }
    glEnd();
}

// Tower (trapezoid) holding the windmill up
void drawTower(float baseX, float baseY, float topX, float topY, float baseWidth, float topWidth)
{
    glColor3ub(235,235,235);
    glBegin(GL_QUADS);
        glVertex2f(baseX - baseWidth/2, baseY);
        glVertex2f(baseX + baseWidth/2, baseY);
        glVertex2f(topX + topWidth/2, topY);
        glVertex2f(topX - topWidth/2, topY);
    glEnd();
}

// Blades + hub, rotating together about (cx, cy) - same push/rotate/pop trick as drawWheel()
void drawBlades(float cx, float cy, float length, float width, int numBlades)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cx, cy, 0.0f);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);
    glTranslatef(-cx, -cy, 0.0f);

    glColor3ub(250,250,250);
    for(int i=0;i<numBlades;i++)
    {
        glPushMatrix();
        glTranslatef(cx, cy, 0.0f);
        glRotatef((360.0f/numBlades)*i, 0.0f, 0.0f, 1.0f);
        glTranslatef(-cx, -cy, 0.0f);

        glBegin(GL_TRIANGLES);
            glVertex2f(cx - width/2, cy);
            glVertex2f(cx + width/2, cy);
            glVertex2f(cx, cy + length);
        glEnd();

        glPopMatrix();
    }
    glPopMatrix();

    circle(0.025f, cx, cy, 200, 60, 60); // hub, drawn last so it sits on top
}

// Called once at start AND every time the window is resized/moved by the OS -
// keeps the drawing area (viewport) and the 0..1 coordinate system (ortho)
// locked to whatever the window's real current size actually is.
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f); // sky blue background
    glClear(GL_COLOR_BUFFER_BIT);

    // ground
    glColor3ub(60,150,60);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(1.0f, 0.15f);
        glVertex2f(0.0f, 0.15f);
    glEnd();

    drawTower(0.5f, 0.15f, 0.5f, 0.65f, 0.08f, 0.03f);
    drawBlades(0.5f, 0.65f, 0.22f, 0.045f, 4);

    glFlush();
}

void update(int value)
{
    _angle1 -= 3.0f;
    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Windmill with Rotating Blades");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(20, update, 0);
    glutMainLoop();
    return 0;
}
