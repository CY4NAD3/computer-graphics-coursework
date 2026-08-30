#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1416
//GLOBAL VARIABLES

// My car position
float myCarMove = -8.0f;

// Opposite cars position
float otherCar1 = 108.0f;
float otherCar2 = 68.0f;
float otherCar3 = 28.0f;

// Cloud movement
float cloudMove = 0.0f;

// Wheel rotation
float myWheelAngle = 0.0f;
float trafficWheelAngle = 0.0f;

// All animation control
int animationOn = 1;

// My car control
int vehicleOn = 1;

// Street light control
int lightsOn = 1;
// 0 = Dawn
// 1 = Day
// 2 = Evening
// 3 = Night
int timeMode = 1;


     //   RECTANGLE FUNCTION
void rect(float x1, float y1,float x2, float y2,float r, float g, float b)   // ref#rectHelper
{
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glEnd();
}

void circle(float radius) // ref#circleHelper
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

void windowRect(float x1, float y1,float x2, float y2)  // ref#windowHelper
{
    if(timeMode == 3)
    {
        rect( x1, y1,x2, y2,1.0f, 0.8f, 0.2f);
    }
    else
    {
        rect( x1, y1,x2, y2, 0.7f, 0.9f, 1.0f);
    }
}


void sun()  // ref#sunFunction
{
    if(timeMode == 3)
    {
        return;
    }

    glPushMatrix();

    // Dawn
    if(timeMode == 0)
    {
        glTranslatef(12.0f,86.0f,0.0f);

        glColor3f(1.0f,0.45f,0.10f);
    }
    // Day
    else if(timeMode == 1)
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

    circle(4.5f);

    glPopMatrix();
}


        // BUILDING 1
void building1() // ref#building1Function
{
    rect(1.5f, 52,16.0f, 78,0.20f, 0.40f, 1.0f);

    windowRect(4.0f, 61,7.0f, 66);

    windowRect(10.5f, 61,13.5f, 66);

    windowRect(4.0f, 69,7.0f, 74);

    windowRect(10.5f, 69,13.5f, 74);
}

              // BUILDING 2
void building2()  // ref#building2Function
{
    rect(17.0f, 52,32.0f, 90,0.65f, 0.30f, 0.25f);

    windowRect(19.5f, 61,22.5f, 66);

    windowRect(26.5f, 61,29.5f, 66);

    windowRect(19.5f, 71,22.5f, 76);

    windowRect(26.5f, 71,29.5f, 76);

    windowRect(19.5f, 81,22.5f, 86);

    windowRect(26.5f, 81,29.5f, 86);
}


    //  BUILDING 3
void building3()  // ref#building3Function
{
    rect(33.0f, 52,47.5f, 75,0.35f, 0.60f, 0.75f);

    windowRect(35.5f, 60,38.5f, 65);

    windowRect(42.0f, 60,45.0f, 65);

    windowRect(35.5f, 68,38.5f, 72);

    windowRect(42.0f, 68,45.0f, 72);
}


        //  BUILDING 4
void building4()  // ref#building4Function
{
    rect(48.0f, 39,64.5f, 83,0.45f, 0.60f, 0.40f);

    // Door
    rect(54.3f, 39,58.3f, 48,0.30f, 0.15f, 0.05f);

    windowRect(50.5f, 52,54.0f, 57);

    windowRect(58.5f, 52,62.0f, 57);

    windowRect(50.5f, 63,54.0f, 68);

    windowRect(58.5f, 63,62.0f, 68);

    windowRect(50.5f, 73,54.0f, 78);

    windowRect(58.5f, 73,62.0f, 78);
}


            // SHOP
void shop(float x1,float x2,float r,float g,float b)  // ref#shopStyleA
{
    // Shop body
    rect(x1, 39,x2, 52,r, g, b);

    // Red roof
    rect(x1 - 0.3f, 50.5f,x2 + 0.3f, 52,0.80f, 0.10f, 0.10f);

    // Window
    windowRect(x1 + 1.0f,43,x1 + 3.5f,47.5f);

    // Door
    rect(x2 - 4.0f,39,x2 - 1.0f,47,0.15f, 0.15f, 0.15f);
}


        // STATIC TREE
void tree(float x, float y)  // ref#treeStyleA
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
void cloud(float x, float y)  // ref#cloudStyleA
{
    glColor3f(1.0f,1.0f,1.0f);


    glPushMatrix();

    glTranslatef(x,y,0);

    circle(3.0f);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(x + 4,y + 1,0);

    circle(4.0f);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(x + 8,y,0);

    circle(3.0f);

    glPopMatrix();
}


        //  BENCH
