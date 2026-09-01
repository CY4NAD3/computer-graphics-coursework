#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1416

// =====================================================
//                 GLOBAL VARIABLES
// =====================================================

float cycle = 0.0f;      // drives automatic day-night progression
int timeMode = 2;        // Dawn:1, Day:2, Evening:3, Night:0 (auto-updated)

// =====================================================
//                 BASIC SHAPE FUNCTIONS
// =====================================================

void rect(float x1, float y1, float x2, float y2, float r, float g, float b){ // ref#rect
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b){ // ref#triangle
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void circle(float radius){ // ref#circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for(int i = 0; i <= 360; i++)
    {
        float angle = i * PI / 180.0f;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

// =====================================================
//                     SUN & MOON
// =====================================================

void sun(){ // ref#sun
    glPushMatrix();
    glTranslatef(53.0f, 88.0f, 0.0f);
    glColor3f(1.0f, 0.85f, 0.05f);
    circle(4.2f);
    glPopMatrix();
}

void moon(){ // ref#moon
    glPushMatrix();
    glTranslatef(75.0f, 85.0f, 0.0f);
    glColor3f(0.92f, 0.94f, 0.98f);
    circle(3.5f);
    glPopMatrix();
}

// =====================================================
//                        STARS
// =====================================================

void stars(){ // ref#stars
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
        glVertex2f(15.0f, 82.0f);
        glVertex2f(28.0f, 90.0f);
        glVertex2f(40.0f, 78.0f);
        glVertex2f(60.0f, 92.0f);
        glVertex2f(70.0f, 80.0f);
        glVertex2f(85.0f, 85.0f);
        glVertex2f(92.0f, 70.0f);
    glEnd();
}

// =====================================================
//                        TREE
// =====================================================

void tree(float x, float y, float scale){ // ref#tree
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    rect(-0.55f, 0.0f, 0.55f, 5.0f, 0.34f, 0.21f, 0.09f);
    triangle(-3.7f, 3.5f, 3.7f, 3.5f, 0.0f, 10.5f, 0.10f, 0.42f, 0.10f);
    triangle(-2.8f, 8.0f, 2.8f, 8.0f, 0.0f, 14.0f, 0.16f, 0.55f, 0.14f);

    glPopMatrix();
}

// =====================================================
//                        HOUSE
// =====================================================

void house(float x, float y, float w, float h, int lit){ // ref#house
    rect(x, y, x + w, y + h, 0.92f, 0.83f, 0.55f);
    triangle(x - 1.5f, y + h, x + w + 1.5f, y + h, x + w * 0.5f, y + h + 8.0f, 0.60f, 0.20f, 0.14f);

    rect(x + w * 0.58f, y, x + w * 0.76f, y + h * 0.48f, 0.27f, 0.15f, 0.08f);

    if(lit == 1)
    {
        rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.95f, 0.85f, 0.30f);
    }
    else
    {
        rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.36f, 0.24f, 0.12f);
    }
}

// =====================================================
//                       DISPLAY
// =====================================================

void scene()
{ // ref#scene
    float skyR, skyG, skyB;

    if(timeMode == 0)      // Night
    {
        skyR = 0.06f; skyG = 0.08f; skyB = 0.18f;
    }
    else if(timeMode == 1) // Dawn
    {
        skyR = 0.85f; skyG = 0.50f; skyB = 0.35f;
    }
    else if(timeMode == 2) // Day
    {
        skyR = 0.28f; skyG = 0.61f; skyB = 0.84f;
    }
    else                    // Evening
    {
        skyR = 0.55f; skyG = 0.30f; skyB = 0.45f;
    }

    glClearColor(skyR, skyG, skyB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    rect(0, 40, 100, 100, skyR, skyG, skyB);

    if(timeMode == 0)
    {
        moon();
        stars();
    }
    else
    {
        sun();
    }

    // Ground
    rect(0, 0, 100, 40, 0.30f, 0.55f, 0.25f);

    tree(15, 40, 1.0f);
    tree(85, 40, 0.9f);

    house(40, 40, 20, 15, timeMode == 0);

    glutSwapBuffers();
}

// =====================================================
//                   UPDATE ANIMATION
// =====================================================

void update(int value)
{ // ref#update
    cycle += 0.50f;
    if(cycle >= 400.0f) cycle = 0.0f;

    if(cycle < 100.0f)      timeMode = 1; // Dawn
    else if(cycle < 200.0f) timeMode = 2; // Day
    else if(cycle < 300.0f) timeMode = 3; // Evening
    else                    timeMode = 0; // Night

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

// =====================================================
//                        INIT
// =====================================================

void init()
{ // ref#init
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// =====================================================
//                        MAIN
// =====================================================

int main(int argc, char** argv)
{ // ref#main
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Day and Night Scenario");

    init();

    glutDisplayFunc(scene);
    glutTimerFunc(20, update, 0);

    glutMainLoop();
    return 0;
}
