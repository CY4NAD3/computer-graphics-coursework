// =====================================================================
// GLUT GROUP PROJECT - MERGED SCENES
// Scene 1: Village | Scene 2: Town | Scene 3: City | Scene 4: Highway
//
// SHARED KEY (works in every scene):
//   M           -> next scene, loops 1 -> 2 -> 3 -> 4 -> 1
//
// Each scene below keeps its OWN original keybinds - they only do
// anything while that scene is the one currently on screen.
//
//   SCENE 1 - VILLAGE
//     6           -> moving car: go
//     5           -> moving car: stop
//     D           -> Dawn
//     F           -> Day
//     E           -> Evening
//     N           -> Night
//     L           -> toggle street lamps on/off
//     C           -> (placeholder - just prints a line to the console)
//     ESC         -> quit
//     Mouse Left  -> toggle all animation on/off
//     Mouse Right -> boost the moving boat forward
//
//   SCENE 2 - TOWN
//     Q           -> Dawn
//     W           -> Day
//     E           -> Evening
//     R           -> Night
//     T           -> toggle street lights on/off
//     Up Arrow    -> my car: move
//     Down Arrow  -> my car: stop
//     C           -> (placeholder - blanks the screen; press M to move on)
//     Mouse Left  -> animation ON
//     Mouse Right -> animation OFF
//
//   SCENE 3 - CITY
//     L           -> vehicles: move
//     K           -> vehicles: stop
//     A           -> Dawn
//     S           -> Day
//     D           -> Evening
//     F           -> Night
//     N           -> toggle lights on/off
//     ESC         -> quit
//     Mouse Left  -> toggle all animation on/off
//
//   SCENE 4 - HIGHWAY
//     C           -> toggle river/no-river variant (this scene's own,
//                    kept as originally authored - NOT the scene switcher)
//     O           -> vehicles: move
//     P           -> vehicles: stop
//     Z           -> Dawn
//     X           -> Day
//     V           -> Night
//     B           -> toggle headlights on/off
//     Mouse Left  -> toggle animation on/off
//     Mouse Right -> reset boat to start position
// =====================================================================

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#define PI 3.1416



// =====================================================================
//  SCENE 1: VILLAGE
// =====================================================================

// =====================================================
//                 GLOBAL VARIABLES
// =====================================================

float vlg_boatMove = -15.0f;      // moving vlg_boat left-to-right across the river, , starts at the left edge
float vlg_boatMove2 = 115.0f;   // second vlg_boat, travels right-to-left, starts at the right edge
float vlg_cloudMove = 0.0f;
float vlg_vehicleMove = -5.0f;    // progress of the moving vlg_car across the vlg_road
float vlg_carWheelAngle = 0.0f;   // vlg_wheel spin for the moving vlg_car

int vlg_animationOn = 1;     // Left Click toggles this, for vlg_boat left-to-right
int vlg_vehicleMoving = 1;   // Key 6/5 controls vehicle start stop
int vlg_timeMode = 2;        // D(Dawn:1), F(Day:2), E(Evening:3), N(Night:0)
int vlg_lightsOn = 0;        // 'L' toggles street lamps on/off (auto-on at night)

// =====================================================
//                 BASIC SHAPE FUNCTIONS
// =====================================================

