// =====================================================
//                      CONTROLS
// =====================================================
// Scene switching:
//   M           - manually toggle between Scene 1 and Scene 2
//   Scene 1/2 buttons (bottom-left of window) - click to switch
//   Auto-switch - scenes alternate automatically every ~15 seconds
//
// Scenario 1 (Day and Night):
//   D           - force Dawn (pauses auto day-night cycle)
//   F           - force Day (pauses auto day-night cycle)
//   E           - force Evening (pauses auto day-night cycle)
//   N           - force Night (pauses auto day-night cycle)
//   R           - resume automatic day-night cycle
//   Left Click  - pause/resume day-night cycle
//
// Scenario 2 (Moving Car):
//   W           - increase car speed
//   S           - decrease car speed
//   A           - reverse car direction
//   Space       - pause/resume car movement
//   Left Click  - pause/resume car movement
//   Right Click - reverse car direction
// =====================================================

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1416

// =====================================================
//                 GLOBAL VARIABLES
// =====================================================

int currentScene = 0;      // 0 = Day-Night Scene, 1 = Car Scene
int autoSwitchTimer = 0;   // ticks toward automatic scene switch
int autoSwitchLimit = 750; // ~15 seconds at 20ms per tick

// Scenario 1 (Day-Night)
float cycle1 = 0.0f;
int timeMode = 2;          // 0=Night, 1=Dawn, 2=Day, 3=Evening
bool scene1Paused = false;

// Scenario 2 (Car)
float carX = 10.0f;
float wheelAngle = 0.0f;
float carSpeed = 0.4f;
int carDirection = 1;
bool scene2Paused = false;

// =====================================================
//                 BASIC SHAPE FUNCTIONS
// =====================================================

