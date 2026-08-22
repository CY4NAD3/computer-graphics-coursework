#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

float _angle1 = 0.0f;

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
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);
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

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLineWidth(7.5);

	// Car body
	glColor3ub(220,20,20);
	glBegin(GL_QUADS);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.9f, 0.1f);
        glVertex2f(0.9f, 0.3f);
        glVertex2f(0.1f, 0.3f);
	glEnd();

	// Wheels
	drawWheel(0.3f, 0.1f, 0.08f);
	drawWheel(0.7f, 0.1f, 0.08f);

	glFlush();  // Render now
}

void update(int value) {
    _angle1 -= 2.0f;
	glutPostRedisplay();
	glutTimerFunc(20, update, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test");
	glutInitWindowSize(400, 400);// Set the window's initial width & height
	glutDisplayFunc(display);// Register display callback handler for window re-paint
	glutTimerFunc(20, update, 0); //Add a timer
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
