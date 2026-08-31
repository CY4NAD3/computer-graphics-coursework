#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

#define PI 3.1416

// =====================================================
//                 GLOBAL VARIABLES
// =====================================================

float boatMove = -15.0f;      // moving boat left-to-right across the river, , starts at the left edge
float boatMove2 = 115.0f;   // second boat, travels right-to-left, starts at the right edge
float cloudMove = 0.0f;
float vehicleMove = -5.0f;    // progress of the moving car across the road
float carWheelAngle = 0.0f;   // wheel spin for the moving car

int animationOn = 1;     // Left Click toggles this, for boat left-to-right
int vehicleMoving = 1;   // Key 6/5 controls vehicle start stop
int timeMode = 2;        // D(Dawn:1), F(Day:2), E(Evening:3), N(Night:0)
int lightsOn = 0;        // 'L' toggles street lamps on/off (auto-on at night)

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

void polygon(float r, float g, float b, int n, float points[][2]){ // ref#polygon
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for(int i = 0; i < n; i++)
    {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();
}

void line2D(float x1, float y1, float x2, float y2, float r, float g, float b, float width){ // ref#line2D
    glColor3f(r, g, b);
    glLineWidth(width);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
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
//                     (SUN & MOON)
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
//                        CLOUD
// =====================================================

void cloud(float x, float y){ // ref#cloud
    glColor3f(1.0f, 1.0f, 1.0f);

    glPushMatrix();
    glTranslatef(x, y, 0);
    circle(2.8f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 3.2f, y + 1.0f, 0);
    circle(3.6f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 6.8f, y, 0);
    circle(2.8f);
    glPopMatrix();
}

// =====================================================
//                    BACKGROUND HILLS
// =====================================================

void mountain(float x1, float y1, float xPeak, float yPeak, float x2, float y2, float r, float g, float b){ // ref#mountain
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(xPeak, yPeak);
    glVertex2f(x2, y2);
    glEnd();

    glColor3f(r * 0.70f, g * 0.70f, b * 0.70f); //1.0 er niche hole dark color dei
    glBegin(GL_TRIANGLES);
    glVertex2f(xPeak, yPeak);
    glVertex2f(x2, y2);
    glVertex2f(xPeak + (x2 - xPeak) * 0.4f, y1);
    glEnd();
}

void hills(){ // ref#hills
    // Back mountain
    mountain(64, 52, 82, 88, 110, 52, 0.35f, 0.52f, 0.20f);
    // Front mountain
    mountain(57, 52, 73, 78, 88, 52, 0.43f, 0.60f, 0.24f);
}

// =====================================================
//                        TREE
// =====================================================

void treeA(float x, float y, float scale){ // ref#treeA
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    rect(-0.55f, 0.0f, 0.55f, 5.0f, 0.34f, 0.21f, 0.09f);

    triangle(-3.7f, 3.5f, 3.7f, 3.5f, 0.0f, 10.5f, 0.10f, 0.42f, 0.10f);
    triangle(-2.8f, 8.0f, 2.8f, 8.0f, 0.0f, 14.0f, 0.16f, 0.55f, 0.14f);

    glPopMatrix();
}

void treeB(float x, float y, float scale){ // ref#treeB
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    rect(-0.55f, 0.0f, 0.55f, 5.0f, 0.34f, 0.21f, 0.09f);

    triangle(-3.7f, 3.5f, 3.7f, 3.5f, 0.0f, 10.5f, 0.28f, 0.42f, 0.06f);
    triangle(-2.8f, 8.0f, 2.8f, 8.0f, 0.0f, 14.0f, 0.38f, 0.55f, 0.08f);

    glPopMatrix();
}

void treeC(float x, float y, float scale){ // ref#treeC
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    rect(-0.55f, 0.0f, 0.55f, 5.0f, 0.34f, 0.21f, 0.09f);

    triangle(-3.7f, 3.5f, 3.7f, 3.5f, 0.0f, 10.5f, 0.15f, 0.34f, 0.06f);
    triangle(-2.8f, 8.0f, 2.8f, 8.0f, 0.0f, 14.0f, 0.21f, 0.43f, 0.08f);

    glPopMatrix();
}

// =====================================================
//                        HOUSE
// =====================================================

void houseA(float x, float y, float w, float h, float bodyR, float bodyG, float bodyB, float roofR, float roofG, float roofB){ // ref#houseA
    rect(x, y, x + w, y + h, bodyR, bodyG, bodyB);

    float roof[][2] = {
        {x - 1.5f, y + h},
        {x + w * 0.25f, y + h + 8.0f},
        {x + w * 0.75f, y + h + 7.0f},
        {x + w + 1.5f, y + h}
    };
    polygon(roofR, roofG, roofB, 4, roof); //roof e pathaitesi parameter diye, okhane giye glvertex use hoye plot hoye jabe
    //angle line diye 3d effect
    line2D(x + w * 0.25f, y + h + 8.0f, x + w * 0.48f, y + h, 0.25f, 0.12f, 0.08f, 1.0f);
    //door
    rect(x + w * 0.58f, y, x + w * 0.76f, y + h * 0.48f, 0.27f, 0.15f, 0.08f);
    //door knob
    glPushMatrix();
    glTranslatef(x + w * 0.72f, y + h * 0.25f, 0.0f);
    glColor3f(0.90f, 0.78f, 0.25f);
    circle(0.22f);
    glPopMatrix();
    //window
    rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.36f, 0.24f, 0.12f);

    line2D(x + w * 0.265f, y + h * 0.38f, x + w * 0.265f, y + h * 0.62f, 0.08f, 0.08f, 0.06f, 1.0f);
    line2D(x + w * 0.16f, y + h * 0.50f, x + w * 0.37f, y + h * 0.50f, 0.08f, 0.08f, 0.06f, 1.0f);
}

void houseB(float x, float y, float w, float h, float bodyR, float bodyG, float bodyB, float roofR, float roofG, float roofB) { // ref#houseB
    rect(x, y, x + w, y + h, bodyR, bodyG, bodyB);

    float roof[][2] = {
        {x - 1.5f, y + h},
        {x + w * 0.25f, y + h + 8.0f},
        {x + w * 0.75f, y + h + 7.0f},
        {x + w + 1.5f, y + h}
    };
    polygon(roofR, roofG, roofB, 4, roof);

    line2D(x + w * 0.25f, y + h + 8.0f, x + w * 0.48f, y + h, 0.25f, 0.12f, 0.08f, 1.0f);

    rect(x + w * 0.58f, y, x + w * 0.76f, y + h * 0.48f, 0.27f, 0.15f, 0.08f);

    glPushMatrix();
    glTranslatef(x + w * 0.72f, y + h * 0.25f, 0.0f);
    glColor3f(0.90f, 0.78f, 0.25f);
    circle(0.22f);
    glPopMatrix();

    rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.36f, 0.24f, 0.12f);

    line2D(x + w * 0.265f, y + h * 0.38f, x + w * 0.265f, y + h * 0.62f, 0.08f, 0.08f, 0.06f, 1.0f);
    line2D(x + w * 0.16f, y + h * 0.50f, x + w * 0.37f, y + h * 0.50f, 0.08f, 0.08f, 0.06f, 1.0f);
}