void rect(float x1, float y1, float x2, float y2, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void circle(float radius){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for(int i = 0; i <= 360; i++){
        float angle = i * PI / 180.0f;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

void drawText(float x, float y, const char* text){
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(x, y);
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// =====================================================
//              SCENARIO 1: DAY-NIGHT OBJECTS
// =====================================================

void sun(){
    glPushMatrix();
    glTranslatef(53.0f, 78.0f, 0.0f);
    glColor3f(1.0f, 0.85f, 0.05f);
    circle(4.2f);
    glPopMatrix();
}

void moon(){
    glPushMatrix();
    glTranslatef(75.0f, 76.0f, 0.0f);
    glColor3f(0.92f, 0.94f, 0.98f);
    circle(3.5f);
    glPopMatrix();
}

void stars(){
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
        glVertex2f(15.0f, 72.0f);
        glVertex2f(28.0f, 80.0f);
        glVertex2f(40.0f, 68.0f);
        glVertex2f(60.0f, 82.0f);
        glVertex2f(85.0f, 75.0f);
    glEnd();
}

void tree1(float x, float y, float scale){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);
    rect(-0.55f, 0.0f, 0.55f, 5.0f, 0.34f, 0.21f, 0.09f);
    triangle(-3.7f, 3.5f, 3.7f, 3.5f, 0.0f, 10.5f, 0.10f, 0.42f, 0.10f);
    triangle(-2.8f, 8.0f, 2.8f, 8.0f, 0.0f, 14.0f, 0.16f, 0.55f, 0.14f);
    glPopMatrix();
}

void house1(float x, float y, float w, float h, int lit){
    rect(x, y, x + w, y + h, 0.92f, 0.83f, 0.55f);
    triangle(x - 1.5f, y + h, x + w + 1.5f, y + h, x + w * 0.5f, y + h + 8.0f, 0.60f, 0.20f, 0.14f);
    rect(x + w * 0.58f, y, x + w * 0.76f, y + h * 0.48f, 0.27f, 0.15f, 0.08f);

    if(lit == 1){
        rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.95f, 0.85f, 0.30f);
    }
    else{
        rect(x + w * 0.16f, y + h * 0.38f, x + w * 0.37f, y + h * 0.62f, 0.36f, 0.24f, 0.12f);
    }
}

void sceneOneDraw(){
    float skyR, skyG, skyB;

    if(timeMode == 0){
        skyR = 0.06f; skyG = 0.08f; skyB = 0.18f;
    }
    else if(timeMode == 1){
        skyR = 0.85f; skyG = 0.50f; skyB = 0.35f;
    }
    else if(timeMode == 2){
        skyR = 0.28f; skyG = 0.61f; skyB = 0.84f;
    }
    else{
        skyR = 0.55f; skyG = 0.30f; skyB = 0.45f;
    }

    rect(0, 30, 100, 90, skyR, skyG, skyB);

    if(timeMode == 0){
        moon();
        stars();
    }
    else{
        sun();
    }

    rect(0, 0, 100, 30, 0.30f, 0.55f, 0.25f);
    tree1(15, 30, 0.9f);
    tree1(85, 30, 0.8f);
    house1(40, 30, 20, 13, timeMode == 0);

    drawText(3, 92, "Scenario 1: Day and Night");
}

void sceneOneKeyboard(unsigned char key){
    if(key == 'd' || key == 'D'){
        timeMode = 1;
        scene1Paused = true;
    }
    else if(key == 'f' || key == 'F'){
        timeMode = 2;
        scene1Paused = true;
    }
    else if(key == 'e' || key == 'E'){
        timeMode = 3;
        scene1Paused = true;
    }
    else if(key == 'n' || key == 'N'){
        timeMode = 0;
        scene1Paused = true;
    }
    else if(key == 'r' || key == 'R'){
        scene1Paused = false;
    }
}

void sceneOneMouse(int button, int state, float ox, float oy){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        scene1Paused = !scene1Paused;
    }
}

void sceneOneUpdate(){
    if(scene1Paused){
        return;
    }

    cycle1 += 0.15f;
    if(cycle1 >= 400.0f){
        cycle1 = 0.0f;
    }

    if(cycle1 < 100.0f) timeMode = 1;
    else if(cycle1 < 200.0f) timeMode = 2;
    else if(cycle1 < 300.0f) timeMode = 3;
    else timeMode = 0;
}

// =====================================================
//                SCENARIO 2: CAR OBJECTS
// =====================================================

void wheel(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    circle(3.0f);

    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(0.8f, 0.8f, 0.8f);
    rect(-0.4f, -3.0f, 0.4f, 3.0f, 0.8f, 0.8f, 0.8f);
    rect(-3.0f, -0.4f, 3.0f, 0.4f, 0.8f, 0.8f, 0.8f);
    glPopMatrix();
}

void car(float x){
    glPushMatrix();
    glTranslatef(x, 0.0f, 0.0f);

    rect(0, 10, 25, 18, 0.75f, 0.15f, 0.15f);
    triangle(3, 18, 10, 25, 18, 18, 0.75f, 0.15f, 0.15f);

    wheel(6, 8);
    wheel(19, 8);

    glPopMatrix();
}

void sceneTwoDraw(){
    rect(0, 0, 100, 100, 0.55f, 0.75f, 0.85f);
    rect(0, 0, 100, 8, 0.35f, 0.35f, 0.35f);
    car(carX);

    drawText(3, 92, "Scenario 2: Moving Car");
}

void sceneTwoKeyboard(unsigned char key){
    if(key == 'w' || key == 'W'){
        carSpeed += 0.1f;
    }
    else if(key == 's' || key == 'S'){
        carSpeed -= 0.1f;
        if(carSpeed < 0.0f){
            carSpeed = 0.0f;
        }
    }
    else if(key == 'a' || key == 'A'){
        carDirection = -carDirection;
    }
    else if(key == ' '){
        scene2Paused = !scene2Paused;
    }
}

void sceneTwoMouse(int button, int state, float ox, float oy){
    if(state != GLUT_DOWN){
        return;
    }

    if(button == GLUT_LEFT_BUTTON){
        scene2Paused = !scene2Paused;
    }
    else if(button == GLUT_RIGHT_BUTTON){
        carDirection = -carDirection;
    }
}

void sceneTwoUpdate(){
    if(scene2Paused){
        return;
    }

    carX += carSpeed * carDirection;
    if(carX > 90.0f){
        carX = -20.0f;
    }
    if(carX < -20.0f){
        carX = 90.0f;
    }

    wheelAngle -= carSpeed * 8.0f;
    if(wheelAngle < -360.0f){
        wheelAngle = 0.0f;
    }
}

// =====================================================
//              MERGE: BUTTONS AND DISPATCH
// =====================================================

void drawButtons(){
    if(currentScene == 0){
        rect(2, 2, 22, 8, 0.20f, 0.60f, 0.20f);
        rect(24, 2, 44, 8, 0.40f, 0.40f, 0.40f);
    }
    else{
        rect(2, 2, 22, 8, 0.40f, 0.40f, 0.40f);
        rect(24, 2, 44, 8, 0.20f, 0.60f, 0.20f);
    }

    drawText(5, 4, "Scene 1");
    drawText(27, 4, "Scene 2");
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    if(currentScene == 0){
        sceneOneDraw();
    }
    else{
        sceneTwoDraw();
    }

    drawButtons();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    if(key == 'm' || key == 'M'){
        currentScene = !currentScene;
        autoSwitchTimer = 0;
    }
    else if(currentScene == 0){
        sceneOneKeyboard(key);
    }
    else{
        sceneTwoKeyboard(key);
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    float ox = (x / 800.0f) * 100.0f;
    float oy = ((600 - y) / 600.0f) * 100.0f;

    if(state == GLUT_DOWN && oy >= 2.0f && oy <= 8.0f){
        if(ox >= 2.0f && ox <= 22.0f){
            currentScene = 0;
            autoSwitchTimer = 0;
            glutPostRedisplay();
            return;
        }
        else if(ox >= 24.0f && ox <= 44.0f){
            currentScene = 1;
            autoSwitchTimer = 0;
            glutPostRedisplay();
            return;
        }
    }

    if(currentScene == 0){
        sceneOneMouse(button, state, ox, oy);
    }
    else{
        sceneTwoMouse(button, state, ox, oy);
    }

    glutPostRedisplay();
}

void update(int value){
    sceneOneUpdate();
    sceneTwoUpdate();

    autoSwitchTimer++;
    if(autoSwitchTimer >= autoSwitchLimit){
        currentScene = !currentScene;
        autoSwitchTimer = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

// =====================================================
//                        INIT
// =====================================================

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// =====================================================
//                        MAIN
// =====================================================

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Merged Scenario: Day-Night and Car");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(20, update, 0);

    glutMainLoop();
    return 0;
}
