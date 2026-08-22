#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1416

// =====================================================
//                 GLOBAL VARIABLES
// =====================================================

float myCartMove = 61.0f;
float boatMove = 43.0f;
int boatDirection = 1;

float cloudMove = 0.0f;
float myWheelAngle = 0.0f;

int animationOn = 1;
int vehicleOn = 1;
int boatSailing = 0;

int lightsOn = 1;

// 0 = Dawn, 1 = Day, 2 = Evening, 3 = Night
int timeMode = 1;


// =====================================================
//                  RECTANGLE FUNCTION
// =====================================================

void rect(float x1,float y1,float x2,float y2,
          float r,float g,float b)
{
    glColor3f(r,g,b);

    glBegin(GL_POLYGON);

    glVertex2f(x1,y1);
    glVertex2f(x2,y1);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);

    glEnd();
}


// =====================================================
//                   CIRCLE FUNCTION
// =====================================================

void circle(float radius)
{
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0.0f,0.0f);

    for(int i = 0;i <= 360;i++)
    {
        float angle = i * PI / 180.0f;

        glVertex2f(
            radius * cos(angle),
            radius * sin(angle)
        );
    }

    glEnd();
}


// =====================================================
//                   TRIANGLE FUNCTION
// =====================================================

void triangle(float x1,float y1,
              float x2,float y2,
              float x3,float y3,
              float r,float g,float b)
{
    glColor3f(r,g,b);

    glBegin(GL_POLYGON);

    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);

    glEnd();
}


// =====================================================
//                     QUAD FUNCTION
// =====================================================

void quad(float x1,float y1,
          float x2,float y2,
          float x3,float y3,
          float x4,float y4,
          float r,float g,float b)
{
    glColor3f(r,g,b);

    glBegin(GL_POLYGON);

    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);

    glEnd();
}


// =====================================================
//                  HOUSE WINDOW
// =====================================================

void windowGlow(float x1,float y1,float x2,float y2)
{
    if(timeMode == 3 && lightsOn == 1)
        rect(x1,y1,x2,y2,1.0f,0.82f,0.25f);
    else
        rect(x1,y1,x2,y2,0.18f,0.13f,0.08f);
}


// =====================================================
//                         SUN
// =====================================================

void sun()
{
    if(timeMode == 3)
        return;

    glPushMatrix();

    if(timeMode == 0)
    {
        glTranslatef(25.0f,88.0f,0.0f);
        glColor3f(1.0f,0.45f,0.12f);
    }
    else if(timeMode == 1)
    {
        glTranslatef(53.2f,88.0f,0.0f);
        glColor3f(1.0f,0.80f,0.05f);
    }
    else
    {
        glTranslatef(80.0f,78.0f,0.0f);
        glColor3f(1.0f,0.35f,0.05f);
    }

    circle(4.0f);

    glPopMatrix();
}


// =====================================================
//                         CLOUD
// =====================================================

void cloud(float x,float y,float scale)
{
    if(timeMode == 3)
        return;

    glColor3f(1.0f,1.0f,1.0f);

    glPushMatrix();

    glTranslatef(x,y,0.0f);
    glScalef(scale,scale,1.0f);

    circle(3.0f);

    glTranslatef(3.0f,1.7f,0.0f);
    circle(4.0f);

    glTranslatef(3.0f,-1.7f,0.0f);
    circle(3.0f);

    glPopMatrix();
}


// =====================================================
//                       MOUNTAINS
// =====================================================

void mountains()
{
    // Large right mountain
    triangle(
        72.0f,64.0f,
        98.5f,64.0f,
        83.5f,86.0f,
        0.27f,0.46f,0.19f
    );

    // Smaller front mountain
    triangle(
        65.0f,64.0f,
        82.0f,64.0f,
        75.0f,77.5f,
        0.39f,0.58f,0.25f
    );
}


// =====================================================
//                          FIELD
// =====================================================

void field()
{
    rect(
        0.0f,0.0f,
        100.0f,64.0f,
        0.43f,0.68f,0.23f
    );
}


// =====================================================
//                    ROAD CENTRE LINE
// =====================================================

float roadY(float x)
{
    return 31.0f + (62.0f - 31.0f) * (x / 100.0f);
}


// =====================================================
//                         RIVER
// =====================================================