void houseC(float x, float y, float w, float h, float bodyR, float bodyG, float bodyB, float roofR, float roofG, float roofB){ // ref#houseC
    rect(x, y, x + w, y + h, bodyR, bodyG, bodyB);

    float roof[][2] = {
        {x - 1.5f, y + h},
        {x + w * 0.25f, y + h + 8.0f},
        {x + w * 0.75f, y + h + 7.0f},
        {x + w + 1.5f, y + h}
    };
    polygon(roofR, roofG, roofB, 4, roof);

    line2D(x + w * 0.25f, y + h + 8.0f, x + w * 0.48f, y + h, 0.25f, 0.12f, 0.08f, 1.0f);

    rect(x + w * 0.58f, y, x + w * 0.76f, y + h * 0.48f, 0.27f, 0.15f, 0.08f);

    glPushMatrix();
    glTranslatef(x + w * 0.72f, y + h * 0.25f, 0.0f);
    glColor3f(0.90f, 0.78f, 0.25f);
    circle(0.22f);
    glPopMatrix();

    rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.36f, 0.24f, 0.12f);

    line2D(x + w * 0.265f, y + h * 0.38f, x + w * 0.265f, y + h * 0.62f, 0.08f, 0.08f, 0.06f, 1.0f);
    line2D(x + w * 0.16f, y + h * 0.50f, x + w * 0.37f, y + h * 0.50f, 0.08f, 0.08f, 0.06f, 1.0f);
}

// =====================================================
//                     STREET LAMP
// =====================================================

void streetLampA(float x, float y) { // ref#streetLampA
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    rect(0.0f, 0.0f, 0.5f, 7.0f, 0.20f, 0.20f, 0.18f);
    rect(0.5f, 6.5f, 3.0f, 7.0f, 0.20f, 0.20f, 0.18f);

    glPushMatrix();
    glTranslatef(3.0f, 6.0f, 0.0f);

    if (lightsOn == 1 || timeMode == 0) // Light at night or when L is pressed
    {
        glColor3f(1.0f, 1.0f, 0.5f);
        circle(1.0f);
    }
    else
    {
        glColor3f(1.0f, 0.86f, 0.25f);
        circle(0.8f);
    }
    glPopMatrix();

    glPopMatrix();
}

