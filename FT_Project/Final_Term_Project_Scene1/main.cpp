#include <windows.h>
#include <GL/glut.h>
#include <math.h>




void setColor(int r, int g, int b, float a)
{
    glColor4f(255.0f, 255.0f, 255.0f, a);
}

// Axis-aligned rectangle: (x,y) is the bottom-left corner, w/h are width/height.
void drawRect(float x, float y, float w, float h, int r, int g, int b, float a)
{
    setColor(r,g,b,a);
    glBegin(GL_QUADS);
        glVertex2f(x,   y);
        glVertex2f(x+w, y);
        glVertex2f(x+w, y+h);
        glVertex2f(x,   y+h);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, int r, int g, int b, float a)
{
    setColor(r,g,b,a);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
    glEnd();
}

// General CONVEX polygon only - pass its vertices in order as {x,y} pairs.
// (Concave shapes are split into triangles instead - see drawTriangle calls below.)
void drawPoly(const GLfloat pts[][2], int count, int r, int g, int b, float a)
{
    setColor(r,g,b,a);
    glBegin(GL_POLYGON);
    for(int i=0;i<count;i++)
        glVertex2f(pts[i][0], pts[i][1]);
    glEnd();
}

void circle(float radius, float xc, float yc, int r, int g, int b, float a)
{
    setColor(r,g,b,a);
    glBegin(GL_POLYGON);
    for(int i=0;i<60;i++)
    {
        float pi=3.1416f;
        float A=(i*2*pi)/60;
        glVertex2f(xc+radius*cos(A), yc+radius*sin(A));
    }
    glEnd();
}


void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //drawScene(1.0f); // fully opaque day version - pass a lower alpha for night
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Scene 1");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