void river()
{
    glColor3f(0.10f,0.61f,0.83f);

    glBegin(GL_POLYGON);

    // Upper edge
    glVertex2f(0.0f,24.7f);
    glVertex2f(34.0f,30.0f);
    glVertex2f(63.0f,35.0f);
    glVertex2f(100.0f,41.0f);

    // Right lower edge
    glVertex2f(100.0f,18.0f);

    // Bottom edge
    glVertex2f(0.0f,2.2f);

    glEnd();

    // Water ripples
    glColor3f(0.38f,0.78f,0.92f);

    glLineWidth(1.3f);

    glBegin(GL_LINES);

    glVertex2f(4.0f,17.0f);
    glVertex2f(10.0f,17.0f);

    glVertex2f(8.0f,8.0f);
    glVertex2f(14.0f,8.0f);

    glVertex2f(31.0f,12.5f);
    glVertex2f(37.0f,12.5f);

    glVertex2f(55.0f,20.8f);
    glVertex2f(61.0f,20.8f);

    glVertex2f(75.0f,25.0f);
    glVertex2f(82.0f,25.0f);

    glVertex2f(91.0f,34.0f);
    glVertex2f(98.0f,34.0f);

    glEnd();
}


// =====================================================
//                         ROAD
// =====================================================

void road()
{
    // Main road
    quad(
        0.0f,27.0f,
        100.0f,56.0f,
        100.0f,63.2f,
        0.0f,34.2f,
        0.25f,0.25f,0.27f
    );

    // Road edge lines
    glColor3f(0.12f,0.12f,0.12f);

    glLineWidth(1.5f);

    glBegin(GL_LINES);

    glVertex2f(0.0f,27.0f);
    glVertex2f(100.0f,56.0f);

    glVertex2f(0.0f,34.2f);
    glVertex2f(100.0f,63.2f);

    glEnd();

    // Dashed white centre line
    glColor3f(0.96f,0.96f,0.96f);

    glLineWidth(2.2f);

    for(float x = 2.0f;x < 100.0f;x += 7.0f)
    {
        float y = 30.6f + (x / 100.0f) * 29.0f;

        glBegin(GL_LINES);

        glVertex2f(x,y);
        glVertex2f(x + 3.5f,y + 1.0f);

        glEnd();
    }
}


// =====================================================
//                       FENCE LINE
// =====================================================

void fenceLine(float x1,float y1,
               float x2,float y2,
               int posts)
{
    glColor3f(0.42f,0.25f,0.12f);

    glLineWidth(1.7f);

    // Main upper rail
    glBegin(GL_LINES);

    glVertex2f(x1,y1);
    glVertex2f(x2,y2);

    glEnd();

    // Lower rail
    glBegin(GL_LINES);

    glVertex2f(x1,y1 - 2.0f);
    glVertex2f(x2,y2 - 2.0f);

    glEnd();

    // Vertical posts
    for(int i = 0;i <= posts;i++)
    {
        float t = (float)i / posts;

        float px = x1 + (x2-x1)*t;
        float py = y1 + (y2-y1)*t;

        glBegin(GL_LINES);

        glVertex2f(px,py-2.8f);
        glVertex2f(px,py+0.8f);

        glEnd();
    }
}


// =====================================================
//                         TREE
// =====================================================

void tree(float x,float y,float scale)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);
    glScalef(scale,scale,1.0f);

    // Trunk
    rect(
        -0.55f,0.0f,
        0.55f,5.0f,
        0.34f,0.21f,0.09f
    );

    // Lower leaves
    triangle(
        -3.7f,3.5f,
        3.7f,3.5f,
        0.0f,10.5f,
        0.15f,0.34f,0.06f
    );

    // Upper leaves
    triangle(
        -2.8f,8.0f,
        2.8f,8.0f,
        0.0f,14.0f,
        0.21f,0.43f,0.08f
    );

    glPopMatrix();
}


// =====================================================
//                         BUSH
// =====================================================

void bush(float x,float y,float scale)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);
    glScalef(scale,scale,1.0f);

    glColor3f(0.14f,0.34f,0.06f);

    glPushMatrix();
    glTranslatef(-1.5f,0.0f,0.0f);
    circle(1.5f);
    glPopMatrix();

    glColor3f(0.20f,0.43f,0.07f);

    glPushMatrix();
    glTranslatef(0.0f,0.8f,0.0f);
    circle(2.0f);
    glPopMatrix();

    glColor3f(0.14f,0.34f,0.06f);

    glPushMatrix();
    glTranslatef(1.7f,0.0f,0.0f);
    circle(1.5f);
    glPopMatrix();

    glPopMatrix();
}