void streetLampB(float x, float y) { // ref#streetLampB
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    rect(0.0f, 0.0f, 0.5f, 7.0f, 0.20f, 0.20f, 0.18f);
    rect(0.5f, 6.5f, 3.0f, 7.0f, 0.20f, 0.20f, 0.18f);

    glPushMatrix();
    glTranslatef(3.0f, 6.0f, 0.0f);

    if (lightsOn == 1 || timeMode == 0)
    {
        glColor3f(1.0f, 1.0f, 0.5f);
        circle(1.0f);
    }
    else
    {
        glColor3f(1.0f, 0.86f, 0.25f);
        circle(0.8f);
    }
    glPopMatrix();

    glPopMatrix();
}

void streetLampC(float x, float y) { // ref#streetLampC
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    rect(0.0f, 0.0f, 0.5f, 7.0f, 0.20f, 0.20f, 0.18f);
    rect(0.5f, 6.5f, 3.0f, 7.0f, 0.20f, 0.20f, 0.18f);

    glPushMatrix();
    glTranslatef(3.0f, 6.0f, 0.0f);

    if (lightsOn == 1 || timeMode == 0)
    {
        glColor3f(1.0f, 1.0f, 0.5f);
        circle(1.0f);
    }
    else
    {
        glColor3f(1.0f, 0.86f, 0.25f);
        circle(0.8f);
    }
    glPopMatrix();

    glPopMatrix();
}

// =====================================================
//                     WATER WELL
// =====================================================