void bench(float x, float y) // ref#benchStyleA
{
    // Back
    rect(x,y + 3.0f,x + 7.0f,y + 4.0f,0.55f, 0.30f, 0.10f);

    // Middle wood
    rect(x,y + 1.8f,x + 7.0f,y + 2.6f,0.65f, 0.38f, 0.12f);

    // Seat
    rect(x,y,x + 7.0f,y + 1.0f,0.60f, 0.34f, 0.10f);

    // Left leg
    rect(x + 1.0f,y - 2.0f,x + 1.8f,y,0.18f, 0.18f, 0.18f);

    // Right leg
    rect(x + 5.2f,y - 2.0f,x + 6.0f,y,0.18f, 0.18f, 0.18f);
}


         // SMALL PARK
void park()  // ref#parkFunction
{
    // Grass
    rect(65, 39,100, 46,0.28f, 0.62f, 0.25f);

    // Back grass
    rect(65, 45,100, 47,0.22f, 0.55f, 0.20f);

    // Park walking path
    glColor3f(0.82f,0.76f,0.58f);

    glBegin(GL_POLYGON);

    glVertex2f(67.0f, 39.3f);
    glVertex2f(98.0f, 39.3f);
    glVertex2f(94.0f, 43.0f);
    glVertex2f(70.0f, 43.0f);

    glEnd();

    tree(68,42); // ref#treeObj1

    tree(78,42); // ref#treeObj2

    tree(90,42); // ref#treeObj3

    tree(98,42); // ref#treeObj4

    bench(70,43); // ref#benchObj1

    bench(84,43);  // ref#benchObj2
}
              //STREET LAMP

void lamp(float x)  // ref#lampStyleA
{
    // Pole
    rect(x, 35,x + 0.5f, 48,0.15f, 0.15f, 0.15f);

    // Top arm
    rect(x, 47.5f,x + 3, 48,0.15f, 0.15f, 0.15f);

    glPushMatrix();

    glTranslatef(x + 3,47.0f,0);


    if(timeMode == 3 &&
            lightsOn == 1)
    {
        glColor3f(1.0f,1.0f,0.0f);

        circle(1.3f);
    }

    else
    {
        glColor3f(0.3f,0.3f,0.3f);

        circle(0.8f);
    }


    glPopMatrix();
}
     // FOOTPATH

void walkingRoad()  // ref#footpathFunction
{
    // Upper footpath
    rect(0, 34,100, 39,0.75f, 0.75f, 0.70f);

    // White edge
    rect(0, 34,100, 34.6f,0.95f, 0.95f, 0.95f);

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
    rect(0, 0,100, 6,0.75f, 0.75f, 0.70f);

    // White edge
    rect(0, 5.4f,100, 6,0.95f, 0.95f, 0.95f);
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
void road()  // ref#roadFunction
{
    // Main road
    rect(0, 6,100, 34,0.22f, 0.22f, 0.22f);

    for(int i = 0; i < 100; i += 14)
    {
        rect(i, 19.5f,i + 8, 20.5f,1.0f, 1.0f, 1.0f);
    }
}

//CAR WHEEL
void wheel(float x,float y,float angle)  // ref#wheelHelper
{
    glPushMatrix();

    glTranslatef(x,y,0);

    glRotatef(angle,0,0,1);

    // Black wheel
    glColor3f(0.0f,0.0f,0.0f);

    circle(1.4f);

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

    circle(0.5f);

    glPopMatrix();
}
               //CAR
void car(float x, float y,float r,float g,float b,int direction,float angle)  // ref#carStyleA
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


    wheel(-3.2f,0,angle);

    wheel(3.2f,0,angle);


    glPopMatrix();
}
// TOWN SCENE
void town()  // ref#townScene
{
    if(timeMode == 0)
    {
        glClearColor(0.95f,0.55f,0.45f,1.0f);
    }

    else if(timeMode == 1)
    {
        glClearColor(0.45f,0.75f,1.0f,1.0f);
    }

    else if(timeMode == 2)
    {
        glClearColor(0.80f,0.35f,0.25f,1.0f);
    }

    else
    {
        glClearColor(0.03f,0.05f,0.18f,1.0f);
    }


    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    sun();  // ref#sunObj1

    glPushMatrix();

    glTranslatef(cloudMove,0,0);

    cloud(5, 94);  // ref#cloudObj1
    cloud(40, 94);  // ref#cloudObj2
    cloud(70, 92);  // ref#cloudObj3

    glPopMatrix();


    building1();  // ref#buildingObj1
    building2();   // ref#buildingObj2
    building3();   // ref#buildingObj3
    building4();   // ref#buildingObj4


    shop(1.5f,16.0f,0.80f,0.50f,0.20f);  // ref#shopObj1


    shop(17.0f,32.0f,0.20f,0.70f,0.70f);   // ref#shopObj2


    shop(33.0f,47.5f,0.70f,0.30f,0.60f);  // ref#shopObj3

    park();  // ref#parkObj1

    // Footpath
    walkingRoad();   // ref#footpathObj1

    lamp(8);   // ref#lampObj
    lamp(34);   // ref#lampObj2
    lamp(62);   // ref#lampObj3
    lamp(88);   // ref#lampObj4

    road();   // ref#roadObj1

    // OPPOSITE CARS
    // RIGHT -> LEFT

    car(otherCar1,24.0f,1.0f,1.0f,0.0f,-1,trafficWheelAngle);  // ref#trafficCarObj1


    car(otherCar2,24.0f,0.0f,0.7f,1.0f,-1,trafficWheelAngle);  // ref#trafficCarObj2


    car(otherCar3,24.0f,0.7f,0.2f,0.8f,-1,trafficWheelAngle);  // ref#trafficCarObj3

    // MY RED CAR
    // LEFT -> RIGHT

    car(myCarMove,10.5f,1.0f,0.0f,0.0f,1,myWheelAngle);  // ref#myCarObj1

    glutSwapBuffers();
}