// =====================================================
//                         HOUSE
// =====================================================

void house(float x,float y,float scale,
           float wallR,float wallG,float wallB,
           float roofR,float roofG,float roofB)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);
    glScalef(scale,scale,1.0f);

    // Main body
    rect(
        -7.0f,0.0f,
        7.0f,12.0f,
        wallR,wallG,wallB
    );

    // Roof
    triangle(
        -7.8f,12.0f,
        7.8f,12.0f,
        0.0f,18.5f,
        roofR,roofG,roofB
    );

    // Door
    rect(
        1.0f,0.0f,
        4.2f,6.2f,
        0.23f,0.15f,0.07f
    );

    // Window
    windowGlow(
        -4.8f,4.0f,
        -1.3f,7.5f
    );

    // Window frame
    glColor3f(0.10f,0.08f,0.04f);

    glLineWidth(1.2f);

    glBegin(GL_LINES);

    glVertex2f(-3.05f,4.0f);
    glVertex2f(-3.05f,7.5f);

    glVertex2f(-4.8f,5.75f);
    glVertex2f(-1.3f,5.75f);

    glEnd();

    glPopMatrix();
}


// =====================================================
//                     SMALL HOUSE
// =====================================================

void smallHouse(float x,float y,float scale,
                float wallR,float wallG,float wallB,
                float roofR,float roofG,float roofB)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);
    glScalef(scale,scale,1.0f);

    rect(
        -5.5f,0.0f,
        5.5f,9.5f,
        wallR,wallG,wallB
    );

    triangle(
        -6.0f,9.5f,
        6.0f,9.5f,
        0.0f,14.5f,
        roofR,roofG,roofB
    );

    rect(
        0.5f,0.0f,
        3.0f,5.0f,
        0.23f,0.15f,0.07f
    );

    rect(
        -4.0f,3.8f,
        -1.3f,6.3f,
        0.18f,0.13f,0.08f
    );

    glPopMatrix();
}


// =====================================================
//                    MARKET STALL
// =====================================================

void marketStall(float x,float y,
                 float r,float g,float b)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);

    // Table legs
    glColor3f(0.25f,0.14f,0.06f);

    glLineWidth(2.0f);

    glBegin(GL_LINES);

    glVertex2f(-4.5f,0.0f);
    glVertex2f(-4.5f,4.0f);

    glVertex2f(4.5f,0.0f);
    glVertex2f(4.5f,4.0f);

    glEnd();

    // Table
    rect(
        -5.0f,4.0f,
        5.0f,5.5f,
        0.45f,0.25f,0.10f
    );

    // Goods
    rect(
        -4.3f,5.5f,
        4.3f,6.5f,
        0.58f,0.34f,0.12f
    );

    // Awning
    rect(
        -5.2f,6.5f,
        5.2f,7.8f,
        r,g,b
    );

    // White stripes
    for(float i = -4.8f;i < 4.8f;i += 2.0f)
    {
        rect(
            i,6.5f,
            i+1.0f,7.8f,
            0.95f,0.93f,0.84f
        );
    }

    glPopMatrix();
}


// =====================================================
//                       VILLAGER
// =====================================================

void villager(float x,float y,
              float shirtR,float shirtG,float shirtB)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);

    // Head
    glColor3f(0.76f,0.50f,0.28f);
    circle(0.9f);

    // Body
    rect(
        -0.8f,-2.4f,
        0.8f,-0.2f,
        shirtR,shirtG,shirtB
    );

    // Legs
    glColor3f(0.10f,0.08f,0.05f);

    glLineWidth(1.5f);

    glBegin(GL_LINES);

    glVertex2f(-0.4f,-2.4f);
    glVertex2f(-0.8f,-4.0f);

    glVertex2f(0.4f,-2.4f);
    glVertex2f(0.8f,-4.0f);

    glEnd();

    // Arms
    glBegin(GL_LINES);

    glVertex2f(-0.7f,-0.7f);
    glVertex2f(-1.4f,-2.0f);

    glVertex2f(0.7f,-0.7f);
    glVertex2f(1.4f,-2.0f);

    glEnd();

    glPopMatrix();
}