void wellA(float x, float y, float scale) { // ref#wellA
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    rect(-3.0f, 0.0f, 3.0f, 3.5f, 0.55f, 0.55f, 0.58f);
    rect(-2.1f, 2.0f, 2.1f, 3.5f, 0.15f, 0.15f, 0.18f);

    glColor3f(0.34f, 0.20f, 0.08f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2f(-2.5f, 3.5f); glVertex2f(-2.5f, 7.5f);
    glVertex2f(2.5f, 3.5f); glVertex2f(2.5f, 7.5f);
    glEnd();

    triangle(-3.2f, 7.5f, 3.2f, 7.5f, 0.0f, 10.5f, 0.45f, 0.22f, 0.10f);

    glColor3f(0.85f, 0.85f, 0.85f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 7.5f); glVertex2f(0.0f, 2.8f);
    glEnd();

    rect(-0.5f, 1.8f, 0.5f, 2.8f, 0.35f, 0.35f, 0.38f);
    glPopMatrix();
}

void wellB(float x, float y, float scale) { // ref#wellB
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    rect(-3.0f, 0.0f, 3.0f, 3.5f, 0.55f, 0.55f, 0.58f);
    rect(-2.1f, 2.0f, 2.1f, 3.5f, 0.15f, 0.15f, 0.18f);

    glColor3f(0.34f, 0.20f, 0.08f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2f(-2.5f, 3.5f); glVertex2f(-2.5f, 7.5f);
    glVertex2f(2.5f, 3.5f); glVertex2f(2.5f, 7.5f);
    glEnd();

    triangle(-3.2f, 7.5f, 3.2f, 7.5f, 0.0f, 10.5f, 0.45f, 0.22f, 0.10f);

    glColor3f(0.85f, 0.85f, 0.85f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 7.5f); glVertex2f(0.0f, 2.8f);
    glEnd();

    rect(-0.5f, 1.8f, 0.5f, 2.8f, 0.35f, 0.35f, 0.38f);
    glPopMatrix();
}

// =====================================================
//                    MARKET STALL
// =====================================================

void stallA(float x, float y, float r, float g, float b) { // ref#stallA
    rect(x, y, x + 7.0f, y + 3.0f, 0.48f, 0.28f, 0.10f);
    rect(x + 0.7f, y + 0.6f, x + 6.3f, y + 2.4f, 0.40f, 0.27f, 0.12f);
    rect(x - 0.3f, y + 5.5f, x + 7.3f, y + 7.0f, r, g, b); //stripe color
    //roof stripes
    for(int i = 0; i < 4; i++)
    {
        rect(x + i * 1.8f, y + 5.5f, x + i * 1.8f + 0.9f, y + 7.0f, 0.95f, 0.85f, 0.55f);
    }
    //support pillars
    rect(x + 0.3f, y + 3.0f, x + 0.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);
    rect(x + 6.3f, y + 3.0f, x + 6.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);
    //fruits or items
    glColor3f(0.40f, 0.10f, 0.10f);
    for(int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(x + 1.0f + i * 1.1f, y + 1.4f + (i % 2) * 0.35f, 0.0f);
        circle(0.4f);
        glPopMatrix();
    }
}

void stallB(float x, float y, float r, float g, float b) { // ref#stallB
    rect(x, y, x + 7.0f, y + 3.0f, 0.48f, 0.28f, 0.10f);
    rect(x + 0.7f, y + 0.6f, x + 6.3f, y + 2.4f, 0.40f, 0.27f, 0.12f);
    rect(x - 0.3f, y + 5.5f, x + 7.3f, y + 7.0f, r, g, b);

    for(int i = 0; i < 4; i++)
    {
        rect(x + i * 1.8f, y + 5.5f, x + i * 1.8f + 0.9f, y + 7.0f, 0.95f, 0.85f, 0.55f);
    }

    rect(x + 0.3f, y + 3.0f, x + 0.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);
    rect(x + 6.3f, y + 3.0f, x + 6.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);

    glColor3f(0.40f, 0.10f, 0.10f);
    for(int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(x + 1.0f + i * 1.1f, y + 1.4f + (i % 2) * 0.35f, 0.0f);
        circle(0.4f);
        glPopMatrix();
    }
}

void stallC(float x, float y, float r, float g, float b) { // ref#stallC
    rect(x, y, x + 7.0f, y + 3.0f, 0.48f, 0.28f, 0.10f);
    rect(x + 0.7f, y + 0.6f, x + 6.3f, y + 2.4f, 0.40f, 0.27f, 0.12f);
    rect(x - 0.3f, y + 5.5f, x + 7.3f, y + 7.0f, r, g, b);

    for(int i = 0; i < 4; i++)
    {
        rect(x + i * 1.8f, y + 5.5f, x + i * 1.8f + 0.9f, y + 7.0f, 0.95f, 0.85f, 0.55f);
    }

    rect(x + 0.3f, y + 3.0f, x + 0.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);
    rect(x + 6.3f, y + 3.0f, x + 6.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);

    glColor3f(0.40f, 0.10f, 0.10f);
    for(int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(x + 1.0f + i * 1.1f, y + 1.4f + (i % 2) * 0.35f, 0.0f);
        circle(0.4f);
        glPopMatrix();
    }
}

// =====================================================
//                      FENCE LINE
// =====================================================

void fenceLineA(float x1, float y1, float x2, float y2, int posts) { // ref#fenceLineA
    glColor3f(0.42f, 0.25f, 0.12f);
    glLineWidth(7.0f);

    glBegin(GL_LINES);
    glVertex2f(x1, y1); glVertex2f(x2, y2);
    glVertex2f(x1, y1 - 2.0f); glVertex2f(x2, y2 - 2.0f);
    glEnd();

    for(int i = 0; i <= posts; i++)
    {
        float t = (float)i / posts;
        float px = x1 + (x2 - x1) * t;
        float py = y1 + (y2 - y1) * t;

        glBegin(GL_LINES);
        glVertex2f(px, py - 2.8f);
        glVertex2f(px, py + 0.8f);
        glEnd();
    }
}

void fenceLineB(float x1, float y1, float x2, float y2, int posts) { // ref#fenceLineB
    glColor3f(0.42f, 0.25f, 0.12f);
    glLineWidth(7.0f);

    glBegin(GL_LINES);
    glVertex2f(x1, y1); glVertex2f(x2, y2);
    glVertex2f(x1, y1 - 2.0f); glVertex2f(x2, y2 - 2.0f);
    glEnd();

    for(int i = 0; i <= posts; i++)
    {
        float t = (float)i / posts;
        float px = x1 + (x2 - x1) * t;
        float py = y1 + (y2 - y1) * t;

        glBegin(GL_LINES);
        glVertex2f(px, py - 2.8f);
        glVertex2f(px, py + 0.8f);
        glEnd();
    }
}

// =====================================================
//                  STATIC BULLOCK CART
// =====================================================

void bullockCart(float x, float y){ // ref#bullockCart
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    float cartBody[][2] = {
        {-3.5f, 1.0f},
        {3.5f, 1.0f},
        {3.2f, 4.0f},
        {-3.2f, 4.0f}
    };
    polygon(0.46f, 0.30f, 0.14f, 4, cartBody);

    glColor3f(0.34f, 0.20f, 0.08f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(3.2f, 2.5f); glVertex2f(6.5f, 1.2f);
    glEnd();

    // Left Wheel
    glPushMatrix();
    glTranslatef(-2.0f, 0.8f, 0.0f);
    glColor3f(0.12f, 0.12f, 0.12f);
    circle(1.25f);
    glColor3f(0.75f, 0.75f, 0.75f);
    glLineWidth(1.2f);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f); glVertex2f(0.0f, 1.0f);
    glEnd();
    glPopMatrix();

    // Right Wheel
    glPushMatrix();
    glTranslatef(2.0f, 0.8f, 0.0f);
    glColor3f(0.12f, 0.12f, 0.12f);
    circle(1.25f);
    glColor3f(0.75f, 0.75f, 0.75f);
    glLineWidth(1.2f);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f); glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f); glVertex2f(0.0f, 1.0f);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

// =====================================================
//                       BOAT
// =====================================================

void boat(float x, float y, int flipped, float angle = 0.0f){ // ref#boat
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(angle, 0, 0, 1);

    if(flipped == 1)
    {
        glScalef(-1.0f, 1.0f, 1.0f);
    }

    float body[][2] =
    { {4, 0},
      {11, 0},
      {15, 4},
      {0, 4}};
    polygon(0.40f, 0.22f, 0.10f, 4, body);

    line2D(0, 4, 15, 4, 0.18f, 0.10f, 0.04f, 2.0f);

    rect(7.0f, 4.0f, 7.5f, 15.0f, 0.25f, 0.16f, 0.08f);

    float sail[][2] =
    { {7.5f, 14.8f},
    {14.0f, 10.0f},
    {7.5f, 8.8f} };
    polygon(0.96f, 0.96f, 0.93f, 3, sail);

    glPopMatrix();
}

// =====================================================
//                    MOVING BOAT
// =====================================================

void movingBoat(float xProg){ // ref#movingBoat
    float bx = xProg;

    // River center line runs roughly from (0, 18.5) to (100, 34.5)
    float by = 18.5f + bx * 0.16f;

    // River rises ~16 units over 100 keeps the boat's tilt aligned with the water
    float riverAngle = atan2f(16.0f, 100.0f) * 180.0f / PI; //tan inverse

    boat(bx, by, 0, riverAngle);
}
// =====================================================
//                    Docked BOAT
// =====================================================
void smallBoat(float x, float y){ // ref#smallBoat
    float body[][2] = { {x + 2, y}, {x + 8, y}, {x + 10, y + 2}, {x, y + 2} };
    polygon(0.58f, 0.34f, 0.15f, 4, body);
    rect(x + 1.0f, y + 2.0f, x + 8.8f, y + 2.6f, 0.36f, 0.22f, 0.08f);
}

void dockLog(float x, float y){ // ref#dockLog
    rect(x, y, x + 5.0f, y + 1.0f, 0.30f, 0.19f, 0.09f);
    rect(x - 1.4f, y - 3.5f, x + 0.6f, y + 1.4f, 0.24f, 0.15f, 0.07f);
}

// =====================================================
//                    MOVING BOAT 2
// =====================================================

void movingBoat2(float xProg){ // ref#movingBoat2
    float bx = xProg;

    // Hugs the lower/bottom part of the river band
    float by = 16.0f + bx * 0.15f;

    float riverAngle = atan2f(15.0f, 100.0f) * 180.0f / PI;

    // flipped = 1 so it visually faces the direction it's travelling (right -> left)
    boat(bx, by, 1, riverAngle);
}
// =====================================================
//                     WATER RIPPLE
// =====================================================

void ripple(float x, float y, float w){ // ref#ripple
    line2D(x, y, x + w, y, 0.08f, 0.55f, 0.72f, 1.3f);
    line2D(x + w * 0.20f, y + 1.2f, x + w * 0.65f, y + 1.2f, 0.08f, 0.55f, 0.72f, 1.0f);
}

// =====================================================
//                     VILLAGE PEOPLE
// =====================================================

void personA(float x, float y, float scale, float bodyR, float bodyG, float bodyB) { // ref#personA
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glColor3f(0.72f, 0.48f, 0.30f);
    circle(0.9f);
    glPopMatrix();

    rect(-1.0f, 0.0f, 1.0f, 4.0f, bodyR, bodyG, bodyB);

    line2D(-0.5f, 0.0f, -0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);
    line2D(0.5f, 0.0f, 0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);

    glPopMatrix();
}

void personB(float x, float y, float scale, float bodyR, float bodyG, float bodyB) { // ref#personB
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glColor3f(0.72f, 0.48f, 0.30f);
    circle(0.9f);
    glPopMatrix();

    rect(-1.0f, 0.0f, 1.0f, 4.0f, bodyR, bodyG, bodyB);

    line2D(-0.5f, 0.0f, -0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);
    line2D(0.5f, 0.0f, 0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);

    glPopMatrix();
}

void personC(float x, float y, float scale, float bodyR, float bodyG, float bodyB) { // ref#personC
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glColor3f(0.72f, 0.48f, 0.30f);
    circle(0.9f);
    glPopMatrix();

    rect(-1.0f, 0.0f, 1.0f, 4.0f, bodyR, bodyG, bodyB);

    line2D(-0.5f, 0.0f, -0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);
    line2D(0.5f, 0.0f, 0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);

    glPopMatrix();
}

// =====================================================
//                        BUSH
// =====================================================

void bushA(float x, float y, float s) { // ref#bushA
    glColor3f(0.20f, 0.42f, 0.12f);

    glPushMatrix();
    glTranslatef(x, y, 0);
    circle(1.6f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 1.9f * s, y + 0.6f * s, 0);
    circle(2.1f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 3.8f * s, y, 0);
    circle(1.6f * s);
    glPopMatrix();
}

void bushB(float x, float y, float s) { // ref#bushB
    glColor3f(0.20f, 0.42f, 0.12f);

    glPushMatrix();
    glTranslatef(x, y, 0);
    circle(1.6f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 1.9f * s, y + 0.6f * s, 0);
    circle(2.1f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 3.8f * s, y, 0);
    circle(1.6f * s);
    glPopMatrix();
}

void bushC(float x, float y, float s) { // ref#bushC
    glColor3f(0.20f, 0.42f, 0.12f);

    glPushMatrix();
    glTranslatef(x, y, 0);
    circle(1.6f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 1.9f * s, y + 0.6f * s, 0);
    circle(2.1f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 3.8f * s, y, 0);
    circle(1.6f * s);
    glPopMatrix();
}

void grassMark(float x, float y){ // ref#grassMark
    line2D(x, y, x - 1.0f, y + 2.0f, 0.20f, 0.38f, 0.10f, 1.2f);
    line2D(x, y, x + 0.8f, y + 2.2f, 0.20f, 0.38f, 0.10f, 1.2f);
    line2D(x, y, x, y + 2.4f, 0.20f, 0.38f, 0.10f, 1.0f);
}

// =====================================================
//                        RIVER
// =====================================================

void riverBand()
{ // ref#riverBand
    float xs[5]  = {0, 23, 45, 69, 100};
    float topY[5] = {25, 29, 34, 38, 42};
    float botY[5];

    for(int i = 0; i < 5; i++)
    {
        botY[i] = 12.0f + (27.0f - 12.0f) * (xs[i] / 100.0f);
    }

    for(int i = 0; i < 4; i++)
    {
        float quad[][2] = {
            {xs[i], botY[i]},
            {xs[i+1], botY[i+1]},
            {xs[i+1], topY[i+1]},
            {xs[i], topY[i]}
        };
        polygon(0.20f, 0.67f, 0.84f, 4, quad);
    }

    for(int i = 0; i < 4; i++)
    {
        line2D(xs[i], topY[i], xs[i+1], topY[i+1], 0.12f, 0.32f, 0.36f, 2.0f);
    }

    line2D(xs[0], botY[0], xs[4], botY[4], 0.12f, 0.32f, 0.36f, 2.0f);

    ripple(7, 17, 6);
    ripple(23, 20, 7);
    ripple(44, 24, 6);
    ripple(57, 27, 6);
    ripple(82, 32, 7);
    ripple(89, 37, 5);
}

// =====================================================
//                        ROAD
// =====================================================

void road()
{ // ref#road
    float roadShape[][2] = { {0, 30}, {100, 57}, {100, 64}, {0, 37} };
    polygon(0.25f, 0.25f, 0.27f, 4, roadShape);

    line2D(0, 30, 100, 57, 0.95f, 0.95f, 0.95f, 2.0f);
    line2D(0, 37, 100, 64, 0.95f, 0.95f, 0.95f, 2.0f);

    for(int i = 0; i < 8; i++)
    {
        float x1 = i * 14.0f - 1.0f;
        float y1 = 33.5f + i * 3.78f;
        float x2 = x1 + 7.0f;
        float y2 = y1 + 1.9f;
        line2D(x1, y1, x2, y2, 1.0f, 1.0f, 1.0f, 2.2f);
    }
}

// =====================================================
//                     CAR WHEEL
// =====================================================

void wheel(float x, float y, float angle)
{ // ref#wheel
    glPushMatrix();

    glTranslatef(x, y, 0);
    glRotatef(angle, 0, 0, 1);

    // Black wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(1.4f);

    // White lines
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINES);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glVertex2f(0, -1);
    glVertex2f(0, 1);
    glEnd();

    // Center
    glColor3f(0.6f, 0.6f, 0.6f);
    circle(0.5f);

    glPopMatrix();
}