void nextScene()   // ref#nextScene
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

void update(int value)   // ref#updateAnimation
{
    if(animationOn == 1)
    {
        // Cloud movement
        cloudMove += 0.05f;


        if(cloudMove > 105.0f)
        {
            cloudMove = -100.0f;
        }
        // OPPOSITE CARS
        // RIGHT -> LEFT

        otherCar1 -= 0.18f;
        otherCar2 -= 0.18f;
        otherCar3 -= 0.18f;


        if(otherCar1 < -8.0f)
        {
            otherCar1 = 108.0f;
        }


        if(otherCar2 < -8.0f)
        {
            otherCar2 = 108.0f;
        }


        if(otherCar3 < -8.0f)
        {
            otherCar3 = 108.0f;
        }


        trafficWheelAngle -= 5.0f;


        if(trafficWheelAngle < -360.0f)
        {
            trafficWheelAngle = 0.0f;
        }
        // MY CAR
        // LEFT -> RIGHT

        if(vehicleOn == 1)
        {
            myCarMove += 0.20f;

            myWheelAngle -= 5.0f;


            if(myCarMove > 108.0f)
            {
                myCarMove = -8.0f;
            }


            if(myWheelAngle < -360.0f)
            {
                myWheelAngle = 0.0f;
            }
        }
    }


    glutPostRedisplay();


    glutTimerFunc(20,update,0);
}

void handleMouse(int button,int state,int x,int y)  // ref#mouseControl
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

void handleKeypress(unsigned char key,int x,int y)   // ref#keyboardControl
{
    switch(key)
    {
    // C = Next Scene
    case 'c':
    case 'C':

        glutDisplayFunc(
            nextScene
        );

        glutPostRedisplay();

        break;
    // Q = Dawn
    case 'q':
    case 'Q':

        timeMode = 0;

        glutPostRedisplay();

        break;
    // W = Day
    case 'w':
    case 'W':

        timeMode = 1;

        glutPostRedisplay();

        break;
    // E = Evening
    case 'e':
    case 'E':

        timeMode = 2;

        glutPostRedisplay();

        break;
    // R = Night
    case 'r':
    case 'R':

        timeMode = 3;

        glutPostRedisplay();

        break;
    // T = Light ON/OFF
    case 't':
    case 'T':

        if(lightsOn == 1)
        {
            lightsOn = 0;
        }

        else
        {
            lightsOn = 1;
        }


        glutPostRedisplay();

        break;
    }
}

void handleSpecialKey(int key,int x,int y)  // ref#specialKeyControl
{
    switch(key)
    {
    // UP = My car move
    case GLUT_KEY_UP:

        vehicleOn = 1;

        break;
    // DOWN = My car stop
    case GLUT_KEY_DOWN:

        vehicleOn = 0;

        break;
    }

    glutPostRedisplay();
}

void init()  // ref#initFunction
{
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();


    gluOrtho2D(0,100,0,100);

    glMatrixMode(GL_MODELVIEW);
}


int main(int argc,char** argv)   // ref#mainFunction
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE |GLUT_RGB);

    glutInitWindowSize(1000,700);

    glutInitWindowPosition(100,50);

    glutCreateWindow("Scene 2 - Town");

    init();

    glutDisplayFunc(town);

    glutKeyboardFunc(handleKeypress);

    glutSpecialFunc(handleSpecialKey);

    glutMouseFunc(handleMouse);

    glutTimerFunc(20,update,0);

    glutMainLoop();

    return 0;
}