// =====================================================
//                    PARKED CAR
// =====================================================

void parkedCar(float x,float y)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);

    // Main body
    rect(
        -5.5f,0.0f,
        5.5f,2.8f,
        0.17f,0.32f,0.63f
    );

    // Top cabin
    quad(
        -3.7f,2.8f,
        3.2f,2.8f,
        2.0f,5.0f,
        -2.3f,5.0f,
        0.17f,0.32f,0.63f
    );

    // Windows
    quad(
        -2.0f,3.1f,
        -0.1f,3.1f,
        -0.1f,4.5f,
        -1.5f,4.5f,
        0.30f,0.47f,0.70f
    );

    quad(
        0.2f,3.1f,
        2.5f,3.1f,
        1.8f,4.5f,
        0.2f,4.5f,
        0.30f,0.47f,0.70f
    );

    // Wheels
    glColor3f(0.08f,0.08f,0.08f);

    glPushMatrix();
    glTranslatef(-3.4f,0.0f,0.0f);
    circle(1.25f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.4f,0.0f,0.0f);
    circle(1.25f);
    glPopMatrix();

    glPopMatrix();
}


// =====================================================
//                  BULLOCK CART WHEEL
// =====================================================

void cartWheel(float x,float y,float angle)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);
    glRotatef(angle,0,0,1);

    glColor3f(0.10f,0.10f,0.10f);
    circle(1.25f);

    glColor3f(0.72f,0.72f,0.72f);

    glLineWidth(1.2f);

    glBegin(GL_LINES);

    glVertex2f(-0.9f,0.0f);
    glVertex2f(0.9f,0.0f);

    glVertex2f(0.0f,-0.9f);
    glVertex2f(0.0f,0.9f);

    glEnd();

    glPopMatrix();
}


// =====================================================
//                      BULLOCK CART
// =====================================================

void bullockCart(float x,float y,float angle)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);

    // Cart body
    quad(
        -4.0f,1.0f,
        3.8f,1.0f,
        3.5f,4.2f,
        -3.8f,4.2f,
        0.46f,0.30f,0.14f
    );

    // Front raised portion
    quad(
        3.5f,1.0f,
        5.2f,1.5f,
        5.0f,3.6f,
        3.5f,4.2f,
        0.46f,0.30f,0.14f
    );

    // Wooden pole toward the animal
    glColor3f(0.34f,0.20f,0.08f);

    glLineWidth(2.0f);

    glBegin(GL_LINES);

    glVertex2f(5.0f,2.6f);
    glVertex2f(9.0f,3.2f);

    glEnd();

    // Wheels
    cartWheel(-2.5f,0.8f,angle);
    cartWheel(2.2f,0.8f,angle);

    glPopMatrix();
}


// =====================================================
//                         BOAT
// =====================================================

void boat(float x,float y,float scale)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);
    glScalef(scale,scale,1.0f);

    // Hull
    glColor3f(0.42f,0.25f,0.10f);

    glBegin(GL_POLYGON);

    glVertex2f(-5.0f,0.0f);
    glVertex2f(5.0f,0.0f);
    glVertex2f(3.0f,-1.7f);
    glVertex2f(-3.0f,-1.7f);

    glEnd();

    // Top edge
    glColor3f(0.18f,0.11f,0.05f);

    glLineWidth(1.5f);

    glBegin(GL_LINES);

    glVertex2f(-5.0f,0.0f);
    glVertex2f(5.0f,0.0f);

    glEnd();

    // Mast
    rect(
        -0.25f,0.0f,
        0.25f,9.0f,
        0.35f,0.21f,0.08f
    );

    // Sail
    triangle(
        0.3f,8.6f,
        0.3f,2.5f,
        7.0f,5.0f,
        0.96f,0.95f,0.90f
    );

    // Sail outline
    glColor3f(0.15f,0.15f,0.15f);

    glLineWidth(1.0f);

    glBegin(GL_LINE_LOOP);

    glVertex2f(0.3f,8.6f);
    glVertex2f(0.3f,2.5f);
    glVertex2f(7.0f,5.0f);

    glEnd();

    glPopMatrix();
}


// =====================================================
//                       FOUNTAIN
// =====================================================