// =====================================================
//                         CAR
// =====================================================

void car(float x, float y, float r, float g, float b, int direction, float roadAngle, float wheelSpin, float scale)
{ // ref#car
    glPushMatrix();

    glTranslatef(x, y, 0);
    glRotatef(roadAngle, 0, 0, 1);
    glScalef(scale, scale, 1.0f);

    if(direction == -1)
    {
        glScalef(-1.0f, 1.0f, 1.0f);
    }

    // Car body
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(-5.5f, 0);
    glVertex2f(5.5f, 0);
    glVertex2f(5.5f, 4);
    glVertex2f(-5.5f, 4);
    glEnd();

    // Upper part
    glBegin(GL_POLYGON);
    glVertex2f(-3.5f, 4);
    glVertex2f(-2, 7);
    glVertex2f(2, 7);
    glVertex2f(3.5f, 4);
    glEnd();

    // Left window
    glColor3f(0.4f, 0.8f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-2.8f, 4.5f);
    glVertex2f(-1.7f, 6.4f);
    glVertex2f(-0.3f, 6.4f);
    glVertex2f(-0.3f, 4.5f);
    glEnd();

    // Right window
    glBegin(GL_POLYGON);
    glVertex2f(0.3f, 4.5f);
    glVertex2f(0.3f, 6.4f);
    glVertex2f(1.7f, 6.4f);
    glVertex2f(2.8f, 4.5f);
    glEnd();

    // Wheels
    wheel(-3.2f, 0, wheelSpin);
    wheel(3.2f, 0, wheelSpin);

    glPopMatrix();
}