void vlg_rect(float x1, float y1, float x2, float y2, float r, float g, float b){ // ref#vlg_rect
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void vlg_polygon(float r, float g, float b, int n, float points[][2]){ // ref#vlg_polygon
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for(int i = 0; i < n; i++)
    {
        glVertex2f(points[i][0], points[i][1]);
    }
    glEnd();
}

void vlg_line2D(float x1, float y1, float x2, float y2, float r, float g, float b, float width){ // ref#vlg_line2D
    glColor3f(r, g, b);
    glLineWidth(width);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void vlg_triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b){ // ref#vlg_triangle
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void vlg_circle(float radius){ // ref#vlg_circle
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

void vlg_sun(){ // ref#vlg_sun
    glPushMatrix();
    glTranslatef(53.0f, 88.0f, 0.0f);
    glColor3f(1.0f, 0.85f, 0.05f);
    vlg_circle(4.2f);
    glPopMatrix();
}

void vlg_moon(){ // ref#vlg_moon
    glPushMatrix();
    glTranslatef(75.0f, 85.0f, 0.0f);
    glColor3f(0.92f, 0.94f, 0.98f);
    vlg_circle(3.5f);
    glPopMatrix();
}

// =====================================================
//                        CLOUD
// =====================================================

void vlg_cloud(float x, float y){ // ref#vlg_cloud
    glColor3f(1.0f, 1.0f, 1.0f);

    glPushMatrix();
    glTranslatef(x, y, 0);
    vlg_circle(2.8f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 3.2f, y + 1.0f, 0);
    vlg_circle(3.6f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 6.8f, y, 0);
    vlg_circle(2.8f);
    glPopMatrix();
}

// =====================================================
//                    BACKGROUND HILLS
// =====================================================

void vlg_mountain(float x1, float y1, float xPeak, float yPeak, float x2, float y2, float r, float g, float b){ // ref#vlg_mountain
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

void vlg_hills(){ // ref#vlg_hills
    // Back vlg_mountain
    vlg_mountain(64, 52, 82, 88, 110, 52, 0.35f, 0.52f, 0.20f);
    // Front vlg_mountain
    vlg_mountain(57, 52, 73, 78, 88, 52, 0.43f, 0.60f, 0.24f);
}

// =====================================================
//                        TREE
// =====================================================

void vlg_treeA(float x, float y, float scale){ // ref#vlg_treeA
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    vlg_rect(-0.55f, 0.0f, 0.55f, 5.0f, 0.34f, 0.21f, 0.09f);

    vlg_triangle(-3.7f, 3.5f, 3.7f, 3.5f, 0.0f, 10.5f, 0.10f, 0.42f, 0.10f);
    vlg_triangle(-2.8f, 8.0f, 2.8f, 8.0f, 0.0f, 14.0f, 0.16f, 0.55f, 0.14f);

    glPopMatrix();
}

void vlg_treeB(float x, float y, float scale){ // ref#vlg_treeB
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    vlg_rect(-0.55f, 0.0f, 0.55f, 5.0f, 0.34f, 0.21f, 0.09f);

    vlg_triangle(-3.7f, 3.5f, 3.7f, 3.5f, 0.0f, 10.5f, 0.28f, 0.42f, 0.06f);
    vlg_triangle(-2.8f, 8.0f, 2.8f, 8.0f, 0.0f, 14.0f, 0.38f, 0.55f, 0.08f);

    glPopMatrix();
}

void vlg_treeC(float x, float y, float scale){ // ref#vlg_treeC
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    vlg_rect(-0.55f, 0.0f, 0.55f, 5.0f, 0.34f, 0.21f, 0.09f);

    vlg_triangle(-3.7f, 3.5f, 3.7f, 3.5f, 0.0f, 10.5f, 0.15f, 0.34f, 0.06f);
    vlg_triangle(-2.8f, 8.0f, 2.8f, 8.0f, 0.0f, 14.0f, 0.21f, 0.43f, 0.08f);

    glPopMatrix();
}

// =====================================================
//                        HOUSE
// =====================================================

void vlg_houseA(float x, float y, float w, float h, float bodyR, float bodyG, float bodyB, float roofR, float roofG, float roofB){ // ref#vlg_houseA
    vlg_rect(x, y, x + w, y + h, bodyR, bodyG, bodyB);

    float roof[][2] = {
        {x - 1.5f, y + h},
        {x + w * 0.25f, y + h + 8.0f},
        {x + w * 0.75f, y + h + 7.0f},
        {x + w + 1.5f, y + h}
    };
    vlg_polygon(roofR, roofG, roofB, 4, roof); //roof e pathaitesi parameter diye, okhane giye glvertex use hoye plot hoye jabe
    //angle line diye 3d effect
    vlg_line2D(x + w * 0.25f, y + h + 8.0f, x + w * 0.48f, y + h, 0.25f, 0.12f, 0.08f, 1.0f);
    //door
    vlg_rect(x + w * 0.58f, y, x + w * 0.76f, y + h * 0.48f, 0.27f, 0.15f, 0.08f);
    //door knob
    glPushMatrix();
    glTranslatef(x + w * 0.72f, y + h * 0.25f, 0.0f);
    glColor3f(0.90f, 0.78f, 0.25f);
    vlg_circle(0.22f);
    glPopMatrix();
    //window
    vlg_rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.36f, 0.24f, 0.12f);

    vlg_line2D(x + w * 0.265f, y + h * 0.38f, x + w * 0.265f, y + h * 0.62f, 0.08f, 0.08f, 0.06f, 1.0f);
    vlg_line2D(x + w * 0.16f, y + h * 0.50f, x + w * 0.37f, y + h * 0.50f, 0.08f, 0.08f, 0.06f, 1.0f);
}

void vlg_houseB(float x, float y, float w, float h, float bodyR, float bodyG, float bodyB, float roofR, float roofG, float roofB) { // ref#vlg_houseB
    vlg_rect(x, y, x + w, y + h, bodyR, bodyG, bodyB);

    float roof[][2] = {
        {x - 1.5f, y + h},
        {x + w * 0.25f, y + h + 8.0f},
        {x + w * 0.75f, y + h + 7.0f},
        {x + w + 1.5f, y + h}
    };
    vlg_polygon(roofR, roofG, roofB, 4, roof);

    vlg_line2D(x + w * 0.25f, y + h + 8.0f, x + w * 0.48f, y + h, 0.25f, 0.12f, 0.08f, 1.0f);

    vlg_rect(x + w * 0.58f, y, x + w * 0.76f, y + h * 0.48f, 0.27f, 0.15f, 0.08f);

    glPushMatrix();
    glTranslatef(x + w * 0.72f, y + h * 0.25f, 0.0f);
    glColor3f(0.90f, 0.78f, 0.25f);
    vlg_circle(0.22f);
    glPopMatrix();

    vlg_rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.36f, 0.24f, 0.12f);

    vlg_line2D(x + w * 0.265f, y + h * 0.38f, x + w * 0.265f, y + h * 0.62f, 0.08f, 0.08f, 0.06f, 1.0f);
    vlg_line2D(x + w * 0.16f, y + h * 0.50f, x + w * 0.37f, y + h * 0.50f, 0.08f, 0.08f, 0.06f, 1.0f);
}

void vlg_houseC(float x, float y, float w, float h, float bodyR, float bodyG, float bodyB, float roofR, float roofG, float roofB){ // ref#vlg_houseC
    vlg_rect(x, y, x + w, y + h, bodyR, bodyG, bodyB);

    float roof[][2] = {
        {x - 1.5f, y + h},
        {x + w * 0.25f, y + h + 8.0f},
        {x + w * 0.75f, y + h + 7.0f},
        {x + w + 1.5f, y + h}
    };
    vlg_polygon(roofR, roofG, roofB, 4, roof);

    vlg_line2D(x + w * 0.25f, y + h + 8.0f, x + w * 0.48f, y + h, 0.25f, 0.12f, 0.08f, 1.0f);

    vlg_rect(x + w * 0.58f, y, x + w * 0.76f, y + h * 0.48f, 0.27f, 0.15f, 0.08f);

    glPushMatrix();
    glTranslatef(x + w * 0.72f, y + h * 0.25f, 0.0f);
    glColor3f(0.90f, 0.78f, 0.25f);
    vlg_circle(0.22f);
    glPopMatrix();

    vlg_rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.36f, 0.24f, 0.12f);

    vlg_line2D(x + w * 0.265f, y + h * 0.38f, x + w * 0.265f, y + h * 0.62f, 0.08f, 0.08f, 0.06f, 1.0f);
    vlg_line2D(x + w * 0.16f, y + h * 0.50f, x + w * 0.37f, y + h * 0.50f, 0.08f, 0.08f, 0.06f, 1.0f);
}

// =====================================================
//                     STREET LAMP
// =====================================================

void vlg_streetLampA(float x, float y) { // ref#vlg_streetLampA
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    vlg_rect(0.0f, 0.0f, 0.5f, 7.0f, 0.20f, 0.20f, 0.18f);
    vlg_rect(0.5f, 6.5f, 3.0f, 7.0f, 0.20f, 0.20f, 0.18f);

    glPushMatrix();
    glTranslatef(3.0f, 6.0f, 0.0f);

    if (vlg_lightsOn == 1 || vlg_timeMode == 0) // Light at night or when L is pressed
    {
        glColor3f(1.0f, 1.0f, 0.5f);
        vlg_circle(1.0f);
    }
    else
    {
        glColor3f(1.0f, 0.86f, 0.25f);
        vlg_circle(0.8f);
    }
    glPopMatrix();

    glPopMatrix();
}

void vlg_streetLampB(float x, float y) { // ref#vlg_streetLampB
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    vlg_rect(0.0f, 0.0f, 0.5f, 7.0f, 0.20f, 0.20f, 0.18f);
    vlg_rect(0.5f, 6.5f, 3.0f, 7.0f, 0.20f, 0.20f, 0.18f);

    glPushMatrix();
    glTranslatef(3.0f, 6.0f, 0.0f);

    if (vlg_lightsOn == 1 || vlg_timeMode == 0)
    {
        glColor3f(1.0f, 1.0f, 0.5f);
        vlg_circle(1.0f);
    }
    else
    {
        glColor3f(1.0f, 0.86f, 0.25f);
        vlg_circle(0.8f);
    }
    glPopMatrix();

    glPopMatrix();
}

void vlg_streetLampC(float x, float y) { // ref#vlg_streetLampC
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    vlg_rect(0.0f, 0.0f, 0.5f, 7.0f, 0.20f, 0.20f, 0.18f);
    vlg_rect(0.5f, 6.5f, 3.0f, 7.0f, 0.20f, 0.20f, 0.18f);

    glPushMatrix();
    glTranslatef(3.0f, 6.0f, 0.0f);

    if (vlg_lightsOn == 1 || vlg_timeMode == 0)
    {
        glColor3f(1.0f, 1.0f, 0.5f);
        vlg_circle(1.0f);
    }
    else
    {
        glColor3f(1.0f, 0.86f, 0.25f);
        vlg_circle(0.8f);
    }
    glPopMatrix();

    glPopMatrix();
}

// =====================================================
//                     WATER WELL
// =====================================================

void vlg_wellA(float x, float y, float scale) { // ref#vlg_wellA
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    vlg_rect(-3.0f, 0.0f, 3.0f, 3.5f, 0.55f, 0.55f, 0.58f);
    vlg_rect(-2.1f, 2.0f, 2.1f, 3.5f, 0.15f, 0.15f, 0.18f);

    glColor3f(0.34f, 0.20f, 0.08f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2f(-2.5f, 3.5f); glVertex2f(-2.5f, 7.5f);
    glVertex2f(2.5f, 3.5f); glVertex2f(2.5f, 7.5f);
    glEnd();

    vlg_triangle(-3.2f, 7.5f, 3.2f, 7.5f, 0.0f, 10.5f, 0.45f, 0.22f, 0.10f);

    glColor3f(0.85f, 0.85f, 0.85f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 7.5f); glVertex2f(0.0f, 2.8f);
    glEnd();

    vlg_rect(-0.5f, 1.8f, 0.5f, 2.8f, 0.35f, 0.35f, 0.38f);
    glPopMatrix();
}

void vlg_wellB(float x, float y, float scale) { // ref#vlg_wellB
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    vlg_rect(-3.0f, 0.0f, 3.0f, 3.5f, 0.55f, 0.55f, 0.58f);
    vlg_rect(-2.1f, 2.0f, 2.1f, 3.5f, 0.15f, 0.15f, 0.18f);

    glColor3f(0.34f, 0.20f, 0.08f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2f(-2.5f, 3.5f); glVertex2f(-2.5f, 7.5f);
    glVertex2f(2.5f, 3.5f); glVertex2f(2.5f, 7.5f);
    glEnd();

    vlg_triangle(-3.2f, 7.5f, 3.2f, 7.5f, 0.0f, 10.5f, 0.45f, 0.22f, 0.10f);

    glColor3f(0.85f, 0.85f, 0.85f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 7.5f); glVertex2f(0.0f, 2.8f);
    glEnd();

    vlg_rect(-0.5f, 1.8f, 0.5f, 2.8f, 0.35f, 0.35f, 0.38f);
    glPopMatrix();
}

// =====================================================
//                    MARKET STALL
// =====================================================

void vlg_stallA(float x, float y, float r, float g, float b) { // ref#vlg_stallA
    vlg_rect(x, y, x + 7.0f, y + 3.0f, 0.48f, 0.28f, 0.10f);
    vlg_rect(x + 0.7f, y + 0.6f, x + 6.3f, y + 2.4f, 0.40f, 0.27f, 0.12f);
    vlg_rect(x - 0.3f, y + 5.5f, x + 7.3f, y + 7.0f, r, g, b); //stripe color
    //roof stripes
    for(int i = 0; i < 4; i++)
    {
        vlg_rect(x + i * 1.8f, y + 5.5f, x + i * 1.8f + 0.9f, y + 7.0f, 0.95f, 0.85f, 0.55f);
    }
    //support pillars
    vlg_rect(x + 0.3f, y + 3.0f, x + 0.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);
    vlg_rect(x + 6.3f, y + 3.0f, x + 6.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);
    //fruits or items
    glColor3f(0.40f, 0.10f, 0.10f);
    for(int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(x + 1.0f + i * 1.1f, y + 1.4f + (i % 2) * 0.35f, 0.0f);
        vlg_circle(0.4f);
        glPopMatrix();
    }
}

void vlg_stallB(float x, float y, float r, float g, float b) { // ref#vlg_stallB
    vlg_rect(x, y, x + 7.0f, y + 3.0f, 0.48f, 0.28f, 0.10f);
    vlg_rect(x + 0.7f, y + 0.6f, x + 6.3f, y + 2.4f, 0.40f, 0.27f, 0.12f);
    vlg_rect(x - 0.3f, y + 5.5f, x + 7.3f, y + 7.0f, r, g, b);

    for(int i = 0; i < 4; i++)
    {
        vlg_rect(x + i * 1.8f, y + 5.5f, x + i * 1.8f + 0.9f, y + 7.0f, 0.95f, 0.85f, 0.55f);
    }

    vlg_rect(x + 0.3f, y + 3.0f, x + 0.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);
    vlg_rect(x + 6.3f, y + 3.0f, x + 6.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);

    glColor3f(0.40f, 0.10f, 0.10f);
    for(int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(x + 1.0f + i * 1.1f, y + 1.4f + (i % 2) * 0.35f, 0.0f);
        vlg_circle(0.4f);
        glPopMatrix();
    }
}

void vlg_stallC(float x, float y, float r, float g, float b) { // ref#vlg_stallC
    vlg_rect(x, y, x + 7.0f, y + 3.0f, 0.48f, 0.28f, 0.10f);
    vlg_rect(x + 0.7f, y + 0.6f, x + 6.3f, y + 2.4f, 0.40f, 0.27f, 0.12f);
    vlg_rect(x - 0.3f, y + 5.5f, x + 7.3f, y + 7.0f, r, g, b);

    for(int i = 0; i < 4; i++)
    {
        vlg_rect(x + i * 1.8f, y + 5.5f, x + i * 1.8f + 0.9f, y + 7.0f, 0.95f, 0.85f, 0.55f);
    }

    vlg_rect(x + 0.3f, y + 3.0f, x + 0.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);
    vlg_rect(x + 6.3f, y + 3.0f, x + 6.7f, y + 6.0f, 0.23f, 0.14f, 0.07f);

    glColor3f(0.40f, 0.10f, 0.10f);
    for(int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(x + 1.0f + i * 1.1f, y + 1.4f + (i % 2) * 0.35f, 0.0f);
        vlg_circle(0.4f);
        glPopMatrix();
    }
}

// =====================================================
//                      FENCE LINE
// =====================================================

void vlg_fenceLineA(float x1, float y1, float x2, float y2, int posts) { // ref#vlg_fenceLineA
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

void vlg_fenceLineB(float x1, float y1, float x2, float y2, int posts) { // ref#vlg_fenceLineB
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

void vlg_bullockCart(float x, float y){ // ref#vlg_bullockCart
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    float cartBody[][2] = {
        {-3.5f, 1.0f},
        {3.5f, 1.0f},
        {3.2f, 4.0f},
        {-3.2f, 4.0f}
    };
    vlg_polygon(0.46f, 0.30f, 0.14f, 4, cartBody);

    glColor3f(0.34f, 0.20f, 0.08f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(3.2f, 2.5f); glVertex2f(6.5f, 1.2f);
    glEnd();

    // Left Wheel
    glPushMatrix();
    glTranslatef(-2.0f, 0.8f, 0.0f);
    glColor3f(0.12f, 0.12f, 0.12f);
    vlg_circle(1.25f);
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
    vlg_circle(1.25f);
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

void vlg_boat(float x, float y, int flipped, float angle = 0.0f){ // ref#vlg_boat
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
    vlg_polygon(0.40f, 0.22f, 0.10f, 4, body);

    vlg_line2D(0, 4, 15, 4, 0.18f, 0.10f, 0.04f, 2.0f);

    vlg_rect(7.0f, 4.0f, 7.5f, 15.0f, 0.25f, 0.16f, 0.08f);

    float sail[][2] =
    { {7.5f, 14.8f},
    {14.0f, 10.0f},
    {7.5f, 8.8f} };
    vlg_polygon(0.96f, 0.96f, 0.93f, 3, sail);

    glPopMatrix();
}

// =====================================================
//                    MOVING BOAT
// =====================================================

void vlg_movingBoat(float xProg){ // ref#vlg_movingBoat
    float bx = xProg;

    // River center line runs roughly from (0, 18.5) to (100, 34.5)
    float by = 18.5f + bx * 0.16f;

    // River rises ~16 units over 100 keeps the vlg_boat's tilt aligned with the water
    float riverAngle = atan2f(16.0f, 100.0f) * 180.0f / PI; //tan inverse

    vlg_boat(bx, by, 0, riverAngle);
}
// =====================================================
//                    Docked BOAT
// =====================================================
void vlg_smallBoat(float x, float y){ // ref#vlg_smallBoat
    float body[][2] = { {x + 2, y}, {x + 8, y}, {x + 10, y + 2}, {x, y + 2} };
    vlg_polygon(0.58f, 0.34f, 0.15f, 4, body);
    vlg_rect(x + 1.0f, y + 2.0f, x + 8.8f, y + 2.6f, 0.36f, 0.22f, 0.08f);
}

void vlg_dockLog(float x, float y){ // ref#vlg_dockLog
    vlg_rect(x, y, x + 5.0f, y + 1.0f, 0.30f, 0.19f, 0.09f);
    vlg_rect(x - 1.4f, y - 3.5f, x + 0.6f, y + 1.4f, 0.24f, 0.15f, 0.07f);
}

// =====================================================
//                    MOVING BOAT 2
// =====================================================

void vlg_movingBoat2(float xProg){ // ref#vlg_movingBoat2
    float bx = xProg;

    // Hugs the lower/bottom part of the river band
    float by = 16.0f + bx * 0.15f;

    float riverAngle = atan2f(15.0f, 100.0f) * 180.0f / PI;

    // flipped = 1 so it visually faces the direction it's travelling (right -> left)
    vlg_boat(bx, by, 1, riverAngle);
}
// =====================================================
//                     WATER RIPPLE
// =====================================================

void vlg_ripple(float x, float y, float w){ // ref#vlg_ripple
    vlg_line2D(x, y, x + w, y, 0.08f, 0.55f, 0.72f, 1.3f);
    vlg_line2D(x + w * 0.20f, y + 1.2f, x + w * 0.65f, y + 1.2f, 0.08f, 0.55f, 0.72f, 1.0f);
}

// =====================================================
//                     VILLAGE PEOPLE
// =====================================================

void vlg_personA(float x, float y, float scale, float bodyR, float bodyG, float bodyB) { // ref#vlg_personA
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glColor3f(0.72f, 0.48f, 0.30f);
    vlg_circle(0.9f);
    glPopMatrix();

    vlg_rect(-1.0f, 0.0f, 1.0f, 4.0f, bodyR, bodyG, bodyB);

    vlg_line2D(-0.5f, 0.0f, -0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);
    vlg_line2D(0.5f, 0.0f, 0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);

    glPopMatrix();
}

void vlg_personB(float x, float y, float scale, float bodyR, float bodyG, float bodyB) { // ref#vlg_personB
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glColor3f(0.72f, 0.48f, 0.30f);
    vlg_circle(0.9f);
    glPopMatrix();

    vlg_rect(-1.0f, 0.0f, 1.0f, 4.0f, bodyR, bodyG, bodyB);

    vlg_line2D(-0.5f, 0.0f, -0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);
    vlg_line2D(0.5f, 0.0f, 0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);

    glPopMatrix();
}

void vlg_personC(float x, float y, float scale, float bodyR, float bodyG, float bodyB) { // ref#vlg_personC
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glColor3f(0.72f, 0.48f, 0.30f);
    vlg_circle(0.9f);
    glPopMatrix();

    vlg_rect(-1.0f, 0.0f, 1.0f, 4.0f, bodyR, bodyG, bodyB);

    vlg_line2D(-0.5f, 0.0f, -0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);
    vlg_line2D(0.5f, 0.0f, 0.8f, -2.2f, 0.10f, 0.10f, 0.10f, 1.7f);

    glPopMatrix();
}

// =====================================================
//                        BUSH
// =====================================================

void vlg_bushA(float x, float y, float s) { // ref#vlg_bushA
    glColor3f(0.20f, 0.42f, 0.12f);

    glPushMatrix();
    glTranslatef(x, y, 0);
    vlg_circle(1.6f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 1.9f * s, y + 0.6f * s, 0);
    vlg_circle(2.1f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 3.8f * s, y, 0);
    vlg_circle(1.6f * s);
    glPopMatrix();
}

void vlg_bushB(float x, float y, float s) { // ref#vlg_bushB
    glColor3f(0.20f, 0.42f, 0.12f);

    glPushMatrix();
    glTranslatef(x, y, 0);
    vlg_circle(1.6f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 1.9f * s, y + 0.6f * s, 0);
    vlg_circle(2.1f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 3.8f * s, y, 0);
    vlg_circle(1.6f * s);
    glPopMatrix();
}

void vlg_bushC(float x, float y, float s) { // ref#vlg_bushC
    glColor3f(0.20f, 0.42f, 0.12f);

    glPushMatrix();
    glTranslatef(x, y, 0);
    vlg_circle(1.6f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 1.9f * s, y + 0.6f * s, 0);
    vlg_circle(2.1f * s);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 3.8f * s, y, 0);
    vlg_circle(1.6f * s);
    glPopMatrix();
}

void vlg_grassMark(float x, float y){ // ref#vlg_grassMark
    vlg_line2D(x, y, x - 1.0f, y + 2.0f, 0.20f, 0.38f, 0.10f, 1.2f);
    vlg_line2D(x, y, x + 0.8f, y + 2.2f, 0.20f, 0.38f, 0.10f, 1.2f);
    vlg_line2D(x, y, x, y + 2.4f, 0.20f, 0.38f, 0.10f, 1.0f);
}

// =====================================================
//                        RIVER
// =====================================================

void vlg_riverBand()
{ // ref#vlg_riverBand
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
        vlg_polygon(0.20f, 0.67f, 0.84f, 4, quad);
    }

    for(int i = 0; i < 4; i++)
    {
        vlg_line2D(xs[i], topY[i], xs[i+1], topY[i+1], 0.12f, 0.32f, 0.36f, 2.0f);
    }

    vlg_line2D(xs[0], botY[0], xs[4], botY[4], 0.12f, 0.32f, 0.36f, 2.0f);

    vlg_ripple(7, 17, 6);
    vlg_ripple(23, 20, 7);
    vlg_ripple(44, 24, 6);
    vlg_ripple(57, 27, 6);
    vlg_ripple(82, 32, 7);
    vlg_ripple(89, 37, 5);
}

// =====================================================
//                        ROAD
// =====================================================

void vlg_road()
{ // ref#vlg_road
    float roadShape[][2] = { {0, 30}, {100, 57}, {100, 64}, {0, 37} };
    vlg_polygon(0.25f, 0.25f, 0.27f, 4, roadShape);

    vlg_line2D(0, 30, 100, 57, 0.95f, 0.95f, 0.95f, 2.0f);
    vlg_line2D(0, 37, 100, 64, 0.95f, 0.95f, 0.95f, 2.0f);

    for(int i = 0; i < 8; i++)
    {
        float x1 = i * 14.0f - 1.0f;
        float y1 = 33.5f + i * 3.78f;
        float x2 = x1 + 7.0f;
        float y2 = y1 + 1.9f;
        vlg_line2D(x1, y1, x2, y2, 1.0f, 1.0f, 1.0f, 2.2f);
    }
}

// =====================================================
//                     CAR WHEEL
// =====================================================

void vlg_wheel(float x, float y, float angle)
{ // ref#vlg_wheel
    glPushMatrix();

    glTranslatef(x, y, 0);
    glRotatef(angle, 0, 0, 1);

    // Black vlg_wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    vlg_circle(1.4f);

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
    vlg_circle(0.5f);

    glPopMatrix();
}

// =====================================================
//                         CAR
// =====================================================

void vlg_car(float x, float y, float r, float g, float b, int direction, float roadAngle, float wheelSpin, float scale)
{ // ref#vlg_car
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
    vlg_wheel(-3.2f, 0, wheelSpin);
    vlg_wheel(3.2f, 0, wheelSpin);

    glPopMatrix();
}

// =====================================================
//                   MOVING CAR
// =====================================================

void vlg_movingCar(float xProg)
{ // ref#vlg_movingCar
    // xProg is driven directly by vlg_vehicleMove, which vlg_update() already
    // resets cleanly at each end - no modulo wraparound needed here.
    // (fmod combined with a negative-to-positive range was causing the
    // vlg_car to snap through the wrap point multiple times before settling.)
    float cx = xProg;

    // Center of the lane (average of vlg_road's top/bottom edges)
    float cy = 35.5f + cx * 0.27f;

    // Road rises 27 units over 100 - same slope as vlg_road()
    float roadAngle = atan2f(27.0f, 100.0f) * 180.0f / PI;

    vlg_car(cx, cy, 0.82f, 0.22f, 0.18f, 1, roadAngle, vlg_carWheelAngle, 0.75f);
}

// =====================================================
//                     MAIN VILLAGE SCENE
// =====================================================

void vlg_village()
{ // ref#vlg_village
    // Time of day color setup
    float skyR, skyG, skyB;

    if (vlg_timeMode == 0)      // Night (N)
    {
        skyR = 0.06f; skyG = 0.08f; skyB = 0.18f;
    }
    else if (vlg_timeMode == 1) // Dawn (D)
    {
        skyR = 0.85f; skyG = 0.50f; skyB = 0.35f;
    }
    else if (vlg_timeMode == 2) // Day (F)
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
    vlg_rect(0, 40, 100, 100, skyR, skyG, skyB);

    if (vlg_timeMode == 0)
    {
        vlg_moon();
    }
    else
    {
        vlg_sun();
    }

    // Clouds
    glPushMatrix();
    glTranslatef(vlg_cloudMove, 0, 0);
    vlg_cloud(18, 87);
    vlg_cloud(33, 80);
    vlg_cloud(61, 90);
    glPopMatrix();

    vlg_hills();

    // Green Field
    vlg_rect(0, 0, 100, 52, 0.42f, 0.62f, 0.30f);
    vlg_rect(0, 48, 100, 63, 0.40f, 0.60f, 0.28f);

    vlg_riverBand();
    vlg_road();

    // Grass Marks (12)
    vlg_grassMark(10, 5);
    vlg_grassMark(20, 10);
    vlg_grassMark(41, 8);
    vlg_grassMark(53, 12);
    vlg_grassMark(76, 9);
    vlg_grassMark(84, 16);
    vlg_grassMark(96, 9);
    vlg_grassMark(5, 44);
    vlg_grassMark(15, 47);
    vlg_grassMark(58, 56);
    vlg_grassMark(68, 58);
    vlg_grassMark(81, 41);

    // Bushes (7)
    vlg_bushA(28, 6, 1.0f); // ref#bushObj1
    vlg_bushB(67, 5, 1.0f); // ref#bushObj2
    vlg_bushC(25, 33, 0.9f); // ref#bushObj3
    vlg_bushA(94, 47, 0.8f); // ref#bushObj4
    vlg_bushB(72, 60, 0.7f); // ref#bushObj5
    vlg_bushC(53, 55, 0.7f); // ref#bushObj6
    vlg_bushA(10, 45, 0.9f); // ref#bushObj7

    // Fences (2)
    vlg_fenceLineA(0.0f, 32.0f, 100.0f, 60.0f, 12); // ref#fenceLineObj1
    vlg_fenceLineB(0.0f, 40.0f, 100.0f, 67.0f, 9); // ref#fenceLineObj2

    // Trees (10 total: 5 background + 5 small near field)
    vlg_treeA(5, 57, 1.1f); // ref#treeObj1
    vlg_treeB(20, 62, 1.2f); // ref#treeObj2
    vlg_treeC(35, 60, 1.25f); // ref#treeObj3
    vlg_treeA(48, 61, 1.1f); // ref#treeObj4
    vlg_treeB(63, 58, 1.0f); // ref#treeObj5

    vlg_treeC(5, 47, 0.8f); // ref#treeObj6
    vlg_treeA(20, 45, 0.6f); // ref#treeObj7
    vlg_treeB(66, 40, 0.8f); // ref#treeObj8
    vlg_treeC(72, 10, 0.9f); // ref#treeObj9
    vlg_treeA(95, 12, 0.7f); // ref#treeObj10

    // Small Houses (4)
    vlg_houseA(7, 53, 13, 9, 0.92f, 0.83f, 0.55f, 0.90f, 0.30f, 0.16f); // ref#houseObj1
    vlg_houseB(22, 56, 12, 8, 0.85f, 0.74f, 0.45f, 0.75f, 0.18f, 0.10f); // ref#houseObj2
    vlg_houseC(37, 58, 10, 7, 0.88f, 0.77f, 0.52f, 0.82f, 0.25f, 0.10f); // ref#houseObj3
    vlg_houseA(50, 59, 8, 7, 0.75f, 0.45f, 0.31f, 0.40f, 0.25f, 0.15f); // ref#houseObj4

    // Water Wells (2)
    vlg_wellA(48.0, 54.0, 1.00); // ref#wellObj1
    vlg_wellB(60.0f, 6.0f, 1.25f); // ref#wellObj2

    // Market Stalls (3)
    vlg_stallA(23, 50, 0.88f, 0.08f, 0.08f); // ref#stallObj1
    vlg_stallB(31, 52, 0.95f, 0.72f, 0.06f); // ref#stallObj2
    vlg_stallC(80, 7, 0.90f, 0.08f, 0.08f); // ref#stallObj3

    // Village People (4)
    vlg_personA(39, 55, 0.65f, 0.25f, 0.30f, 0.75f); // ref#personObj1
    vlg_personB(42, 55, 0.65f, 0.80f, 0.20f, 0.30f); // ref#personObj2
    vlg_personC(40, 52, 0.7f, 0.30f, 0.55f, 0.75f); // ref#personObj3
    vlg_personA(43, 52, 0.7f, 0.30f, 0.55f, 0.75f); // ref#personObj4

    // Bullock Cart (Static) (1)
    vlg_bullockCart(55, 39); // ref#bullockCartObj1

    vlg_streetLampA(39.0f, 48.0f); // ref#streetLampObj1
    vlg_streetLampB(77.0f, 58.0f); // ref#streetLampObj2


    // Moving Car along vlg_road
    vlg_movingCar(vlg_vehicleMove); // ref#movingCarObj1

    //Small Houses below vlg_road(2)
    vlg_houseB(82, 45, 10, 6, 0.90f, 0.79f, 0.53f, 0.95f, 0.25f, 0.12f); // ref#houseObj5
    vlg_houseC(75, 44, 9, 5, 0.72f, 0.42f, 0.30f, 0.45f, 0.25f, 0.13f); // ref#houseObj6


      // Street Lamps bottom(3)
    vlg_streetLampC(15.0f, 32.0f); // ref#streetLampObj3
    vlg_streetLampA(62.0f, 46.0f); // ref#streetLampObj4
    vlg_streetLampB(95.0f, 54.0f); // ref#streetLampObj5

    // Static vlg_boat at bank
    vlg_dockLog(41, 38); // ref#dockLogObj1
    vlg_smallBoat(38, 32); // ref#smallBoatObj1
    vlg_line2D(47.0f, 33.6f, 45.0f, 38.0f, 0.30f, 0.20f, 0.10f, 1.5f);
    // Boats (1 moving across the river + 1 docked)
    vlg_movingBoat(vlg_boatMove); // ref#movingBoatObj1
    vlg_movingBoat2(vlg_boatMove2); // ref#movingBoat2Obj1


    glutSwapBuffers();
}

// =====================================================
//                   UPDATE ANIMATION
// =====================================================

void vlg_update(int value)
{ // ref#vlg_update
    if(vlg_animationOn == 1)
    {
        vlg_cloudMove += 0.03f;
        if(vlg_cloudMove > 105.0f) vlg_cloudMove = -105.0f;

        // Boat travels the full river, spawning just before the left
        // edge and resetting once it clears the right edge - same clean
        // single-reset pattern as the vlg_car (no fmod wraparound).
        vlg_boatMove += 0.04f;
        if(vlg_boatMove > 115.0f) vlg_boatMove = -15.0f;

        vlg_boatMove2 -= 0.03f;
        if(vlg_boatMove2 < -15.0f) vlg_boatMove2 = 115.0f;

        if(vlg_vehicleMoving == 1)
        {
            vlg_vehicleMove += 0.20f;
            if(vlg_vehicleMove > 105.0f) vlg_vehicleMove = -5.0f;

            vlg_carWheelAngle -= 5.0f;
            if(vlg_carWheelAngle < -360.0f) vlg_carWheelAngle = 0.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, vlg_update, 0);
}

// =====================================================
//                 MOUSE INTERACTIONS
// =====================================================

void vlg_handleMouse(int button, int state, int x, int y)
{ // ref#vlg_handleMouse
    if(state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            // Toggle all animations start/stop
            vlg_animationOn = !vlg_animationOn;
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            // Right click boosts vlg_boat sail
            vlg_boatMove += 2.0f;
        }
    }
    glutPostRedisplay();
}

// =====================================================
//                 KEYBOARD INTERACTIONS
// =====================================================

void vlg_handleKeypress(unsigned char key, int x, int y)
{ // ref#vlg_handleKeypress
    switch(key)
    {
        case 'c':
        case 'C':
            std::cout << "[Scene Switch] Transitioning to Next Scene..." << std::endl;
            break;

        case '6':
            vlg_vehicleMoving = 1; // Move vehicle
            break;

        case '5':
            vlg_vehicleMoving = 0; // Stop vehicle
            break;

        case 'd':
        case 'D':
            vlg_timeMode = 1; // Dawn
            break;

        case 'f':
        case 'F':
            vlg_timeMode = 2; // Day
            break;

        case 'e':
        case 'E':
            vlg_timeMode = 3; // Evening
            break;

        case 'n':
        case 'N':
            vlg_timeMode = 0; // Night
            break;

        case 'l':
        case 'L':
            vlg_lightsOn = !vlg_lightsOn; // Toggle lights
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

void vlg_init()
{ // ref#vlg_init
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// =====================================================
//                        MAIN
// =====================================================


// =====================================================================
//  SCENE 2: TOWN
// =====================================================================

//GLOBAL VARIABLES

// My twn_car position
float twn_myCarMove = -8.0f;

// Opposite cars position
float twn_otherCar1 = 108.0f;
float twn_otherCar2 = 68.0f;
float twn_otherCar3 = 28.0f;

// Cloud movement
float twn_cloudMove = 0.0f;

// Wheel rotation
float twn_myWheelAngle = 0.0f;
float twn_trafficWheelAngle = 0.0f;

// All animation control
int twn_animationOn = 1;

// My twn_car control
int twn_vehicleOn = 1;

// Street light control
int twn_lightsOn = 1;
// 0 = Dawn
// 1 = Day
// 2 = Evening
// 3 = Night
int twn_timeMode = 1;


     //   RECTANGLE FUNCTION
void twn_rect(float x1, float y1,float x2, float y2,float r, float g, float b)   // ref#rectHelper
{
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glEnd();
}

void twn_circle(float radius) // ref#circleHelper
{
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0.0f, 0.0f);

    for(int i = 0; i <= 360; i++)
    {
        float angle = i * PI / 180.0f;

        glVertex2f(
            radius * cos(angle),
            radius * sin(angle)
        );
    }

    glEnd();
}

void twn_windowRect(float x1, float y1,float x2, float y2)  // ref#windowHelper
{
    if(twn_timeMode == 3)
    {
        twn_rect( x1, y1,x2, y2,1.0f, 0.8f, 0.2f);
    }
    else
    {
        twn_rect( x1, y1,x2, y2, 0.7f, 0.9f, 1.0f);
    }
}


void twn_sun()  // ref#sunFunction
{
    if(twn_timeMode == 3)
    {
        return;
    }

    glPushMatrix();

    // Dawn
    if(twn_timeMode == 0)
    {
        glTranslatef(12.0f,86.0f,0.0f);

        glColor3f(1.0f,0.45f,0.10f);
    }
    // Day
    else if(twn_timeMode == 1)
    {
        glTranslatef(88.0f,87.0f,0.0f);

        glColor3f(1.0f, 0.90f,0.0f);
    }

    // Evening
    else
    {
        glTranslatef(88.0f,78.0f,0.0f);

        glColor3f(1.0f,0.35f,0.0f);
    }

    twn_circle(4.5f);

    glPopMatrix();
}


        // BUILDING 1
void twn_building1() // ref#building1Function
{
    twn_rect(1.5f, 52,16.0f, 78,0.20f, 0.40f, 1.0f);

    twn_windowRect(4.0f, 61,7.0f, 66);

    twn_windowRect(10.5f, 61,13.5f, 66);

    twn_windowRect(4.0f, 69,7.0f, 74);

    twn_windowRect(10.5f, 69,13.5f, 74);
}

              // BUILDING 2
void twn_building2()  // ref#building2Function
{
    twn_rect(17.0f, 52,32.0f, 90,0.65f, 0.30f, 0.25f);

    twn_windowRect(19.5f, 61,22.5f, 66);

    twn_windowRect(26.5f, 61,29.5f, 66);

    twn_windowRect(19.5f, 71,22.5f, 76);

    twn_windowRect(26.5f, 71,29.5f, 76);

    twn_windowRect(19.5f, 81,22.5f, 86);

    twn_windowRect(26.5f, 81,29.5f, 86);
}


    //  BUILDING 3
void twn_building3()  // ref#building3Function
{
    twn_rect(33.0f, 52,47.5f, 75,0.35f, 0.60f, 0.75f);

    twn_windowRect(35.5f, 60,38.5f, 65);

    twn_windowRect(42.0f, 60,45.0f, 65);

    twn_windowRect(35.5f, 68,38.5f, 72);

    twn_windowRect(42.0f, 68,45.0f, 72);
}


        //  BUILDING 4
void twn_building4()  // ref#building4Function
{
    twn_rect(48.0f, 39,64.5f, 83,0.45f, 0.60f, 0.40f);

    // Door
    twn_rect(54.3f, 39,58.3f, 48,0.30f, 0.15f, 0.05f);

    twn_windowRect(50.5f, 52,54.0f, 57);

    twn_windowRect(58.5f, 52,62.0f, 57);

    twn_windowRect(50.5f, 63,54.0f, 68);

    twn_windowRect(58.5f, 63,62.0f, 68);

    twn_windowRect(50.5f, 73,54.0f, 78);

    twn_windowRect(58.5f, 73,62.0f, 78);
}


            // SHOP
void twn_shop(float x1,float x2,float r,float g,float b)  // ref#shopStyleA
{
    // Shop body
    twn_rect(x1, 39,x2, 52,r, g, b);

    // Red roof
    twn_rect(x1 - 0.3f, 50.5f,x2 + 0.3f, 52,0.80f, 0.10f, 0.10f);

    // Window
    twn_windowRect(x1 + 1.0f,43,x1 + 3.5f,47.5f);

    // Door
    twn_rect(x2 - 4.0f,39,x2 - 1.0f,47,0.15f, 0.15f, 0.15f);
}


        // STATIC TREE
void twn_tree(float x, float y)  // ref#treeStyleA
{
    glPushMatrix();

    glTranslatef(x,y,0.0f);

    // Tree trunk
    glColor3f(0.50f,0.28f,0.08f);

    glBegin(GL_POLYGON);

    glVertex2f(-0.7f, 0.0f);
    glVertex2f(0.7f, 0.0f);
    glVertex2f(0.7f, 7.0f);
    glVertex2f(-0.7f, 7.0f);

    glEnd();

    // Lower leaves
    glColor3f(0.05f,0.55f,0.08f);

    glBegin(GL_POLYGON);

    glVertex2f(-3.7f, 6.0f);
    glVertex2f(0.0f, 14.0f);
    glVertex2f(3.7f, 6.0f);

    glEnd();

    // Upper leaves
    glColor3f(0.00f,0.75f,0.05f);

    glBegin(GL_POLYGON);

    glVertex2f(-2.8f, 10.0f);
    glVertex2f(0.0f, 17.0f);
    glVertex2f(2.8f, 10.0f);

    glEnd();


    glPopMatrix();
}


       //  CLOUD
void twn_cloud(float x, float y)  // ref#cloudStyleA
{
    glColor3f(1.0f,1.0f,1.0f);


    glPushMatrix();

    glTranslatef(x,y,0);

    twn_circle(3.0f);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(x + 4,y + 1,0);

    twn_circle(4.0f);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(x + 8,y,0);

    twn_circle(3.0f);

    glPopMatrix();
}


        //  BENCH
void twn_bench(float x, float y) // ref#benchStyleA
{
    // Back
    twn_rect(x,y + 3.0f,x + 7.0f,y + 4.0f,0.55f, 0.30f, 0.10f);

    // Middle wood
    twn_rect(x,y + 1.8f,x + 7.0f,y + 2.6f,0.65f, 0.38f, 0.12f);

    // Seat
    twn_rect(x,y,x + 7.0f,y + 1.0f,0.60f, 0.34f, 0.10f);

    // Left leg
    twn_rect(x + 1.0f,y - 2.0f,x + 1.8f,y,0.18f, 0.18f, 0.18f);

    // Right leg
    twn_rect(x + 5.2f,y - 2.0f,x + 6.0f,y,0.18f, 0.18f, 0.18f);
}


         // SMALL PARK
void twn_park()  // ref#parkFunction
{
    // Grass
    twn_rect(65, 39,100, 46,0.28f, 0.62f, 0.25f);

    // Back grass
    twn_rect(65, 45,100, 47,0.22f, 0.55f, 0.20f);

    // Park walking path
    glColor3f(0.82f,0.76f,0.58f);

    glBegin(GL_POLYGON);

    glVertex2f(67.0f, 39.3f);
    glVertex2f(98.0f, 39.3f);
    glVertex2f(94.0f, 43.0f);
    glVertex2f(70.0f, 43.0f);

    glEnd();

    twn_tree(68,42); // ref#treeObj1

    twn_tree(78,42); // ref#treeObj2

    twn_tree(90,42); // ref#treeObj3

    twn_tree(98,42); // ref#treeObj4

    twn_bench(70,43); // ref#benchObj1

    twn_bench(84,43);  // ref#benchObj2
}
              //STREET LAMP

void twn_lamp(float x)  // ref#lampStyleA
{
    // Pole
    twn_rect(x, 35,x + 0.5f, 48,0.15f, 0.15f, 0.15f);

    // Top arm
    twn_rect(x, 47.5f,x + 3, 48,0.15f, 0.15f, 0.15f);

    glPushMatrix();

    glTranslatef(x + 3,47.0f,0);


    if(twn_timeMode == 3 &&
            twn_lightsOn == 1)
    {
        glColor3f(1.0f,1.0f,0.0f);

        twn_circle(1.3f);
    }

    else
    {
        glColor3f(0.3f,0.3f,0.3f);

        twn_circle(0.8f);
    }


    glPopMatrix();
}
     // FOOTPATH

void twn_walkingRoad()  // ref#footpathFunction
{
    // Upper footpath
    twn_rect(0, 34,100, 39,0.75f, 0.75f, 0.70f);

    // White edge
    twn_rect(0, 34,100, 34.6f,0.95f, 0.95f, 0.95f);

    // Tiles
    glColor3f(0.55f,0.55f,0.55f);

    glLineWidth(1.0f);

    for(int i = 0; i <= 100; i += 10)
    {
        glBegin(GL_LINES);

        glVertex2f(i, 34);
        glVertex2f(i, 39);

        glEnd();
    }
    // Lower footpath
    twn_rect(0, 0,100, 6,0.75f, 0.75f, 0.70f);

    // White edge
    twn_rect(0, 5.4f,100, 6,0.95f, 0.95f, 0.95f);
    // Tiles
    glColor3f(0.55f,0.55f,0.55f);


    for(int i = 0; i <= 100; i += 10)
    {
        glBegin(GL_LINES);

        glVertex2f(i, 0);
        glVertex2f(i, 6);

        glEnd();
    }
}
//  ROAD
void twn_road()  // ref#roadFunction
{
    // Main twn_road
    twn_rect(0, 6,100, 34,0.22f, 0.22f, 0.22f);

    for(int i = 0; i < 100; i += 14)
    {
        twn_rect(i, 19.5f,i + 8, 20.5f,1.0f, 1.0f, 1.0f);
    }
}

//CAR WHEEL
void twn_wheel(float x,float y,float angle)  // ref#wheelHelper
{
    glPushMatrix();

    glTranslatef(x,y,0);

    glRotatef(angle,0,0,1);

    // Black twn_wheel
    glColor3f(0.0f,0.0f,0.0f);

    twn_circle(1.4f);

    // White lines
    glColor3f(1.0f,1.0f,1.0f);

    glLineWidth(2.0f);

    glBegin(GL_LINES);

    glVertex2f(-1, 0);
    glVertex2f(1, 0);

    glVertex2f(0, -1);
    glVertex2f(0, 1);

    glEnd();

    glColor3f(0.6f,0.6f,0.6f);

    twn_circle(0.5f);

    glPopMatrix();
}
               //CAR
void twn_car(float x, float y,float r,float g,float b,int direction,float angle)  // ref#carStyleA
{
    glPushMatrix();

    glTranslatef(x,y,0);

    // Flip opposite cars horizontally
    if(direction == -1)
    {
        glScalef(-1.0f,1.0f,1.0f);
    }

    // Car body
    glColor3f(r,g,b);

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
    glColor3f(0.4f,0.8f,1.0f);

    glBegin(GL_POLYGON);

    glVertex2f(-2.8f, 4.5f);
    glVertex2f(-1.7f, 6.4f);
    glVertex2f(-0.3f, 6.4f);
    glVertex2f(-0.3f, 4.5f);

    glEnd();


    glBegin(GL_POLYGON);

    glVertex2f(0.3f, 4.5f);
    glVertex2f(0.3f, 6.4f);
    glVertex2f(1.7f, 6.4f);
    glVertex2f(2.8f, 4.5f);

    glEnd();


    twn_wheel(-3.2f,0,angle);

    twn_wheel(3.2f,0,angle);


    glPopMatrix();
}
// TOWN SCENE
void twn_town()  // ref#townScene
{
    if(twn_timeMode == 0)
    {
        glClearColor(0.95f,0.55f,0.45f,1.0f);
    }

    else if(twn_timeMode == 1)
    {
        glClearColor(0.45f,0.75f,1.0f,1.0f);
    }

    else if(twn_timeMode == 2)
    {
        glClearColor(0.80f,0.35f,0.25f,1.0f);
    }

    else
    {
        glClearColor(0.03f,0.05f,0.18f,1.0f);
    }


    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    twn_sun();  // ref#sunObj1

    glPushMatrix();

    glTranslatef(twn_cloudMove,0,0);

    twn_cloud(5, 94);  // ref#cloudObj1
    twn_cloud(40, 94);  // ref#cloudObj2
    twn_cloud(70, 92);  // ref#cloudObj3

    glPopMatrix();


    twn_building1();  // ref#buildingObj1
    twn_building2();   // ref#buildingObj2
    twn_building3();   // ref#buildingObj3
    twn_building4();   // ref#buildingObj4


    twn_shop(1.5f,16.0f,0.80f,0.50f,0.20f);  // ref#shopObj1


    twn_shop(17.0f,32.0f,0.20f,0.70f,0.70f);   // ref#shopObj2


    twn_shop(33.0f,47.5f,0.70f,0.30f,0.60f);  // ref#shopObj3

    twn_park();  // ref#parkObj1

    // Footpath
    twn_walkingRoad();   // ref#footpathObj1

    twn_lamp(8);   // ref#lampObj
    twn_lamp(34);   // ref#lampObj2
    twn_lamp(62);   // ref#lampObj3
    twn_lamp(88);   // ref#lampObj4

    twn_road();   // ref#roadObj1

    // OPPOSITE CARS
    // RIGHT -> LEFT

    twn_car(twn_otherCar1,24.0f,1.0f,1.0f,0.0f,-1,twn_trafficWheelAngle);  // ref#trafficCarObj1


    twn_car(twn_otherCar2,24.0f,0.0f,0.7f,1.0f,-1,twn_trafficWheelAngle);  // ref#trafficCarObj2


    twn_car(twn_otherCar3,24.0f,0.7f,0.2f,0.8f,-1,twn_trafficWheelAngle);  // ref#trafficCarObj3

    // MY RED CAR
    // LEFT -> RIGHT

    twn_car(twn_myCarMove,10.5f,1.0f,0.0f,0.0f,1,twn_myWheelAngle);  // ref#myCarObj1

    glutSwapBuffers();
}

void twn_nextScene()   // ref#twn_nextScene
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

void twn_update(int value)   // ref#updateAnimation
{
    if(twn_animationOn == 1)
    {
        // Cloud movement
        twn_cloudMove += 0.05f;


        if(twn_cloudMove > 105.0f)
        {
            twn_cloudMove = -100.0f;
        }
        // OPPOSITE CARS
        // RIGHT -> LEFT

        twn_otherCar1 -= 0.18f;
        twn_otherCar2 -= 0.18f;
        twn_otherCar3 -= 0.18f;


        if(twn_otherCar1 < -8.0f)
        {
            twn_otherCar1 = 108.0f;
        }


        if(twn_otherCar2 < -8.0f)
        {
            twn_otherCar2 = 108.0f;
        }


        if(twn_otherCar3 < -8.0f)
        {
            twn_otherCar3 = 108.0f;
        }


        twn_trafficWheelAngle -= 5.0f;


        if(twn_trafficWheelAngle < -360.0f)
        {
            twn_trafficWheelAngle = 0.0f;
        }
        // MY CAR
        // LEFT -> RIGHT

        if(twn_vehicleOn == 1)
        {
            twn_myCarMove += 0.20f;

            twn_myWheelAngle -= 5.0f;


            if(twn_myCarMove > 108.0f)
            {
                twn_myCarMove = -8.0f;
            }


            if(twn_myWheelAngle < -360.0f)
            {
                twn_myWheelAngle = 0.0f;
            }
        }
    }


    glutPostRedisplay();


    glutTimerFunc(20,twn_update,0);
}

void twn_handleMouse(int button,int state,int x,int y)  // ref#mouseControl
{

    if(state == GLUT_DOWN)
    {

        if(button == GLUT_LEFT_BUTTON)
        {
            twn_animationOn = 1;
        }

        else if(button == GLUT_RIGHT_BUTTON)
        {
            twn_animationOn = 0;
        }
    }


    glutPostRedisplay();
}

void twn_handleKeypress(unsigned char key,int x,int y)   // ref#keyboardControl
{
    switch(key)
    {
    // C = Next Scene
    case 'c':
    case 'C':

        glutDisplayFunc(
            twn_nextScene
        );

        glutPostRedisplay();

        break;
    // Q = Dawn
    case 'q':
    case 'Q':

        twn_timeMode = 0;

        glutPostRedisplay();

        break;
    // W = Day
    case 'w':
    case 'W':

        twn_timeMode = 1;

        glutPostRedisplay();

        break;
    // E = Evening
    case 'e':
    case 'E':

        twn_timeMode = 2;

        glutPostRedisplay();

        break;
    // R = Night
    case 'r':
    case 'R':

        twn_timeMode = 3;

        glutPostRedisplay();

        break;
    // T = Light ON/OFF
    case 't':
    case 'T':

        if(twn_lightsOn == 1)
        {
            twn_lightsOn = 0;
        }

        else
        {
            twn_lightsOn = 1;
        }


        glutPostRedisplay();

        break;
    }
}

void twn_handleSpecialKey(int key,int x,int y)  // ref#specialKeyControl
{
    switch(key)
    {
    // UP = My twn_car move
    case GLUT_KEY_UP:

        twn_vehicleOn = 1;

        break;
    // DOWN = My twn_car stop
    case GLUT_KEY_DOWN:

        twn_vehicleOn = 0;

        break;
    }

    glutPostRedisplay();
}

void twn_init()  // ref#initFunction
{
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();


    gluOrtho2D(0,100,0,100);

    glMatrixMode(GL_MODELVIEW);
}


// =====================================================================
//  SCENE 3: CITY
// =====================================================================

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
// ANIM-01 : cty_update()
// ANIM-02 : cty_keyboard()
// ANIM-03 : cty_mouse()
// ANIM-04 : Vehicle movement
// ANIM-05 : Cloud movement
// ANIM-06 : Traffic state cycle

// Variables
float cty_car = -25.0f;
float cty_car1 = 110.0f;
float cty_bus1 = 140.0f;
float cty_car2 = 172.0f;

float cty_cloud1 = 5.0f;
float cty_cloud2 = 38.0f;
float cty_cloud3 = 72.0f;

float cty_tree1 = 5.0f;
float cty_tree2 = 67.0f;
float cty_tree3 = 99.0f;

float cty_lamppost1 = 18.0f;
float cty_lamppost2 = 38.0f;
float cty_lamppost3 = 58.0f;
float cty_lamppost4 = 68.0f;

bool cty_allAnimation = true;
bool cty_vehicleMoving = true;
bool cty_lightsOn = true;

int cty_timeMode = 1;
int cty_trafficState = 0;

// Basic Shapes

void cty_rectangle(float x1, float y1, float x2, float y2)
{
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void cty_circle(float x, float y, float radius)
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

void cty_line(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void cty_drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// Sun & Moon

void cty_drawSunMoon()
{
    // Object ID: OBJ-02

    if (cty_timeMode == 3)
    {
        glColor3f(1.0f, 1.0f, 0.75f);
        cty_circle(84.0f, 85.0f, 5.0f);

        glColor3f(0.06f, 0.08f, 0.20f);
        cty_circle(86.0f, 87.0f, 5.0f);
    }
    else
    {
        if (cty_timeMode == 0)
            glColor3f(1.0f, 0.45f, 0.15f);
        else if (cty_timeMode == 2)
            glColor3f(1.0f, 0.30f, 0.05f);
        else
            glColor3f(1.0f, 0.85f, 0.10f);

        cty_circle(84.0f, 85.0f, 5.0f);
    }
}

// Clouds

void cty_drawCloud(float x, float y)
{
    // Object ID: OBJ-04 / OBJ-05 / OBJ-06

    if (cty_timeMode == 3)
        glColor3f(0.42f, 0.45f, 0.55f);
    else
        glColor3f(1.0f, 1.0f, 1.0f);

    cty_circle(x, y, 3.0f);
    cty_circle(x + 4.0f, y + 1.0f, 3.5f);
    cty_circle(x + 8.0f, y, 3.0f);

    cty_rectangle(x - 2.0f, y - 2.0f, x + 10.0f, y + 1.0f);
}

// Sky

void cty_drawSky()
{
    // Object ID: OBJ-01

    if (cty_timeMode == 0)
        glColor3f(0.95f, 0.55f, 0.35f);
    else if (cty_timeMode == 1)
        glColor3f(0.35f, 0.72f, 1.0f);
    else if (cty_timeMode == 2)
        glColor3f(0.70f, 0.32f, 0.38f);
    else
        glColor3f(0.05f, 0.07f, 0.20f);

    cty_rectangle(0.0f, 30.0f, 100.0f, 100.0f);

    cty_drawSunMoon();

    if (cty_timeMode == 3)
    {
        // Object ID: OBJ-03

        glColor3f(1.0f, 1.0f, 0.75f);
        cty_circle(10.0f, 90.0f, 0.3f);
        cty_circle(20.0f, 80.0f, 0.3f);
    }
}

// Building 1

void cty_drawBuilding1()
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

    if (cty_timeMode == 3 && cty_lightsOn)
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

void cty_drawBuilding2()
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

    if (cty_timeMode == 3 && cty_lightsOn)
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

void cty_drawBuilding3()
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

    if (cty_timeMode == 3 && cty_lightsOn)
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

void cty_drawBuilding4()
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

    if (cty_timeMode == 3 && cty_lightsOn)
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

void cty_drawBuilding5()
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

    if (cty_timeMode == 3 && cty_lightsOn)
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

void cty_drawBuilding6()
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

    if (cty_timeMode == 3 && cty_lightsOn)
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

void cty_drawSkyline()
{
    cty_drawBuilding1();
    cty_drawBuilding2();
    cty_drawBuilding3();
    cty_drawBuilding4();
    cty_drawBuilding5();
    cty_drawBuilding6();
}

// Road

void cty_drawRoad()
{
    // Object ID: OBJ-14

    // Grass
    glColor3f(0.20f, 0.48f, 0.20f);
    cty_rectangle(0.0f, 0.0f, 100.0f, 35.0f);

    // Road
    glColor3f(0.12f, 0.12f, 0.14f);
    cty_rectangle(0.0f, 10.0f, 100.0f, 30.0f);

    // Lane lines
    glColor3f(1.0f, 0.85f, 0.10f);
    cty_rectangle(0.0f, 19.4f, 100.0f, 19.8f);
    cty_rectangle(0.0f, 20.4f, 100.0f, 20.8f);
}

// Car

void cty_drawCar(float x, float y, float r, float g, float b, bool facingRight)
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
    cty_circle(-3.0f, -2.0f, 1.5f);
    cty_circle(3.0f, -2.0f, 1.5f);

    // Tire centers
    glColor3f(0.55f, 0.55f, 0.55f);
    cty_circle(-3.0f, -2.0f, 0.6f);
    cty_circle(3.0f, -2.0f, 0.6f);

    if (cty_timeMode == 3 && cty_lightsOn)
    {
        glColor3f(1.0f, 1.0f, 0.60f);
        cty_circle(4.8f, 0.0f, 0.35f);
    }

    if (cty_timeMode == 3 && cty_lightsOn)
    {
        glColor3f(1.0f, 1.0f, 0.60f);
        cty_circle(5.0f, 0.5f, 0.4f);
    }
    else
    {
        glColor3f(1.0f, 1.0f, 0.9f);
        cty_circle(5.0f, 0.5f, 0.4f);

        glColor3f(1.0f, 0.2f, 0.2f);
        cty_circle(-5.0f, 0.5f, 0.3f);
    }

    glPopMatrix();
}

// Bus

void cty_drawBus(float x, float y, bool facingRight)
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
    cty_circle(-5.0f, -3.0f, 1.7f);
    cty_circle(5.0f, -3.0f, 1.7f);

    glColor3f(0.60f, 0.60f, 0.60f);
    cty_circle(-5.0f, -3.0f, 0.7f);
    cty_circle(5.0f, -3.0f, 0.7f);

    if (cty_timeMode == 3 && cty_lightsOn)
    {
        glColor3f(1.0f, 1.0f, 0.60f);
        cty_circle(8.0f, 0.0f, 0.4f);
    }

    glPopMatrix();
}

// Trees

void cty_drawTree(float x, float y)
{
    // Object ID: OBJ-15 / OBJ-16 / OBJ-17

    // Tree trunk
    glColor3f(0.38f, 0.20f, 0.08f);
    cty_rectangle(x - 1.0f, y, x + 1.0f, y + 8.0f);

    // Leaves
    glColor3f(0.03f, 0.45f, 0.12f);
    cty_circle(x, y + 11.0f, 4.0f);
    cty_circle(x - 3.0f, y + 9.0f, 3.0f);
    cty_circle(x + 3.0f, y + 9.0f, 3.0f);
    cty_circle(x, y + 14.0f, 3.5f);
}

// Street Lamps

void cty_drawStreetLamp(float x, float y)
{
    // Object ID: OBJ-18 / OBJ-19 / OBJ-20 / OBJ-21

    glColor3f(0.10f, 0.10f, 0.10f);

    glLineWidth(3.0f);

    cty_line(x, y, x, y + 16.0f);
    cty_line(x, y + 16.0f, x + 4.0f, y + 16.0f);

    if (cty_timeMode == 3 && cty_lightsOn)
        glColor3f(1.0f, 0.85f, 0.15f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    cty_circle(x + 4.0f, y + 15.5f, 1.2f);

    if (cty_timeMode == 3 && cty_lightsOn)
    {
        glColor3f(1.0f, 0.70f, 0.15f);
        cty_circle(x + 4.0f, y + 14.0f, 2.0f);
    }
}

// Shopping Mall

void cty_drawShoppingMall()
{
    // Object ID: OBJ-13

    // Main building
    glColor3f(0.65f, 0.22f, 0.16f);
    cty_rectangle(72.0f, 35.0f, 97.0f, 53.0f);

    // Glass front
    glColor3f(0.25f, 0.65f, 0.75f);
    cty_rectangle(74.0f, 36.0f, 95.0f, 48.0f);

    // Door
    glColor3f(0.10f, 0.12f, 0.16f);
    cty_rectangle(82.0f, 35.0f, 88.0f, 44.0f);

    // Roof
    glColor3f(0.85f, 0.40f, 0.08f);
    cty_rectangle(70.5f, 53.0f, 98.5f, 55.0f);

    // Sign
    if (cty_lightsOn)
        glColor3f(1.0f, 0.80f, 0.05f);
    else
        glColor3f(0.35f, 0.25f, 0.03f);

    cty_rectangle(77.0f, 49.0f, 92.0f, 52.0f);

    // Sign blocks
    glColor3f(0.90f, 0.10f, 0.10f);

    cty_rectangle(79.0f, 49.5f, 80.0f, 51.5f);
    cty_rectangle(81.0f, 49.5f, 82.0f, 51.5f);
    cty_rectangle(83.0f, 49.5f, 84.0f, 51.5f);
    cty_rectangle(85.0f, 49.5f, 86.0f, 51.5f);
    cty_rectangle(87.0f, 49.5f, 88.0f, 51.5f);
    cty_rectangle(89.0f, 49.5f, 90.0f, 51.5f);

    // Mall windows
    glColor3f(0.95f, 0.95f, 0.70f);

    cty_rectangle(75.0f, 45.0f, 76.5f, 47.0f);
    cty_rectangle(78.0f, 45.0f, 79.5f, 47.0f);
    cty_rectangle(81.0f, 45.0f, 82.5f, 47.0f);
    cty_rectangle(84.0f, 45.0f, 85.5f, 47.0f);
    cty_rectangle(87.0f, 45.0f, 88.5f, 47.0f);
    cty_rectangle(90.0f, 45.0f, 91.5f, 47.0f);
}

// Display Function

void cty_display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    cty_drawSky();

    cty_drawCloud(cty_cloud1, 84.0f);
    cty_drawCloud(cty_cloud2, 91.0f);
    cty_drawCloud(cty_cloud3, 78.0f);

    cty_drawSkyline();
    cty_drawShoppingMall();
    cty_drawRoad();

    cty_drawTree(cty_tree1, 30.0f);
    cty_drawTree(cty_tree2, 30.0f);
    cty_drawTree(cty_tree3, 30.0f);

    cty_drawStreetLamp(cty_lamppost1, 30.0f);
    cty_drawStreetLamp(cty_lamppost2, 30.0f);
    cty_drawStreetLamp(cty_lamppost3, 30.0f);
    cty_drawStreetLamp(cty_lamppost4, 30.0f);

    cty_drawCar(cty_car, 16.5f, 0.85f, 0.20f, 0.20f, true);
    cty_drawCar(cty_car1, 28.0f, 0.10f, 0.35f, 0.85f, false);
    cty_drawBus(cty_bus1, 28.0f, false);
    cty_drawCar(cty_car2, 25.8f, 0.90f, 0.55f, 0.05f, false);

    glColor3f(1.0f, 1.0f, 1.0f);

    cty_drawText(2.0f, 96.0f, "SCENE 3 - TWO WAY CITY ROAD");
    cty_drawText(2.0f, 2.0f, "Mouse: Animation | L: Move | K: Stop | A/S/D/F: Time | N: Lights");

    glutSwapBuffers();
}

// Animation & Update

void cty_update(int value)
{
    // Animation Function ID: ANIM-01

    if (cty_allAnimation)
    {
        if (cty_vehicleMoving)
        {
            // ANIM-04: Vehicle movement

            cty_car += 0.45f;

            if (cty_car > 115.0f)
                cty_car = -30.0f;

            cty_car1 -= 0.45f;

            if (cty_car1 < -80.0f)
                cty_car1 = 110.0f;

            cty_bus1 -= 0.45f;

            if (cty_bus1 < -80.0f)
                cty_bus1 = 140.0f;

            cty_car2 -= 0.45f;

            if (cty_car2 < -80.0f)
                cty_car2 = 172.0f;
        }

        // ANIM-05: Cloud movement

        cty_cloud1 += 0.07f;
        cty_cloud2 += 0.06f;
        cty_cloud3 += 0.10f;

        if (cty_cloud1 > 110.0f)
            cty_cloud1 = -15.0f;

        if (cty_cloud2 > 110.0f)
            cty_cloud2 = -15.0f;

        if (cty_cloud3 > 110.0f)
            cty_cloud3 = -15.0f;

        // ANIM-06: Traffic state cycle

        static int counter = 0;

        counter++;

        if (counter >= 100)
        {
            cty_trafficState++;

            if (cty_trafficState > 2)
                cty_trafficState = 0;

            counter = 0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, cty_update, 0);
}

// Keyboard

void cty_keyboard(unsigned char key, int x, int y)
{
    // Animation Function ID: ANIM-02

    if (key >= 'A' && key <= 'Z')
        key = key + ('a' - 'A');

    switch (key)
    {
        case 'l':
            cty_vehicleMoving = true;
            break;

        case 'k':
            cty_vehicleMoving = false;
            break;

        case 'a':
            cty_timeMode = 0;
            break;

        case 's':
            cty_timeMode = 1;
            break;

        case 'd':
            cty_timeMode = 2;
            break;

        case 'f':
            cty_timeMode = 3;
            break;

        case 'n':
            cty_lightsOn = !cty_lightsOn;
            break;

        case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}

// Mouse

void cty_mouse(int button, int state, int x, int y)
{
    // Animation Function ID: ANIM-03

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        cty_allAnimation = !cty_allAnimation;
    }

    glutPostRedisplay();
}

// Window Reshape

void cty_reshape(int width, int height)
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

void cty_init()
{
    glClearColor(0.35f, 0.72f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0f, 100.0f, 0.0f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Main Function


// =====================================================================
//  SCENE 4: HIGHWAY
// =====================================================================

// Object ID Reference Table
// ITEM-01 : Water
// ITEM-02 : Waves
// ITEM-03 : Boat
// ITEM-04 : Cloud 1
// ITEM-05 : Cloud 2
// ITEM-06 : Cloud 3
// ITEM-07 : Hill 1
// ITEM-08 : Hill 2
// ITEM-09 : Hill 3
// ITEM-10 : Hill 4
// ITEM-11 : Road
// ITEM-12 : Bridge
// ITEM-13 : Road Markings
// ITEM-14 : Tree 1
// ITEM-15 : Tree 2
// ITEM-16 : Tree 3
// ITEM-17 : Tree 4
// ITEM-18 : Street Lamp 1
// ITEM-19 : Street Lamp 2
// ITEM-20 : Street Lamp 3
// ITEM-21 : Street Lamp 4
// ITEM-22 : Highway Sign 1
// ITEM-23 : Highway Sign 2
// ITEM-24 : Car 1
// ITEM-25 : Car 2
// ITEM-26 : Car 3
// ITEM-27 : Bus

// Animation Function ID Reference Table
// FUNC-01 : hwy_init()
// FUNC-02 : hwy_updateBackground()
// FUNC-03 : hwy_drawWater()
// FUNC-04 : hwy_drawCircle()
// FUNC-05 : hwy_drawClouds()
// FUNC-06 : hwy_drawHills()
// FUNC-07 : hwy_drawRoadAndBridge()
// FUNC-08 : hwy_drawTrees()
// FUNC-09 : hwy_drawLamps()
// FUNC-10 : hwy_drawHighwaySigns()
// FUNC-11 : hwy_drawCustomCar()
// FUNC-12 : hwy_drawBus()
// FUNC-13 : hwy_display()
// FUNC-14 : hwy_update()
// FUNC-15 : hwy_handleKeypress()
// FUNC-16 : hwy_handleMouse()
// FUNC-17 : main()

float hwy_carX1 = -15.0f;
float hwy_carX2 = -45.0f;
float hwy_carX3 = -75.0f;
float hwy_busX = -30.0f;
float hwy_cloudX = 0.0f;
float hwy_boatX = -25.0f;
float hwy_waveX = 0.0f;

float hwy_wheelAngle = 0.0f;
float hwy_speed = 0.04f;
float hwy_savedSpeed = 0.04f;
bool hwy_isAnimating = true;


int hwy_currentScene = 0;
bool hwy_vehicleMoving = true;
int hwy_timeState = 1;
bool hwy_lightsOn = false;

void hwy_init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}


void hwy_updateBackground()
{
	if (hwy_timeState == 0)
		glClearColor(1.0f, 0.6f, 0.4f, 1.0f);
	else if (hwy_timeState == 1)
		glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
	else if (hwy_timeState == 2)
		glClearColor(0.9f, 0.4f, 0.2f, 1.0f);
	else if (hwy_timeState == 3)
		glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
}

void hwy_drawWater()
{

	glColor3ub(135, 206, 250);
	glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(100, 0);
		glVertex2f(100, 35);
		glVertex2f(0, 35);
	glEnd();


	glPushMatrix();
		glTranslatef(hwy_waveX, 0.0f, 0.0f);

		glColor3ub(255, 255, 255);
		glLineWidth(1.5f);


		glBegin(GL_LINE_STRIP);
			glVertex2f(20.0f, 26.0f);
			glVertex2f(21.5f, 26.8f);
			glVertex2f(23.0f, 26.0f);
			glVertex2f(24.5f, 26.8f);
			glVertex2f(26.0f, 26.0f);
		glEnd();


		glBegin(GL_LINE_STRIP);
			glVertex2f(55.0f, 25.0f);
			glVertex2f(56.5f, 25.8f);
			glVertex2f(58.0f, 25.0f);
			glVertex2f(59.5f, 25.8f);
			glVertex2f(61.0f, 25.0f);
		glEnd();


		glBegin(GL_LINE_STRIP);
			glVertex2f(35.0f, 16.0f);
			glVertex2f(36.5f, 16.8f);
			glVertex2f(38.0f, 16.0f);
			glVertex2f(39.5f, 16.8f);
			glVertex2f(41.0f, 16.0f);
		glEnd();


		glBegin(GL_LINE_STRIP);
			glVertex2f(12.0f, 11.0f);
			glVertex2f(13.5f, 11.8f);
			glVertex2f(15.0f, 11.0f);
			glVertex2f(16.5f, 11.8f);
			glVertex2f(18.0f, 11.0f);
		glEnd();


		glBegin(GL_LINE_STRIP);
			glVertex2f(72.0f, 11.0f);
			glVertex2f(73.5f, 11.8f);
			glVertex2f(75.0f, 11.0f);
			glVertex2f(76.5f, 11.8f);
			glVertex2f(78.0f, 11.0f);
		glEnd();

	glPopMatrix();


	glPushMatrix();
		glTranslatef(hwy_boatX, 0.0f, 0.0f);


		glColor3ub(255, 255, 255);
		glLineWidth(1.5f);
		glBegin(GL_LINE_STRIP);
			glVertex2f(14.0f, 12.5f);
			glVertex2f(15.5f, 13.3f);
			glVertex2f(17.0f, 12.5f);
			glVertex2f(18.5f, 13.3f);
			glVertex2f(20.0f, 12.5f);
		glEnd();


		glColor3ub(160, 82, 45);
		glBegin(GL_QUADS);
			glVertex2f(13.0f, 18.0f);
			glVertex2f(21.0f, 18.0f);
			glVertex2f(19.0f, 14.0f);
			glVertex2f(15.0f, 14.0f);
		glEnd();


		glColor3ub(80, 40, 20);
		glLineWidth(2.5f);
		glBegin(GL_LINES);
			glVertex2f(17.0f, 18.0f);
			glVertex2f(17.0f, 25.0f);
		glEnd();


		glColor3ub(255, 255, 255);
		glBegin(GL_TRIANGLES);
			glVertex2f(17.2f, 24.5f);
			glVertex2f(17.2f, 19.0f);
			glVertex2f(21.5f, 21.5f);
		glEnd();

	glPopMatrix();
}

void hwy_drawCircle(float cx, float cy, float r)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < 30; i++)
	{
		float angle = (i * 2.0f * 3.1416f) / 30;
		glVertex2f(cx + (r * cos(angle)), cy + (r * sin(angle)));
	}
	glEnd();
}

void hwy_drawClouds(float offsetX)
{
	glPushMatrix();
		glTranslatef(offsetX, 0.0f, 0.0f);

		glColor3ub(255, 255, 255);


		hwy_drawCircle(18.0f, 82.0f, 2.5f);
		hwy_drawCircle(20.5f, 83.0f, 3.0f);
		hwy_drawCircle(23.0f, 82.0f, 2.6f);
		hwy_drawCircle(20.5f, 80.8f, 2.3f);


		hwy_drawCircle(47.0f, 76.0f, 2.5f);
		hwy_drawCircle(49.5f, 77.0f, 3.0f);
		hwy_drawCircle(52.0f, 76.0f, 2.6f);
		hwy_drawCircle(49.5f, 74.8f, 2.3f);


		hwy_drawCircle(75.0f, 83.0f, 2.5f);
		hwy_drawCircle(77.5f, 84.0f, 3.0f);
		hwy_drawCircle(80.0f, 83.0f, 2.6f);
		hwy_drawCircle(77.5f, 81.8f, 2.3f);

	glPopMatrix();
}

void hwy_drawHills()
{
	glBegin(GL_TRIANGLES);
		glColor3ub(80, 140, 55);
		glVertex2f(-20, 35);
		glVertex2f(40, 35);
		glVertex2f(10, 70);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3ub(90, 150, 60);
		glVertex2f(20, 35);
		glVertex2f(70, 35);
		glVertex2f(45, 80);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3ub(75, 130, 50);
		glVertex2f(50, 35);
		glVertex2f(100, 35);
		glVertex2f(75, 65);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3ub(85, 145, 58);
		glVertex2f(75, 35);
		glVertex2f(120, 35);
		glVertex2f(95, 75);
	glEnd();
}

void hwy_drawRoadAndBridge()
{
	glColor3ub(50, 50, 55);
	glBegin(GL_QUADS);
		glVertex2f(0, 35);
		glVertex2f(35, 35);
		glVertex2f(35, 45);
		glVertex2f(0, 45);

		glVertex2f(65, 35);
		glVertex2f(100, 35);
		glVertex2f(100, 45);
		glVertex2f(65, 45);
	glEnd();

	glColor3ub(180, 50, 40);
	glBegin(GL_QUADS);
		glVertex2f(35, 34);
		glVertex2f(65, 34);
		glVertex2f(65, 46);
		glVertex2f(35, 46);
	glEnd();

	glColor3ub(65, 65, 70);
	glBegin(GL_QUADS);
		glVertex2f(35, 36);
		glVertex2f(65, 36);
		glVertex2f(65, 44);
		glVertex2f(35, 44);
	glEnd();

	glColor3ub(220, 220, 220);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(0, 45);
		glVertex2f(100, 45);
		glVertex2f(0, 35);
		glVertex2f(100, 35);
	glEnd();

	glColor3ub(255, 215, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(0, 40);
		glVertex2f(4, 40);
		glVertex2f(8, 40);
		glVertex2f(12, 40);
		glVertex2f(16, 40);
		glVertex2f(20, 40);
		glVertex2f(24, 40);
		glVertex2f(28, 40);
		glVertex2f(32, 40);
		glVertex2f(36, 40);
		glVertex2f(40, 40);
		glVertex2f(44, 40);
		glVertex2f(48, 40);
		glVertex2f(52, 40);
		glVertex2f(56, 40);
		glVertex2f(60, 40);
		glVertex2f(64, 40);
		glVertex2f(68, 40);
		glVertex2f(72, 40);
		glVertex2f(76, 40);
		glVertex2f(80, 40);
		glVertex2f(84, 40);
		glVertex2f(88, 40);
		glVertex2f(92, 40);
		glVertex2f(96, 40);
		glVertex2f(100, 40);
	glEnd();

	glColor3ub(220, 40, 30);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(35, 48);
		glVertex2f(65, 48);
		glVertex2f(35, 32);
		glVertex2f(65, 32);
	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(35, 44);
		glVertex2f(35, 48);
		glVertex2f(38, 44);
		glVertex2f(38, 48);
		glVertex2f(41, 44);
		glVertex2f(41, 48);
		glVertex2f(44, 44);
		glVertex2f(44, 48);
		glVertex2f(47, 44);
		glVertex2f(47, 48);
		glVertex2f(50, 44);
		glVertex2f(50, 48);
		glVertex2f(53, 44);
		glVertex2f(53, 48);
		glVertex2f(56, 44);
		glVertex2f(56, 48);
		glVertex2f(59, 44);
		glVertex2f(59, 48);
		glVertex2f(62, 44);
		glVertex2f(62, 48);
		glVertex2f(65, 44);
		glVertex2f(65, 48);
		glVertex2f(35, 32);
		glVertex2f(35, 36);
		glVertex2f(38, 32);
		glVertex2f(38, 36);
		glVertex2f(41, 32);
		glVertex2f(41, 36);
		glVertex2f(44, 32);
		glVertex2f(44, 36);
		glVertex2f(47, 32);
		glVertex2f(47, 36);
		glVertex2f(50, 32);
		glVertex2f(50, 36);
		glVertex2f(53, 32);
		glVertex2f(53, 36);
		glVertex2f(56, 32);
		glVertex2f(56, 36);
		glVertex2f(59, 32);
		glVertex2f(59, 36);
		glVertex2f(62, 32);
		glVertex2f(62, 36);
		glVertex2f(65, 32);
		glVertex2f(65, 36);
	glEnd();
}

void hwy_drawTrees()
{
	glColor3ub(100, 55, 25);
	glBegin(GL_QUADS);
		glVertex2f(4, 45);
		glVertex2f(6, 45);
		glVertex2f(6, 53);
		glVertex2f(4, 53);
	glEnd();

	glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(1, 51);
		glVertex2f(9, 51);
		glVertex2f(5, 58);
    glEnd();
		glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(2, 54);
		glVertex2f(8, 54);
		glVertex2f(5, 61);
	glEnd();

	glColor3ub(100, 55, 25);
	glBegin(GL_QUADS);
		glVertex2f(24, 45);
		glVertex2f(26, 45);
		glVertex2f(26, 53);
		glVertex2f(24, 53);
	glEnd();

	glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(21, 51);
		glVertex2f(29, 51);
		glVertex2f(25, 58);
    glEnd();
    glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(22, 54);
		glVertex2f(28, 54);
		glVertex2f(25, 61);
	glEnd();

	glColor3ub(100, 55, 25);
	glBegin(GL_QUADS);
		glVertex2f(71, 45);
		glVertex2f(73, 45);
		glVertex2f(73, 53);
		glVertex2f(71, 53);
	glEnd();

	glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(68, 51);
		glVertex2f(76, 51);
		glVertex2f(72, 58);
		glEnd();
    glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(69, 54);
		glVertex2f(75, 54);
		glVertex2f(72, 61);
	glEnd();

	glColor3ub(100, 55, 25);
	glBegin(GL_QUADS);
		glVertex2f(91, 45);
		glVertex2f(93, 45);
		glVertex2f(93, 53);
		glVertex2f(91, 53);
	glEnd();

	glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(88, 51);
		glVertex2f(96, 51);
		glVertex2f(92, 58);
    glEnd();
    glColor3ub(35, 135, 45);
	glBegin(GL_TRIANGLES);
		glVertex2f(89, 54);
		glVertex2f(95, 54);
		glVertex2f(92, 61);
	glEnd();
}

void hwy_drawLamps()
{
	glColor3ub(40, 40, 40);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(12, 45);
		glVertex2f(12, 55);
		glVertex2f(12, 55);
		glVertex2f(14, 55);
	glEnd();

	glColor3ub(255, 255, 150);
	glPointSize(6);
	glBegin(GL_POINTS);
		glVertex2f(14, 54.5f);
	glEnd();

	glColor3ub(40, 40, 40);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(28, 45);
		glVertex2f(28, 55);
		glVertex2f(28, 55);
		glVertex2f(30, 55);
	glEnd();

	glColor3ub(255, 255, 150);
	glPointSize(6);
	glBegin(GL_POINTS);
		glVertex2f(30, 54.5f);
	glEnd();

	glColor3ub(40, 40, 40);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(72, 45);
		glVertex2f(72, 55);
		glVertex2f(72, 55);
		glVertex2f(74, 55);
	glEnd();

	glColor3ub(255, 255, 150);
	glPointSize(6);
	glBegin(GL_POINTS);
		glVertex2f(74, 54.5f);
	glEnd();

	glColor3ub(40, 40, 40);
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2f(88, 45);
		glVertex2f(88, 55);
		glVertex2f(88, 55);
		glVertex2f(90, 55);
	glEnd();

	glColor3ub(255, 255, 150);
	glPointSize(6);
	glBegin(GL_POINTS);
		glVertex2f(90, 54.5f);
	glEnd();
}

void hwy_drawHighwaySigns()
{
	glColor3ub(60, 60, 60);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(18, 45);
		glVertex2f(18, 51);
	glEnd();

	glColor3ub(0, 100, 190);
	glBegin(GL_QUADS);
		glVertex2f(15, 51);
		glVertex2f(21, 51);
		glVertex2f(21, 55);
		glVertex2f(15, 55);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(15, 51);
		glVertex2f(21, 51);
		glVertex2f(21, 55);
		glVertex2f(15, 55);
	glEnd();

	glBegin(GL_QUADS);
		glVertex2f(16.2f, 52.7f);
		glVertex2f(18.8f, 52.7f);
		glVertex2f(18.8f, 53.3f);
		glVertex2f(16.2f, 53.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(18.8f, 52.2f);
		glVertex2f(18.8f, 53.8f);
		glVertex2f(20.0f, 53.0f);
	glEnd();

	glColor3ub(60, 60, 60);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2f(82, 45);
		glVertex2f(82, 51);
	glEnd();

	glColor3ub(20, 130, 60);
	glBegin(GL_QUADS);
		glVertex2f(79, 51);
		glVertex2f(85, 51);
		glVertex2f(85, 55);
		glVertex2f(79, 55);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
		glVertex2f(79, 51);
		glVertex2f(85, 51);
		glVertex2f(85, 55);
		glVertex2f(79, 55);
	glEnd();

	glBegin(GL_QUADS);
		glVertex2f(80.2, 52.7);
		glVertex2f(82.8, 52.7);
		glVertex2f(82.8, 53.3);
		glVertex2f(80.2, 53.3);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(82.8f, 52.2f);
		glVertex2f(82.8f, 53.8f);
		glVertex2f(84.0f, 53.0f);
	glEnd();
}

void hwy_drawCustomCar(float posX, unsigned char r1, unsigned char g1, unsigned char b1, unsigned char r2, unsigned char g2, unsigned char b2)
{
	glPushMatrix();
		glTranslatef(posX, 36.0f, 0.0f);
		glScalef(0.5f, 0.5f, 1.0f);

		// Car Body Base
		glBegin(GL_QUADS);
			glColor3ub(r1, g1, b1);
			glVertex2f(2, 3.5);
			glVertex2f(12, 3.5);
			glVertex2f(11.5, 6);
			glVertex2f(2.5, 6);
		glEnd();

		// Car Top Roof Cabin
		glBegin(GL_QUADS);
			glColor3ub(r2, g2, b2);
			glVertex2f(4.5, 6);
			glVertex2f(9.5, 6);
			glVertex2f(8.5, 8.5);
			glVertex2f(5.5, 8.5);
		glEnd();

		// Windows
		glBegin(GL_TRIANGLES);
			glColor3ub(200, 204, 232);
			glVertex2f(4.8, 6.2);
			glVertex2f(5.7, 6.2);
			glVertex2f(5.7, 8.2);
		glEnd();

		glBegin(GL_QUADS);
			glColor3ub(200, 204, 232);
			glVertex2f(6, 6.2);
			glVertex2f(8, 6.2);
			glVertex2f(8, 8.2);
			glVertex2f(6, 8.2);
		glEnd();

		glBegin(GL_TRIANGLES);
			glColor3ub(200, 204, 232);
			glVertex2f(8.3, 6.2);
			glVertex2f(9.2, 6.2);
			glVertex2f(8.3, 8.2);
		glEnd();

		// Headlight (Toggled by 'B')
		if (hwy_lightsOn)
		{
			glColor3ub(255, 255, 0);
			glBegin(GL_QUADS);
				glVertex2f(12, 5);
				glVertex2f(12.5, 5);
				glVertex2f(12.5, 5.6);
				glVertex2f(12, 5.6);
			glEnd();
		}
		else
		{
			glBegin(GL_QUADS);
				glColor3ub(247, 203, 114);
				glVertex2f(12, 5);
				glVertex2f(11.3, 5);
				glVertex2f(11.2, 5.6);
				glVertex2f(11.7, 5.6);
			glEnd();
		}

		// Wheel 1
		{
			float radius = 1.2f;
			float xc = 4.5f, yc = 3.5f;

			glBegin(GL_POLYGON);
				glColor3ub(0, 0, 0);
				for(int i = 0; i < 100; i++)
				{
					float pi = 3.1416f;
					float A = (i * 2 * pi) / 100;
					glVertex2f((radius * cos(A)) + xc, (radius * sin(A)) + yc);
				}
			glEnd();

			glPushMatrix();
				glTranslatef(xc, yc, 0.0f);
				glRotatef(hwy_wheelAngle, 0.0f, 0.0f, 1.0f);

				glBegin(GL_POLYGON);
					glColor3ub(200, 200, 200);
					for(int i = 0; i <= 50; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();

				glBegin(GL_POLYGON);
					glColor3ub(140, 140, 140);
					for(int i = 50; i <= 100; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();
			glPopMatrix();
		}

		// Wheel 2
		{
			float radius = 1.2f;
			float xc = 9.5f, yc = 3.5f;

			glBegin(GL_POLYGON);
				glColor3ub(0, 0, 0);
				for(int i = 0; i < 100; i++)
				{
					float pi = 3.1416f;
					float A = (i * 2 * pi) / 100;
					glVertex2f((radius * cos(A)) + xc, (radius * sin(A)) + yc);
				}
			glEnd();

			glPushMatrix();
				glTranslatef(xc, yc, 0.0f);
				glRotatef(hwy_wheelAngle, 0.0f, 0.0f, 1.0f);

				glBegin(GL_POLYGON);
					glColor3ub(200, 200, 200);
					for(int i = 0; i <= 50; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();

				glBegin(GL_POLYGON);
					glColor3ub(140, 140, 140);
					for(int i = 50; i <= 100; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();
			glPopMatrix();
		}
	glPopMatrix();
}

void hwy_drawBus(float posX)
{
	glPushMatrix();
		glTranslatef(posX, 36.0f, 0.0f);
		glScalef(0.7f, 0.7f, 1.0f);

		// 1. Bus Main Body (Green)
		glColor3f(0.2f, 0.6f, 0.3f);
		glBegin(GL_QUADS);
			glVertex2f(2.0, 3.5);
			glVertex2f(16.0, 3.5);
			glVertex2f(16.0, 9.5);
			glVertex2f(2.0, 9.5);
		glEnd();

		// 2. Windows on the Bus
		glColor3f(0.85f, 0.95f, 1.0f);

		// Window 1
		glBegin(GL_QUADS);
			glVertex2f(3.5, 6.0);
			glVertex2f(6.0, 6.0f);
			glVertex2f(6.0, 9.0);
			glVertex2f(3.5, 9.0);
		glEnd();

		// Window 2
		glBegin(GL_QUADS);
			glVertex2f(7.5, 6.0);
			glVertex2f(10.0, 6.0);
			glVertex2f(10.0, 9.0);
			glVertex2f(7.5, 9.0);
		glEnd();

		// Window 3
		glBegin(GL_QUADS);
			glVertex2f(11.5, 6.0);
			glVertex2f(14.0, 6.0);
			glVertex2f(14.0, 9.0);
			glVertex2f(11.5, 9.0);
		glEnd();

		// 3. Headlight
		if (hwy_lightsOn)
		{
			glColor3f(1.0f, 1.0f, 0.0f);
		}
		else
		{
			glColor3f(1.0f, 0.9f, 0.4f);
		}
		glBegin(GL_QUADS);
			glVertex2f(16.0f, 4.5f);
			glVertex2f(16.5f, 4.5f);
			glVertex2f(16.5f, 6.0f);
			glVertex2f(16.0f, 6.0f);
		glEnd();

		// 4. Wheel 1
		{
			float radius = 1.2f;
			float xc = 4.5f, yc = 3.5f;

			glBegin(GL_POLYGON);
				glColor3ub(0, 0, 0);
				for(int i = 0; i < 100; i++)
				{
					float pi = 3.1416f;
					float A = (i * 2 * pi) / 100;
					glVertex2f((radius * cos(A)) + xc, (radius * sin(A)) + yc);
				}
			glEnd();

			glPushMatrix();
				glTranslatef(xc, yc, 0.0f);
				glRotatef(hwy_wheelAngle, 0.0f, 0.0f, 1.0f);

				glBegin(GL_POLYGON);
					glColor3ub(200, 200, 200);
					for(int i = 0; i <= 50; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();

				glBegin(GL_POLYGON);
					glColor3ub(140, 140, 140);
					for(int i = 50; i <= 100; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();
			glPopMatrix();
		}

		// 5. Wheel 2
		{
			float radius = 1.2f;
			float xc = 13.5f, yc = 3.5f;

			glBegin(GL_POLYGON);
				glColor3ub(0, 0, 0);
				for(int i = 0; i < 100; i++)
				{
					float pi = 3.1416f;
					float A = (i * 2 * pi) / 100;
					glVertex2f((radius * cos(A)) + xc, (radius * sin(A)) + yc);
				}
			glEnd();

			glPushMatrix();
				glTranslatef(xc, yc, 0.0f);
				glRotatef(hwy_wheelAngle, 0.0f, 0.0f, 1.0f);

				glBegin(GL_POLYGON);
					glColor3ub(200, 200, 200);
					for(int i = 0; i <= 50; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();

				glBegin(GL_POLYGON);
					glColor3ub(140, 140, 140);
					for(int i = 50; i <= 100; i++)
					{
						float pi = 3.1416f;
						float A = (i * 2 * pi) / 100;
						glVertex2f((radius * 0.45f) * cos(A), (radius * 0.45f) * sin(A));
					}
				glEnd();
			glPopMatrix();
		}
	glPopMatrix();
}

void hwy_display()
{
	hwy_updateBackground();
	glClear(GL_COLOR_BUFFER_BIT);

	if (hwy_currentScene == 0)
	{
		hwy_drawWater();
		hwy_drawClouds(hwy_cloudX);
		hwy_drawHills();
		hwy_drawRoadAndBridge();
		hwy_drawTrees();
		hwy_drawLamps();
		hwy_drawHighwaySigns();

		hwy_drawBus(hwy_busX);

		hwy_drawCustomCar(hwy_carX1, 215, 181, 232, 211, 148, 242);
		hwy_drawCustomCar(hwy_carX2, 230, 50, 50, 200, 30, 30);
		hwy_drawCustomCar(hwy_carX3, 100, 180, 255, 70, 150, 235);
	}
	else if (hwy_currentScene == 1)
	{
		hwy_drawHills();
		hwy_drawRoadAndBridge();
		hwy_drawTrees();
		hwy_drawLamps();
		hwy_drawCustomCar(hwy_carX1, 50, 200, 50, 30, 150, 30);
		hwy_drawCustomCar(hwy_carX3, 50, 100, 250, 30, 70, 180);
	}

	glutSwapBuffers();
}

void hwy_update(int value)
{
	if (hwy_vehicleMoving)
	{
		hwy_carX1 += hwy_speed;
		hwy_carX2 += hwy_speed;
		hwy_carX3 += hwy_speed;
		hwy_busX  += hwy_speed;
		hwy_cloudX += (hwy_speed * 0.25f);
		hwy_boatX  += (hwy_speed * 0.5f);
		hwy_waveX  += (hwy_speed * 0.2f);

		hwy_wheelAngle -= (hwy_speed * 100.0f);
		if (hwy_wheelAngle < -360.0f)
		{
			hwy_wheelAngle += 360.0f;
		}
	}

	if (hwy_carX1 > 110.0f) hwy_carX1 = -15.0f;
	if (hwy_carX2 > 110.0f) hwy_carX2 = -15.0f;
	if (hwy_carX3 > 110.0f) hwy_carX3 = -15.0f;
	if (hwy_busX > 110.0f)  hwy_busX  = -30.0f;
	if (hwy_cloudX > 110.0f) hwy_cloudX = -90.0f;
	if (hwy_boatX > 110.0f)  hwy_boatX  = -25.0f;
	if (hwy_waveX > 100.0f)  hwy_waveX  = 0.0f;

	glutPostRedisplay();
	glutTimerFunc(16, hwy_update, 0);
}


void hwy_handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'c': // C: next scene, looping back to Village
		case 'C':
			hwy_currentScene = (hwy_currentScene + 1) % 2;
			break;

		case 'o': // O: vehicle control move
		case 'O':
			hwy_vehicleMoving = true;
			break;

		case 'p': // P: vehicle control stop
		case 'P':
			hwy_vehicleMoving = false;
			break;

		case 'z': // Z: Dawn
		case 'Z':
			hwy_timeState = 0;
			break;

		case 'x': // X: Day
		case 'X':
			hwy_timeState = 1;
			break;

		case 'v': // V: Night
		case 'V':
			hwy_timeState = 3;
			break;

		case 'b': // B: toggle lights on/off
		case 'B':
			hwy_lightsOn = !hwy_lightsOn;
			break;
	}
	glutPostRedisplay();
}

void hwy_handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (hwy_isAnimating)
		{
			hwy_savedSpeed = hwy_speed;
			hwy_speed = 0.0f;
			hwy_isAnimating = false;
		}
		else
		{
			hwy_speed = hwy_savedSpeed;
			hwy_isAnimating = true;
		}
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		hwy_boatX = -25.0f;
	}
	glutPostRedisplay();
}


// =====================================================================
//                       MASTER SCENE SWITCHING (M key)
// =====================================================================

int activeScene = 1; // 1=Village, 2=Town, 3=City, 4=Highway

void goToScene(int n)
{
    activeScene = n;
    switch (activeScene)
    {
        case 1: glutDisplayFunc(vlg_village); break;
        case 2: glutDisplayFunc(twn_town);    break;
        case 3: glutDisplayFunc(cty_display); break;
        case 4: glutDisplayFunc(hwy_display); break;
    }
    glutPostRedisplay();
}

void nextScene()
{
    activeScene++;
    if (activeScene > 4) activeScene = 1; // loop back Highway -> Village
    goToScene(activeScene);
}

// Master keyboard: 'M' is the only shared key (cycles scenes).
// Every other key - including 'C', which Highway uses for its own
// internal toggle - is forwarded, untouched, to the CURRENTLY ACTIVE
// scene's own original keypress handler, so each scene's keybinds
// keep working exactly as they did in that scene's standalone file.
void masterKeyboard(unsigned char key, int x, int y)
{
    if (key == 'm' || key == 'M')
    {
        nextScene();
        return;
    }

    switch (activeScene)
    {
        case 1: vlg_handleKeypress(key, x, y); break;
        case 2: twn_handleKeypress(key, x, y); break;
        case 3: cty_keyboard(key, x, y);       break;
        case 4: hwy_handleKeypress(key, x, y); break;
    }
}

// Master mouse: forwarded to whichever scene is currently active.
void masterMouse(int button, int state, int x, int y)
{
    switch (activeScene)
    {
        case 1: vlg_handleMouse(button, state, x, y); break;
        case 2: twn_handleMouse(button, state, x, y); break;
        case 3: cty_mouse(button, state, x, y);       break;
        case 4: hwy_handleMouse(button, state, x, y); break;
    }
}

// Only Town defines special (arrow) key handling - forward to it
// only while Town is the active scene.
void masterSpecialKey(int key, int x, int y)
{
    if (activeScene == 2)
    {
        twn_handleSpecialKey(key, x, y);
    }
}

// =====================================================================
//                                MAIN
// =====================================================================

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 900);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("GLUT Project - Village / Town / City / Highway");

    // Each scene's own init() just sets the same 0-100 ortho projection -
    // calling all four is harmless and preserves each scene's original setup.
    vlg_init();
    twn_init();
    cty_init();
    hwy_init();

    // Start on Scene 1 (Village)
    glutDisplayFunc(vlg_village);

    glutKeyboardFunc(masterKeyboard);
    glutMouseFunc(masterMouse);
    glutSpecialFunc(masterSpecialKey);
    glutReshapeFunc(cty_reshape);

    // Each scene's own animation timer keeps running with its original
    // interval and update function, exactly as in its standalone file.
    glutTimerFunc(20, vlg_update, 0);
    glutTimerFunc(20, twn_update, 0);
    glutTimerFunc(30, cty_update, 0);
    glutTimerFunc(16, hwy_update, 0);

    glutMainLoop();
    return 0;
}