void fountain(float x,float y)
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);

    // Basin
    quad(
        -3.0f,0.0f,
        3.0f,0.0f,
        2.4f,2.0f,
        -2.4f,2.0f,
        0.47f,0.47f,0.43f
    );

    // Top
    rect(
        -2.2f,2.0f,
        2.2f,2.6f,
        0.55f,0.55f,0.50f
    );

    // Water
    rect(
        -1.9f,2.1f,
        1.9f,2.45f,
        0.20f,0.65f,0.82f
    );

    glPopMatrix();
}


// =====================================================
//                    VILLAGE SCENE
// =====================================================

void village()
{
    // Background
    if(timeMode == 0)
        glClearColor(0.90f,0.55f,0.42f,1.0f);
    else if(timeMode == 1)
        glClearColor(0.25f,0.58f,0.84f,1.0f);
    else if(timeMode == 2)
        glClearColor(0.78f,0.35f,0.24f,1.0f);
    else
        glClearColor(0.03f,0.05f,0.16f,1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // =================================================
    // BACKGROUND
    // =================================================

    field();

    sun();

    glPushMatrix();

    glTranslatef(cloudMove,0.0f,0.0f);

    cloud(22.0f,87.0f,0.95f);
    cloud(37.0f,78.0f,0.75f);
    cloud(64.0f,87.0f,1.0f);

    glPopMatrix();

    mountains();

    // =================================================
    // HOUSES BEHIND THE ROAD
    // =================================================

    // Left large house
    house(
        12.0f,46.0f,0.95f,
        0.90f,0.84f,0.62f,
        0.82f,0.20f,0.07f
    );

    // Middle-left house
    house(
        30.0f,55.0f,0.82f,
        0.91f,0.84f,0.62f,
        0.78f,0.22f,0.08f
    );

    // Middle house
    house(
        42.0f,56.0f,0.72f,
        0.89f,0.83f,0.62f,
        0.78f,0.22f,0.08f
    );

    // Wooden house
    smallHouse(
        60.0f,62.0f,0.75f,
        0.58f,0.36f,0.23f,
        0.25f,0.17f,0.10f
    );

    // Right middle houses
    smallHouse(
        84.0f,40.5f,0.90f,
        0.68f,0.40f,0.27f,
        0.28f,0.18f,0.10f
    );

    smallHouse(
        94.0f,42.0f,0.75f,
        0.90f,0.84f,0.62f,
        0.82f,0.20f,0.07f
    );

    // =================================================
    // TREES BEHIND ROAD
    // =================================================

    tree(4.5f,61.0f,0.90f);
    tree(20.5f,56.0f,0.85f);
    tree(36.5f,60.0f,0.90f);
    tree(67.0f,59.0f,0.90f);
    tree(73.0f,53.0f,0.75f);
    tree(93.0f,61.0f,0.90f);

    bush(54.0f,57.0f,0.85f);
    bush(75.0f,58.0f,0.70f);

    // =================================================
    // RIVER
    // =================================================

    river();

    // =================================================
    // ROAD
    // =================================================

    road();

    // Fence on upper side of road
    fenceLine(
        0.0f,35.5f,
        100.0f,64.5f,
        12
    );

    // Fence on lower side of road
    fenceLine(
        0.0f,25.8f,
        68.0f,45.5f,
        9
    );

    // =================================================
    // MARKET AREA
    // =================================================

    marketStall(
        27.0f,52.0f,
        0.78f,0.12f,0.10f
    );

    marketStall(
        35.5f,51.0f,
        0.85f,0.70f,0.18f
    );

    villager(
        34.5f,51.5f,
        0.20f,0.38f,0.64f
    );

    villager(
        38.5f,52.0f,
        0.78f,0.28f,0.25f
    );

    villager(
        30.0f,49.5f,
        0.30f,0.55f,0.35f
    );

    // =================================================
    // CAR
    // =================================================

    parkedCar(10.5f,36.0f);

    // =================================================
    // CART
    // =================================================

    bullockCart(
        myCartMove,
        roadY(myCartMove) - 8.0f,
        myWheelAngle
    );

    // =================================================
    // RIVER BOATS
    // =================================================

    boat(23.0f,15.5f,0.85f);

    boat(43.0f,27.5f,0.62f);

    boat(
        boatMove,
        24.0f + boatMove * 0.12f,
        0.82f
    );

    // =================================================
    // FOREGROUND
    // =================================================

    tree(46.0f,2.0f,0.80f);

    bush(35.0f,5.0f,0.75f);
    bush(66.0f,8.0f,0.72f);

    fountain(57.5f,3.0f);

    // Bottom-right house
    house(
        81.0f,5.0f,0.82f,
        0.91f,0.84f,0.62f,
        0.82f,0.20f,0.07f
    );

    // Bottom-right stall
    marketStall(
        93.0f,5.0f,
        0.78f,0.12f,0.10f
    );

    glutSwapBuffers();
}


// =====================================================
//                 NEXT SCENE PLACEHOLDER
// =====================================================

void nextScene()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}