// =====================================================
//                   MOVING CAR
// =====================================================

void movingCar(float xProg)
{ // ref#movingCar
    // xProg is driven directly by vehicleMove, which update() already
    // resets cleanly at each end - no modulo wraparound needed here.
    // (fmod combined with a negative-to-positive range was causing the
    // car to snap through the wrap point multiple times before settling.)
    float cx = xProg;

    // Center of the lane (average of road's top/bottom edges)
    float cy = 35.5f + cx * 0.27f;

    // Road rises 27 units over 100 - same slope as road()
    float roadAngle = atan2f(27.0f, 100.0f) * 180.0f / PI;

    car(cx, cy, 0.82f, 0.22f, 0.18f, 1, roadAngle, carWheelAngle, 0.75f);
}

// =====================================================
//                     MAIN VILLAGE SCENE
// =====================================================

void village()
{ // ref#village
    // Time of day color setup
    float skyR, skyG, skyB;

    if (timeMode == 0)      // Night (N)
    {
        skyR = 0.06f; skyG = 0.08f; skyB = 0.18f;
    }
    else if (timeMode == 1) // Dawn (D)
    {
        skyR = 0.85f; skyG = 0.50f; skyB = 0.35f;
    }
    else if (timeMode == 2) // Day (F)
    {
        skyR = 0.28f; skyG = 0.61f; skyB = 0.84f;
    }
    else                    // Evening (E)
    {
        skyR = 0.55f; skyG = 0.30f; skyB = 0.45f;
    }

    glClearColor(skyR, skyG, skyB, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Background Sky
    rect(0, 40, 100, 100, skyR, skyG, skyB);

    if (timeMode == 0)
    {
        moon();
    }
    else
    {
        sun();
    }

    // Clouds
    glPushMatrix();
    glTranslatef(cloudMove, 0, 0);
    cloud(18, 87);
    cloud(33, 80);
    cloud(61, 90);
    glPopMatrix();

    hills();

    // Green Field
    rect(0, 0, 100, 52, 0.42f, 0.62f, 0.30f);
    rect(0, 48, 100, 63, 0.40f, 0.60f, 0.28f);

    riverBand();
    road();

    // Grass Marks (12)
    grassMark(10, 5);
    grassMark(20, 10);
    grassMark(41, 8);
    grassMark(53, 12);
    grassMark(76, 9);
    grassMark(84, 16);
    grassMark(96, 9);
    grassMark(5, 44);
    grassMark(15, 47);
    grassMark(58, 56);
    grassMark(68, 58);
    grassMark(81, 41);

    // Bushes (7)
    bushA(28, 6, 1.0f); // ref#bushObj1
    bushB(67, 5, 1.0f); // ref#bushObj2
    bushC(25, 33, 0.9f); // ref#bushObj3
    bushA(94, 47, 0.8f); // ref#bushObj4
    bushB(72, 60, 0.7f); // ref#bushObj5
    bushC(53, 55, 0.7f); // ref#bushObj6
    bushA(10, 45, 0.9f); // ref#bushObj7

    // Fences (2)
    fenceLineA(0.0f, 32.0f, 100.0f, 60.0f, 12); // ref#fenceLineObj1
    fenceLineB(0.0f, 40.0f, 100.0f, 67.0f, 9); // ref#fenceLineObj2

    // Trees (10 total: 5 background + 5 small near field)
    treeA(5, 57, 1.1f); // ref#treeObj1
    treeB(20, 62, 1.2f); // ref#treeObj2
    treeC(35, 60, 1.25f); // ref#treeObj3
    treeA(48, 61, 1.1f); // ref#treeObj4
    treeB(63, 58, 1.0f); // ref#treeObj5

    treeC(5, 47, 0.8f); // ref#treeObj6
    treeA(20, 45, 0.6f); // ref#treeObj7
    treeB(66, 40, 0.8f); // ref#treeObj8
    treeC(72, 10, 0.9f); // ref#treeObj9
    treeA(95, 12, 0.7f); // ref#treeObj10

    // Small Houses (4)
    houseA(7, 53, 13, 9, 0.92f, 0.83f, 0.55f, 0.90f, 0.30f, 0.16f); // ref#houseObj1
    houseB(22, 56, 12, 8, 0.85f, 0.74f, 0.45f, 0.75f, 0.18f, 0.10f); // ref#houseObj2
    houseC(37, 58, 10, 7, 0.88f, 0.77f, 0.52f, 0.82f, 0.25f, 0.10f); // ref#houseObj3
    houseA(50, 59, 8, 7, 0.75f, 0.45f, 0.31f, 0.40f, 0.25f, 0.15f); // ref#houseObj4

    // Water Wells (2)
    wellA(48.0, 54.0, 1.00); // ref#wellObj1
    wellB(60.0f, 6.0f, 1.25f); // ref#wellObj2

    // Market Stalls (3)
    stallA(23, 50, 0.88f, 0.08f, 0.08f); // ref#stallObj1
    stallB(31, 52, 0.95f, 0.72f, 0.06f); // ref#stallObj2
    stallC(80, 7, 0.90f, 0.08f, 0.08f); // ref#stallObj3

    // Village People (4)
    personA(39, 55, 0.65f, 0.25f, 0.30f, 0.75f); // ref#personObj1
    personB(42, 55, 0.65f, 0.80f, 0.20f, 0.30f); // ref#personObj2
    personC(40, 52, 0.7f, 0.30f, 0.55f, 0.75f); // ref#personObj3
    personA(43, 52, 0.7f, 0.30f, 0.55f, 0.75f); // ref#personObj4

    // Bullock Cart (Static) (1)
    bullockCart(55, 39); // ref#bullockCartObj1

    streetLampA(39.0f, 48.0f); // ref#streetLampObj1
    streetLampB(77.0f, 58.0f); // ref#streetLampObj2


    // Moving Car along road
    movingCar(vehicleMove); // ref#movingCarObj1

    //Small Houses below road(2)
    houseB(82, 45, 10, 6, 0.90f, 0.79f, 0.53f, 0.95f, 0.25f, 0.12f); // ref#houseObj5
    houseC(75, 44, 9, 5, 0.72f, 0.42f, 0.30f, 0.45f, 0.25f, 0.13f); // ref#houseObj6


      // Street Lamps bottom(3)
    streetLampC(15.0f, 32.0f); // ref#streetLampObj3
    streetLampA(62.0f, 46.0f); // ref#streetLampObj4
    streetLampB(95.0f, 54.0f); // ref#streetLampObj5

    // Static boat at bank
    dockLog(41, 38); // ref#dockLogObj1
    smallBoat(38, 32); // ref#smallBoatObj1
    line2D(47.0f, 33.6f, 45.0f, 38.0f, 0.30f, 0.20f, 0.10f, 1.5f);
    // Boats (1 moving across the river + 1 docked)
    movingBoat(boatMove); // ref#movingBoatObj1
    movingBoat2(boatMove2); // ref#movingBoat2Obj1


    glutSwapBuffers();
}

// =====================================================
//                   UPDATE ANIMATION
// =====================================================

void update(int value)
{ // ref#update
    if(animationOn == 1)
    {
        cloudMove += 0.03f;
        if(cloudMove > 105.0f) cloudMove = -105.0f;

        // Boat travels the full river, spawning just before the left
        // edge and resetting once it clears the right edge - same clean
        // single-reset pattern as the car (no fmod wraparound).
        boatMove += 0.04f;
        if(boatMove > 115.0f) boatMove = -15.0f;

        boatMove2 -= 0.03f;
        if(boatMove2 < -15.0f) boatMove2 = 115.0f;

        if(vehicleMoving == 1)
        {
            vehicleMove += 0.20f;
            if(vehicleMove > 105.0f) vehicleMove = -5.0f;

            carWheelAngle -= 5.0f;
            if(carWheelAngle < -360.0f) carWheelAngle = 0.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

// =====================================================
//                 MOUSE INTERACTIONS
// =====================================================

void handleMouse(int button, int state, int x, int y)
{ // ref#handleMouse
    if(state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            // Toggle all animations start/stop
            animationOn = !animationOn;
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            // Right click boosts boat sail
            boatMove += 2.0f;
        }
    }
    glutPostRedisplay();
}

// =====================================================
//                 KEYBOARD INTERACTIONS
// =====================================================

void handleKeypress(unsigned char key, int x, int y)
{ // ref#handleKeypress
    switch(key)
    {
        case 'c':
        case 'C':
            std::cout << "[Scene Switch] Transitioning to Next Scene..." << std::endl;
            break;

        case '6':
            vehicleMoving = 1; // Move vehicle
            break;

        case '5':
            vehicleMoving = 0; // Stop vehicle
            break;

        case 'd':
        case 'D':
            timeMode = 1; // Dawn
            break;

        case 'f':
        case 'F':
            timeMode = 2; // Day
            break;

        case 'e':
        case 'E':
            timeMode = 3; // Evening
            break;

        case 'n':
        case 'N':
            timeMode = 0; // Night
            break;

        case 'l':
        case 'L':
            lightsOn = !lightsOn; // Toggle lights
            break;

        case 27: // ESC
            exit(0);
            break;
    }
    glutPostRedisplay();
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
    glutInitWindowSize(1200, 900);
    glutInitWindowPosition(100, 40);
    glutCreateWindow("Scene-1 : Village");

    init();

    glutDisplayFunc(village);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(20, update, 0);

    glutMainLoop();
    return 0;
}
