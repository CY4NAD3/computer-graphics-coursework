#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

float angle1 = 0.0f;
float _move = 0.0f;

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}

void drawWheel(float cx, float cy, float radius)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(cx, cy, 0.0f);
    glRotatef(angle1, 0.0f, 0.0f, 1.0f);
    glTranslatef(-cx, -cy, 0.0f);

    circle(radius, cx, cy, 0, 0, 0); // black tire

    glColor3ub(255,255,255); // white rim
    glBegin(GL_QUADS); //horizontal bar
        glVertex2f(cx-radius, cy-0.01f);
        glVertex2f(cx+radius, cy-0.01f);
        glVertex2f(cx+radius, cy+0.01f);
        glVertex2f(cx-radius, cy+0.01f);
    glEnd();
    glBegin(GL_QUADS); //vertical bar
        glVertex2f(cx-0.01f, cy-radius);
        glVertex2f(cx+0.01f, cy-radius);
        glVertex2f(cx+0.01f, cy+radius);
        glVertex2f(cx-0.01f, cy+radius);
    glEnd();

    glPopMatrix();
}

void box(float r, float g, float b)
{
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.9f, 0.1f);
        glVertex2f(0.9f, 0.3f);
        glVertex2f(0.1f, 0.3f);
    glEnd();
}

void car()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move,0.0,0);
    box(220,20,20);
    drawWheel(0.3f, 0.1f, 0.08f);
    drawWheel(0.7f, 0.1f, 0.08f);
    glPopMatrix();
}

void updateWheelRotation(int a)
{
    angle1-=2.0f;
    glutPostRedisplay();
    glutTimerFunc(20, updateWheelRotation, 0);
}

void updatCar(int a)
{
    _move+=0.02f;
    glutPostRedisplay();
    glutTimerFunc(20, updatCar, 0);
    if(_move>1)
    {
        _move=-1;
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	car();
	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test");
	glutInitWindowSize(320, 320);// Set the window's initial width & height
	glutDisplayFunc(display);// Register display callback handler for window re-paint
	glutTimerFunc(20, updateWheelRotation, 0);
	glutTimerFunc(20, updatCar, 0);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