// =====================================================
//                    UPDATE FUNCTION
// =====================================================

void update(int value)
{
    if(animationOn == 1)
    {
        // Clouds
        cloudMove += 0.025f;

        if(cloudMove > 15.0f)
            cloudMove = -15.0f;

        // Bullock cart
        if(vehicleOn == 1)
        {
            myCartMove += 0.10f;
            myWheelAngle -= 5.0f;

            if(myCartMove > 108.0f)
                myCartMove = -8.0f;

            if(myWheelAngle < -360.0f)
                myWheelAngle = 0.0f;
        }

        // Boat
        if(boatSailing == 1)
        {
            boatMove += 0.08f * boatDirection;

            if(boatMove > 94.0f)
                boatDirection = -1;

            if(boatMove < 6.0f)
                boatDirection = 1;
        }
    }

    glutPostRedisplay();

    glutTimerFunc(20,update,0);
}


// =====================================================
//                    MOUSE CONTROL
// =====================================================

void handleMouse(int button,int state,int x,int y)
{
    if(state == GLUT_DOWN)
    {
        // LEFT = animation pause/resume
        if(button == GLUT_LEFT_BUTTON)
        {
            if(animationOn == 1)
                animationOn = 0;
            else
                animationOn = 1;
        }

        // RIGHT = ferry on/off
        else if(button == GLUT_RIGHT_BUTTON)
        {
            if(boatSailing == 1)
                boatSailing = 0;
            else
                boatSailing = 1;
        }
    }

    glutPostRedisplay();
}


// =====================================================
//                  KEYBOARD CONTROL
// =====================================================

void handleKeypress(unsigned char key,int x,int y)
{
    switch(key)
    {
        // C = Next Scene
        case 'c':
        case 'C':

            glutDisplayFunc(nextScene);

            glutPostRedisplay();

            break;

        // 1 = Dawn
        case '1':

            timeMode = 0;

            glutDisplayFunc(village);

            glutPostRedisplay();

            break;

        // 2 = Day
        case '2':

            timeMode = 1;

            glutDisplayFunc(village);

            glutPostRedisplay();

            break;

        // 3 = Evening
        case '3':

            timeMode = 2;

            glutDisplayFunc(village);

            glutPostRedisplay();

            break;

        // 4 = Night
        case '4':

            timeMode = 3;

            glutDisplayFunc(village);

            glutPostRedisplay();

            break;

        // L = Lights
        case 'l':
        case 'L':

            if(lightsOn == 1)
                lightsOn = 0;
            else
                lightsOn = 1;

            glutPostRedisplay();

            break;
    }
}


// =====================================================
//                  ARROW KEY CONTROL
// =====================================================

void handleSpecialKey(int key,int x,int y)
{
    switch(key)
    {
        // RIGHT = cart moves
        case GLUT_KEY_RIGHT:

            vehicleOn = 1;

            break;

        // LEFT = cart stops
        case GLUT_KEY_LEFT:

            vehicleOn = 0;

            break;
    }

    glutPostRedisplay();
}


// =====================================================
//                         INIT
// =====================================================

void init()
{
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0,100,0,100);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glClearColor(0.25f,0.58f,0.84f,1.0f);
}


// =====================================================
//                         MAIN
// =====================================================

int main(int argc,char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1000,775);

    glutInitWindowPosition(100,50);

    glutCreateWindow("Scene 1 - Village");

    init();

    glutDisplayFunc(village);

    glutKeyboardFunc(handleKeypress);

    glutSpecialFunc(handleSpecialKey);

    glutMouseFunc(handleMouse);

    glutTimerFunc(20,update,0);

    glutMainLoop();

    return 0;
}
