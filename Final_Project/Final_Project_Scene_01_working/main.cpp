#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1416

// =====================================================
//                 GLOBAL VARIABLES
// =====================================================

float boatMove = 0.0f;
float cloudMove = 0.0f;
int animationOn = 1;
int timeMode = 1;

// =====================================================
//                 BASIC SHAPE FUNCTIONS
// =====================================================

// =====================================================
//                  RECTANGLE FUNCTION
// =====================================================

void rect(float x1, float y1, float x2, float y2,
          float r, float g, float b)
{
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glEnd();
}

// =====================================================
//                  POLYGON FUNCTION
// =====================================================
void polygon(float r, float g, float b,
             int n, float points[][2])
{
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);

    for(int i = 0; i < n; i++)
    {
        glVertex2f(points[i][0], points[i][1]);
    }

    glEnd();
}

void line2D(float x1, float y1, float x2, float y2,
            float r, float g, float b, float width)
{
    glColor3f(r, g, b);
    glLineWidth(width);

    glBegin(GL_LINES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

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
//                         SUN
// =====================================================
void sun()
{
    glPushMatrix();

    glTranslatef(53.0f, 88.0f, 0.0f);

    glColor3f(1.0f, 0.85f, 0.05f);

    circle(4.2f);

    glPopMatrix();
}

// =====================================================
//                         CLOUD
// =====================================================

void cloud(float x, float y)
{
    // Simple 3-circle cloud

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
//                     BACKGROUND HILLS
// =====================================================

void mountain(float x1, float y1,
              float xPeak, float yPeak,
              float x2, float y2,
              float r, float g, float b)
{
    // Main mountain
    glColor3f(r, g, b);

    glBegin(GL_TRIANGLES);

    glVertex2f(x1, y1);
    glVertex2f(xPeak, yPeak);
    glVertex2f(x2, y2);

    glEnd();

    // Dark side
    glColor3f(r * 0.70f,
              g * 0.70f,
              b * 0.70f);

    glBegin(GL_TRIANGLES);

    glVertex2f(xPeak, yPeak);
    glVertex2f(x2, y2);
    glVertex2f(xPeak + (x2 - xPeak) * 0.4f, y1);

    glEnd();
}

void hills()
{
    // Back mountain

    mountain(64, 52,
             82, 88,
             110, 52,
             0.35f, 0.52f, 0.20f);

    // Front mountain

    mountain(57, 52,
             73, 78,
             88, 52,
             0.43f, 0.60f, 0.24f);
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
//                        HOUSE
// =====================================================

void house(float x, float y, float w, float h,
           float bodyR, float bodyG, float bodyB,
           float roofR, float roofG, float roofB)
{
    // House body
    rect(x, y, x + w, y + h,
         bodyR, bodyG, bodyB);

    // Roof
    float roof[][2] =
    {
        {x - 1.5f, y + h},
        {x + w * 0.25f, y + h + 8.0f},
        {x + w * 0.75f, y + h + 7.0f},
        {x + w + 1.5f, y + h}
    };

    polygon(roofR, roofG, roofB, 4, roof);

    // Roof center divider
    line2D(x + w * 0.25f, y + h + 8.0f,
           x + w * 0.48f, y + h,
           0.25f, 0.12f, 0.08f, 1.0f);

    // Door
    rect(x + w * 0.58f, y,
         x + w * 0.76f, y + h * 0.48f,
         0.27f, 0.15f, 0.08f);

    // Door knob
    glPushMatrix();
    glTranslatef(x + w * 0.72f,
                 y + h * 0.25f,
                 0.0f);
    glColor3f(0.90f, 0.78f, 0.25f);
    circle(0.22f);
    glPopMatrix();

    // Window
    rect(x + w * 0.16f, y + h * 0.38f,
         x + w * 0.37f, y + h * 0.62f,
         0.36f, 0.24f, 0.12f);

    // Window center
    line2D(x + w * 0.265f, y + h * 0.38f,
           x + w * 0.265f, y + h * 0.62f,
           0.08f, 0.08f, 0.06f, 1.0f);

    line2D(x + w * 0.16f, y + h * 0.50f,
           x + w * 0.37f, y + h * 0.50f,
           0.08f, 0.08f, 0.06f, 1.0f);
}

// =====================================================
//                     STREET LAMP
// =====================================================

void streetLamp(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    // Vertical post
    rect(0.0f, 0.0f,
         0.5f, 7.0f,
         0.20f, 0.20f, 0.18f);

    // Horizontal arm
    rect(0.5f, 6.5f,
         3.0f, 7.0f,
         0.20f, 0.20f, 0.18f);

    // Light bulb
    glPushMatrix();
    glTranslatef(3.0f, 6.0f, 0.0f);
    glColor3f(1.0f, 0.86f, 0.25f);
    circle(0.8f);
    glPopMatrix();

    glPopMatrix();
}

// =====================================================
//                     WATER WELL
// =====================================================

void well(float x, float y, float scale)
{
    glPushMatrix();

    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    // Stone base outer structure
    rect(
        -3.0f, 0.0f,
        3.0f, 3.5f,
        0.55f, 0.55f, 0.58f
    );

    // Dark inner well opening
    rect(
        -2.1f, 2.0f,
        2.1f, 3.5f,
        0.15f, 0.15f, 0.18f
    );

    // Wooden support posts
    glColor3f(0.34f, 0.20f, 0.08f);
    glLineWidth(2.5f);

    glBegin(GL_LINES);
        // Left post
        glVertex2f(-2.5f, 3.5f);
        glVertex2f(-2.5f, 7.5f);

        // Right post
        glVertex2f(2.5f, 3.5f);
        glVertex2f(2.5f, 7.5f);
    glEnd();

    // Roof / Canopy
    triangle(
        -3.2f, 7.5f,
        3.2f, 7.5f,
        0.0f, 10.5f,
        0.45f, 0.22f, 0.10f
    );

    // Hanging rope
    glColor3f(0.85f, 0.85f, 0.85f);
    glLineWidth(1.5f);

    glBegin(GL_LINES);
        glVertex2f(0.0f, 7.5f);
        glVertex2f(0.0f, 2.8f);
    glEnd();

    // Small bucket hanging inside
    rect(
        -0.5f, 1.8f,
        0.5f, 2.8f,
        0.35f, 0.35f, 0.38f
    );

    glPopMatrix();
}

// =====================================================
//                     MARKET STALL
// =====================================================

void stall(float x, float y, float r, float g, float b)
{
    // Wooden counter
    rect(x, y, x + 7.0f, y + 3.0f,
         0.48f, 0.28f, 0.10f);

    // Produce area
    rect(x + 0.7f, y + 0.6f,
         x + 6.3f, y + 2.4f,
         0.40f, 0.27f, 0.12f);

    // Roof
    rect(x - 0.3f, y + 5.5f,
         x + 7.3f, y + 7.0f,
         r, g, b);

    // Stripes
    for(int i = 0; i < 4; i++)
    {
        rect(x + i * 1.8f, y + 5.5f,
             x + i * 1.8f + 0.9f, y + 7.0f,
             0.95f, 0.85f, 0.55f);
    }

    // Front posts
    rect(x + 0.3f, y + 3.0f,
         x + 0.7f, y + 6.0f,
         0.23f, 0.14f, 0.07f);

    rect(x + 6.3f, y + 3.0f,
         x + 6.7f, y + 6.0f,
         0.23f, 0.14f, 0.07f);

    // Simple fruits
    glColor3f(0.40f, 0.10f, 0.10f);

    for(int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(x + 1.0f + i * 1.1f,
                     y + 1.4f + (i % 2) * 0.35f, 0.0f);
        circle(0.4f);
        glPopMatrix();
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
//             STATIC BULLOCK CART (IN FIELD)
// =====================================================

void bullockCart(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    // Cart body (using your polygon helper function for the trapezoid)
    float cartBody[][2] = {
        {-3.5f, 1.0f},
        { 3.5f, 1.0f},
        { 3.2f, 4.0f},
        {-3.2f, 4.0f}
    };
    polygon(0.46f, 0.30f, 0.14f, 4, cartBody); // Wood brown

    // Resting front pole (angled slightly downward toward the ground)
    glColor3f(0.34f, 0.20f, 0.08f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(3.2f, 2.5f);
        glVertex2f(6.5f, 1.2f);
    glEnd();

    // Left Wheel (Fixed)
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

    // Right Wheel (Fixed)
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
//                         BOAT
//   FIX: hull was wide-at-bottom / narrow-at-top, which
//   is the silhouette of a capsized boat. A right-side-up
//   hull is narrow at the keel (bottom) and wide at the
//   deck (top) -- swapped below.
// =====================================================

void boat(float x, float y, int flipped)
{
    glPushMatrix();

    glTranslatef(x, y, 0.0f);

    if(flipped == 1)
    {
        glScalef(-1.0f, 1.0f, 1.0f);
    }

    // Boat hull: narrow keel (bottom), wide deck (top)
    float body[][2] =
    {
        {4, 0},
        {11, 0},
        {15, 4},
        {0, 4}
    };

    polygon(0.40f, 0.22f, 0.10f, 4, body);

    // Deck edge (top of hull)
    line2D(0, 4, 15, 4,
           0.18f, 0.10f, 0.04f, 2.0f);

    // Mast (rises from the deck)
    rect(7.0f, 4.0f,
         7.5f, 15.0f,
         0.25f, 0.16f, 0.08f);

    // Sail
    float sail[][2] =
    {
        {7.5f, 14.8f},
        {14.0f, 10.0f},
        {7.5f, 8.8f}
    };

    polygon(0.96f, 0.96f, 0.93f, 3, sail);


    glPopMatrix();
}

// =====================================================
//                     SMALL DOCKED BOAT
//   FIX: same wide-bottom/narrow-top hull bug as boat().
// =====================================================

void smallBoat(float x, float y)
{
    float body[][2] =
    {
        {x + 2, y},
        {x + 8, y},
        {x + 10, y + 2},
        {x, y + 2}
    };

    polygon(0.58f, 0.34f, 0.15f, 4, body);

    rect(x + 1.0f, y + 2.0f,
         x + 8.8f, y + 2.6f,
         0.36f, 0.22f, 0.08f);
}

// =====================================================
//                    WATER RIPPLE
// =====================================================

void ripple(float x, float y, float w)
{
    line2D(x, y, x + w, y,
           0.08f, 0.55f, 0.72f, 1.3f);

    line2D(x + w * 0.20f, y + 1.2f,
           x + w * 0.65f, y + 1.2f,
           0.08f, 0.55f, 0.72f, 1.0f);
}

// =====================================================
//                     VILLAGE PEOPLE
// =====================================================

void person(float x, float y, float scale, float bodyR, float bodyG, float bodyB)
{
    glPushMatrix();

    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    // Head (local offset from base y)
    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glColor3f(0.72f, 0.48f, 0.30f);
    circle(0.9f);
    glPopMatrix();

    // Body (local coordinates)
    rect(-1.0f, 0.0f,
          1.0f, 4.0f,
          bodyR, bodyG, bodyB);

    // Legs (local coordinates)
    line2D(-0.5f, 0.0f,
           -0.8f, -2.2f,
           0.10f, 0.10f, 0.10f, 1.7f);

    line2D( 0.5f, 0.0f,
            0.8f, -2.2f,
            0.10f, 0.10f, 0.10f, 1.7f);

    glPopMatrix();
}
// =====================================================
//                       GRASS
// =====================================================

// =====================================================
//                        BUSH
//   FIX: previously an irregular hand-picked polygon.
//   Rebuilt using the same 3-circle clustering technique
//   as cloud(), just smaller and green.
// =====================================================

void bush(float x, float y, float s)
{
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

void grassMark(float x, float y)
{
    line2D(x, y, x - 1.0f, y + 2.0f,
           0.20f, 0.38f, 0.10f, 1.2f);

    line2D(x, y, x + 0.8f, y + 2.2f,
           0.20f, 0.38f, 0.10f, 1.2f);

    line2D(x, y, x, y + 2.4f,
           0.20f, 0.38f, 0.10f, 1.0f);
}

// =====================================================
//                       RIVER
// =====================================================

void riverBand()
{
    // FIX: the far bank (top) keeps its angled/zig-zag
    // shape; the near bank (bottom) is now a single
    // straight line (constant slope, no bends), as
    // requested -- angles face the top, straight line
    // faces the bottom.

    float xs[5]   = {0,  23, 45, 69, 100};
    float topY[5] = {25, 29, 34, 38, 42};   // far/angled bank

    float botY[5];
    for(int i = 0; i < 5; i++)
    {
        // straight line from (0,12) to (100,27)
        botY[i] = 12.0f + (27.0f - 12.0f) * (xs[i] / 100.0f);
    }

    // Fill: 4 convex trapezoids
    for(int i = 0; i < 4; i++)
    {
        float quad[][2] =
        {
            {xs[i],   botY[i]},
            {xs[i+1], botY[i+1]},
            {xs[i+1], topY[i+1]},
            {xs[i],   topY[i]}
        };

        polygon(0.20f, 0.67f, 0.84f, 4, quad);
    }

    // Far (angled) bank outline
    for(int i = 0; i < 4; i++)
    {
        line2D(xs[i], topY[i], xs[i+1], topY[i+1],
               0.12f, 0.32f, 0.36f, 2.0f);
    }

    // Near (straight) bank outline -- single line, no bends
    line2D(xs[0], botY[0], xs[4], botY[4],
           0.12f, 0.32f, 0.36f, 2.0f);

    // Water ripple marks
    ripple(7, 17, 6);
    ripple(23, 20, 7);
    ripple(44, 24, 6);
    ripple(57, 27, 6);
    ripple(82, 32, 7);
    ripple(89, 37, 5);
}

// =====================================================
//                TIED BOAT (NO SAIL)
//   FIX: the no-sail small boat now sits tied to a log
//   jutting out from the angled (top) bank at one of its
//   bend points, with a rope connecting the two.
// =====================================================

void dockLog(float x, float y)
{
    // Log projecting out from the bank
    rect(x, y, x + 5.0f, y + 1.0f,
         0.30f, 0.19f, 0.09f);

    // Post anchoring the log into the bank
    rect(x - 1.4f, y - 3.5f, x + 0.6f, y + 1.4f,
         0.24f, 0.15f, 0.07f);
}

// =====================================================
//                        ROAD
// =====================================================

void road()
{
    float roadShape[][2] =
    {
        {0, 30},
        {100, 57},
        {100, 64},
        {0, 37}
    };

    polygon(0.25f, 0.25f, 0.27f, 4, roadShape);

    // Road outer white edges
    line2D(0, 30, 100, 57,
           0.95f, 0.95f, 0.95f, 2.0f);

    line2D(0, 37, 100, 64,
           0.95f, 0.95f, 0.95f, 2.0f);

    // Dashed center line
    for(int i = 0; i < 8; i++)
    {
        float x1 = i * 14.0f - 1.0f;
        float y1 = 33.5f + i * 3.78f;
        float x2 = x1 + 7.0f;
        float y2 = y1 + 1.9f;

        line2D(x1, y1, x2, y2,
               1.0f, 1.0f, 1.0f, 2.2f);
    }
}

// =====================================================
//                       MAIN VILLAGE
// =====================================================

void village()
{
    // Sky
    glClearColor(0.28f, 0.61f, 0.84f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // =================================================
    // BACKGROUND
    // =================================================

    rect(0, 40, 100, 100,
         0.28f, 0.61f, 0.84f);

    sun();

    glPushMatrix();
    glTranslatef(cloudMove, 0, 0);

    cloud(18, 87);
    cloud(33, 80);
    cloud(61, 90);

    glPopMatrix();

    hills();

    // =================================================
    // GREEN FIELD
    // FIX: the field used to extend up to y=57, which
    // painted grass over the bottom of the mountains
    // (mountain base is y=48), hiding their base inside
    // the green area instead of sitting on a clean
    // horizon line. Field now stops exactly at y=48, the
    // same height as the mountain base, so the horizon
    // and mountain base are stuck together.
    // =================================================

    rect(0, 0, 100, 52,
         0.42f, 0.62f, 0.30f);

    rect(0, 48, 100, 63,
         0.40f, 0.60f, 0.28f);

    // =================================================
    // GROUND LAYER: RIVER + ROAD
    // FIX: these are now drawn BEFORE any buildings,
    // stalls, wells or people, so every village element
    // is guaranteed to render ON TOP of them instead of
    // being partly painted-over (the old bug where a
    // market stall got drawn under/behind the road).
    // =================================================

    riverBand();
    road();

    // =================================================
    // FENCES
    // Drawn after the road so they remain clearly visible
    // =================================================

    // Fence on upper side of road
    fenceLine( //0, 30, 100, 57,
        0.0f,32.0f,
        100.0f,60.0f,
        12
    );

    // Fence on lower side of road
    fenceLine(//0, 37, 100, 64,
        0.0f,40.0f,
        100.0f,67.0f,
        9
    );


    // =================================================
    // BACKGROUND TREES
    // =================================================

    tree(5, 57, 1.1f);
    tree(20, 62, 1.2f);
    tree(35, 60, 1.25f);
    tree(48, 61, 1.1f);
    tree(63, 58, 1.0f);

    // =================================================
    // HOUSES
    // FIX: the house at x=82 previously had y=37, which
    // put its base below the river's far-bank edge at
    // that x (~39.7), so the river painted over it and
    // it looked like it was sitting in the water. Moved
    // to y=47, clear above the bank.
    // =================================================

    house(7, 53, 13, 9,
          0.92f, 0.83f, 0.55f,
          0.90f, 0.30f, 0.16f);

    house(22, 56, 12, 8,
          0.85f, 0.74f, 0.45f,
          0.75f, 0.18f, 0.10f);

    house(37, 58, 10, 7,
          0.88f, 0.77f, 0.52f,
          0.82f, 0.25f, 0.10f);

    house(50, 59, 8, 7,
          0.75f, 0.45f, 0.31f,
          0.40f, 0.25f, 0.15f);

    house(82, 45, 10, 6,
          0.90f, 0.79f, 0.53f,
          0.95f, 0.25f, 0.12f);

    house(75, 44, 9, 5,
          0.72f, 0.42f, 0.30f,
          0.45f, 0.25f, 0.13f);

    // =================================================
    // SMALL TREES NEAR FIELD
    // (tree at x=16 nudged from y=42 to y=47 so it sits
    // clearly above the road instead of in the middle of it)
    // =================================================

    tree(5, 47, 0.8f);
    tree(20, 45, 0.6f);
    tree(66, 40, 0.8f);
    tree(72, 10, 0.9f);
    tree(95, 12, 0.7f);

    // =================================================
    // VILLAGE WELL
    // =================================================

    well(48.0, 54.0, 1.00);

    // =================================================
    // MARKET STALLS
    // (nudged up slightly so they read clearly as being
    // on the grass above the road, not standing in it)
    // =================================================

    stall(23, 50, 0.88f, 0.08f, 0.08f);
    stall(31, 52, 0.95f, 0.72f, 0.06f);

    // =================================================
    // VILLAGE PEOPLE
    // =================================================

    // Example with scale added as the 3rd parameter
    person(39, 55, 0.65f, 0.25f, 0.30f, 0.75f);
    person(42, 55, 0.65f, 0.80f, 0.20f, 0.30f);
    person(40, 52, 0.7f, 0.30f, 0.55f, 0.75f);
    person(43, 52, 0.7f, 0.30f, 0.55f, 0.75f);


    // =================================================
    // BULLOCK CART
    // =================================================

    bullockCart(55, 39);

    // =================================================
    // BOATS
    // =================================================

    boat(69 + boatMove, 25, 0);
    boat(28, 16, 0);

    // Tied boat (no sail): sits at the angled bank's bend
    // point (x=45), roped to a log jutting out of the bank.
    dockLog(41, 38);
    smallBoat(38, 32);

    line2D(47.0f, 33.6f,
           45.0f, 38.0f,
           0.30f, 0.20f, 0.10f, 1.5f);

    // =================================================
    // FOREGROUND WELL
    // =================================================

    well(60.0f, 6.0f, 1.25f);

    // =================================================
    // FOREGROUND MARKET STALL
    // =================================================

    stall(80, 7, 0.90f, 0.08f, 0.08f);

    // =================================================
    // FOREGROUND GRASS
    // =================================================
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

    // =================================================
    // LITTLE SHRUBS
    // =================================================

    bush(28, 6, 1.0f);
    bush(67, 5, 1.0f);
    bush(25, 33, 0.9f);
    bush(94, 47, 0.8f);
    bush(72, 60, 0.7f);

    // =================================================
    // STREET LAMPS
    // =================================================

    streetLamp(15.0f, 32.0f); // Shifted up from 32.0f
    streetLamp(39.0f, 48.0f); // New intermediate lamp
    streetLamp(62.0f, 46.0f); // New intermediate lamp
    streetLamp(77.0f, 58.0f); // New intermediate lamp
    streetLamp(95.0f, 54.0f); // Shifted up from 57.0f

    glutSwapBuffers();
}

// =====================================================
//                       UPDATE FUNCTION
// =====================================================

void update(int value)
{
    if(animationOn == 1)
    {
        cloudMove += 0.03f;

        if(cloudMove > 105.0f)
        {
            cloudMove = -105.0f;
        }

        boatMove += 0.03f;

        if(boatMove > 16.0f)
        {
            boatMove = -16.0f;
        }
    }

    glutPostRedisplay();

    glutTimerFunc(20, update, 0);
}

// =====================================================
//                    MOUSE CONTROL
// =====================================================

void handleMouse(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            animationOn = 1;
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            animationOn = 0;
        }
    }

    glutPostRedisplay();
}

// =====================================================
//                  KEYBOARD CONTROL
// =====================================================

void handleKeypress(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'q':
        case 'Q':
            timeMode = 0;
            break;

        case 'w':
        case 'W':
            timeMode = 1;
            break;

        case 'e':
        case 'E':
            timeMode = 2;
            break;

        case 'r':
        case 'R':
            timeMode = 3;
            break;

        case 'c':
        case 'C':
            if(animationOn == 1)
            {
                animationOn = 0;
            }
            else
            {
                animationOn = 1;
            }
            break;

        case 27: // ESC
            exit(0);
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

    gluOrtho2D(0, 100, 0, 100);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
}

// =====================================================
//                         MAIN
// =====================================================

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1200, 900);

    glutInitWindowPosition(100, 40);

    glutCreateWindow("Scene - Village");

    init();

    glutDisplayFunc(village);

    glutKeyboardFunc(handleKeypress);

    glutMouseFunc(handleMouse);

    glutTimerFunc(20, update, 0);

    glutMainLoop();

    return 0;
}
