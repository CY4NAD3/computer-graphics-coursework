#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

// Object ID Reference Table
// OBJ-01  : Sky (Background)
// OBJ-02  : Sun / Moon
// OBJ-03  : Stars
// OBJ-04  : Cloud 1
// OBJ-05  : Cloud 2
// OBJ-06  : Cloud 3
// OBJ-07  : Building 1 (Small Left)
// OBJ-08  : Building 2 (Medium Left)
// OBJ-09  : Building 3 (Small Center-Left)
// OBJ-10  : Building 4 (Tall Center)
// OBJ-11  : Building 5 (Medium Center-Right)
// OBJ-12  : Building 6 (Medium Right)
// OBJ-13  : Shopping Mall
// OBJ-14  : Road
// OBJ-15  : Tree 1
// OBJ-16  : Tree 2
// OBJ-17  : Tree 3
// OBJ-18  : Street Lamp 1
// OBJ-19  : Street Lamp 2
// OBJ-20  : Street Lamp 3
// OBJ-21  : Street Lamp 4
// OBJ-22  : Car 1
// OBJ-23  : Car 2
// OBJ-24  : Bus
// OBJ-25  : Car 3

// Animation Function ID Reference Table
// ANIM-01 : update()
// ANIM-02 : keyboard()
// ANIM-03 : mouse()
// ANIM-04 : Vehicle movement
// ANIM-05 : Cloud movement
// ANIM-06 : Traffic state cycle

// Variables
float car = -25.0f;
float car1 = 110.0f;
float bus1 = 140.0f;
float car2 = 172.0f;

float cloud1 = 5.0f;
float cloud2 = 38.0f;
float cloud3 = 72.0f;

float tree1 = 5.0f;
float tree2 = 67.0f;
float tree3 = 99.0f;

float lamppost1 = 18.0f;
float lamppost2 = 38.0f;
float lamppost3 = 58.0f;
float lamppost4 = 68.0f;

bool allAnimation = true;
bool vehicleMoving = true;
bool lightsOn = true;

int timeMode = 1;
int trafficState = 0;

// Basic Shapes

void rectangle(float x1, float y1, float x2, float y2)
{
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void circle(float x, float y, float radius)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; i++)
    {
        float angle = 2.0f * 3.14159f * i / 100.0f;
        float px = x + radius * cos(angle);
        float py = y + radius * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();
}

