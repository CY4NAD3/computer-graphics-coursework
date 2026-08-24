#include <GL/freeglut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 700.0, 0.0, 450.0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 700.0, 0.0, 450.0);
    glMatrixMode(GL_MODELVIEW);
}

// helper function for straight rectangles
void box(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

// helper function for angled shapes (bow, stern, bridge)
void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
    glEnd();
}

// Function to draw simple lines (wires, railings)
void line(float x1, float y1, float x2, float y2, float width = 2.0) {
    glLineWidth(width);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // WATER
    glColor3f(0.53, 0.78, 0.83); // Light blue
    box(140, 50, 620, 60);

    // LOWER HULL (Dark Red)
    glColor3f(0.48, 0.13, 0.16);
    glBegin(GL_POLYGON);
        glVertex2f(190, 60);  // Bottom left (stern base)
        glVertex2f(580, 60);  // Bottom right (bow base)
        glVertex2f(615, 100); // Top right (meets blue hull bow)
        glVertex2f(165, 100); // Top left (meets blue hull stern)
    glEnd();

    // UPPER HULL (Navy Blue)
    glColor3f(0.09, 0.27, 0.41);
    glBegin(GL_POLYGON);
        glVertex2f(165, 100); // Bottom left (angles out from red hull)
        glVertex2f(615, 100); // Bottom right (starts sharp bow angle)
        glVertex2f(660, 180); // Top right (very front tip of the bow)
        glVertex2f(550, 180); // Top horizontal edge moving left
        glVertex2f(140, 180); // Top left (angles outward at the stern)
    glEnd();

    // Dark Anchor Hole
    glColor3f(0.05, 0.1, 0.15);
    quad(595, 115, 615, 115, 625, 145, 610, 145);

    // Yellow Portholes
    glColor3f(0.96, 0.83, 0.36);
    box(540, 145, 550, 155);
    box(565, 145, 575, 155);
    box(590, 145, 600, 155);
    box(615, 145, 625, 155);

    // WHITE DECK STRIPE
    glColor3f(0.93, 0.92, 0.84);
    // Use polygon here too so the back left edge aligns perfectly with the blue hull's slant
    glBegin(GL_POLYGON);
        glVertex2f(140, 180);
        glVertex2f(550, 180);
        glVertex2f(550, 195);
        glVertex2f(140, 195);
    glEnd();

    // Tan detail block on the left edge
    glColor3f(0.85, 0.76, 0.60);
    box(140, 180, 175, 235);
    // Windows on tan block
    glColor3f(0.6, 0.55, 0.5);
    box(145, 195, 165, 210);
    // Windows on tan block
    glColor3f(0.6, 0.55, 0.5);
    box(145, 195, 165, 210);

    // LOWER CREAM SUPERSTRUCTURE
    glColor3f(0.93, 0.92, 0.84);
    box(175, 195, 550, 235);

    // Square Beige Windows (Left side of lower deck)
    glColor3f(0.70, 0.68, 0.60);
    for(int x = 185; x <= 335; x += 30) {
        box(x, 205, x + 15, 220);
    }

    // Long Light Blue Windows (Right side of lower deck)
    glColor3f(0.46, 0.71, 0.79);
    box(410, 205, 450, 218);
    box(465, 205, 505, 218);

    // FUNNEL & CONTAINERS (Drawn behind bridge)
    // Funnel (Yellow-Tan with Black/Red top)
    glColor3f(0.87, 0.68, 0.38); // Yellow
    box(360, 280, 385, 345);
    glColor3f(0.67, 0.15, 0.18); // Red Stripe
    box(360, 315, 385, 325);
    glColor3f(0.15, 0.15, 0.15); // Black Top
    box(360, 325, 385, 345);

    // Cargo Containers
    glColor3f(0.85, 0.25, 0.15); // Red Container
    box(385, 235, 415, 285);
    glColor3f(0.35, 0.65, 0.80); // Blue Container
    box(415, 235, 445, 285);
    // Container detail line
    glColor3f(0.2, 0.4, 0.6);
    line(430, 235, 430, 285, 2.0);

    // UPPER RED CABIN
    glColor3f(0.67, 0.15, 0.18);
    box(220, 235, 380, 290);

    // Darker red shading detail
    glColor3f(0.55, 0.12, 0.15);
    box(220, 235, 250, 290);

    // Small dark blue window squares on red cabin
    glColor3f(0.09, 0.27, 0.41);
    box(240, 260, 255, 275);
    box(265, 260, 280, 275);
    box(290, 260, 305, 275);
    box(315, 260, 330, 275);

    // TOP BRIDGE (Cream)
    // Bridge Base
    glColor3f(0.93, 0.92, 0.84);
    box(235, 290, 380, 305);

    // Angled Bridge Windows Area
    quad(225, 340, 395, 340, 380, 305, 235, 305);

    // Light Blue Bridge Windows
    glColor3f(0.46, 0.71, 0.79);
    quad(235, 330, 250, 330, 255, 310, 245, 310); // Left angled window
    box(258, 310, 275, 330);
    box(282, 310, 299, 330);
    box(306, 310, 323, 330);
    box(330, 310, 347, 330);
    box(354, 310, 371, 330);
    quad(375, 330, 385, 330, 375, 310, 368, 310); // Right angled window

    // Bridge Roof (Red Overhang)
    glColor3f(0.67, 0.15, 0.18);
    box(215, 340, 405, 348);

    // RAILINGS
    glColor3f(0.67, 0.15, 0.18); // Red rails
    // Front and back lower deck rails
    line(140, 245, 220, 245, 3.0);
    line(445, 245, 550, 245, 3.0);
    // Vertical posts
    for(int x = 145; x <= 220; x += 15) line(x, 235, x, 245, 2.0);
    for(int x = 450; x <= 550; x += 15) line(x, 235, x, 245, 2.0);

    // MASTS & ANTENNAS
    // Front Radar Mast (On top of bridge)
    glColor3f(0.12, 0.15, 0.18);
    box(297, 348, 305, 420); // Center Pole
    // Radar box structure (wireframe look using thin boxes)
    box(285, 370, 317, 374);
    box(285, 390, 317, 394);
    box(285, 410, 317, 414);
    box(285, 370, 289, 414); // Left side
    box(313, 370, 317, 414); // Right side
    box(297, 420, 305, 425); // Top beacon

    // Rear Mast (Stern)
    glColor3f(0.15, 0.15, 0.15);
    box(585, 180, 592, 330); // Tall pole
    box(570, 310, 595, 315); // Crossbar

    // Guy-wire / Rope
    glColor3f(0.85, 0.80, 0.70); // Light tan rope color
    line(590, 310, 630, 180, 2.0);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 450);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Vector Cargo Ship");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