void line(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// Sun & Moon

void drawSunMoon()
{
    // Object ID: OBJ-02

    if (timeMode == 3)
    {
        glColor3f(1.0f, 1.0f, 0.75f);
        circle(84.0f, 85.0f, 5.0f);

        glColor3f(0.06f, 0.08f, 0.20f);
        circle(86.0f, 87.0f, 5.0f);
    }
    else
    {
        if (timeMode == 0)
            glColor3f(1.0f, 0.45f, 0.15f);
        else if (timeMode == 2)
            glColor3f(1.0f, 0.30f, 0.05f);
        else
            glColor3f(1.0f, 0.85f, 0.10f);

        circle(84.0f, 85.0f, 5.0f);
    }
}

// Clouds

void drawCloud(float x, float y)
{
    // Object ID: OBJ-04 / OBJ-05 / OBJ-06

    if (timeMode == 3)
        glColor3f(0.42f, 0.45f, 0.55f);
    else
        glColor3f(1.0f, 1.0f, 1.0f);

    circle(x, y, 3.0f);
    circle(x + 4.0f, y + 1.0f, 3.5f);
    circle(x + 8.0f, y, 3.0f);

    rectangle(x - 2.0f, y - 2.0f, x + 10.0f, y + 1.0f);
}

// Sky

void drawSky()
{
    // Object ID: OBJ-01

    if (timeMode == 0)
        glColor3f(0.95f, 0.55f, 0.35f);
    else if (timeMode == 1)
        glColor3f(0.35f, 0.72f, 1.0f);
    else if (timeMode == 2)
        glColor3f(0.70f, 0.32f, 0.38f);
    else
        glColor3f(0.05f, 0.07f, 0.20f);

    rectangle(0.0f, 30.0f, 100.0f, 100.0f);

    drawSunMoon();

    if (timeMode == 3)
    {
        // Object ID: OBJ-03

        glColor3f(1.0f, 1.0f, 0.75f);
        circle(10.0f, 90.0f, 0.3f);
        circle(20.0f, 80.0f, 0.3f);
    }
}

// Building 1

void drawBuilding1()
{
    // Object ID: OBJ-07

    glColor3f(0.25f, 0.30f, 0.43f);

    // Main building
    glBegin(GL_QUADS);
    glVertex2f(2.0f, 35.0f);
    glVertex2f(11.0f, 35.0f);
    glVertex2f(11.0f, 59.0f);
    glVertex2f(2.0f, 59.0f);
    glEnd();

    // Rooftop ledge
    glColor3f(0.18f, 0.21f, 0.30f);

    glBegin(GL_QUADS);
    glVertex2f(1.5f, 59.0f);
    glVertex2f(11.5f, 59.0f);
    glVertex2f(11.5f, 60.0f);
    glVertex2f(1.5f, 60.0f);
    glEnd();

    if (timeMode == 3 && lightsOn)
        glColor3f(1.0f, 0.85f, 0.20f);
    else
        glColor3f(0.55f, 0.80f, 0.95f);

    // Window 1
    glBegin(GL_QUADS);
    glVertex2f(4.0f, 39.0f);
    glVertex2f(6.0f, 39.0f);
    glVertex2f(6.0f, 41.5f);
    glVertex2f(4.0f, 41.5f);
    glEnd();

    // Window 2
    glBegin(GL_QUADS);
    glVertex2f(8.0f, 39.0f);
    glVertex2f(10.0f, 39.0f);
    glVertex2f(10.0f, 41.5f);
    glVertex2f(8.0f, 41.5f);
    glEnd();

    // Window 3
    glBegin(GL_QUADS);
    glVertex2f(4.0f, 44.0f);
    glVertex2f(6.0f, 44.0f);
    glVertex2f(6.0f, 46.5f);
    glVertex2f(4.0f, 46.5f);
    glEnd();

    // Window 4
    glBegin(GL_QUADS);
    glVertex2f(8.0f, 44.0f);
    glVertex2f(10.0f, 44.0f);
    glVertex2f(10.0f, 46.5f);
    glVertex2f(8.0f, 46.5f);
    glEnd();

    // Window 5
    glBegin(GL_QUADS);
    glVertex2f(4.0f, 49.0f);
    glVertex2f(6.0f, 49.0f);
    glVertex2f(6.0f, 51.5f);
    glVertex2f(4.0f, 51.5f);
    glEnd();

    // Window 6
    glBegin(GL_QUADS);
    glVertex2f(8.0f, 49.0f);
    glVertex2f(10.0f, 49.0f);
    glVertex2f(10.0f, 51.5f);
    glVertex2f(8.0f, 51.5f);
    glEnd();

    // Window 7
    glBegin(GL_QUADS);
    glVertex2f(4.0f, 54.0f);
    glVertex2f(6.0f, 54.0f);
    glVertex2f(6.0f, 56.5f);
    glVertex2f(4.0f, 56.5f);
    glEnd();

    // Window 8
    glBegin(GL_QUADS);
    glVertex2f(8.0f, 54.0f);
    glVertex2f(10.0f, 54.0f);
    glVertex2f(10.0f, 56.5f);
    glVertex2f(8.0f, 56.5f);
    glEnd();
}

// Building 2

void drawBuilding2()
{
    // Object ID: OBJ-08

    glColor3f(0.32f, 0.38f, 0.52f);

    // Main building
    glBegin(GL_QUADS);
    glVertex2f(13.0f, 35.0f);
    glVertex2f(23.0f, 35.0f);
    glVertex2f(23.0f, 65.0f);
    glVertex2f(13.0f, 65.0f);
    glEnd();

    // Rooftop ledge
    glColor3f(0.22f, 0.27f, 0.36f);

    glBegin(GL_QUADS);
    glVertex2f(12.5f, 65.0f);
    glVertex2f(23.5f, 65.0f);
    glVertex2f(23.5f, 66.0f);
    glVertex2f(12.5f, 66.0f);
    glEnd();

    if (timeMode == 3 && lightsOn)
        glColor3f(1.0f, 0.85f, 0.20f);
    else
        glColor3f(0.55f, 0.80f, 0.95f);

    // Windows
    glBegin(GL_QUADS);
    glVertex2f(15.0f, 39.0f);
    glVertex2f(17.0f, 39.0f);
    glVertex2f(17.0f, 41.5f);
    glVertex2f(15.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(19.0f, 39.0f);
    glVertex2f(21.0f, 39.0f);
    glVertex2f(21.0f, 41.5f);
    glVertex2f(19.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(15.0f, 44.0f);
    glVertex2f(17.0f, 44.0f);
    glVertex2f(17.0f, 46.5f);
    glVertex2f(15.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(19.0f, 44.0f);
    glVertex2f(21.0f, 44.0f);
    glVertex2f(21.0f, 46.5f);
    glVertex2f(19.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(15.0f, 49.0f);
    glVertex2f(17.0f, 49.0f);
    glVertex2f(17.0f, 51.5f);
    glVertex2f(15.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(19.0f, 49.0f);
    glVertex2f(21.0f, 49.0f);
    glVertex2f(21.0f, 51.5f);
    glVertex2f(19.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(15.0f, 54.0f);
    glVertex2f(17.0f, 54.0f);
    glVertex2f(17.0f, 56.5f);
    glVertex2f(15.0f, 56.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(19.0f, 54.0f);
    glVertex2f(21.0f, 54.0f);
    glVertex2f(21.0f, 56.5f);
    glVertex2f(19.0f, 56.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(15.0f, 59.0f);
    glVertex2f(17.0f, 59.0f);
    glVertex2f(17.0f, 61.5f);
    glVertex2f(15.0f, 61.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(19.0f, 59.0f);
    glVertex2f(21.0f, 59.0f);
    glVertex2f(21.0f, 61.5f);
    glVertex2f(19.0f, 61.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(15.0f, 64.0f);
    glVertex2f(17.0f, 64.0f);
    glVertex2f(17.0f, 66.5f);
    glVertex2f(15.0f, 66.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(19.0f, 64.0f);
    glVertex2f(21.0f, 64.0f);
    glVertex2f(21.0f, 66.5f);
    glVertex2f(19.0f, 66.5f);
    glEnd();
}

// Building 3

void drawBuilding3()
{
    // Object ID: OBJ-09

    glColor3f(0.38f, 0.42f, 0.55f);

    // Main building
    glBegin(GL_QUADS);
    glVertex2f(26.0f, 35.0f);
    glVertex2f(35.0f, 35.0f);
    glVertex2f(35.0f, 57.0f);
    glVertex2f(26.0f, 57.0f);
    glEnd();

    // Rooftop ledge
    glColor3f(0.27f, 0.29f, 0.38f);

    glBegin(GL_QUADS);
    glVertex2f(25.5f, 57.0f);
    glVertex2f(35.5f, 57.0f);
    glVertex2f(35.5f, 58.0f);
    glVertex2f(25.5f, 58.0f);
    glEnd();

    if (timeMode == 3 && lightsOn)
        glColor3f(1.0f, 0.85f, 0.20f);
    else
        glColor3f(0.55f, 0.80f, 0.95f);

    glBegin(GL_QUADS);
    glVertex2f(28.0f, 39.0f);
    glVertex2f(30.0f, 39.0f);
    glVertex2f(30.0f, 41.5f);
    glVertex2f(28.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(32.0f, 39.0f);
    glVertex2f(34.0f, 39.0f);
    glVertex2f(34.0f, 41.5f);
    glVertex2f(32.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(28.0f, 44.0f);
    glVertex2f(30.0f, 44.0f);
    glVertex2f(30.0f, 46.5f);
    glVertex2f(28.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(32.0f, 44.0f);
    glVertex2f(34.0f, 44.0f);
    glVertex2f(34.0f, 46.5f);
    glVertex2f(32.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(28.0f, 49.0f);
    glVertex2f(30.0f, 49.0f);
    glVertex2f(30.0f, 51.5f);
    glVertex2f(28.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(32.0f, 49.0f);
    glVertex2f(34.0f, 49.0f);
    glVertex2f(34.0f, 51.5f);
    glVertex2f(32.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(28.0f, 54.0f);
    glVertex2f(30.0f, 54.0f);
    glVertex2f(30.0f, 56.5f);
    glVertex2f(28.0f, 56.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(32.0f, 54.0f);
    glVertex2f(34.0f, 54.0f);
    glVertex2f(34.0f, 56.5f);
    glVertex2f(32.0f, 56.5f);
    glEnd();
}

// Building 4

void drawBuilding4()
{
    // Object ID: OBJ-10

    glColor3f(0.20f, 0.32f, 0.50f);

    // Main building
    glBegin(GL_QUADS);
    glVertex2f(38.0f, 35.0f);
    glVertex2f(48.0f, 35.0f);
    glVertex2f(48.0f, 75.0f);
    glVertex2f(38.0f, 75.0f);
    glEnd();

    // Rooftop ledge
    glColor3f(0.14f, 0.22f, 0.35f);

    glBegin(GL_QUADS);
    glVertex2f(37.5f, 75.0f);
    glVertex2f(48.5f, 75.0f);
    glVertex2f(48.5f, 76.0f);
    glVertex2f(37.5f, 76.0f);
    glEnd();

    if (timeMode == 3 && lightsOn)
        glColor3f(1.0f, 0.85f, 0.20f);
    else
        glColor3f(0.55f, 0.80f, 0.95f);

    glBegin(GL_QUADS);
    glVertex2f(40.0f, 39.0f);
    glVertex2f(42.0f, 39.0f);
    glVertex2f(42.0f, 41.5f);
    glVertex2f(40.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(44.0f, 39.0f);
    glVertex2f(46.0f, 39.0f);
    glVertex2f(46.0f, 41.5f);
    glVertex2f(44.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(40.0f, 44.0f);
    glVertex2f(42.0f, 44.0f);
    glVertex2f(42.0f, 46.5f);
    glVertex2f(40.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(44.0f, 44.0f);
    glVertex2f(46.0f, 44.0f);
    glVertex2f(46.0f, 46.5f);
    glVertex2f(44.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(40.0f, 49.0f);
    glVertex2f(42.0f, 49.0f);
    glVertex2f(42.0f, 51.5f);
    glVertex2f(40.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(44.0f, 49.0f);
    glVertex2f(46.0f, 49.0f);
    glVertex2f(46.0f, 51.5f);
    glVertex2f(44.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(40.0f, 54.0f);
    glVertex2f(42.0f, 54.0f);
    glVertex2f(42.0f, 56.5f);
    glVertex2f(40.0f, 56.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(44.0f, 54.0f);
    glVertex2f(46.0f, 54.0f);
    glVertex2f(46.0f, 56.5f);
    glVertex2f(44.0f, 56.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(40.0f, 59.0f);
    glVertex2f(42.0f, 59.0f);
    glVertex2f(42.0f, 61.5f);
    glVertex2f(40.0f, 61.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(44.0f, 59.0f);
    glVertex2f(46.0f, 59.0f);
    glVertex2f(46.0f, 61.5f);
    glVertex2f(44.0f, 61.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(40.0f, 64.0f);
    glVertex2f(42.0f, 64.0f);
    glVertex2f(42.0f, 66.5f);
    glVertex2f(40.0f, 66.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(44.0f, 64.0f);
    glVertex2f(46.0f, 64.0f);
    glVertex2f(46.0f, 66.5f);
    glVertex2f(44.0f, 66.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(40.0f, 69.0f);
    glVertex2f(42.0f, 69.0f);
    glVertex2f(42.0f, 71.5f);
    glVertex2f(40.0f, 71.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(44.0f, 69.0f);
    glVertex2f(46.0f, 69.0f);
    glVertex2f(46.0f, 71.5f);
    glVertex2f(44.0f, 71.5f);
    glEnd();
}

// Building 5

void drawBuilding5()
{
    // Object ID: OBJ-11

    glColor3f(0.30f, 0.47f, 0.58f);

    // Main building
    glBegin(GL_QUADS);
    glVertex2f(51.0f, 35.0f);
    glVertex2f(62.0f, 35.0f);
    glVertex2f(62.0f, 68.0f);
    glVertex2f(51.0f, 68.0f);
    glEnd();

    // Rooftop ledge
    glColor3f(0.21f, 0.33f, 0.40f);

    glBegin(GL_QUADS);
    glVertex2f(50.5f, 68.0f);
    glVertex2f(62.5f, 68.0f);
    glVertex2f(62.5f, 69.0f);
    glVertex2f(50.5f, 69.0f);
    glEnd();

    if (timeMode == 3 && lightsOn)
        glColor3f(1.0f, 0.85f, 0.20f);
    else
        glColor3f(0.55f, 0.80f, 0.95f);

    glBegin(GL_QUADS);
    glVertex2f(53.0f, 39.0f);
    glVertex2f(55.0f, 39.0f);
    glVertex2f(55.0f, 41.5f);
    glVertex2f(53.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(57.0f, 39.0f);
    glVertex2f(59.0f, 39.0f);
    glVertex2f(59.0f, 41.5f);
    glVertex2f(57.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(53.0f, 44.0f);
    glVertex2f(55.0f, 44.0f);
    glVertex2f(55.0f, 46.5f);
    glVertex2f(53.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(57.0f, 44.0f);
    glVertex2f(59.0f, 44.0f);
    glVertex2f(59.0f, 46.5f);
    glVertex2f(57.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(53.0f, 49.0f);
    glVertex2f(55.0f, 49.0f);
    glVertex2f(55.0f, 51.5f);
    glVertex2f(53.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(57.0f, 49.0f);
    glVertex2f(59.0f, 49.0f);
    glVertex2f(59.0f, 51.5f);
    glVertex2f(57.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(53.0f, 54.0f);
    glVertex2f(55.0f, 54.0f);
    glVertex2f(55.0f, 56.5f);
    glVertex2f(53.0f, 56.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(57.0f, 54.0f);
    glVertex2f(59.0f, 54.0f);
    glVertex2f(59.0f, 56.5f);
    glVertex2f(57.0f, 56.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(53.0f, 59.0f);
    glVertex2f(55.0f, 59.0f);
    glVertex2f(55.0f, 61.5f);
    glVertex2f(53.0f, 61.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(57.0f, 59.0f);
    glVertex2f(59.0f, 59.0f);
    glVertex2f(59.0f, 61.5f);
    glVertex2f(57.0f, 61.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(53.0f, 64.0f);
    glVertex2f(55.0f, 64.0f);
    glVertex2f(55.0f, 66.5f);
    glVertex2f(53.0f, 66.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(57.0f, 64.0f);
    glVertex2f(59.0f, 64.0f);
    glVertex2f(59.0f, 66.5f);
    glVertex2f(57.0f, 66.5f);
    glEnd();
}

// Building 6

void drawBuilding6()
{
    // Object ID: OBJ-12

    glColor3f(0.43f, 0.36f, 0.52f);

    // Main building
    glBegin(GL_QUADS);
    glVertex2f(65.0f, 35.0f);
    glVertex2f(76.0f, 35.0f);
    glVertex2f(76.0f, 62.0f);
    glVertex2f(65.0f, 62.0f);
    glEnd();

    // Rooftop ledge
    glColor3f(0.30f, 0.25f, 0.36f);

    glBegin(GL_QUADS);
    glVertex2f(64.5f, 62.0f);
    glVertex2f(76.5f, 62.0f);
    glVertex2f(76.5f, 63.0f);
    glVertex2f(64.5f, 63.0f);
    glEnd();

    if (timeMode == 3 && lightsOn)
        glColor3f(1.0f, 0.85f, 0.20f);
    else
        glColor3f(0.55f, 0.80f, 0.95f);

    glBegin(GL_QUADS);
    glVertex2f(67.0f, 39.0f);
    glVertex2f(69.0f, 39.0f);
    glVertex2f(69.0f, 41.5f);
    glVertex2f(67.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(71.0f, 39.0f);
    glVertex2f(73.0f, 39.0f);
    glVertex2f(73.0f, 41.5f);
    glVertex2f(71.0f, 41.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(67.0f, 44.0f);
    glVertex2f(69.0f, 44.0f);
    glVertex2f(69.0f, 46.5f);
    glVertex2f(67.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(71.0f, 44.0f);
    glVertex2f(73.0f, 44.0f);
    glVertex2f(73.0f, 46.5f);
    glVertex2f(71.0f, 46.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(67.0f, 49.0f);
    glVertex2f(69.0f, 49.0f);
    glVertex2f(69.0f, 51.5f);
    glVertex2f(67.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(71.0f, 49.0f);
    glVertex2f(73.0f, 49.0f);
    glVertex2f(73.0f, 51.5f);
    glVertex2f(71.0f, 51.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(67.0f, 54.0f);
    glVertex2f(69.0f, 54.0f);
    glVertex2f(69.0f, 56.5f);
    glVertex2f(67.0f, 56.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(71.0f, 54.0f);
    glVertex2f(73.0f, 54.0f);
    glVertex2f(73.0f, 56.5f);
    glVertex2f(71.0f, 56.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(67.0f, 59.0f);
    glVertex2f(69.0f, 59.0f);
    glVertex2f(69.0f, 61.5f);
    glVertex2f(67.0f, 61.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(71.0f, 59.0f);
    glVertex2f(73.0f, 59.0f);
    glVertex2f(73.0f, 61.5f);
    glVertex2f(71.0f, 61.5f);
    glEnd();
}

// Skyline

void drawSkyline()
{
    drawBuilding1();
    drawBuilding2();
    drawBuilding3();
    drawBuilding4();
    drawBuilding5();
    drawBuilding6();
}

// Road

void drawRoad()
{
    // Object ID: OBJ-14

    // Grass
    glColor3f(0.20f, 0.48f, 0.20f);
    rectangle(0.0f, 0.0f, 100.0f, 35.0f);

    // Road
    glColor3f(0.12f, 0.12f, 0.14f);
    rectangle(0.0f, 10.0f, 100.0f, 30.0f);

    // Lane lines
    glColor3f(1.0f, 0.85f, 0.10f);
    rectangle(0.0f, 19.4f, 100.0f, 19.8f);
    rectangle(0.0f, 20.4f, 100.0f, 20.8f);
}

// Car

void drawCar(float x, float y, float r, float g, float b, bool facingRight)
{
    // Object ID: OBJ-22 / OBJ-23 / OBJ-25

    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    if (!facingRight)
        glScalef(-1.0f, 1.0f, 1.0f);

    // Car body
    glColor3f(r, g, b);

    glBegin(GL_QUADS);
    glVertex2f(-5.0f, -2.0f);
    glVertex2f(5.0f, -2.0f);
    glVertex2f(5.0f, 1.0f);
    glVertex2f(-5.0f, 1.0f);
    glEnd();

    // Car roof
    glBegin(GL_POLYGON);
    glVertex2f(-3.5f, 1.0f);
    glVertex2f(-2.0f, 4.0f);
    glVertex2f(2.5f, 4.0f);
    glVertex2f(4.0f, 1.0f);
    glEnd();

    // Left window
    glColor3f(0.60f, 0.85f, 0.95f);

    glBegin(GL_QUADS);
    glVertex2f(-1.8f, 1.2f);
    glVertex2f(-0.3f, 1.2f);
    glVertex2f(-0.6f, 3.2f);
    glVertex2f(-1.5f, 3.2f);
    glEnd();

    // Right window
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 1.2f);
    glVertex2f(2.5f, 1.2f);
    glVertex2f(2.0f, 3.2f);
    glVertex2f(0.2f, 3.2f);
    glEnd();

    // Tires
    glColor3f(0.02f, 0.02f, 0.02f);
    circle(-3.0f, -2.0f, 1.5f);
    circle(3.0f, -2.0f, 1.5f);

    // Tire centers
    glColor3f(0.55f, 0.55f, 0.55f);
    circle(-3.0f, -2.0f, 0.6f);
    circle(3.0f, -2.0f, 0.6f);

    if (timeMode == 3 && lightsOn)
    {
        glColor3f(1.0f, 1.0f, 0.60f);
        circle(4.8f, 0.0f, 0.35f);
    }

    if (timeMode == 3 && lightsOn)
    {
        glColor3f(1.0f, 1.0f, 0.60f);
        circle(5.0f, 0.5f, 0.4f);
    }
    else
    {
        glColor3f(1.0f, 1.0f, 0.9f);
        circle(5.0f, 0.5f, 0.4f);

        glColor3f(1.0f, 0.2f, 0.2f);
        circle(-5.0f, 0.5f, 0.3f);
    }

    glPopMatrix();
}

// Bus

void drawBus(float x, float y, bool facingRight)
{
    // Object ID: OBJ-24

    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    if (!facingRight)
        glScalef(-1.0f, 1.0f, 1.0f);

    // Bus body
    glColor3f(0.90f, 0.52f, 0.05f);

    glBegin(GL_QUADS);
    glVertex2f(-8.0f, -3.0f);
    glVertex2f(8.0f, -3.0f);
    glVertex2f(8.0f, 4.0f);
    glVertex2f(-8.0f, 4.0f);
    glEnd();

    // Upper strip
    glColor3f(0.70f, 0.25f, 0.04f);

    glBegin(GL_QUADS);
    glVertex2f(-8.0f, 4.0f);
    glVertex2f(7.0f, 4.0f);
    glVertex2f(7.0f, 4.8f);
    glVertex2f(-8.0f, 4.8f);
    glEnd();

    // Bus window 1
    glColor3f(0.45f, 0.65f, 0.90f);

    glBegin(GL_QUADS);
    glVertex2f(-6.5f, 0.0f);
    glVertex2f(-4.5f, 0.0f);
    glVertex2f(-4.5f, 3.0f);
    glVertex2f(-6.5f, 3.0f);
    glEnd();

    // Bus window 2
    glBegin(GL_QUADS);
    glVertex2f(-3.5f, 0.0f);
    glVertex2f(-1.5f, 0.0f);
    glVertex2f(-1.5f, 3.0f);
    glVertex2f(-3.5f, 3.0f);
    glEnd();

    // Bus window 3
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(1.5f, 0.0f);
    glVertex2f(1.5f, 3.0f);
    glVertex2f(-0.5f, 3.0f);
    glEnd();

    // Bus window 4
    glBegin(GL_QUADS);
    glVertex2f(2.5f, 0.0f);
    glVertex2f(4.5f, 0.0f);
    glVertex2f(4.5f, 3.0f);
    glVertex2f(2.5f, 3.0f);
    glEnd();

    // Front section
    glColor3f(0.15f, 0.17f, 0.20f);

    glBegin(GL_QUADS);
    glVertex2f(5.0f, -1.0f);
    glVertex2f(7.0f, -1.0f);
    glVertex2f(7.0f, 3.5f);
    glVertex2f(5.0f, 3.5f);
    glEnd();

    // Wheels
    glColor3f(0.02f, 0.02f, 0.02f);
    circle(-5.0f, -3.0f, 1.7f);
    circle(5.0f, -3.0f, 1.7f);

    glColor3f(0.60f, 0.60f, 0.60f);
    circle(-5.0f, -3.0f, 0.7f);
    circle(5.0f, -3.0f, 0.7f);

    if (timeMode == 3 && lightsOn)
    {
        glColor3f(1.0f, 1.0f, 0.60f);
        circle(8.0f, 0.0f, 0.4f);
    }

    glPopMatrix();
}

// Trees

void drawTree(float x, float y)
{
    // Object ID: OBJ-15 / OBJ-16 / OBJ-17

    // Tree trunk
    glColor3f(0.38f, 0.20f, 0.08f);
    rectangle(x - 1.0f, y, x + 1.0f, y + 8.0f);

    // Leaves
    glColor3f(0.03f, 0.45f, 0.12f);
    circle(x, y + 11.0f, 4.0f);
    circle(x - 3.0f, y + 9.0f, 3.0f);
    circle(x + 3.0f, y + 9.0f, 3.0f);
    circle(x, y + 14.0f, 3.5f);
}

// Street Lamps

void drawStreetLamp(float x, float y)
{
    // Object ID: OBJ-18 / OBJ-19 / OBJ-20 / OBJ-21

    glColor3f(0.10f, 0.10f, 0.10f);

    glLineWidth(3.0f);

    line(x, y, x, y + 16.0f);
    line(x, y + 16.0f, x + 4.0f, y + 16.0f);

    if (timeMode == 3 && lightsOn)
        glColor3f(1.0f, 0.85f, 0.15f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    circle(x + 4.0f, y + 15.5f, 1.2f);

    if (timeMode == 3 && lightsOn)
    {
        glColor3f(1.0f, 0.70f, 0.15f);
        circle(x + 4.0f, y + 14.0f, 2.0f);
    }
}

// Shopping Mall

void drawShoppingMall()
{
    // Object ID: OBJ-13

    // Main building
    glColor3f(0.65f, 0.22f, 0.16f);
    rectangle(72.0f, 35.0f, 97.0f, 53.0f);

    // Glass front
    glColor3f(0.25f, 0.65f, 0.75f);
    rectangle(74.0f, 36.0f, 95.0f, 48.0f);

    // Door
    glColor3f(0.10f, 0.12f, 0.16f);
    rectangle(82.0f, 35.0f, 88.0f, 44.0f);

    // Roof
    glColor3f(0.85f, 0.40f, 0.08f);
    rectangle(70.5f, 53.0f, 98.5f, 55.0f);

    // Sign
    if (lightsOn)
        glColor3f(1.0f, 0.80f, 0.05f);
    else
        glColor3f(0.35f, 0.25f, 0.03f);

    rectangle(77.0f, 49.0f, 92.0f, 52.0f);

    // Sign blocks
    glColor3f(0.90f, 0.10f, 0.10f);

    rectangle(79.0f, 49.5f, 80.0f, 51.5f);
    rectangle(81.0f, 49.5f, 82.0f, 51.5f);
    rectangle(83.0f, 49.5f, 84.0f, 51.5f);
    rectangle(85.0f, 49.5f, 86.0f, 51.5f);
    rectangle(87.0f, 49.5f, 88.0f, 51.5f);
    rectangle(89.0f, 49.5f, 90.0f, 51.5f);

    // Mall windows
    glColor3f(0.95f, 0.95f, 0.70f);

    rectangle(75.0f, 45.0f, 76.5f, 47.0f);
    rectangle(78.0f, 45.0f, 79.5f, 47.0f);
    rectangle(81.0f, 45.0f, 82.5f, 47.0f);
    rectangle(84.0f, 45.0f, 85.5f, 47.0f);
    rectangle(87.0f, 45.0f, 88.5f, 47.0f);
    rectangle(90.0f, 45.0f, 91.5f, 47.0f);
}

// Display Function

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawSky();

    drawCloud(cloud1, 84.0f);
    drawCloud(cloud2, 91.0f);
    drawCloud(cloud3, 78.0f);

    drawSkyline();
    drawShoppingMall();
    drawRoad();

    drawTree(tree1, 30.0f);
    drawTree(tree2, 30.0f);
    drawTree(tree3, 30.0f);

    drawStreetLamp(lamppost1, 30.0f);
    drawStreetLamp(lamppost2, 30.0f);
    drawStreetLamp(lamppost3, 30.0f);
    drawStreetLamp(lamppost4, 30.0f);

    drawCar(car, 16.5f, 0.85f, 0.20f, 0.20f, true);
    drawCar(car1, 28.0f, 0.10f, 0.35f, 0.85f, false);
    drawBus(bus1, 28.0f, false);
    drawCar(car2, 25.8f, 0.90f, 0.55f, 0.05f, false);

    glColor3f(1.0f, 1.0f, 1.0f);

    drawText(2.0f, 96.0f, "SCENE 3 - TWO WAY CITY ROAD");
    drawText(2.0f, 2.0f, "Mouse: Animation | L: Move | K: Stop | A/S/D/F: Time | N: Lights");

    glutSwapBuffers();
}

// Animation & Update

void update(int value)
{
    // Animation Function ID: ANIM-01

    if (allAnimation)
    {
        if (vehicleMoving)
        {
            // ANIM-04: Vehicle movement

            car += 0.45f;

            if (car > 115.0f)
                car = -30.0f;

            car1 -= 0.45f;

            if (car1 < -80.0f)
                car1 = 110.0f;

            bus1 -= 0.45f;

            if (bus1 < -80.0f)
                bus1 = 140.0f;

            car2 -= 0.45f;

            if (car2 < -80.0f)
                car2 = 172.0f;
        }

        // ANIM-05: Cloud movement

        cloud1 += 0.07f;
        cloud2 += 0.06f;
        cloud3 += 0.10f;

        if (cloud1 > 110.0f)
            cloud1 = -15.0f;

        if (cloud2 > 110.0f)
            cloud2 = -15.0f;

        if (cloud3 > 110.0f)
            cloud3 = -15.0f;

        // ANIM-06: Traffic state cycle

        static int counter = 0;

        counter++;

        if (counter >= 100)
        {
            trafficState++;

            if (trafficState > 2)
                trafficState = 0;

            counter = 0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

// Keyboard

void keyboard(unsigned char key, int x, int y)
{
    // Animation Function ID: ANIM-02

    if (key >= 'A' && key <= 'Z')
        key = key + ('a' - 'A');

    switch (key)
    {
        case 'l':
            vehicleMoving = true;
            break;

        case 'k':
            vehicleMoving = false;
            break;

        case 'a':
            timeMode = 0;
            break;

        case 's':
            timeMode = 1;
            break;

        case 'd':
            timeMode = 2;
            break;

        case 'f':
            timeMode = 3;
            break;

        case 'n':
            lightsOn = !lightsOn;
            break;

        case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}

// Mouse

void mouse(int button, int state, int x, int y)
{
    // Animation Function ID: ANIM-03

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        allAnimation = !allAnimation;
    }

    glutPostRedisplay();
}

// Window Reshape

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0f, 100.0f, 0.0f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Initialization

void init()
{
    glClearColor(0.35f, 0.72f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0f, 100.0f, 0.0f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Main Function

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1100, 700);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Scene 3 - Two Way City Road");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(30, update, 0);

    glutMainLoop();
    return 0;
}
