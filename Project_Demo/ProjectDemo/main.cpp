#include <iostream>
#include<cstdio>
#include<stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
# define PI 3.14159265358979323846

///................................TOWN......................................///

void dis();
void drawScene();
void myInit()
{


    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
}
GLfloat car_position = -1.5f;
GLfloat speedcar = 0.002f;
void updatecar(int value)
{
    car_position += speedcar;
    if (car_position > 1.2)
        car_position = -1.5f;

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, updatecar, 0); // 60 FPS
}
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        float angle = 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

float p = -10;
int i= -700;
float j= -250;
float k= -100;
///////////town//////////////////////
///Lamp post///
void lamp()
{
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1,-1, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 131, 131);
    glVertex2f(233,81);
    glVertex2f(234,81);
    glVertex2f(234,197);
    glVertex2f(233,197);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(83, 131, 131);
    glVertex2f(333,81);
    glVertex2f(334,81);
    glVertex2f(334,197);
    glVertex2f(333,197);
    glEnd();
    glPopMatrix();
}

void car()
{
    glScalef(0.15,0.15,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.0, 0.0);
//car-body

    glVertex2f(-0.79,0.05);
    glVertex2f(-0.8,0.22);
    glVertex2f(-0.77,0.27);
    //glVertex2f(-0.6,0.3);
    glVertex2f(-0.5,0.3);
    glVertex2f(-0.35,0.6);
    glVertex2f(0.35,0.6);
    glVertex2f(0.65,0.3);
    glVertex2f(0.9,0.28);
    glVertex2f(1.0,0.23);
    glVertex2f(1.05,0.1);
    glVertex2f(0.99,0.1);
    glVertex2f(0.99,0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.54, 0.61, 0.55); //window
    glVertex2f(-0.4,0.31);
    glVertex2f(-0.28,0.56);
    glVertex2f(0.32,0.56);
    glVertex2f(0.58,0.31);



    glEnd();
    glLineWidth(7.5);
    glBegin(GL_LINES);
    glColor3f(0.7f, 0.0f, 0.0f); //middle of window
    glVertex2f(0,0.58);
    glVertex2f(0,0.31);
    glEnd();




    float x1=-0.47,x2=0.47,y1=-0.033,y2=-0.033,radius=0.13;;
    int i;
    int triangleAmount = 360; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f *3.14159;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x2, y2); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x1, y1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


}

void tree()
{



    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1,-1, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
///....Left side circle tree in Food court..... ///
    glColor3ub(139, 146, 22);
    circle(3,6,280,101);
    glColor3ub(139, 146, 22);
    circle(5,12,275,111);
    glColor3ub(139, 146, 22);
    circle(5,12,285,111);
    glColor3ub(139, 146, 22);
    circle(5,12,290,106);
    glColor3ub(139, 146, 22);
    circle(5,12,270,121);


    glColor3ub(181, 106, 76);
    circle(5,12,275,123);
    glColor3ub(139, 146, 22);
    circle(5,12,276,123);
    glColor3ub(139, 146, 22);
    circle(5,12,280,141);
    glColor3ub(139, 146, 22);
    circle(4,10,275,136);
    glColor3ub(181, 106, 76);
    circle(4,10,277,134);

    glColor3ub(139, 146, 22);
    circle(4,10,278,133);

    glColor3ub(139, 146, 22);
    circle(5,12,290,131);
    glColor3ub(139, 146, 22);
    circle(5,12,285,131);
    glColor3ub(181, 106, 76);
    circle(5,12,284,126);
    glColor3ub(139, 146, 22);
    circle(5,12,283,125);
    glColor3ub(139, 146, 22);
    circle(5,12,295,121);
    glColor3ub(181, 106, 76);
    circle(5,12,290,116);
    glColor3ub(139, 146, 22);
    circle(5,12,289,116);
    glColor3ub(139, 146, 22);
    circle(5,12,280,119);
    glColor3ub(139, 146, 22);
    circle(5,12,292,141);

    glColor3ub(227, 91, 137);
    circle(1,2,280,119);
    glColor3ub(227, 91, 137);
    circle(1,2,280,133);
    glColor3ub(227, 91, 137);
    circle(1,2,290,133);
    glColor3ub(227, 91, 137);
    circle(1,2,295,128);
    glColor3ub(227, 91, 137);
    circle(1,2,269,119);
    glColor3ub(227, 91, 137);
    circle(1,2.5,275,134);
    glColor3ub(227, 91, 137);
    circle(1,1.5,276,110);
    glColor3ub(227, 91, 137);
    circle(1,2.5,290,106);
    glColor3ub(227, 91, 137);
    circle(1,3,295,119);
    glColor3ub(227, 91, 137);
    circle(1,3,285,103);

    glBegin(GL_TRIANGLE_FAN);  // tree stem 1....//
    glColor3ub(75, 35, 5);
    glVertex2f(285,90);
    glVertex2f(288,90);
    glVertex2f(287,100);
    glVertex2f(282,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  // tree stem 2....//
    glColor3ub(75, 35, 5);
    glVertex2f(285,90);
    glVertex2f(288,90);
    glVertex2f(284,100);
    glVertex2f(278,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  // tree stem 3....//
    glColor3ub(75, 35, 5);
    glVertex2f(284,90);
    glVertex2f(288,90);
    glVertex2f(289,110);
    glVertex2f(292,140);
    glEnd();

    glPopMatrix();
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1,-1, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
/// christmas tree.........beside 4th Building.....///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,05);
    glVertex2f(545,119);  // tree stem ....//
    glVertex2f(550,119);
    glVertex2f(550,139);
    glVertex2f(545,139);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(535,139);    // tree  tri 1....//
    glVertex2f(560,139);
    glVertex2f(547.5,169);
    glVertex2f(547.5,169);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(536,149);    // tree  tri 2....//
    glVertex2f(559,149);
    glVertex2f(547.5,189);
    glVertex2f(547.5,189);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(537,159);    // tree  tri 3....//
    glVertex2f(558,159);
    glVertex2f(547.5,209);
    glVertex2f(547.5,209);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(537.5,169);  // tree  tri 4....//
    glVertex2f(557.5,169);
    glVertex2f(547.5,214);
    glVertex2f(547.5,214);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(538,179);   // tree  tri 5....//
    glVertex2f(557,179);
    glVertex2f(547.5,224);
    glVertex2f(547.5,224);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(540.5,189);  // tree  tri 6....//
    glVertex2f(554.5,187);
    glVertex2f(547.5,237);
    glVertex2f(549.5,239);
    glEnd();
    glPopMatrix();
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1,-1, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
/// Big tree......left side of 1st building......//
    glColor3ub(139, 146, 22);
    circle(8,22,0,150);
    glColor3ub(139, 146, 22);
    circle(8,22,10,170);
    glColor3ub(139, 146, 22);
    circle(8,22,13,140);
    glColor3ub(139, 146, 22);
    circle(7,25,22,150);
    glColor3ub(139, 146, 22);
    circle(8,22,30,150);
    glColor3ub(139, 146, 22);
    circle(10,40,0,250);
    glColor3ub(139, 146, 22);
    circle(9,22,30,295);
    glColor3ub(139, 146, 22);
    circle(8,15,30,293);
    glColor3ub(139, 146, 22);
    circle(9,22,45,285);
    glColor3ub(139, 146, 22);
    circle(9,22,45,280);
    glColor3ub(139, 146, 22);
    circle(8,15,45,275);
    glColor3ub(139, 146, 22);
    circle(9,22,55,235);
    glColor3ub(139, 146, 22);
    circle(9,32,50,255);
    glColor3ub(139, 146, 22);
    circle(9,22,59,225);
    glColor3ub(139, 146, 22);
    circle(9,22,56,255);
    glColor3ub(139, 146, 22);
    circle(9,22,63,195);
    glColor3ub(139, 146, 22);
    circle(9,22,50,180);
    glColor3ub(139, 146, 22);
    circle(9,22,58,165);
    glColor3ub(139, 146, 22);
    circle(9,22,49,150);
    glColor3ub(139, 146, 22);
    circle(9,22,38,140);
    glColor3ub(0, 77, 26);
    circle(10,20,55,190);
    glColor3ub(139, 146, 22);
    circle(9.5,19,55,190);
    glColor3ub(0, 77, 26);
    circle(10,20,55,205);
    glColor3ub(139, 146, 22);
    circle(9.5,20,55,205);
    glColor3ub(0, 77, 26);
    circle(10,20,50,218);
    glColor3ub(139, 146, 22);
    circle(9.5,20,50,218);
    glColor3ub(139, 146, 22);
    circle(10,20,27,130);
    glColor3ub(139, 146, 22);
    circle(35,70,20,200);
    glColor3ub(139, 146, 22);
    circle(15,30,30,255);
    glColor3ub(0, 77, 26);
    circle(10,20,42,225);
    glColor3ub(139, 146, 22);
    circle(9.5,20,42,224);
    glColor3ub(0, 77, 26);
    circle(10,20,30,225);
    glColor3ub(139, 146, 22);
    circle(10,20,30,224);
    glColor3ub(0, 77, 26);
    circle(10,18,42,263);
    glColor3ub(139, 146, 22);
    circle(10,18,42,262);
    glColor3ub(0, 77, 26);
    circle(10,20,30,180);
    glColor3ub(139, 146, 22);
    circle(10,20,30,179);
    glColor3ub(0, 77, 26);
    circle(10,20,20,180);
    glColor3ub(139, 146, 22);
    circle(10,20,20,179);
    glColor3ub(0, 77, 26);
    circle(10,20,40,155);
    glColor3ub(139, 146, 22);
    circle(10,20,40,156);
    glColor3ub(139, 146, 22);
    circle(9,22,20,280);
    glColor3ub(0, 77, 26);
    circle(9,21,20,270);
    glColor3ub(139, 146, 22);
    circle(9,21,20,269);
    glColor3ub(139, 146, 22);
    circle(9,22,10,255);
    glColor3ub(0, 77, 26);
    circle(9,20,10,245);
    glColor3ub(139, 146, 22);
    circle(9,20,10.5,244);



    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);  // tree stem 1....//
    glVertex2f(15,90);
    glVertex2f(22,90);
    glVertex2f(21,100);
    glVertex2f(20,110);
    glVertex2f(18,120);
    glVertex2f(16,130);
    glVertex2f(17,140);
    glVertex2f(18,145);
    glVertex2f(20,150);
    glVertex2f(22,150);
    glVertex2f(21,147);
    glVertex2f(20,145);
    glVertex2f(18,140);
    glVertex2f(16,130);
    glVertex2f(13,120);
    glVertex2f(16,130);
    glVertex2f(18,140);
    glVertex2f(20,145);
    glVertex2f(22,150);
    glVertex2f(22,160);
    glVertex2f(18,150);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  // tree stem 2....//
    glColor3ub(75,35,5);
    glVertex2f(15,125);
    glVertex2f(19,130);
    glVertex2f(14,140);
    glVertex2f(14,150);
    glVertex2f(13,160);
    glVertex2f(10,170);
    glVertex2f(12,170);
    glVertex2f(12,160);
    glVertex2f(11,150);
    glVertex2f(11,140);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  // tree stem 3....//
    glColor3ub(75,35,5);
    glVertex2f(31,140);
    glVertex2f(29,140);
    glVertex2f(28,120);
    glVertex2f(25,120);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);  // tree stem 4....//
    glColor3ub(75,35,5);
    glVertex2f(16,100);
    glVertex2f(21,100);
    glVertex2f(24.5,120);
    glVertex2f(28,120);
    glEnd();
///End  Big tree........
    glPopMatrix();
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1,-1, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
///christmas tree.........beside 5th Building........1st tree   ///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139,99,47);  // tree stem....
    glVertex2f(650,90);
    glVertex2f(655,90);
    glVertex2f(655,110);
    glVertex2f(650,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 1....//
    glVertex2f(640,110);
    glVertex2f(665,110);
    glVertex2f(652.5,140);
    glVertex2f(652.5,140);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 2....//
    glVertex2f(641,120);
    glVertex2f(664,120);
    glVertex2f(652.5,160);
    glVertex2f(652.5,160);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 3....//
    glVertex2f(642,130);
    glVertex2f(663,130);
    glVertex2f(652.5,180);
    glVertex2f(652.5,180);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 4....//
    glVertex2f(642.5,140);
    glVertex2f(662.5,140);
    glVertex2f(652.5,185);
    glVertex2f(652.5,185);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 5....//
    glVertex2f(643,150);
    glVertex2f(662,150);
    glVertex2f(652.5,195);
    glVertex2f(652.5,195);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 6....//
    glVertex2f(643.5,160);
    glVertex2f(661.5,160);
    glVertex2f(652.5,210);
    glVertex2f(652.5,210);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 7....//
    glVertex2f(644,170);
    glVertex2f(661,170);
    glVertex2f(652.5,230);
    glVertex2f(652.5,230);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 8....//
    glVertex2f(644.5,180);
    glVertex2f(660.5,180);
    glVertex2f(652.5,250);
    glVertex2f(652.5,250);
    glEnd();

///christmas tree.........beside 5th Building........2nd tree....///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139,99,47);   // tree stem....
    glVertex2f(670,90);
    glVertex2f(675,90);
    glVertex2f(675,120);
    glVertex2f(670,120);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);     // tree  tri 1....//
    glVertex2f(660,120);
    glVertex2f(685,120);
    glVertex2f(672.5,180);
    glVertex2f(672.5,180);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);   // tree  tri 2....//
    glVertex2f(661,135);
    glVertex2f(684,135);
    glVertex2f(672.5,190);
    glVertex2f(672.5,190);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 3....//
    glVertex2f(662,150);
    glVertex2f(683,150);
    glVertex2f(672.5,180);
    glVertex2f(672.5,180);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 4....//
    glVertex2f(663,160);
    glVertex2f(682,160);
    glVertex2f(672.5,190);
    glVertex2f(672.5,190);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 5....//
    glVertex2f(664,170);
    glVertex2f(681,170);
    glVertex2f(672.5,200);
    glVertex2f(672.5,200);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 6....//
    glVertex2f(665,180);
    glVertex2f(680,180);
    glVertex2f(672.5,210);
    glVertex2f(672.5,210);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 7....//
    glVertex2f(666,190);
    glVertex2f(679,190);
    glVertex2f(672.5,260);
    glVertex2f(672.5,260);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 8....//
    glVertex2f(666,200);
    glVertex2f(679,200);
    glVertex2f(672.5,270);
    glVertex2f(672.5,270);
    glEnd();

    glPopMatrix();
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1,-1, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);

///christmas tree.........beside 5th Building........3rd tree.....///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139,99,47);
    glVertex2f(680,90);   // tree stem....
    glVertex2f(685,90);
    glVertex2f(685,100);
    glVertex2f(680,100);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102,0);  // tree  tri 1....//
    glVertex2f(675,100);
    glVertex2f(690,100);
    glVertex2f(682.5,130);
    glVertex2f(682.5,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102,0);  // tree  tri 2....//
    glVertex2f(676,110);
    glVertex2f(689,110);
    glVertex2f(682.5,140);
    glVertex2f(682.5,140);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102,0);  // tree  tri 3....//
    glVertex2f(677,122);
    glVertex2f(688,122);
    glVertex2f(682.5,155);
    glVertex2f(682.5,155);
    glEnd();

///christmas tree.........beside 5th Building........4th tree.....///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139,99,47);  // tree stem....
    glVertex2f(690,90);
    glVertex2f(695,90);
    glVertex2f(695,105);
    glVertex2f(690,105);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,99,47);  // tree  tri 1....//
    glVertex2f(685,105);
    glVertex2f(700,105);
    glVertex2f(692.5,135);
    glVertex2f(692.5,135);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102,0); // tree  tri 2....//
    glVertex2f(686,115);
    glVertex2f(699,115);
    glVertex2f(692.5,145);
    glVertex2f(692.5,145);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102,0);  // tree  tri 3....//
    glVertex2f(687,127);
    glVertex2f(698,127);
    glVertex2f(692.5,165);
    glVertex2f(692.5,165);
    glEnd();


///....Middle circle tree of 4th & 5th building... ///
    glColor3ub(0, 153, 51);
    circle(3,6,575,100);   //tree
    glColor3ub(0, 153, 51);
    circle(5,12,570,110);
    glColor3ub(0, 153, 51);
    circle(5,12,580,110);
    glColor3ub(0, 153, 51);
    circle(5,12,585,105);
    glColor3ub(0, 153, 51);
    circle(5,12,565,120);
    glColor3ub(0, 102, 00);
    circle(5,12,570,122);
    glColor3ub(0, 153, 51);
    circle(5,12,571,122);
    glColor3ub(0, 153, 51);
    circle(5,12,575,140);
    glColor3ub(0, 153, 51);
    circle(4,10,570,135);
    glColor3ub(0, 102,0);
    circle(4,10,572,133);
    glColor3ub(0, 153, 51);
    circle(4,10,573,132);
    glColor3ub(0, 153, 51);
    circle(5,12,585,130);
    glColor3ub(0, 153, 51);
    circle(5,12,580,130);
    glColor3ub(0, 102,0);
    circle(5,12,579,125);
    glColor3ub(0, 153, 51);
    circle(5,12,578,124);
    glColor3ub(0, 153, 51);
    circle(5,12,590,120);
    glColor3ub(0, 102,0);
    circle(5,12,585,115);
    glColor3ub(0, 153, 51);
    circle(5,12,584,115);
    glColor3ub(0, 153, 51);
    circle(5,12,575,118);
    glColor3ub(0, 153, 51);
    circle(5,12,587,140);


    glColor3ub(255, 255, 255);  //white flower
    circle(1,2,575,118);
    glColor3ub(255, 255, 255);
    circle(1,2,575,138);
    glColor3ub(255, 255, 255);
    circle(1,2,585,138);
    glColor3ub(255, 255, 255);
    circle(1,2,580,127);
    glColor3ub(255, 255, 255);
    circle(1,2,564,118);
    glColor3ub(255, 255, 255);
    circle(1,2.5,570,133);
    glColor3ub(255, 255, 255);
    circle(1,1.5,571,109);
    glColor3ub(255, 255, 255);
    circle(1,2.5,585,105);
    glColor3ub(255, 255, 255);
    circle(1,3,590,118);
    glColor3ub(255, 255, 255);
    circle(1,3,585,120);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);  //tree stem 1
    glVertex2f(580,90);
    glVertex2f(583,90);
    glVertex2f(582,100);
    glVertex2f(577,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);  //tree stem 2
    glVertex2f(580,90);
    glVertex2f(583,90);
    glVertex2f(579,100);
    glVertex2f(573,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);  //tree stem 3
    glVertex2f(579,90);
    glVertex2f(583,90);
    glVertex2f(584,110);
    glVertex2f(587,140);
    glEnd();
    glPopMatrix();

}


void tree1()
{
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1.2,-1.2, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
///....Right side circle tree in Food court... ///
    glColor3ub(139, 146, 22);
    circle(3,6,468,101);
    glColor3ub(139, 146, 22);
    circle(5,12,463,111);
    glColor3ub(139, 146, 22);
    circle(5,12,473,111);
    glColor3ub(139, 146, 22);
    circle(5,12,478,106);
    glColor3ub(139, 146, 22);
    circle(5,12,458,121);
    glColor3ub(181, 106, 76);
    circle(5,12,463,123);
    glColor3ub(139, 146, 22);
    circle(5,12,464,123);
    glColor3ub(139, 146, 22);
    circle(5,12,468,141);
    glColor3ub(139, 146, 22);
    circle(4,10,463,136);
    glColor3ub(181, 106, 76);
    circle(4,10,465,134);
    glColor3ub(139, 146, 22);
    circle(4,10,466,133);
    glColor3ub(139, 146, 22);
    circle(5,12,478,131);
    glColor3ub(139, 146, 22);
    circle(5,12,473,131);
    glColor3ub(181, 106, 76);
    circle(5,12,472,126);
    glColor3ub(139, 146, 22);
    circle(5,12,471,125);
    glColor3ub(139, 146, 22);
    circle(5,12,483,121);
    glColor3ub(181, 106, 76);
    circle(5,12,478,116);
    glColor3ub(139, 146, 22);
    circle(5,12,477,116);
    glColor3ub(139, 146, 22);
    circle(5,12,468,119);
    glColor3ub(139, 146, 22);
    circle(5,12,480,141);
    glColor3ub(227, 91, 137);
    circle(1,2,468,119);
    glColor3ub(227, 91, 137);
    circle(1,2,468,133);
    glColor3ub(227, 91, 137);
    circle(1,2,478,133);
    glColor3ub(227, 91, 137);
    circle(1,2,483,128);
    glColor3ub(227, 91, 137);
    circle(1,2,457,119);
    glColor3ub(227, 91, 137);
    circle(1,2.5,463,134);
    glColor3ub(227, 91, 137);
    circle(1,1.5,464,110);
    glColor3ub(227, 91, 137);
    circle(1,2.5,478,106);


    glBegin(GL_TRIANGLE_FAN);  // tree stem 1....//
    glColor3ub(75, 35, 5);
    glVertex2f(473,90);
    glVertex2f(476,90);
    glVertex2f(475,100);
    glVertex2f(470,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  // tree stem 2....//
    glColor3ub(75, 35, 5);
    glVertex2f(473,90);
    glVertex2f(476,90);
    glVertex2f(472,100);
    glVertex2f(466,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  // tree stem 3....//
    glColor3ub(75, 35, 5);
    glVertex2f(472,90);
    glVertex2f(476,90);
    glVertex2f(477,110);
    glVertex2f(480,140);
    glEnd();
    glPopMatrix();


    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-0.6,-1.2, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
///....Right side circle tree in Food court... ///
    glColor3ub(139, 146, 22);
    circle(3,6,468,101);
    glColor3ub(139, 146, 22);
    circle(5,12,463,111);
    glColor3ub(139, 146, 22);
    circle(5,12,473,111);
    glColor3ub(139, 146, 22);
    circle(5,12,478,106);
    glColor3ub(139, 146, 22);
    circle(5,12,458,121);
    glColor3ub(181, 106, 76);
    circle(5,12,463,123);
    glColor3ub(139, 146, 22);
    circle(5,12,464,123);
    glColor3ub(139, 146, 22);
    circle(5,12,468,141);
    glColor3ub(139, 146, 22);
    circle(4,10,463,136);
    glColor3ub(181, 106, 76);
    circle(4,10,465,134);
    glColor3ub(139, 146, 22);
    circle(4,10,466,133);
    glColor3ub(139, 146, 22);
    circle(5,12,478,131);
    glColor3ub(139, 146, 22);
    circle(5,12,473,131);
    glColor3ub(181, 106, 76);
    circle(5,12,472,126);
    glColor3ub(139, 146, 22);
    circle(5,12,471,125);
    glColor3ub(139, 146, 22);
    circle(5,12,483,121);
    glColor3ub(181, 106, 76);
    circle(5,12,478,116);
    glColor3ub(139, 146, 22);
    circle(5,12,477,116);
    glColor3ub(139, 146, 22);
    circle(5,12,468,119);
    glColor3ub(139, 146, 22);
    circle(5,12,480,141);
    glColor3ub(227, 91, 137);
    circle(1,2,468,119);
    glColor3ub(227, 91, 137);
    circle(1,2,468,133);
    glColor3ub(227, 91, 137);
    circle(1,2,478,133);
    glColor3ub(227, 91, 137);
    circle(1,2,483,128);
    glColor3ub(227, 91, 137);
    circle(1,2,457,119);
    glColor3ub(227, 91, 137);
    circle(1,2.5,463,134);
    glColor3ub(227, 91, 137);
    circle(1,1.5,464,110);
    glColor3ub(227, 91, 137);
    circle(1,2.5,478,106);


    glBegin(GL_TRIANGLE_FAN);  // tree stem 1....//
    glColor3ub(75, 35, 5);
    glVertex2f(473,90);
    glVertex2f(476,90);
    glVertex2f(475,100);
    glVertex2f(470,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);  // tree stem 2....//
    glColor3ub(75, 35, 5);
    glVertex2f(473,90);
    glVertex2f(476,90);
    glVertex2f(472,100);
    glVertex2f(466,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);  // tree stem 3....//
    glColor3ub(75, 35, 5);
    glVertex2f(472,90);
    glVertex2f(476,90);
    glVertex2f(477,110);
    glVertex2f(480,140);
    glEnd();
    glPopMatrix();



    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-2.2,-1.2, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
    ///....Middle circle tree of 4th & 5th building... ///
    glColor3ub(0, 153, 51);
    circle(3,6,575,100);   //tree
    glColor3ub(0, 153, 51);
    circle(5,12,570,110);
    glColor3ub(0, 153, 51);
    circle(5,12,580,110);
    glColor3ub(0, 153, 51);
    circle(5,12,585,105);
    glColor3ub(0, 153, 51);
    circle(5,12,565,120);
    glColor3ub(0, 102, 00);
    circle(5,12,570,122);
    glColor3ub(0, 153, 51);
    circle(5,12,571,122);
    glColor3ub(0, 153, 51);
    circle(5,12,575,140);
    glColor3ub(0, 153, 51);
    circle(4,10,570,135);
    glColor3ub(0, 102,0);
    circle(4,10,572,133);
    glColor3ub(0, 153, 51);
    circle(4,10,573,132);
    glColor3ub(0, 153, 51);
    circle(5,12,585,130);
    glColor3ub(0, 153, 51);
    circle(5,12,580,130);
    glColor3ub(0, 102,0);
    circle(5,12,579,125);
    glColor3ub(0, 153, 51);
    circle(5,12,578,124);
    glColor3ub(0, 153, 51);
    circle(5,12,590,120);
    glColor3ub(0, 102,0);
    circle(5,12,585,115);
    glColor3ub(0, 153, 51);
    circle(5,12,584,115);
    glColor3ub(0, 153, 51);
    circle(5,12,575,118);
    glColor3ub(0, 153, 51);
    circle(5,12,587,140);


    glColor3ub(255, 255, 255);  //white flower
    circle(1,2,575,118);
    glColor3ub(255, 255, 255);
    circle(1,2,575,138);
    glColor3ub(255, 255, 255);
    circle(1,2,585,138);
    glColor3ub(255, 255, 255);
    circle(1,2,580,127);
    glColor3ub(255, 255, 255);
    circle(1,2,564,118);
    glColor3ub(255, 255, 255);
    circle(1,2.5,570,133);
    glColor3ub(255, 255, 255);
    circle(1,1.5,571,109);
    glColor3ub(255, 255, 255);
    circle(1,2.5,585,105);
    glColor3ub(255, 255, 255);
    circle(1,3,590,118);
    glColor3ub(255, 255, 255);
    circle(1,3,585,120);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);  //tree stem 1
    glVertex2f(580,90);
    glVertex2f(583,90);
    glVertex2f(582,100);
    glVertex2f(577,130);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);  //tree stem 2
    glVertex2f(580,90);
    glVertex2f(583,90);
    glVertex2f(579,100);
    glVertex2f(573,110);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);  //tree stem 3
    glVertex2f(579,90);
    glVertex2f(583,90);
    glVertex2f(584,110);
    glVertex2f(587,140);
    glEnd();
    glPopMatrix();

}


void megh()
{
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1,-1, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
///....Megh.......1 covering sun....///
    glColor3ub(232,241,255);
    circle(13,20,p+400,665);
    glColor3ub(252,254,255);
    circle(11,18,p+400,665);

    glColor3ub(232,241,255);
    circle(10,20,p+410,675);
    glColor3ub(252,254,255);
    circle(10,20,p+412,672);

    glColor3ub(232,241,255);
    circle(13,20,p+410,655);

    glColor3ub(221,229,247);
    circle(9,20,p+420,680);
    glColor3ub(252,254,255);
    circle(8,18,p+420,679);

    glColor3ub(232,241,255);
    circle(9,20,p+420,650);
    glColor3ub(252,254,255);
    circle(8,18,p+420,652);

    glColor3ub(221,229,247);
    circle(9,20,p+430,685);
    glColor3ub(252,254,255);
    circle(8,18,p+430,683);

    glColor3ub(232,241,255);
    circle(9,20,p+425,655);
    glColor3ub(252,254,255);
    circle(8,18,p+435,657);

    glColor3ub(232,241,255);
    circle(9,20,p+440,675);

    glColor3ub(221,229,247);
    circle(8,18,p+445,665);
    glColor3ub(252,254,255);
    circle(8,18,p+443,663);
    glColor3ub(252,254,255);
    circle(18,18,p+420,664);
    glColor3ub(252,254,255);
    circle(18,25,p+417,665);

///....Megh.......2.....///
    glColor3ub(232,241,255);
    circle(13,20,p+200,745);
    glColor3ub(252,254,255);
    circle(11,18,p+200,745);

    glColor3ub(232,241,255);
    circle(10,20,p+210,755);
    glColor3ub(252,254,255);
    circle(10,20,p+212,762);

    glColor3ub(232,241,255);
    circle(13,20,p+210,735);

    glColor3ub(221,229,247);
    circle(9,20,p+220,750);
    glColor3ub(252,254,255);
    circle(8,18,p+220,759);

    glColor3ub(232,241,255);
    circle(9,20,p+220,756);
    glColor3ub(252,254,255);
    circle(8,18,p+220,752);

    glColor3ub(232,241,255);
    circle(9,20,p+230,765);
    glColor3ub(252,254,255);
    circle(8,18,p+230,761);

    glColor3ub(232,241,255);
    circle(9,20,p+225,745);
    glColor3ub(252,254,255);
    circle(8,18,p+235,747);

    glColor3ub(232,241,255);
    circle(9,20,p+240,755);

    glColor3ub(221,229,247);
    circle(8,18,p+243,745);
    glColor3ub(252,254,255);
    circle(8,18,p+240,743);
    glColor3ub(173,197,224);
    circle(8,18,p+230,733);
    glColor3ub(252,254,255);
    circle(8,18,p+230,738);
    glColor3ub(173,197,224);
    circle(8,18,p+220,723);
    glColor3ub(252,254,255);
    circle(8,18,p+220,728);

    glColor3ub(252,254,255);
    circle(18,18,p+210,744);
    glColor3ub(252,254,255);
    circle(18,25,p+220,745);

    glColor3ub(173,197,224);
    circle(10,20,p+235,715);
    glColor3ub(252,254,255);
    circle(10,20,p+235,719);


///....Megh.......3.....///
    glColor3ub(173,197,224);
    circle(9,15,p+20,685);
    glColor3ub(252,254,255);
    circle(6,14,p+21,685);

    glColor3ub(232,241,255);
    circle(7,16,p+30,695);
    glColor3ub(252,254,255);
    circle(7,14,p+32,692);

    glColor3ub(252,254,255);
    circle(12,16,p+28,680);

    glColor3ub(221,229,247);
    circle(10,15,p+45,690);
    glColor3ub(252,254,255);
    circle(9,13,p+43,685);
    glColor3ub(252,254,255);
    circle(15,18,p+48,670);

    glColor3ub(173,197,224);
    circle(6,14,p+30,680);
    glColor3ub(252,254,255);
    circle(6,13,p+30,677);

    glColor3ub(173,197,224);
    circle(6,14,p+38,668);
    glColor3ub(252,254,255);
    circle(6,13,p+36,667);


    glColor3ub(252,254,255);
    circle(11,15,p+29,668);

///....Megh.......4.....///

    glColor3ub(173,197,224);
    circle(9,15,p+590,695);
    glColor3ub(252,254,255);
    circle(6,14,p+591,695);

    glColor3ub(232,241,255);
    circle(7,16,p+600,705);
    glColor3ub(252,254,255);
    circle(7,14,p+602,702);

    glColor3ub(252,254,255);
    circle(12,16,p+598,690);

    glColor3ub(221,229,247);
    circle(10,15,p+615,700);
    glColor3ub(252,254,255);
    circle(9,13,p+613,695);
    glColor3ub(252,254,255);
    circle(15,18,p+618,680);

    glColor3ub(173,197,224);
    circle(6,14,p+600,690);
    glColor3ub(252,254,255);
    circle(6,13,p+600,687);

    glColor3ub(173,197,224);
    circle(6,14,p+608,678);
    glColor3ub(252,254,255);
    circle(6,13,p+606,677);


    glColor3ub(252,254,255);
    circle(11,15,p+599,678);

    if(p<= 800)
        p = p + 0.1;
    else
        p = -10;
    glPopMatrix();
}

void bus()
{
///..........B U S...........1
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1,-1, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
    if(j<= 800)
        j = j + 0.4;
    else
        j = -250;

    glBegin(GL_QUADS);
    glColor3ub(255, 81, 76);
    glVertex2f(j+90,98);  //bus...................
    glVertex2f(j+95,98);
    glVertex2f(j+95,100);
    glVertex2f(j+90,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(26, 26,0);
    glVertex2f(j+94,89);   // bus font glass
    glVertex2f(j+96,89);
    glVertex2f(j+96,100);
    glVertex2f(j+94,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 81, 76);
    glVertex2f(j+10,80);  //.....bus
    glVertex2f(j+90,80);
    glVertex2f(j+90,105);
    glVertex2f(j+10,105);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 81, 76);
    glVertex2f(j+10,55);  //top..........lowerpart
    glVertex2f(j+92,55);
    glVertex2f(j+92,80);
    glVertex2f(j+10,80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 51,0);
    glVertex2f(j+11,81);  //top..........
    glVertex2f(j+89,81);
    glVertex2f(j+89,102);
    glVertex2f(j+11,102);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(j+12,85);  //window..........
    glVertex2f(j+20,85);
    glVertex2f(j+20,100);
    glVertex2f(j+12,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(j+22,85);  //window..........
    glVertex2f(j+30,85);
    glVertex2f(j+30,100);
    glVertex2f(j+22,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(j+32,85);  //window..........
    glVertex2f(j+40,85);
    glVertex2f(j+40,100);
    glVertex2f(j+32,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(j+42,85);  //window..........
    glVertex2f(j+50,85);
    glVertex2f(j+50,100);
    glVertex2f(j+42,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(j+52,85);  //window..........
    glVertex2f(j+60,85);
    glVertex2f(j+60,100);
    glVertex2f(j+52,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 247, 255);
    glVertex2f(j+62,55);  //..door..........
    glVertex2f(j+70,55);
    glVertex2f(j+70,95);
    glVertex2f(j+62,95);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(j+72,85);  //window..........
    glVertex2f(j+80,85);
    glVertex2f(j+80,100);
    glVertex2f(j+72,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(j+82,85);  //window..........
    glVertex2f(j+88,85);
    glVertex2f(j+88,100);
    glVertex2f(j+82,100);
    glEnd();

    glColor3ub(255, 255, 204);          //....chaka....back
    circle(4,8,j+45,65);
    glColor3ub(255, 255, 204);
    circle(2,4,j+55,75);
    glColor3ub(255, 255, 204);
    circle(3,6,j+15,75);
    glColor3ub(255, 255, 204);
    circle(2,4,j+35,65);
    glColor3ub(255, 255, 204);
    circle(2,4,j+75,75);


    glColor3ub(0,0,0);          //....chaka....back
    circle(5,10,j+25,55);
    glColor3ub(255,255,255);
    circle(3,6,j+25,55);

    glColor3ub(0,0,0);
    circle(5,10,j+78,55);
    glColor3ub(255,255,255);
    circle(3,6,j+78,55);


    ///..........B U S...........2

    if(k<= 800)
        k = k + 0.4;
    else
        k = -100;

    glBegin(GL_QUADS);
    glColor3ub(43, 58, 139);
    glVertex2f(k+90,98);  //bus...................
    glVertex2f(k+95,98);
    glVertex2f(k+95,100);
    glVertex2f(k+90,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(26, 26,0);
    glVertex2f(k+94,89);   // bus font glass
    glVertex2f(k+96,89);
    glVertex2f(k+96,100);
    glVertex2f(k+94,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(43, 58, 139);
    glVertex2f(k+10,80);  //.....bus
    glVertex2f(k+90,80);
    glVertex2f(k+90,105);
    glVertex2f(k+10,105);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(43, 58, 139);
    glVertex2f(k+10,55);  //top..........lowerpart
    glVertex2f(k+92,55);
    glVertex2f(k+92,80);
    glVertex2f(k+10,80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 51,0);
    glVertex2f(k+11,81);  //top..........
    glVertex2f(k+89,81);
    glVertex2f(k+89,102);
    glVertex2f(k+11,102);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(k+12,85);  //window..........
    glVertex2f(k+20,85);
    glVertex2f(k+20,100);
    glVertex2f(k+12,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(k+22,85);  //window..........
    glVertex2f(k+30,85);
    glVertex2f(k+30,100);
    glVertex2f(k+22,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(k+32,85);  //window..........
    glVertex2f(k+40,85);
    glVertex2f(k+40,100);
    glVertex2f(k+32,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(k+42,85);  //window..........
    glVertex2f(k+50,85);
    glVertex2f(k+50,100);
    glVertex2f(k+42,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(k+52,85);  //window..........
    glVertex2f(k+60,85);
    glVertex2f(k+60,100);
    glVertex2f(k+52,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 247, 255);
    glVertex2f(k+62,55);  //..door..........
    glVertex2f(k+70,55);
    glVertex2f(k+70,95);
    glVertex2f(k+62,95);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(k+72,85);  //window..........
    glVertex2f(k+80,85);
    glVertex2f(k+80,100);
    glVertex2f(k+72,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(k+82,85);  //window..........
    glVertex2f(k+88,85);
    glVertex2f(k+88,100);
    glVertex2f(k+82,100);
    glEnd();

    glColor3ub(255, 255, 204);          //....chaka....back
    circle(4,8,k+45,65);
    glColor3ub(255, 255, 204);
    circle(2,4,k+55,75);
    glColor3ub(255, 255, 204);
    circle(3,6,k+15,75);
    glColor3ub(255, 255, 204);
    circle(2,4,k+35,65);
    glColor3ub(255, 255, 204);
    circle(2,4,k+75,75);


    glColor3ub(0,0,0);          //....chaka....back
    circle(5,10,k+25,55);
    glColor3ub(255,255,255);
    circle(3,6,k+25,55);

    glColor3ub(0,0,0);
    circle(5,10,k+78,55);
    glColor3ub(255,255,255);
    circle(3,6,k+78,55);
    glPopMatrix();
}



void town ()
{
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-1,-1, 0);
    glScalef(1.0 / 350.0, 1.0 / 400.0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);   ///background sky....
    glColor3ub(255, 255, 147);
    glVertex2f(0,100);
    glVertex2f(800,100);
    glColor3ub(102, 204, 255);
    glVertex2f(800,800);
    glVertex2f(0,800);
    glEnd();


///Road..........///
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex2f(0,30);
    glVertex2f(800,30);
    glVertex2f(800,80);
    glVertex2f(0,80);
    glEnd();
///road white line........///
    glBegin(GL_LINES);//Road upper white line..
    glLineWidth(2);
    glColor3f(1.0,1.0,1.0);
    glVertex2i(0,81);
    glVertex2i(800,81);
    glEnd();

    glBegin(GL_LINES);//Road middle white line..
    glLineWidth(2);
    glColor3f(1.0,1.0,1.0);
    glVertex2i(0,62);
    glVertex2i(800,62);
    glEnd();

    glBegin(GL_LINES);//Road lower white line..
    glLineWidth(2);
    glColor3f(1.0,1.0,1.0);
    glVertex2i(0,39);
    glVertex2i(800,39);
    glEnd();

    glBegin(GL_QUADS);  ///upper roadside green......
    glColor3ub(90, 147, 48);
    glVertex2f(0,82);
    glVertex2f(800,82);
    glVertex2f(800,90);
    glVertex2f(0,90);
    glEnd();

    glBegin(GL_QUADS); ///lower roadside green......
    glColor3ub(90, 147, 48);
    glVertex2f(0,38);
    glVertex2f(800,38);
    glVertex2f(800,0);
    glVertex2f(0,0);
    glEnd();


    glBegin(GL_QUADS);   ///2nd building front green area
    glColor3ub(90,147,48);
    glVertex2f(0,100);
    glVertex2f(800,100);
    glVertex2f(800,119.5);
    glVertex2f(0,119.5);
    glEnd();


///...............1st building..............///


    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204); //...1st Building....part-1....left grey part-1
    glVertex2f(50,90);
    glVertex2f(110,90);
    glVertex2f(110,475);
    glVertex2f(50,475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242); //1st Building....part-1....left  white part
    glVertex2f(52.5,90);
    glVertex2f(106,90);
    glVertex2f(106,460);
    glVertex2f(52.5,460);
    glEnd();


/////////////****
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,90);  //1st Building 1st floor...part2
    glVertex2f(197,90);
    glVertex2f(197,145);
    glVertex2f(90,145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,145);   //1st Building 2nd floor...part2
    glVertex2f(197,145);
    glVertex2f(197,200);
    glVertex2f(90,200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,200);   //1st Building 3rd floor...part2
    glVertex2f(197,200);
    glVertex2f(197,255);
    glVertex2f(90,255);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,255);   //1st Building 4th floor...part2
    glVertex2f(197,255);
    glVertex2f(197,310);
    glVertex2f(90,310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,310);   //1st Building 5th floor...part2
    glVertex2f(197,310);
    glVertex2f(197,365);
    glVertex2f(90,365);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,365);   //1st Building 6th floor...part2
    glVertex2f(197,365);
    glVertex2f(197,420);
    glVertex2f(90,420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,420);   //1st Building 7th floor...part2
    glVertex2f(197,420);
    glVertex2f(197,475);
    glVertex2f(90,475);
    glEnd();


///siri ghor
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,475);
    glVertex2f(120,475);
    glVertex2f(120,515);
    glVertex2f(90,515);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(92,475);
    glVertex2f(118,475);
    glVertex2f(118,510);
    glVertex2f(92,510);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(100,475);
    glVertex2f(110,475);
    glVertex2f(110,505);
    glVertex2f(100,505);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(105,483);
    glVertex2f(106,483);
    glVertex2f(106,492);
    glVertex2f(105,492);
    glEnd();
///........................

/// 1st building roof tower
    glBegin(GL_QUADS);
    glColor3ub(140, 140, 140);
    glVertex2f(65,475);
    glVertex2f(66,475);
    glVertex2f(66,600);
    glVertex2f(65,600);
    glEnd();

    glColor3ub(102, 102, 102);
    circle(3,6,64,580);
    glColor3ub(217, 217, 217);
    circle(2.5,5,64,580);
    glColor3ub(102, 102, 102);
    circle(2,4,67,565);
    glColor3ub(217, 217, 217);
    circle(1.5,3,67,565);


    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(110,420);   //.... 1st Building....part2.... 7th floor white border
    glVertex2f(194,420);
    glVertex2f(194,460);
    glVertex2f(110,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,365);   //.... 1st Building....part2.... 6th floor white border
    glVertex2f(194,365);
    glVertex2f(194,405);
    glVertex2f(140,405);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,310);   //.... 1st Building....part2.... 5th floor white border
    glVertex2f(194,310);
    glVertex2f(194,350);
    glVertex2f(140,350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,255);   //.... 1st Building....part2.... 4th floor white border
    glVertex2f(194,255);
    glVertex2f(194,295);
    glVertex2f(140,295);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,200);   //.... 1st Building....part2.... 3rd floor white border
    glVertex2f(194,200);
    glVertex2f(194,240);
    glVertex2f(140,240);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,145);   //.... 1st Building....part2.... 2nd floor white border
    glVertex2f(194,145);
    glVertex2f(194,185);
    glVertex2f(140,185);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,90);  //.... 1st Building....part2.... 1st floor white border
    glVertex2f(194,90);
    glVertex2f(194,130);
    glVertex2f(140,130);
    glEnd();



///design of main building....red part and blue glass..............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,420);  //7 floor.... 1st Building....part1
    glVertex2f(67,420);
    glVertex2f(67,460);
    glVertex2f(52.5,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,365);  //6 floor.... 1st Building....part1
    glVertex2f(67,365);
    glVertex2f(67,405);
    glVertex2f(52.5,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,310);  //5 floor.... 1st Building....part1
    glVertex2f(67,310);
    glVertex2f(67,350);
    glVertex2f(52.5,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,255);  //4 floor.... 1st Building....part1
    glVertex2f(67,255);
    glVertex2f(67,295);
    glVertex2f(52.5,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,200);  //3 floor.... 1st Building....part1
    glVertex2f(67,200);
    glVertex2f(67,240);
    glVertex2f(52.5,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,145);  //2 floor.... 1st Building....part1
    glVertex2f(67,145);
    glVertex2f(67,185);
    glVertex2f(52.5,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,90);  //1 floor.... 1st Building....part1
    glVertex2f(67,90);
    glVertex2f(67,130);
    glVertex2f(52.5,130);
    glEnd();
    /////////.....................
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,420);  //7 floor.... 1st Building....part1
    glVertex2f(106,420);
    glVertex2f(106,460);
    glVertex2f(95,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,365);  //6 floor.... 1st Building....part1
    glVertex2f(106,365);
    glVertex2f(106,405);
    glVertex2f(95,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,310);  //5 floor.... 1st Building....part1
    glVertex2f(106,310);
    glVertex2f(106,350);
    glVertex2f(95,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,255);  //4 floor.... 1st Building....part1
    glVertex2f(106,255);
    glVertex2f(106,295);
    glVertex2f(95,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,200);  //3 floor.... 1st Building....part1
    glVertex2f(106,200);
    glVertex2f(106,240);
    glVertex2f(95,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,145);  //2 floor.... 1st Building....part1
    glVertex2f(106,145);
    glVertex2f(106,185);
    glVertex2f(95,185);
    glEnd();

///left door
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(85,90);  // blue part
    glVertex2f(106,90);
    glVertex2f(106,130);
    glVertex2f(85,130);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(95,90);  //black line
    glVertex2f(96,90);
    glVertex2f(96,130);
    glVertex2f(95,130);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(96,100);  //white line
    glVertex2f(97,100);
    glVertex2f(97,120);
    glVertex2f(96,120);
    glEnd();
    //////////............................
///left middle lower line
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,420);  //7 1st Building  part1
    glVertex2f(110,420);
    glVertex2f(110,421);
    glVertex2f(50,421);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,365);  //6 1st Building  part1
    glVertex2f(137.5,365);
    glVertex2f(137.5,366);
    glVertex2f(50,366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,310);  //5 1st Building  part1
    glVertex2f(110,310);
    glVertex2f(110,311);
    glVertex2f(50,311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,255);  //4 1st Building  part1
    glVertex2f(110,255);
    glVertex2f(110,256);
    glVertex2f(50,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,199);  //3 1st Building  part1
    glVertex2f(110,199);
    glVertex2f(110,200);
    glVertex2f(50,200);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,145);  //2 1st Building  part1
    glVertex2f(110,145);
    glVertex2f(110,146);
    glVertex2f(50,146);
    glEnd();

///left middle upper line
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,405);  //6 1st Building  part1
    glVertex2f(110,405);
    glVertex2f(110,406);
    glVertex2f(50,406);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,350);  //5 1st Building  part1
    glVertex2f(110,350);
    glVertex2f(110,351);
    glVertex2f(50,351);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,295);  //4 1st Building  part1
    glVertex2f(110,295);
    glVertex2f(110,296);
    glVertex2f(50,296);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,240);  //3  1st Building  part1
    glVertex2f(110,240);
    glVertex2f(110,241);
    glVertex2f(50,241);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,185);  //2 1st Building  part1
    glVertex2f(110,185);
    glVertex2f(110,186);
    glVertex2f(50,186);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,130);  //1 1st Building  part1
    glVertex2f(110,130);
    glVertex2f(110,131);
    glVertex2f(50,131);
    glEnd();
////////......................./////

///left big black line
    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(140,90);  // part2
    glVertex2f(141,90);
    glVertex2f(141,420);
    glVertex2f(140,420);
    glEnd();

///6th floor balcony
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(110,365);  //6 1st Building
    glVertex2f(120,365);
    glVertex2f(120,385);
    glVertex2f(110,385);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(128,365);  //6 1st Building
    glVertex2f(137.5,365);
    glVertex2f(137.5,385);
    glVertex2f(128,385);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(57,80,80);
    glVertex2f(120,370);  //6 1st Building
    glVertex2f(128,370);
    glVertex2f(128.5,372);
    glVertex2f(120,372);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(57,80,80);
    glVertex2f(120,379);  //6 1st Building
    glVertex2f(128,379);
    glVertex2f(128.5,381);
    glVertex2f(120,381);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(110,310);  //5 floor middle blue
    glVertex2f(137.5,310);
    glVertex2f(137.5,350);
    glVertex2f(110,350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(110,255);  //4 floor middle blue
    glVertex2f(137.5,255);
    glVertex2f(137.5,295);
    glVertex2f(110,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(110,200);  //3 floor middle blue
    glVertex2f(137.5,200);
    glVertex2f(137.5,240);
    glVertex2f(110,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(110,145);  //2 floor middle blue
    glVertex2f(137.5,145);
    glVertex2f(137.5,185);
    glVertex2f(110,185);
    glEnd();

///right door
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(110,90);  //1 1st Building
    glVertex2f(137.5,90);
    glVertex2f(137.5,130);
    glVertex2f(110,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(117,90);  //1 1st Building
    glVertex2f(118,90);
    glVertex2f(118,130);
    glVertex2f(117,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(127,90);  //1 1st Building
    glVertex2f(128,90);
    glVertex2f(128,130);
    glVertex2f(127,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(118,100);  //1 1st Building
    glVertex2f(119,100);
    glVertex2f(119,120);
    glVertex2f(118,120);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(128,100);  //1 1st Building
    glVertex2f(129,100);
    glVertex2f(129,120);
    glVertex2f(128,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(110,90);   //right black partation
    glVertex2f(111,90);
    glVertex2f(111,475);
    glVertex2f(110,475);
    glEnd();

    //..7th Floor design...................

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(113,425);   //part-1  1st Building 7th floor
    glVertex2f(191,425);
    glVertex2f(191,455);
    glVertex2f(113,455);
    glEnd();

///7th floor....door.....window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(113,420);   //d1 1st Building 7th floor
    glVertex2f(123,420);
    glVertex2f(123,455);
    glVertex2f(113,455);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(118,430);   //d1 1st Building 7th floor
    glVertex2f(119,430);
    glVertex2f(119,445);
    glVertex2f(118,445);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(133,432);   //w1 1st Building 7th floor
    glVertex2f(153,432);
    glVertex2f(153,448);
    glVertex2f(133,448);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(133.5,433);   //w1 1st Building 7th floor
    glVertex2f(152.5,433);
    glVertex2f(152.5,447);
    glVertex2f(133.5,447);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,432);   //w1 1st Building 7th floor
    glVertex2f(144,432);
    glVertex2f(144,448);
    glVertex2f(143,448);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,432);   //w2 1st Building 7th floor
    glVertex2f(183,432);
    glVertex2f(183,448);
    glVertex2f(163,448);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,433);   //w2 1st Building 7th floor
    glVertex2f(182.5,433);
    glVertex2f(182.5,447);
    glVertex2f(163.5,447);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,432);   //w2 1st Building 7th floor2
    glVertex2f(174,432);
    glVertex2f(174,448);
    glVertex2f(173,448);
    glEnd();


///....6th Floor Design..........Door window

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,370);   //part-1 1st Building 6th floor..........Inlook
    glVertex2f(191,370);
    glVertex2f(191,400);
    glVertex2f(141,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,377);   //w1 1st Building 6th floor
    glVertex2f(153,377);
    glVertex2f(153,393);
    glVertex2f(141,393);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,378);   //w1 1st Building 6th floor
    glVertex2f(152.5,378);
    glVertex2f(152.5,392);
    glVertex2f(141,392);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,377);   //w1 1st Building 6th floor
    glVertex2f(144,377);
    glVertex2f(144,393);
    glVertex2f(143,393);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,377);   //w2 1st Building 6th floor
    glVertex2f(183,377);
    glVertex2f(183,393);
    glVertex2f(163,393);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,378);   //w2 1st Building 6th floor
    glVertex2f(182.5,378);
    glVertex2f(182.5,392);
    glVertex2f(163.5,392);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,377);   //w2 1st Building 6th floor
    glVertex2f(174,377);
    glVertex2f(174,393);
    glVertex2f(173,393);
    glEnd();


    ///5th floor......design

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,315);   //part-1 1st Building 5th floor.........
    glVertex2f(191,315);
    glVertex2f(191,345);
    glVertex2f(141,345);
    glEnd();


    ///....door.....window


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,322);   //w1 1st Building 5th floor
    glVertex2f(153,322);
    glVertex2f(153,338);
    glVertex2f(141,338);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,323);   //w1 1st Building 5th floor
    glVertex2f(152.5,323);
    glVertex2f(152.5,337);
    glVertex2f(141,337);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,322);   //w1 1st Building 5th floor
    glVertex2f(144,322);
    glVertex2f(144,338);
    glVertex2f(143,338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,322);   //w2 1st Building 5th floor
    glVertex2f(183,322);
    glVertex2f(183,338);
    glVertex2f(163,338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,323);   //w2 1st Building 5th floor
    glVertex2f(182.5,323);
    glVertex2f(182.5,337);
    glVertex2f(163.5,337);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,322);   //w2 1st Building 5th floor
    glVertex2f(174,322);
    glVertex2f(174,338);
    glVertex2f(173,338);
    glEnd();


///....4TH floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,260);   //part-1 1st Building 5th floor.........
    glVertex2f(191,260);
    glVertex2f(191,290);
    glVertex2f(141,290);
    glEnd();

    //....door.....window

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,267);   //w1 1st Building 4th floor
    glVertex2f(153,267);
    glVertex2f(153,283);
    glVertex2f(141,283);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,268);   //w1 1st Building 4th floor
    glVertex2f(152.5,268);
    glVertex2f(152.5,282);
    glVertex2f(141,282);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,267);   //w1 1st Building 4th floor
    glVertex2f(144,267);
    glVertex2f(144,283);
    glVertex2f(143,283);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,267);   //w2 1st Building 4th floor
    glVertex2f(183,267);
    glVertex2f(183,283);
    glVertex2f(163,283);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,268);   //w2 1st Building 4th floor
    glVertex2f(182.5,268);
    glVertex2f(182.5,282);
    glVertex2f(163.5,282);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,267);   //w2 1st Building 4th floor
    glVertex2f(174,267);
    glVertex2f(174,283);
    glVertex2f(173,283);
    glEnd();


///....3TH floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,205);   //part-1 1st Building 3rd floor.........
    glVertex2f(191,205);
    glVertex2f(191,235);
    glVertex2f(141,235);
    glEnd();

    //....door.....window
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,212);   //w1 1st Building 3rd floor
    glVertex2f(153,212);
    glVertex2f(153,228);
    glVertex2f(141,228);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,213);   //w1 1st Building 3rd floor
    glVertex2f(152.5,213);
    glVertex2f(152.5,227);
    glVertex2f(141,227);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,212);   //w1 1st Building 3rd floor
    glVertex2f(144,212);
    glVertex2f(144,228);
    glVertex2f(143,228);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,212);   //w2 1st Building 3rd floor2
    glVertex2f(183,212);
    glVertex2f(183,228);
    glVertex2f(163,228);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,213);   //w2 1st Building 3rd floor
    glVertex2f(182.5,213);
    glVertex2f(182.5,227);
    glVertex2f(163.5,227);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,212);   //w2 1st Building 3rd floor
    glVertex2f(174,212);
    glVertex2f(174,228);
    glVertex2f(173,228);
    glEnd();


///....2nd floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,150);   //part-1 1st Building 2nd floor.........
    glVertex2f(191,150);
    glVertex2f(191,180);
    glVertex2f(141,180);
    glEnd();


    //....door.....window
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,157);   //w1 1st Building 2nd floor
    glVertex2f(153,157);
    glVertex2f(153,173);
    glVertex2f(141,173);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,158);   //w1 1st Building 2nd floor
    glVertex2f(152.5,158);
    glVertex2f(152.5,172);
    glVertex2f(141,172);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,157);   //w1 1st Building 2nd floor
    glVertex2f(144,157);
    glVertex2f(144,173);
    glVertex2f(143,173);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,157);   //w2 1st Building 2nd floor
    glVertex2f(183,157);
    glVertex2f(183,173);
    glVertex2f(163,173);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,158);   //w2 1st Building 2nd floor
    glVertex2f(182.5,158);
    glVertex2f(182.5,172);
    glVertex2f(163.5,172);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,157);   //w2 1st Building 2nd floor2
    glVertex2f(174,157);
    glVertex2f(174,173);
    glVertex2f(173,173);
    glEnd();

///....1st floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,95);   //part-1 1st Building 1st floor red.........
    glVertex2f(191,95);
    glVertex2f(191,125);
    glVertex2f(141,125);
    glEnd();


    //....door.....window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(196,90);   //d2 AB2 1st floor
    glVertex2f(206,90);
    glVertex2f(206,125);
    glVertex2f(196,125);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(201,100);   //d2 1st Building 1st floor
    glVertex2f(202,100);
    glVertex2f(202,115);
    glVertex2f(201,115);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,102);   //w1 1st Building 1st floor
    glVertex2f(153,102);
    glVertex2f(153,118);
    glVertex2f(141,118);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,103);   //w1 1st Building 1st floor
    glVertex2f(152.5,103);
    glVertex2f(152.5,117);
    glVertex2f(141,117);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,102);   //w1 1st Building 1st floor
    glVertex2f(144,102);
    glVertex2f(144,118);
    glVertex2f(143,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,102);   //w2 1st Building 1st floor
    glVertex2f(183,102);
    glVertex2f(183,118);
    glVertex2f(163,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,103);   //w2 1st Building 1st floor
    glVertex2f(182.5,103);
    glVertex2f(182.5,117);
    glVertex2f(163.5,117);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,102);   //w2 1st Building 1st floor
    glVertex2f(174,102);
    glVertex2f(174,118);
    glVertex2f(173,118);
    glEnd();

    glColor3ub(0, 51, 204);
    glRasterPos2i(133,465);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'N');
    glColor3ub(115, 115, 115);
    glRasterPos2i(139,465);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'&');
    glColor3ub(0, 51, 204);
    glRasterPos2i(143,465);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'M');

///...........End 1st building.....................///


///...............2nd building....................///
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(200,120);
    glVertex2f(287,120);
    glVertex2f(287,395);
    glVertex2f(200,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(202.5,120);        //2nd building main part 2
    glVertex2f(284,120);
    glVertex2f(284,380);
    glVertex2f(202.5,380);
    glEnd();

    ///....1st floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,125);   //part 2 2nd building 1st floor red.........
    glVertex2f(281,125);
    glVertex2f(281,155);
    glVertex2f(205,155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,125);   //part 2 2nd building 1st floor.......red
    glVertex2f(267,125);
    glVertex2f(267,155);
    glVertex2f(281,155);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,120);   //d2 2nd building 1st floor
    glVertex2f(215,120);
    glVertex2f(215,155);
    glVertex2f(205,155);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,132);   //d2 2nd building 1st floor
    glVertex2f(210,132);
    glVertex2f(210,147);
    glVertex2f(209,147);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,131);   //w1 2nd building 1st floor2
    glVertex2f(243,131);
    glVertex2f(243,147);
    glVertex2f(223,147);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,132);   //w1 2nd building 1st floor2
    glVertex2f(242.5,132);
    glVertex2f(242.5,146);
    glVertex2f(223.5,146);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,131);   //w1 2nd building 1st floor2
    glVertex2f(234,131);
    glVertex2f(234,147);
    glVertex2f(233.1,147);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,131);   //w2 2nd building 1st floor2
    glVertex2f(273,131);
    glVertex2f(273,147);
    glVertex2f(253,147);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,132);   //w2 2nd building 1st floor2
    glVertex2f(272.5,132);
    glVertex2f(272.5,146);
    glVertex2f(253.5,146);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,131);   //w2 2nd building 1st floor2
    glVertex2f(264,131);
    glVertex2f(264,147);
    glVertex2f(263.1,147);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,160);  //2nd building 1st floor1
    glVertex2f(284,160);
    glVertex2f(284,175);
    glVertex2f(202.5,175);
    glEnd();

    ///....2nd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,180);   //part 2 2nd building 2nd floor red.........
    glVertex2f(281,180);
    glVertex2f(281,210);
    glVertex2f(205,210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,180);   //part 2 2nd building 2nd floor.......red
    glVertex2f(264,180);
    glVertex2f(264,210);
    glVertex2f(281,210);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,175);   //d2 2nd building 2nd floor
    glVertex2f(215,175);
    glVertex2f(215,210);
    glVertex2f(205,210);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,187);   //d2 2nd building 2nd floor
    glVertex2f(210,187);
    glVertex2f(210,202);
    glVertex2f(209,202);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,186);   //w1 2nd building 2nd floor2
    glVertex2f(243,186);
    glVertex2f(243,202);
    glVertex2f(223,202);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,187);   //w1 2nd building 2nd floor2
    glVertex2f(242.5,187);
    glVertex2f(242.5,201);
    glVertex2f(223.5,201);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,186);   //w1 2nd building 2nd floor2
    glVertex2f(234,186);
    glVertex2f(234,202);
    glVertex2f(233.1,202);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,186);   //w2 2nd building 2nd floor2
    glVertex2f(273,186);
    glVertex2f(273,202);
    glVertex2f(253,202);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,187);   //w2 2nd building 2nd floor2
    glVertex2f(272.5,187);
    glVertex2f(272.5,201);
    glVertex2f(253.5,201);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,186);   //w2 2nd building 2nd floor2
    glVertex2f(264,186);
    glVertex2f(264,202);
    glVertex2f(263.1,202);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,215);  //2nd building 2nd floor1
    glVertex2f(284,215);
    glVertex2f(284,230);
    glVertex2f(202.5,230);
    glEnd();

    ///....3rd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,235);   //part 2 2nd building 3rd floor red.........
    glVertex2f(281,235);
    glVertex2f(281,265);
    glVertex2f(205,265);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,235);   //part 2 2nd building 3rd floor.......red
    glVertex2f(264,235);
    glVertex2f(264,265);
    glVertex2f(281,265);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,230);   //d2 2nd building 3rd floor
    glVertex2f(215,230);
    glVertex2f(215,265);
    glVertex2f(205,265);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,242);   //d2 2nd building 2nd floor
    glVertex2f(210,242);
    glVertex2f(210,257);
    glVertex2f(209,257);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,241);   //w1 2nd building 3rd floor2
    glVertex2f(243,241);
    glVertex2f(243,257);
    glVertex2f(223,257);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,242);   //w1 2nd building 2nd floor2
    glVertex2f(242.5,242);
    glVertex2f(242.5,256);
    glVertex2f(223.5,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,241);   //w1 2nd building 3rd floor2
    glVertex2f(234,241);
    glVertex2f(234,257);
    glVertex2f(233.1,257);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,241);   //w2 2nd building 3rd floor2
    glVertex2f(273,241);
    glVertex2f(273,257);
    glVertex2f(253,257);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,242);   //w2 2nd building 3rd floor2
    glVertex2f(272.5,242);
    glVertex2f(272.5,256);
    glVertex2f(253.5,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,241);   //w2 2nd building 3rd floor2
    glVertex2f(264,241);
    glVertex2f(264,257);
    glVertex2f(263.1,257);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,270);  //2nd building 3rd floor1
    glVertex2f(284,270);
    glVertex2f(284,285);
    glVertex2f(202.5,285);
    glEnd();

    ///....4th floor design............///

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,290);   //part 2 2nd building 4th floor red.........
    glVertex2f(281,290);
    glVertex2f(281,320);
    glVertex2f(205,320);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,290);   //part 2 2nd building 4th floor.......red
    glVertex2f(264,290);
    glVertex2f(264,320);
    glVertex2f(281,320);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,285);   //d2 2nd building 4th floor
    glVertex2f(215,285);
    glVertex2f(215,320);
    glVertex2f(205,320);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,297);   //d2 2nd building 5th floor
    glVertex2f(210,297);
    glVertex2f(210,312);
    glVertex2f(209,312);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,296);   //w1 2nd building 4th floor2
    glVertex2f(243,296);
    glVertex2f(243,312);
    glVertex2f(223,312);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,297);   //w1 2nd building 4th floor2
    glVertex2f(242.5,297);
    glVertex2f(242.5,311);
    glVertex2f(223.5,311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,296);   //w1 2nd building 4th floor2
    glVertex2f(234,296);
    glVertex2f(234,312);
    glVertex2f(233.1,312);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,297);   //w2 2nd building 4th floor2
    glVertex2f(273,297);
    glVertex2f(273,312);
    glVertex2f(253,312);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,297);   //w2 2nd building 4th floor2
    glVertex2f(272.5,297);
    glVertex2f(272.5,311);
    glVertex2f(253.5,311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,297);   //w2 2nd building 4th floor2
    glVertex2f(264,297);
    glVertex2f(264,312);
    glVertex2f(263.1,312);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,325);  //2nd building 4th floor1
    glVertex2f(284,325);
    glVertex2f(284,340);
    glVertex2f(202.5,340);
    glEnd();

    ///....5th floor design............///

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,345);   //part 2 2nd building 5th floor red.........
    glVertex2f(281,345);
    glVertex2f(281,375);
    glVertex2f(205,375);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,345);   //part 2 2nd building 5th floor.......red
    glVertex2f(264,345);
    glVertex2f(264,375);
    glVertex2f(281,375);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,340);   //d2 2nd building 5th floor
    glVertex2f(215,340);
    glVertex2f(215,375);
    glVertex2f(205,375);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,352);   //d2 2nd building 5th floor
    glVertex2f(210,352);
    glVertex2f(210,367);
    glVertex2f(209,367);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,351);   //w1 2nd building 5th floor2
    glVertex2f(243,351);
    glVertex2f(243,367);
    glVertex2f(223,367);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,352);   //w1 2nd building 5th floor2
    glVertex2f(242.5,352);
    glVertex2f(242.5,366);
    glVertex2f(223.5,366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,351);   //w1 2nd building 5th floor2
    glVertex2f(234,351);
    glVertex2f(234,367);
    glVertex2f(233.1,367);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,352);   //w2 2nd building 4th floor2
    glVertex2f(273,352);
    glVertex2f(273,367);
    glVertex2f(253,367);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,352);   //w2 2nd building 5th floor2
    glVertex2f(272.5,352);
    glVertex2f(272.5,366);
    glVertex2f(253.5,366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,352);   //w2 2nd building 5th floor2
    glVertex2f(264,352);
    glVertex2f(264,367);
    glVertex2f(263.1,367);
    glEnd();

    ///Tower 2nd Building//
    glBegin(GL_QUADS);
    glColor3ub(140, 140, 140);
    glVertex2f(273,395);
    glVertex2f(274,395);
    glVertex2f(274,520);
    glVertex2f(273,520);
    glEnd();

    glColor3ub(102, 102, 102);
    circle(3,6,273,500);
    glColor3ub(217, 217, 217);
    circle(2.5,5,273,500);
    glColor3ub(102, 102, 102);
    circle(2,4,276,485);
    glColor3ub(217, 217, 217);
    circle(1.5,3,276,485);

///triangle tree 2nd Building///
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex2f(290,90);
    glVertex2f(295,90);
    glVertex2f(295,120);
    glVertex2f(290,120);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(280,120);
    glVertex2f(305,120);
    glVertex2f(292.5,180);
    glVertex2f(292.5,180);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(281,135);
    glVertex2f(304,135);
    glVertex2f(292.5,190);
    glVertex2f(292.5,190);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(282,150);
    glVertex2f(303,150);
    glVertex2f(292.5,180);
    glVertex2f(292.5,180);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(283,160);
    glVertex2f(302,160);
    glVertex2f(292.5,190);
    glVertex2f(292.5,190);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(284,170);
    glVertex2f(301,170);
    glVertex2f(292.5,200);
    glVertex2f(292.5,200);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(285,180);
    glVertex2f(300,180);
    glVertex2f(292.5,210);
    glVertex2f(292.5,210);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(286,190);
    glVertex2f(299,190);
    glVertex2f(292.5,260);
    glVertex2f(292.5,260);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(139, 146, 22);
    glVertex2f(286,200);
    glVertex2f(299,200);
    glVertex2f(292.5,270);
    glVertex2f(292.5,270);
    glEnd();

///.............End 2nd building...............//




///.............3rd Building Design......................///
///white part///
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(575,90);
    glVertex2f(635,90);
    glVertex2f(635,475);
    glVertex2f(575,475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(577.5,90);        //3rd Building main part 2
    glVertex2f(631,90);
    glVertex2f(631,460);
    glVertex2f(577.5,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(635,90);         //3rd Building 2nd part 2
    glVertex2f(665,90);
    glVertex2f(665,420);
    glVertex2f(635,420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(635,90);         //3rd Building 2nd part 1
    glVertex2f(662.5,90);
    glVertex2f(662.5,410);
    glVertex2f(635,410);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(637,370);   //part 2 3rd Building 6th floor2..........outlook
    glVertex2f(662.5,370);
    glVertex2f(662.5,400);
    glVertex2f(637,400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(638,365);   //part 2 3rd Building 6th floor2..........outlook
    glVertex2f(648,365);
    glVertex2f(648,400);
    glVertex2f(638,400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(643,365);   //Door 3rd Building 6th floor2..........outlook-1
    glVertex2f(644,365);
    glVertex2f(644,392);
    glVertex2f(643,392);
    glEnd();

/////////////****
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,90); //3rd Building 3rd Building floor1
    glVertex2f(667,90);
    glVertex2f(667,145);
    glVertex2f(615,145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,145);   //3rd Building 2nd floor1
    glVertex2f(667,145);
    glVertex2f(667,200);
    glVertex2f(615,200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,200);   //3rd Building 3rd floor1
    glVertex2f(667,200);
    glVertex2f(667,255);
    glVertex2f(615,255);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,255);   //3rd Building 4th floor1
    glVertex2f(667,255);
    glVertex2f(667,310);
    glVertex2f(615,310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,310);   //3rd Building 5th floor1
    glVertex2f(667,310);
    glVertex2f(667,365);
    glVertex2f(615,365);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,365);   //3rd Building 6th floor1
    glVertex2f(667,365);
    glVertex2f(667,420);
    glVertex2f(615,420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,420);   //3rd Building 7th floor1
    glVertex2f(667,420);
    glVertex2f(667,475);
    glVertex2f(615,475);
    glEnd();

    ///design of main building....red and glass....

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,420);  //7 3rd Building main part3
    glVertex2f(592,420);
    glVertex2f(592,460);
    glVertex2f(577.5,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,365);  //6 3rd Building main part3
    glVertex2f(592,365);
    glVertex2f(592,405);
    glVertex2f(577.5,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,310);  //5 3rd Building main part3
    glVertex2f(592,310);
    glVertex2f(592,350);
    glVertex2f(577.5,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,255);  //4 3rd Building main part3
    glVertex2f(592,255);
    glVertex2f(592,295);
    glVertex2f(577.5,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,200);  //3 3rd Building main part3
    glVertex2f(592,200);
    glVertex2f(592,240);
    glVertex2f(577.5,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,145);  //2 3rd Building main part3
    glVertex2f(592,145);
    glVertex2f(592,185);
    glVertex2f(577.5,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,90);  //1 3rd Building main part3
    glVertex2f(592,90);
    glVertex2f(592,130);
    glVertex2f(577.5,130);
    glEnd();
    /////////.....................
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,420);  //7 3rd Building main part3
    glVertex2f(631,420);
    glVertex2f(631,460);
    glVertex2f(620,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,365);  //6 3rd Building main part3
    glVertex2f(631,365);
    glVertex2f(631,405);
    glVertex2f(620,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,310);  //5 3rd Building main part3
    glVertex2f(631,310);
    glVertex2f(631,350);
    glVertex2f(620,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,255);  //4 3rd Building main part3
    glVertex2f(631,255);
    glVertex2f(631,295);
    glVertex2f(620,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,200);  //3 3rd Building main part3
    glVertex2f(631,200);
    glVertex2f(631,240);
    glVertex2f(620,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,145);  //2 3rd Building main part3
    glVertex2f(631,145);
    glVertex2f(631,185);
    glVertex2f(620,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(610,90);  //door
    glVertex2f(631,90);
    glVertex2f(631,130);
    glVertex2f(610,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(620,90);  //door 1 main
    glVertex2f(621,90);
    glVertex2f(621,130);
    glVertex2f(620,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(621,100);  //door 1 main
    glVertex2f(622,100);
    glVertex2f(622,120);
    glVertex2f(621,120);
    glEnd();

    //////////............................

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,420);  //7 3rd Building main part3
    glVertex2f(635,420);
    glVertex2f(635,421);
    glVertex2f(575,421);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,365);  //6 3rd Building main part3
    glVertex2f(662.5,365);
    glVertex2f(662.5,366);
    glVertex2f(575,366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,310);  //5 3rd Building main part3
    glVertex2f(635,310);
    glVertex2f(635,311);
    glVertex2f(575,311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,255);  //4 3rd Building main part3
    glVertex2f(635,255);
    glVertex2f(635,256);
    glVertex2f(575,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,199);  //3 3rd Building main part3
    glVertex2f(635,199);
    glVertex2f(635,200);
    glVertex2f(575,200);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,145);  //2 3rd Building main part3
    glVertex2f(635,145);
    glVertex2f(635,146);
    glVertex2f(575,146);
    glEnd();

    ///////...............................
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,405);  //7 3rd Building main part3
    glVertex2f(635,405);
    glVertex2f(635,406);
    glVertex2f(575,406);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,350);  //6 3rd Building main part3
    glVertex2f(635,350);
    glVertex2f(635,351);
    glVertex2f(575,351);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,295);  //5 3rd Building main part3
    glVertex2f(635,295);
    glVertex2f(635,296);
    glVertex2f(575,296);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,240);  //4 3rd Building main part3
    glVertex2f(635,240);
    glVertex2f(635,241);
    glVertex2f(575,241);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,185);  //3 3rd Building main part3
    glVertex2f(635,185);
    glVertex2f(635,186);
    glVertex2f(575,186);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,130);  //2 3rd Building main part3
    glVertex2f(635,130);
    glVertex2f(635,131);
    glVertex2f(575,131);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(665,90);  // part2 last black line
    glVertex2f(666,90);
    glVertex2f(666,460);
    glVertex2f(665,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,420);  //7 2nd part3
    glVertex2f(662.5,420);
    glVertex2f(662.5,460);
    glVertex2f(635,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,365);  //6 2nd part3
    glVertex2f(662.5,365);
    glVertex2f(662.5,405);
    glVertex2f(635,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,310);  //5 part3
    glVertex2f(662.5,310);
    glVertex2f(662.5,350);
    glVertex2f(635,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,255);  //4 2nd part3
    glVertex2f(662.5,255);
    glVertex2f(662.5,295);
    glVertex2f(635,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,200);  //3 2nd part3
    glVertex2f(662.5,200);
    glVertex2f(662.5,240);
    glVertex2f(635,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,145);  //2 2nd part3
    glVertex2f(662.5,145);
    glVertex2f(662.5,185);
    glVertex2f(635,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(635,90);  //1 3rd Building main part3
    glVertex2f(662.5,90);
    glVertex2f(662.5,130);
    glVertex2f(635,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(642,90);  //1 main part3
    glVertex2f(643,90);
    glVertex2f(643,130);
    glVertex2f(642,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(652,90);  //1 main part3
    glVertex2f(653,90);
    glVertex2f(653,130);
    glVertex2f(652,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(643,100);  //1 main part3
    glVertex2f(644,100);
    glVertex2f(644,120);
    glVertex2f(643,120);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(653,100);  ///1 main part3
    glVertex2f(654,100);
    glVertex2f(654,120);
    glVertex2f(653,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(635,90);   ///partation of Blue line
    glVertex2f(636,90);
    glVertex2f(636,460);
    glVertex2f(635,460);
    glEnd();
///Tower 3rd Building//
    glBegin(GL_QUADS);
    glColor3ub(140, 140, 140);
    glVertex2f(635,475);
    glVertex2f(636,475);
    glVertex2f(636,600);
    glVertex2f(635,600);
    glEnd();

    glColor3ub(102, 102, 102);
    circle(3,6,635,577);
    glColor3ub(217, 217, 217);
    circle(2.5,5,635,577);
    glColor3ub(102, 102, 102);
    circle(2,4,638,560);
    glColor3ub(217, 217, 217);
    circle(1.5,3,638,560);
    ///Tower End//
///...............End 3rd Building.................///



///.............4th Building Design.....Hospital...........///

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);///4th Building main part 2
    glVertex2f(483.5,440);
    glVertex2f(555.2,440);
    glVertex2f(555.2,472);
    glVertex2f(483.5,472);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(483.5,440);        ///4th Building main part 2
    glVertex2f(555.2,440);
    glVertex2f(555.2,467);
    glVertex2f(483.5,467);
    glEnd();
///white part///
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);///4th Building main part 2
    glVertex2f(475,119);
    glVertex2f(563.5,119);
    glVertex2f(563.5,442);
    glVertex2f(475,442);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(477.5,119);        ///4th Building main part 2
    glVertex2f(561,119);
    glVertex2f(561,434);
    glVertex2f(477.5,434);
    glEnd();

    ///floor divided //
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,150);  ///4th Building 1st floor1
    glVertex2f(563,150);
    glVertex2f(563,154);
    glVertex2f(475,154);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,190);  ///4th Building 2nd floor1
    glVertex2f(563,190);
    glVertex2f(563,193);
    glVertex2f(475,193);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,230);  ///4th Building 3rd floor1
    glVertex2f(563,230);
    glVertex2f(563,234);
    glVertex2f(475,234);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,270);  ///4th Building 4th floor1
    glVertex2f(563,270);
    glVertex2f(563,273);
    glVertex2f(475,273);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,310);  ///4th Building 5th floor1
    glVertex2f(563,310);
    glVertex2f(563,314);
    glVertex2f(475,314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,310);  ///4th Building 6th floor1
    glVertex2f(563,310);
    glVertex2f(563,314);
    glVertex2f(475,314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,350);  ///4th Building 7th floor1
    glVertex2f(563,350);
    glVertex2f(563,353);
    glVertex2f(475,353);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,390);  ///4th Building 8th floor1
    glVertex2f(563,390);
    glVertex2f(563,394);
    glVertex2f(475,394);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(491,119);  /// 4th Building white line vertical
    glVertex2f(491.5,119);
    glVertex2f(491.5,440);
    glVertex2f(491,440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(505,119);  /// 4th Building white line vertical
    glVertex2f(505.5,119);
    glVertex2f(505.5,440);
    glVertex2f(505,440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(519,119);  /// 4th Building white line vertical
    glVertex2f(519.5,119);
    glVertex2f(519.5,440);
    glVertex2f(519,440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(533,119);  /// 4th Building white line vertical
    glVertex2f(533.5,119);
    glVertex2f(533.5,440);
    glVertex2f(533,440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(547,119);  /// 4th Building white line vertical
    glVertex2f(547.5,119);
    glVertex2f(547.5,440);
    glVertex2f(547,440);
    glEnd();

    ///Door
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(505,140);  ///4th Building 1st floor1
    glVertex2f(533,140);
    glVertex2f(533,144);
    glVertex2f(505,144);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(532,119);  /// 4th Building white line vertical
    glVertex2f(533.6,119);
    glVertex2f(533.6,140);
    glVertex2f(532,140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(518,119);  /// 4th Building white line vertical
    glVertex2f(519.6,119);
    glVertex2f(519.6,140);
    glVertex2f(518,140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(505,119);  ///4th Building white line vertical
    glVertex2f(506.6,119);
    glVertex2f(506.6,140);
    glVertex2f(505,140);
    glEnd();

    ///Hospital signboard
    glColor3ub(0, 51, 204);
    glRasterPos2i(504,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'H');
    glColor3ub(0, 51, 204);
    glRasterPos2i(509,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
    glColor3ub(0, 51, 204);
    glRasterPos2i(513,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'S');
    glColor3ub(0, 51, 204);
    glRasterPos2i(517,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'P');
    glColor3ub(0, 51, 204);
    glRasterPos2i(521,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'I');
    glColor3ub(0, 51, 204);
    glRasterPos2i(525,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'T');
    glColor3ub(0, 51, 204);
    glRasterPos2i(529,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'A');
    glColor3ub(0, 51, 204);
    glRasterPos2i(534,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'L');
    ///End//

///....................End 4th Building..... Hospital..................///

///...................5th Building Food Court,,,,,,,,,,,,,,,///
    /// Food court big Right part///
    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);///Food Court main part 2
    glVertex2f(373,90);
    glVertex2f(466,90);
    glVertex2f(466,442);
    glVertex2f(373,442);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(91,102,108);
    glVertex2f(377.5,90);        ///Food Court main part 2
    glVertex2f(461,90);
    glVertex2f(461,440);
    glVertex2f(377.5,440);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);
    glVertex2f(282.5,270);  ///Middle divided left right
    glVertex2f(466,270);
    glVertex2f(466,281);
    glVertex2f(282.5,281);
    glEnd();

    ///stairs//Top
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(371,442);  ///3//
    glVertex2f(467.5,442);
    glVertex2f(467.5,451);
    glVertex2f(371,451);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(20, 25, 33);
    glVertex2f(371,454);  ///2//
    glVertex2f(467.5,454);
    glVertex2f(467.5,451);
    glVertex2f(371,451);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(367,454);  ///1//
    glVertex2f(471.5,454);
    glVertex2f(471.5,463);
    glVertex2f(367,463);
    glEnd();

    ///stairs Top End//

    glBegin(GL_QUADS);
    glColor3ub(72, 85, 93);
    glVertex2f(377.5,433);
    glVertex2f(461,433);
    glVertex2f(461,440);
    glVertex2f(377.5,440);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(382,290);        ///black Food Court Right part
    glVertex2f(457,290);
    glVertex2f(457,429);
    glVertex2f(382,429);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 246, 223);
    glVertex2f(383.5,293.6);        /// white color Food Court Right part
    glVertex2f(455.4,293.6);
    glVertex2f(455.4,425.4);
    glVertex2f(383.5,425.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(382,314.2);  ///middle line 2
    glVertex2f(457,314.2);
    glVertex2f(457,310.2);
    glVertex2f(382,310.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(382,409.1);  ///middle line 1
    glVertex2f(457,409.1);
    glVertex2f(457,405.1);
    glVertex2f(382,405.1);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(402,290);   ///partation of Blue line
    glVertex2f(400.6,290);
    glVertex2f(400.6,426);
    glVertex2f(402,426);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(420,290);   ///partation of Blue line
    glVertex2f(418.6,290);
    glVertex2f(418.6,426);
    glVertex2f(420,426);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(438,290);   ///partation of Blue line
    glVertex2f(436.5,290);
    glVertex2f(436.5,426);
    glVertex2f(438,426);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);
    glVertex2f(388.5,255.6);        ///  Food Court board Black
    glVertex2f(450.2,255.6);
    glVertex2f(450.2,283.4);
    glVertex2f(388.5,283.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(182, 138, 94);
    glVertex2f(386.5,258.3);        /// Food Court board
    glVertex2f(448.3,258.3);
    glVertex2f(448.3,287);
    glVertex2f(386.5,287);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(386.5,281.2);  ///middle line 1
    glVertex2f(448.3,281.2);
    glVertex2f(448.3,279);
    glVertex2f(386.5,279);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(386.5,273.2);  ///middle line 1
    glVertex2f(448.3,273.2);
    glVertex2f(448.3,271);
    glVertex2f(386.5,271);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(386.5,265.2);  ///middle line 1
    glVertex2f(448.3,265.2);
    glVertex2f(448.3,263);
    glVertex2f(386.5,263);
    glEnd();

    glColor3ub(31, 46, 53);
    glRasterPos2i(400,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'F');
    glColor3ub(31, 46, 53);
    glRasterPos2i(404,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
    glColor3ub(31, 46, 53);
    glRasterPos2i(408,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
    glColor3ub(31, 46, 53);
    glRasterPos2i(412,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'D');
    glColor3ub(31, 46, 53);
    glRasterPos2i(416,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,' ');
    glColor3ub(31, 46, 53);
    glRasterPos2i(420,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'C');
    glColor3ub(31, 46, 53);
    glRasterPos2i(424,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
    glColor3ub(31, 46, 53);
    glRasterPos2i(428,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'U');
    glColor3ub(31, 46, 53);
    glRasterPos2i(432,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'R');
    glColor3ub(31, 46, 53);
    glRasterPos2i(436,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'T');

    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,241.4);  ///middle line
    glVertex2f(460.9,241.4);
    glVertex2f(460.9,239.2);
    glVertex2f(377.6,239.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,230.4);  ///middle line
    glVertex2f(460.9,230.4);
    glVertex2f(460.9,228.2);
    glVertex2f(377.6,228.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,220.4);  ///middle line
    glVertex2f(460.9,220.4);
    glVertex2f(460.9,218.2);
    glVertex2f(377.6,218.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,210.5);  ///middle line
    glVertex2f(460.9,210.5);
    glVertex2f(460.9,208.4);
    glVertex2f(377.6,208.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,200.5);  ///middle line
    glVertex2f(460.9,200.5);
    glVertex2f(460.9,198.4);
    glVertex2f(377.6,198.4);
    glEnd();

    ///Door///
    glBegin(GL_QUADS);
    glColor3ub(104, 111, 119);
    glVertex2f(397,110);        ///black color Food court door
    glVertex2f(442,110);
    glVertex2f(442,230);
    glVertex2f(397,230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(398.5,110);        /// Food Court black color
    glVertex2f(440,110);
    glVertex2f(440,226.5);
    glVertex2f(398.5,226.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 242, 205);
    glVertex2f(401.5,110);        /// Food Court Right part
    glVertex2f(437,110);
    glVertex2f(437,220.5);
    glVertex2f(401.5,220.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(399,118.7);  ///
    glVertex2f(440,118.7);
    glVertex2f(440,124.6);
    glVertex2f(399,124.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(420,110);   ///partation of Blue line
    glVertex2f(416.6,110);
    glVertex2f(416.6,226);
    glVertex2f(420,226);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(104, 111, 119);
    glVertex2f(421,110);   ///partation
    glVertex2f(419.6,110);
    glVertex2f(419.6,226);
    glVertex2f(421,226);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(424,110);   ///partation of Blue line
    glVertex2f(420.6,110);
    glVertex2f(420.6,226);
    glVertex2f(424,226);
    glEnd();
    ///End Right part///

    ///Food Court left part
    glBegin(GL_QUADS);
    glColor3ub(91, 102, 108);///Food Court small left part
    glVertex2f(288,110);
    glVertex2f(373,110);
    glVertex2f(373,270);
    glVertex2f(288,270);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(293,120);        ///black Food Court small left part
    glVertex2f(368,120);
    glVertex2f(368,259);
    glVertex2f(293,259);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 246, 223);
    glVertex2f(295,124);        /// white color Food Court small left part
    glVertex2f(366,124);
    glVertex2f(366,256);
    glVertex2f(295,256);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(294.5,190);  ///middle line
    glVertex2f(368,190);
    glVertex2f(368,187);
    glVertex2f(294.5,187);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(350,120);   ///partation of Blue line
    glVertex2f(348.6,120);
    glVertex2f(348.6,256);
    glVertex2f(350,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(332,120);   ///partation of Blue line
    glVertex2f(330.6,120);
    glVertex2f(330.6,256);
    glVertex2f(332,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(314,120);   ///partation of Blue line
    glVertex2f(312.6,120);
    glVertex2f(312.6,256);
    glVertex2f(314,256);
    glEnd();

    ///top Boundary
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(284.3,280);   ///partation of Blue line
    glVertex2f(282.5,280);
    glVertex2f(282.5,321);
    glVertex2f(284.3,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(302,280);   ///partation of Blue line
    glVertex2f(300.2,280);
    glVertex2f(300.2,321);
    glVertex2f(302,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(320,280);   ///partation of Blue line
    glVertex2f(318.2,280);
    glVertex2f(318.2,321);
    glVertex2f(320,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(338,280);   ///partation of Blue line
    glVertex2f(336.1,280);
    glVertex2f(336.1,321);
    glVertex2f(338,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(356,280);   ///partation of Blue line
    glVertex2f(354.2,280);
    glVertex2f(354.2,321);
    glVertex2f(356,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(373,280);   ///partation of Blue line
    glVertex2f(371.2,280);
    glVertex2f(371.2,321);
    glVertex2f(373,321);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(282.5,314);  ///middle line
    glVertex2f(372,314);
    glVertex2f(372,309.6);
    glVertex2f(282.5,309.6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(282.5,304);  ///middle line
    glVertex2f(372,304);
    glVertex2f(372,300);
    glVertex2f(282.5,300);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(282.5,294);  ///middle line
    glVertex2f(372,294);
    glVertex2f(372,290);
    glVertex2f(282.5,290);
    glEnd();
    ///End top Boundary//
    ///End left part//
///...................5th Building Food Court,,,,,,,,,,,,,,,///




    glPopMatrix();
///.........S U N.....................///

    //sun
    glColor3ub(245, 176, 65);
    int j;
    GLfloat x=-0.8f;
    GLfloat y=0.9f;
    GLfloat radius =.1f;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(j = 0; j <= triangleAmount+1; j++)
    {
        glVertex2f(
            x + (radius * cos(j *  twicePi / triangleAmount)),
            y + (radius * sin(j * twicePi / triangleAmount))
        );
        glColor3ub(245, 249, 10);
    }
    glEnd();
    lamp();
    tree();
    megh();
    glPushMatrix();
    glTranslatef(car_position, -0.82, 0);
    car();
    glPopMatrix();
    bus();
    tree1();


    glutPostRedisplay();
    glutSwapBuffers();

    glFlush();
}

///.........................End TOWN..................................///
///.........................rangamati start..................................///


////////////////////////////////////////////////////////////////////
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);

}
void circle1(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0; i<200; i++)
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
void line1(float ax, float ay, float bx, float by, float r, float g, float b)
{
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glEnd();
}
void circle2(float rx,float ry,float cx,float cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        float angle = 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void quad(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);
    glVertex2f(dx, dy);
    glEnd();
}

void triangle(float ax, float ay, float bx, float by, float cx, float cy, float r, float g, float b)
{
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);
    glEnd();
}

void line(float ax, float ay, float bx, float by, float r, float g, float b)
{
    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glEnd();
}
void sky()
{
    quad(-1, 1,-1, 0.2,1.1520904873806, 0.2088036964438,1.1439065905304, 1.0026416909165,101, 196, 212);
}

void horizon()
{
    quad(-1, 0.2,-1.0002743842309, 0.25,1.1561824358058, 0.25,1.1520904873806, 0.2,80, 155, 168);
}
void horizon1()
{
    quad(-1, 0.2,-1.0002743842309, 0.0696774499899,1.1561824358058, 0.073769398415,1.1520904873806, 0.2088036964438,111, 72, 3);
}
void waves()
{
    // Number of waves
    int numWaves = 20;  // Increased for more visibility
    // Wave parameters
    float waveHeight = 0.05f;
    float waveWidth = 0.1f;  // Reduced for more detailed waves
    float startX = -1.0f;
    float endX = 1.0f;
    float y = 0.0f;  // Y coordinate where waves start

    glColor3ub(5, 107, 103);  // Set wave color to white

    for (int i = 0; i < numWaves; i++)
    {
        float x = startX + i * waveWidth;
        glBegin(GL_LINES);
        glVertex2f(x, y + waveHeight);
        glVertex2f(x + waveWidth / 2.0f, y);
        glVertex2f(x + waveWidth / 2.0f, y);
        glVertex2f(x + waveWidth, y + waveHeight);
        glEnd();
    }
}
void waves2()
{
    waves();
    glPushMatrix();
    glTranslatef(0,-0.2, 0);
    waves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.1, 0);
    waves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.3, 0);
    waves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.4, 0);
    waves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.5, 0);
    waves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.6, 0);
    waves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.7, 0);
    waves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.8, 0);
    waves();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.9, 0);
    waves();
    glPopMatrix();
}
float _movewave = 0.0f;
bool waveDirectionUp = true;
void updatewave(int value)
{
    if (waveDirectionUp)
    {
        _movewave += 0.001;
        if (_movewave > 0.03)
        {
            waveDirectionUp = false; // Reverse direction
        }
    }
    else
    {
        _movewave -= 0.001;
        if (_movewave < -0.03)
        {
            waveDirectionUp = true; // Reverse direction
        }
    }
    glutPostRedisplay();  // Request a redraw
    glutTimerFunc(20, updatewave, 0);  // Register the timer callback again
}
void wavemoving()
{
    glPushMatrix();
    glTranslatef(0,_movewave, 0);
    waves2();
    glPopMatrix();
}
// Function to draw the water polygon
void water()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 156, 149);  // Set the color using RGB values
    glVertex2f(-1.0002743842309f, 0.0696774499899f);  // Specify the first vertex (ax, ay)
    glColor3ub(100, 248, 241); // Set the color using RGB values
    glVertex2f(-1.0f, -1.0f);  // Specify the second vertex (bx, by)
    glVertex2f(1.1520904873806f, -1.0187808310913f);  // Specify the third vertex (cx, cy)
    glColor3ub(0, 156, 149);  // Set the color using RGB values
    glVertex2f(1.1561824358058f, 0.073769398415f);  // Specify the fourth vertex (dx, dy)
    glEnd();

    wavemoving();




}
void road()
{
    quad(-1.0, -0.3,-1,-0.5,1,-0.5,1,-0.3,80, 83, 82);
    // Draw white road dividers
    glLineWidth(3.0);
    glColor3ub(255, 255, 255);

    // Center divider
    glBegin(GL_LINES);
    glVertex2f(-0.1, -0.3);
    glVertex2f(-0.1, -0.5);
    glEnd();

    // Left road edge divider
    glBegin(GL_LINES);
    glVertex2f(-0.5, -0.3);
    glVertex2f(-0.5, -0.5);
    glEnd();

    // Right road edge divider
    glBegin(GL_LINES);
    glVertex2f(0.5, -0.3);
    glVertex2f(0.5, -0.5);
    glEnd();

    // Horizontal dividers in the center
    glPushMatrix();
    glTranslatef(0.0, -0.4, 0.0); // Adjust vertical position
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();
    glPopMatrix();
}
void boat()
{
    glBegin(GL_POLYGON);
    glColor3ub(56, 19, 2);  // Set the color using RGB values
    glVertex2f(0.5383322701219, -0.8506774775845);  // Specify the first vertex (ax, ay)
    glVertex2f(0.4426267319012, -0.8493919449328);

    glVertex2f(0.5, -0.95);  // Specify the third vertex (cx, cy)
    glVertex2f(0.9, -0.95);

    glVertex2f(0.95, -0.85);  // Specify the first vertex (ax, ay)
    glVertex2f(0.839135064574, -0.8520765603494);
    glVertex2f(0.6670478844921, -0.8590719741739);  // Specify the second vertex (bx, by)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(159, 123, 105);  // Set the color using RGB values
    glVertex2f(0.5383322701219, -0.8506774775845);  // Specify the first vertex (ax, ay)
    glVertex2f(0.562116677125, -0.7611361806313);
    glColor3ub( 122, 94, 81);
    glVertex2f(0.5775065875389, -0.7343556323839);  // Specify the third vertex (cx, cy)
    glVertex2f(0.6015022230204, -0.7295565052876);

    glVertex2f(0.6222984404376, -0.7335557778679);  // Specify the first vertex (ax, ay)
    glVertex2f(0.6334698981346, -0.7597370978664);
    glVertex2f(0.6637305054808, -0.8519140412094);  // Specify the second vertex (bx, by)
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(222, 80, 12);  // Set the color using RGB values
    glVertex2f(0.839135064574, -0.8520765603494);  // Specify the first vertex (ax, ay)
    glVertex2f(0.6637305054808, -0.8519140412094);
    glColor3ub( 122, 94, 81);
    glVertex2f(0.6222984404376, -0.7335557778679);  // Specify the third vertex (cx, cy)
    glVertex2f(0.6526929120475, -0.7207581056111);
    glColor3ub( 222, 193, 12);
    glVertex2f(0.6830873836574, -0.7127595604506);  // Specify the first vertex (ax, ay)
    glVertex2f(0.7214804004278, -0.7127595604506);
    glColor3ub(222, 80, 12);
    glVertex2f(0.7606732717142, -0.7263570872234);  // Specify the second vertex (bx, by)
    glVertex2f(0.7985616643921, -0.7611361806313);  // Specify the second vertex (bx, by)
    glEnd();

}
void bridgerails()
{
    quad(-0.2,0.8,-0.1,0.7,0.2, 0.850578845519,0.2, 0.95,144, 12, 63);
}

void bridgerails1()
{
    glPushMatrix();
    glTranslatef(0,-0.2, 0);
    bridgerails();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.4, 0);
    bridgerails();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.8, 0);
    bridgerails();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.6, 0);
    bridgerails();
    glPopMatrix();

}
void bridgestrings()
{

    line1(-0.8420135543415, -0.3597824391002,-0.4404569329067, 0.0243151987939,1,1,1);
    line1(-0.4404569329067, 0.0243151987939,-0.2, 0.7,1,1,1);
    line1(-0.2, 0.7,-0.3606444367209, -0.0255676113222,1,1,1);
    line1(-0.3606444367209, -0.0255676113222,-0.5551873961738, -0.2475461163389,1,1,1);
    line1(-0.5551873961738, -0.2475461163389,-0.8420135543415, -0.3597824391002,1,1,1);
    line1(-1.0, -0.3,-0.6, 0.1,1,1,1);
    line1(-0.6, 0.1,-0.2, 0.7,1,1,1);

}
void bridgeredstrings2()
{
    line1(0.8420135543415, -0.3597824391002, 0.4404569329067, 0.0243151987939, 1, 1, 1);
    line1(0.4404569329067, 0.0243151987939, 0.2, 0.7, 1,1,1);
    line1(0.2, 0.7, 0.3606444367209, -0.0255676113222, 1, 1, 1);
    line1(0.3606444367209, -0.0255676113222, 0.5551873961738, -0.2475461163389, 1,1,1);
    line1(0.5551873961738, -0.2475461163389, 0.8420135543415, -0.3597824391002,1, 1, 1);
    line1(1.0, -0.3, 0.6, 0.1,1, 1, 1);
    line1(0.6, 0.1, 0.2, 0.7, 1, 1, 1);
}

void redbridgeback()
{
    quad(-0.2,-0.3,-0.1,-0.3,-0.1,0.7,-0.2,0.7,144, 12, 63);
}
void redbridge()
{

    quad(-0.2,0.7,-0.1,0.6,0.2, 0.850578845519,0.2, 0.95,144, 12, 63);
    bridgerails1();
    quad(0.2, 0.95,0.2,-0.5,0.4,-0.5,0.4,0.95,144, 12, 63);

}





void tree(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);

    // Draw tree trunk
    quad(-0.05, 0.0, 0.05, 0.0, 0.05, 0.4, -0.05, 0.4, 111, 72, 3);

    // Draw tree leaves
    circle1(0.2, 0.0, 0.5, 36, 87, 5);

    glPopMatrix();
}

void trees()
{
    // Draw trees at horizon
    glPushMatrix();
    glTranslatef(0.5,-0.1, 0.0);
    glScalef(0.5f, 0.5f, 1.0f);
    tree(-2.0, 0.2);
    tree(-3.0, 0.2);
    tree(-5.0, 0.2);
    tree(0.4, 0.2);
    tree(0.75, 0.2);
    glPopMatrix();
}
void trees1()
{
    glPushMatrix();
    glTranslatef(0.0,0.2, 0.0);
    trees();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5,0.2, 0.0);
    glScalef(0.5f, 0.5f, 1.0f);
    tree(-2.0, 0.2);
    tree(-3.0, 0.2);
    tree(-5.0, 0.2);
    glPopMatrix();

}

void trees2()
{
    glPushMatrix();
    glTranslatef(0.2,0., 0.0);
    trees1();
    glPopMatrix();

}


void soil()
{
    glBegin(GL_POLYGON);
    glColor3ub(25, 133, 8);  // Top-left color
    glVertex2f(-0.5f, -0.25f);
    glColor3ub(110, 200, 96);      // Bottom-left color
    glVertex2f(-0.5f, -1.0f);
    glColor3ub(110, 200, 96);      // Bottom-right color
    glVertex2f(0.5f, -1.0f);
    glColor3ub(25, 133, 8);   // Top-right color
    glVertex2f(0.5f, -0.75f);
    glColor3ub(25, 133, 8);   // Top-right color
    glVertex2f(0.4f, -0.65f);
    glEnd();


}

void buswindows()
{


    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(12, 85); // Lower-left corner
    glVertex2f(20, 85); // Lower-right corner
    glVertex2f(20, 100); // Upper-right corner
    glVertex2f(12, 100); // Upper-left corner
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(22, 85); // Lower-left corner
    glVertex2f(30, 85); // Lower-right corner
    glVertex2f(30, 100); // Upper-right corner
    glVertex2f(22, 100); // Upper-left corner
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(32, 85); // Lower-left corner
    glVertex2f(40, 85); // Lower-right corner
    glVertex2f(40, 100); // Upper-right corner
    glVertex2f(32, 100); // Upper-left corner
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(42, 85); // Lower-left corner
    glVertex2f(50, 85); // Lower-right corner
    glVertex2f(50, 100); // Upper-right corner
    glVertex2f(42, 100); // Upper-left corner
    glEnd();
}
void buswindows1()
{
    glPushMatrix();
    glTranslatef(49,0, 0);
    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(12, 85); // Lower-left corner
    glVertex2f(20, 85); // Lower-right corner
    glVertex2f(20, 100); // Upper-right corner
    glVertex2f(12, 100); // Upper-left corner
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(22, 85); // Lower-left corner
    glVertex2f(30, 85); // Lower-right corner
    glVertex2f(30, 100); // Upper-right corner
    glVertex2f(22, 100); // Upper-left corner
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(32, 85); // Lower-left corner
    glVertex2f(40, 85); // Lower-right corner
    glVertex2f(40, 100); // Upper-right corner
    glVertex2f(32, 100); // Upper-left corner
    glEnd();
    glPopMatrix();
}

void wheels()
{
    // Front left wheel
    glColor3ub(255, 255, 204);
    circle(4, 8, 45, 65);

    // Front right wheel
    glColor3ub(255, 255, 204);
    circle(2, 4, 55, 75);

    // Back left wheel
    glColor3ub(255, 255, 204);
    circle(3, 6, 15, 75);

    // Back right wheel
    glColor3ub(255, 255, 204);
    circle(2, 4, 35, 65);

    // Middle wheel
    glColor3ub(255, 255, 204);
    circle(2, 4, 75, 75);

    // Front left wheel interior
    glColor3ub(0, 0, 0);
    circle(5, 10, 25, 55);

    // Front right wheel interior
    glColor3ub(255, 255, 255);
    circle(3, 6, 25, 55);

    // Back left wheel interior
    glColor3ub(0, 0, 0);
    circle(5, 10, 78, 55);

    // Back right wheel interior
    glColor3ub(255, 255, 255);
    circle(3, 6, 78, 55);
}



void busr()
{
    // Center of the window
    float centerX = -0.9f;
    float centerY = -0.6f;

    // Bus dimensions
    float busWidth = 2.6f; // Increased width by 1 unit
    float busHeight = 2.4f;
    glPushMatrix();
    // Translate and scale the coordinates to center the bus within the window
    glTranslatef(centerX, centerY, 0);
    glScalef((1.0 / 350.0) * 2.0, (1.0 / 400.0)* 1.5, 1.0);

    // Draw bus body
    glBegin(GL_QUADS);
    glColor3ub(255, 81, 76);
    glVertex2f(10, 55);  // Lower-left corner
    glVertex2f(92, 55);  // Lower-right corner
    glVertex2f(92, 105); // Upper-right corner
    glVertex2f(10, 105); // Upper-left corner
    glEnd();

    // Draw front glass
    glBegin(GL_QUADS);
    glColor3ub(26, 26, 0);
    glVertex2f(90, 89);  // Lower-left corner
    glVertex2f(92, 89);  // Lower-right corner
    glVertex2f(92, 100); // Upper-right corner
    glVertex2f(90, 100); // Upper-left corner
    glEnd();



    buswindows();
    buswindows1();
    // Draw door
    wheels();
    glBegin(GL_QUADS);
    glColor3ub(230, 247, 255);
    glVertex2f(51, 55); // Lower-left corner
    glVertex2f(59, 55); // Lower-right corner
    glVertex2f(59, 95); // Upper-right corner
    glVertex2f(51, 95); // Upper-left corner
    glEnd();
    glPopMatrix();
}

void stone()
{
    glBegin(GL_POLYGON);
    glColor3ub(116, 113, 119);
    glVertex2f(0.3641164507417, -0.3462849982933);
    glVertex2f(-0.6248991875483, -0.4059794621702);
    glColor3ub(70, 55, 87);
    glVertex2f(-0.6248991875483, -0.6512125609118);
    glVertex2f(0.5091117274388, -0.7661072539853);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(116, 113, 119);
    glVertex2f(0.5091117274388, -0.7661072539853);
    glVertex2f(-0.6248991875483, -0.6512125609118);
    glVertex2f(-1.0, -0.6781630083083);
    glColor3ub(70, 55, 87);
    glVertex2f(-0.9867686894513, -0.9700517911741);
    glVertex2f(-0.2777572369817, -1.1974479870657);
    glVertex2f(0.6032556359252, -1.1203643992117);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(116, 113, 119);
    glVertex2f(0.6032556359252, -1.1203643992117);
    glVertex2f(-0.2777572369817, -1.1974479870657);
    glVertex2f(-0.9867686894513, -0.9700517911741);
    glVertex2f(-1.6278641837838, -1.0878932045144);
    glColor3ub(70, 55, 87);
    glVertex2f(-1.5580713095718, -1.6933797061444);
    glVertex2f(-0.5855481689243, -2.0463178513806);
    glVertex2f(0.2168221537504, -1.7192088100746);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(116, 113, 119);
    glVertex2f(0.2168221537504, -1.7192088100746);
    glVertex2f(-0.5855481689243, -2.0463178513806);
    glVertex2f(-1.5580713095718, -1.6933797061444);
    glVertex2f(-2.0, -1.8800012898443);
    glColor3ub(70, 55, 87);
    glVertex2f(-1.9786768250652, -2.8236065299961);
    glVertex2f(0.5, -2.5);
    glEnd();
}


void cloud(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);

    // Draw cloud
    circle1(0.05, -0.1, 0.0,  255, 255, 255);
    circle1(0.05, -0.025, 0.05,  255, 255, 255);
    circle1(0.05, 0.05, 0.0,  255, 255, 255);
    circle1(0.05, -0.025, -0.05,  255, 255, 255);
    circle1(0.05, 0.05, -0.05, 255, 255, 255);

    glPopMatrix();
}

void clouds()
{
    // Draw clouds in the sky
    cloud(-0.35, 0.4);
    cloud(-0.25, 0.425);
    cloud(-0.15, 0.4);
    cloud(0.15, 0.425);
    cloud(0.25, 0.4);
    cloud(0.35, 0.425);
}


// Global variables
float _move1 = 0.001f; // Movement increment for the bus
float busPositionX = 0.0f; // Initial bus position
bool busMoving = true; // Flag to indicate if the bus should move

void update1(int value)
{
    if (busMoving)
    {
        busPositionX += _move1;
        if (busPositionX > 1.5f)
        {
            busPositionX = -1.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, update1, 0);
}

void updateBusPosition()
{
    if (busMoving)
    {
        busPositionX += _move1;
    }
}



float _move2 = 0.001f; // Movement increment for the bus
float boatPositionX = 0.0f; // Initial bus position
bool boatMoving = true; // Flag to indicate if the bus should move

void update3(int value)
{
    if (boatMoving)
    {
        boatPositionX += _move2;
        if (boatPositionX > 1.0f)
        {
            boatPositionX = -1.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, update3, 0);
}
void updateBoatPosition()
{
    if (boatMoving)
    {
        boatPositionX += _move2;
    }
}




float _move = 0.0f;

void updatebus(int value)
{
    _move += 0.002;
    if (_move > 1.5)
    {
        _move = -1;
    }
    glutPostRedisplay();
    glutTimerFunc(20, updatebus, 0);
}

void rangamati()
{

    sky();
    horizon1();
    horizon();
    trees1();
    trees2();
    water();
    road();
    glPushMatrix();
    glTranslatef(-_move, 0.4f, 0.0f); // Adjusted translation to fit within the range
    clouds();
    glPopMatrix();

    bridgestrings();
    bridgeredstrings2();
    road();
    redbridgeback();
    glPushMatrix();
    glTranslatef(busPositionX, 0.0f, 0.0f); // Adjusted translation to fit within the range
    busr();
    glPopMatrix();
    redbridge();


//
    glPushMatrix();
    glTranslatef(-0.5f, -0.3f, 0.0f); // Adjusted translation to fit within the range
    soil();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-boatPositionX, 0.2f, 0.0f); // Adjusted translation to fit within the range
    boat();
    glPopMatrix();


    glutSwapBuffers();
}


////////////////cox///////////
GLfloat speed = 0.009f;
void wheel(float x, float y, float radius)
{
    int j;

    GLfloat p= x;
    GLfloat q = y;
    GLfloat radius1=radius;
    int triangleAmount1 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(p, q); // center of circle
    for(j = 0; j <= triangleAmount1; j++)
    {
        glVertex2f(
            p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
            q + (radius1 * sin(j * twicePi1 / triangleAmount1))
        );
    }
    glEnd();
}

void wheel2(float x, float y, float radius)
{
    int j;

    GLfloat p= x;
    GLfloat q = y;
    GLfloat radius1=radius;
    int triangleAmount1 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(200, 200, 200);
    glVertex2f(p, q); // center of circle
    for(j = 0; j <= triangleAmount1; j++)
    {
        glVertex2f(
            p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
            q + (radius1 * sin(j * twicePi1 / triangleAmount1))
        );
    }
    glEnd();
}


void face(float x, float y, float radius)
{
    int j;

    GLfloat p= x;
    GLfloat q = y;
    GLfloat radius1=radius;
    int triangleAmount1 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(254, 198, 172);
    glVertex2f(p, q); // center of circle
    for(j = 0; j <= triangleAmount1; j++)
    {
        glVertex2f(
            p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
            q + (radius1 * sin(j * twicePi1 / triangleAmount1))
        );
    }
    glEnd();
}



GLfloat positionbike1 = 0.0f;

void updatebike1(int value)
{

    if(positionbike1 <-1.0)
        positionbike1 = 1.5f;

    positionbike1 -= speed;

    glutPostRedisplay();


    glutTimerFunc(100, updatebike1, 0);
}
GLfloat positionbike2 = 0.5f;
GLfloat speed3=0.007;

void updatebike2(int value)
{

    if(positionbike2 <-1.0)
        positionbike2 = 1.5f;

    positionbike2 -= speed3;

    glutPostRedisplay();


    glutTimerFunc(100, updatebike2, 0);
}

void bike1()
{
    glPushMatrix();
    glTranslatef(positionbike1,0.0f, 0.0f);


    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.51f, -0.21f);
    glVertex2f(-0.53f, -0.23f);
    glVertex2f(-0.55f, -0.3f);
    glVertex2f(-0.49f, -0.23f);

    glEnd();


    //2nd
    wheel(-0.48f, -0.26f, 0.035f);

    glBegin(GL_POLYGON);
    glColor3ub(58, 62, 102);
    glVertex2f(-0.53f, -0.33f);
    glVertex2f(-0.47f, -0.33f);
    glVertex2f(-0.46f, -0.28f);
    glColor4ub(119,33,46,1.00);
    glVertex2f(-0.37f, -0.23f);
    glVertex2f(-0.46f, -0.23f);
    glVertex2f(-0.46f, -0.21f);
    glVertex2f(-0.5f, -0.21f);


    glEnd();

    //circle-1
    //1st
    wheel(-0.6f, -0.25f, 0.035f);

    //4th
    wheel(-0.43f, -0.32f, 0.035f);
    wheel2(-0.43f, -0.32f, 0.02f);


    glBegin(GL_POLYGON);
    glColor4ub(119,33,46,1.00);
    glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.58f, -0.32f);
    glVertex2f(-0.52f, -0.32f);
    glVertex2f(-0.55f, -0.195f);
    glColor4ub(119,33,46,1.00);
    glVertex2f(-0.57f, -0.2f);
    glVertex2f(-0.63f, -0.19f);
    glVertex2f(-0.63f, -0.23f);
    glVertex2f(-0.61f, -0.25f);


    glEnd();

    //3rd
    wheel(-0.55f, -0.33f, 0.035f);
    wheel2(-0.55f, -0.33f, 0.02f);

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.59f, -0.23f);
    glVertex2f(-0.57f, -0.17f);
    glVertex2f(-0.615f, -0.165f);
    glVertex2f(-0.61f, -0.23f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.63f, -0.17f);
    glVertex2f(-0.55f, -0.18f);
    glEnd();

    //man
    wheel(-0.5f, -0.12f, 0.02f);

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.5f, -0.12f);
    glVertex2f(-0.48f, -0.18f);
    glVertex2f(-0.49f, -0.23f);
    glVertex2f(-0.51f, -0.23f);
    glEnd();


    //Hand
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.57f, -0.15f);
    glVertex2f(-0.5f, -0.15f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.53f, -0.165f);
    glVertex2f(-0.5f, -0.165f);
    glEnd();


    //Handle
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.63f, -0.17f);
    glVertex2f(-0.57f, -0.15f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.55f, -0.18f);
    glVertex2f(-0.53f, -0.165f);
    glEnd();




    glPopMatrix();

}


void bike2()
{
    glPushMatrix();
    glTranslatef(positionbike2,0.0f, 0.0f);


    //man
    glBegin(GL_POLYGON);
    glColor3ub(200, 39, 116);
    glVertex2f(-0.46f, -0.21f);
    glVertex2f(-0.46f, -0.26f);
    glVertex2f(-0.49f, -0.26f);
    glVertex2f(-0.48f, -0.21f);

    glEnd();
    wheel(-0.46f, -0.2f, 0.015f);
    face(-0.47f, -0.21f, 0.015f);



    glBegin(GL_POLYGON);
    glColor3ub(254, 201, 55);

    glVertex2f(-0.589f, -0.24f);  //1
    glVertex2f(-0.515f, -0.20f);//2
    glVertex2f(-0.475f, -0.23f);//3
    glVertex2f(-0.480f,-0.245f);//4
    glVertex2f(-0.395f,-0.258f);//5
    glVertex2f(-0.43f,-0.260f);//6
    glVertex2f(-0.475f,-0.295f);//7
    glVertex2f(-0.475f,-0.33f);//8
    glVertex2f(-0.510f,-0.33f);//9
    glVertex2f(-0.510f, -0.295f);//10
    glVertex2f(-0.55f, -0.275f);//11
    glVertex2f(-0.595f, -0.295f);//12
    glEnd();


    ///////////////////1

    wheel(-0.57f, -0.33f, 0.035f);

    wheel2(-0.57f, -0.33f, 0.02f);

    ///////////////////2

    wheel(-0.43f, -0.32f, 0.035f);

    wheel2(-0.43f, -0.32f, 0.02f);





    glPopMatrix();

}
//*********************************************BeachBike Ends*******************
void sun(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    int i = 0;
    float angle;

    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    for (i = 0; i <= 360; i++)
    {
        angle = i * PI / 180;
        glVertex2f(x + (cos(angle) * rx), y + (sin(angle) * ry));
    }
    glEnd();
}

const float stepSize = 0.009;
float currentX = 0.283;
float currentY = -0.31;
bool passing = true;

void updateBall(int value)
{
    static int delay = 0; // Delay counter
    static int wait_time = 50;

    if (delay > 0)
    {
        delay--;
    }
    else
    {
        if (passing)
        {
            if (currentX >= -0.31)
                currentX -= stepSize;
            else
            {
                passing = false; // Change state to receiving
                delay = wait_time; // Add a delay at the receiver's position
            }
        }
        else // Returning to the starting position or stationary
        {
            if (currentX <= 0.283)
                currentX += stepSize;
            else
            {
                passing = true; // Change state to passing again
                delay = wait_time; // Add a delay before starting the passing loop
            }
        }
    }

    glutPostRedisplay(); // Redisplay to update the ball position
    glutTimerFunc(10, updateBall, 0); // Call updateBall() again after 100 milliseconds
}

GLfloat trans_x_kid1 = 0.0;
GLfloat trans_x_kid2 = 0.0;
GLfloat trans_x_kid3 = 0.0;
GLfloat trans_x_ball = 0.0;


void drawCircle(GLfloat x, GLfloat y,
                GLfloat r, GLfloat g, GLfloat b,
                GLfloat sx, GLfloat sy,
                GLfloat radius)
{
    glPushMatrix();


    glTranslatef(x, y, 0);
    glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    for (GLfloat i = 0; i < 360; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

    glPopMatrix();
}


void drawSemiCircle(GLfloat tx, GLfloat ty,
                    GLfloat sx, GLfloat sy,
                    GLfloat r, GLfloat g, GLfloat b,
                    GLfloat radius,
                    GLfloat start_angle, GLfloat end_angle)
{
    glPushMatrix();


    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    for (GLfloat i = start_angle; i < end_angle; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

    glPopMatrix();
}


// Function to Draw Arc

void drawArc(GLfloat tx, GLfloat ty,
             GLfloat sx, GLfloat sy,
             GLfloat r, GLfloat g, GLfloat b)
{
    glPushMatrix();


    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 1);

    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3ub(r, g, b);
    for (GLfloat i = 90; i < 270; i += 1)
        glVertex2f(15 * sin(i * PI / 180), 15 * cos(i * PI / 180));
    glEnd();
    glPointSize(1);

    glPopMatrix();
}





void drawKidsShirtAndTrousers(GLfloat tx, GLfloat ty,
                              GLfloat sx, GLfloat sy,
                              GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b)
{
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 1.0);

    // Bottom Shirt
    glColor3ub(shirt_r, shirt_g, shirt_b);
    glBegin(GL_POLYGON);
    glVertex2f(0, 20);
    glVertex2f(100, 20);
    glVertex2f(100, 100);
    glVertex2f(0, 100);
    glEnd();

    // Top Shirt
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(135, 105);
    glVertex2f(120, 175);
    glVertex2f(100, 200);
    glVertex2f(50, 180);
    glVertex2f(0, 200);
    glVertex2f(-20, 175);
    glVertex2f(-35, 105);
    glVertex2f(0, 100);
    glEnd();

    // Left Trouser
    glColor3ub(37, 107, 202);
    glBegin(GL_POLYGON);
    glVertex2f(0, 25);
    glVertex2f(0, -100);
    glVertex2f(35, -100);
    glVertex2f(65, 25);
    glEnd();

    // Right Trouser
    glBegin(GL_POLYGON);
    glVertex2f(35, 25);
    glVertex2f(65, -100);
    glVertex2f(100, -100);
    glVertex2f(100, 25);
    glEnd();

    glPopMatrix();
}
void drawKidSmile(GLfloat tx, GLfloat ty, GLfloat scale)
{
    glPushMatrix();


    glTranslatef(tx, ty + 0.1, 0); // Move the smile 0.1 units up
    glScalef(scale * 0.5, scale * 0.5, 1); // Adjust the scale in the x and y direction to make it smaller

    // Draw the smile
    drawArc(0, 0, 1, 1, 20, 20, 20);

    glPopMatrix();
}




void drawKid(GLfloat tx, GLfloat ty,
             GLfloat scale,
             GLfloat shirt_r, GLfloat shirt_g, GLfloat shirt_b)
{
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(scale, scale, 1.0); // Set the scale factor to 1 in the z-direction to prevent distortion

    drawSemiCircle(0, -35, .6, 1,
                   203, 166, 108,
                   20, -90, 90);

    // Face
    drawCircle(0, 0,
               232, 190, 123,
               1, 1,
               24);

    // Left Eye
    drawCircle(-8, 0,
               250, 250, 250,
               1, 1,
               4);
    drawCircle(-6, 0,
               10, 10, 10,
               1, 1,
               2);

    // Right Eye
    drawCircle(8, 0,
               250, 250, 250,
               1, 1,
               4);
    drawCircle(10, 0,
               10, 10, 10,
               1, 1,
               2);

    // Nose
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(0, -7); // Adjust the position and size of the nose as needed
    glEnd();
    glLineWidth(1);

    // Cap
    drawSemiCircle(0, 10, 1, 1,
                   37, 107, 202,
                   24, -90, 90);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(20, 14);
    glVertex2f(40, 16);
    glEnd();
    glLineWidth(1);

    // Hands
    drawCircle(-42, -82,
               232, 190, 123,
               1, 1,
               10);
    drawCircle(38, -82,
               232, 190, 123,
               1, 1,
               10);

    // Shirt and Trousers
    drawKidsShirtAndTrousers(-32, -125,
                             .6, .5,
                             shirt_r, shirt_g, shirt_b);

    // Left Shoe
    drawSemiCircle(-21, -178,
                   1.2, 1,
                   20, 20, 20,
                   10,
                   -90, 90);

    // Right Shoe
    drawSemiCircle(18, -178,
                   1.2, 1,
                   20, 20, 20,
                   10,
                   -90, 90);

    // Smile
    drawKidSmile(0, -12, 1); // Adjust the smile position and size as needed

    glPopMatrix();
}




void kindergarten()
{
    glPushMatrix();
    glTranslatef(0.96, -0.5, 0);
    drawKid(-0.6, -0.26, 0.001, 255, 0, 0); // Adjust the position and scaling factor as per your scene requirements
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, -0.5, 0);
    drawKid(0.0 + trans_x_kid1, -0.26, 0.001, 80, 50, 20);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.8, -0.5, 0);
    drawKid(-0.2 + trans_x_kid2, -0.26, 0.001, 255, 255, 0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, -0.4, 0);
    drawKid(0.2 + trans_x_kid3, -0.26, 0.001, 255, 50, 0);
    glPopMatrix();
}
void drawWoman1()
{
    glPushMatrix();
    glTranslatef(0.7, -0.8, 0);
    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(-0.57, -0.3, 0);
    glScalef(1.0 / 1600.0, 1.0 / 1000.0, 1);
    // Neck
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(203, 166, 108); // Darker Skin
    glVertex2f(507, 380);
    glVertex2f(507, 360);
    glVertex2f(513, 380);
    glVertex2f(513, 360);
    glEnd();
    glLineWidth(1);

    // Face
    drawCircle(510, 407,
               232, 190, 123, // Lighter Skin
               1, 1,
               30);

    // Hair
    drawSemiCircle(510, 420, 1, .6,
                   60, 60, 60,
                   35, -90, 90);

    drawSemiCircle(485, 400, .4, 1,
                   60, 60, 60,
                   35, -180, 0);

    // Left Eye
    drawCircle(505, 410,
               250, 250, 250,
               1, 1,
               5);

    drawCircle(508, 408,
               10, 10, 10,
               1, 1,
               2.5);

    // Right Eye
    drawCircle(530, 410,
               250, 250, 250,
               1, 1,
               5);

    drawCircle(532, 408,
               10, 10, 10,
               1, 1,
               2.5);

    // Smile
    drawArc(514, 388, .5, .3,
            20, 20, 20);

    // Nose
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(518, 405);
    glVertex2f(522, 398);
    glVertex2f(522, 398);
    glVertex2f(518, 395);
    glEnd();
    glLineWidth(1);

    // Arms
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(232, 190, 123); // Lighter Skin
    glVertex2f(470, 340);
    glVertex2f(470, 240);
    glVertex2f(475, 340);
    glVertex2f(475, 240);
    glVertex2f(480, 340);
    glVertex2f(480, 240);

    glVertex2f(540, 340);
    glVertex2f(540, 240);
    glVertex2f(545, 340);
    glVertex2f(545, 240);
    glVertex2f(550, 340);
    glVertex2f(550, 240);
    glEnd();
    glLineWidth(1);

    // Top
    glBegin(GL_POLYGON);
    glColor3ub(229, 49, 49);
    glVertex2f(460, 370);
    glVertex2f(560, 370);
    glVertex2f(540, 300);
    glVertex2f(480, 300);
    glEnd();

    // Skirt
    glBegin(GL_POLYGON);
    glColor3ub(229, 49, 49);
    glVertex2f(480, 300);
    glVertex2f(540, 300);
    glVertex2f(560, 180);
    glVertex2f(460, 180);
    glEnd();

    // Ribbon
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(37, 107, 202);
    glVertex2f(480, 300);
    glVertex2f(540, 300);
    glEnd();
    glLineWidth(1);

    // Legs
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(232, 190, 123); // Lighter Skin
    glVertex2f(490, 180);
    glVertex2f(490, 150);
    glVertex2f(495, 180);
    glVertex2f(495, 150);

    glVertex2f(525, 180);
    glVertex2f(525, 150);
    glVertex2f(530, 180);
    glVertex2f(530, 150);
    glEnd();
    glLineWidth(1);

    glPopMatrix();
}
void drawWoman2()
{
    glPushMatrix();

    // Translate and scale the coordinates to the new range (-1 to 1)
    glTranslatef(0.85, -1.1, 0);
    glScalef(-1.0 / 1600.0, 1.0 / 1000.0, 1);

    // Neck
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(203, 166, 108); // Darker Skin
    glVertex2f(507, 380);
    glVertex2f(507, 360);
    glVertex2f(513, 380);
    glVertex2f(513, 360);
    glEnd();
    glLineWidth(1);

    // Face
    drawCircle(510, 407,
               232, 190, 123, // Lighter Skin
               1, 1,
               30);

    // Hair
    drawSemiCircle(510, 420, 1, .6,
                   20,20,20,
                   35, -90, 90);

    drawSemiCircle(485, 400, .4, 1,
                   20,20,20,
                   35, -180, 0);

    // Left Eye
    drawCircle(505, 410,
               250, 250, 250,
               1, 1,
               5);

    drawCircle(508, 408,
               10, 10, 10,
               1, 1,
               2.5);

    // Right Eye
    drawCircle(530, 410,
               250, 250, 250,
               1, 1,
               5);

    drawCircle(532, 408,
               10, 10, 10,
               1, 1,
               2.5);

    // Smile
    drawArc(514, 388, .5, .3,
            20, 20, 20);

    // Nose
    //glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(518, 405);
    glVertex2f(522, 398);
    glVertex2f(522, 398);
    glVertex2f(518, 395);
    glEnd();
    //glLineWidth(1);

    // Arms
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(232, 190, 123); // Lighter Skin
    glVertex2f(470, 340);
    glVertex2f(470, 240);
    glVertex2f(475, 340);
    glVertex2f(475, 240);
    glVertex2f(480, 340);
    glVertex2f(480, 240);

    glVertex2f(540, 340);
    glVertex2f(540, 240);
    glVertex2f(545, 340);
    glVertex2f(545, 240);
    glVertex2f(550, 340);
    glVertex2f(550, 240);
    glEnd();
    glLineWidth(1);

    // Top
    glBegin(GL_POLYGON);
    glColor3ub(229, 49, 49);
    glVertex2f(460, 370);
    glVertex2f(560, 370);
    glVertex2f(540, 300);
    glVertex2f(480, 300);
    glEnd();

    // Skirt
    glBegin(GL_POLYGON);
    glColor3ub(229, 49, 49);
    glVertex2f(480, 300);
    glVertex2f(540, 300);
    glVertex2f(560, 180);
    glVertex2f(460, 180);
    glEnd();

    // Ribbon
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(37, 107, 202);
    glVertex2f(480, 300);
    glVertex2f(540, 300);
    glEnd();
    glLineWidth(1);

    // Legs
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(232, 190, 123); // Lighter Skin
    glVertex2f(490, 180);
    glVertex2f(490, 150);
    glVertex2f(495, 180);
    glVertex2f(495, 150);

    glVertex2f(525, 180);
    glVertex2f(525, 150);
    glVertex2f(530, 180);
    glVertex2f(530, 150);
    glEnd();
    glLineWidth(1);

    glPopMatrix();
}
void daySky()
{
    //GL_QUADS
    glBegin(GL_QUADS);
    glColor3ub(84, 153, 199); //up left corner
    glVertex2f(-1.1f, 1.0f);
    glColor3ub(135, 206, 235); //up right corner
    glVertex2f(1.1f, 1.0f);
    glColor3ub(251, 252, 252); //color mixing
    glVertex2f(1.1f, -0.1f);
    glColor3ub(251, 252, 252); //color mixing
    glVertex2f(-1.1f, -0.4f);



    glEnd();
}
GLfloat positionCloud1 = 0.4f;


void updateCloud1(int value)
{

    if(positionCloud1 <-1.0)
        positionCloud1 = 1.0f;

    positionCloud1 -= speed;

    glutPostRedisplay();


    glutTimerFunc(100, updateCloud1, 0);
}
void cloud1()
{

    glPushMatrix();
    glTranslatef(-positionCloud1,0.0f,0.0f);


    //circle-1
    int jeight;
    GLfloat p8=.34f;
    GLfloat q8=.8f;
    GLfloat radius8 =.08f;
    int triangleAmount8 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi8 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p8, q8); // center of circle
    for(jeight = 0; jeight <= triangleAmount8; jeight++)
    {
        glVertex2f(
            p8 + (radius8 * cos(jeight *  twicePi8 / triangleAmount8)),
            q8 + (radius8 * sin(jeight * twicePi8 / triangleAmount8))
        );
    }
    glEnd();

    //circle-2
    int jnine;

    GLfloat p9=.41f;
    GLfloat q9=.87f;
    GLfloat radius9 =.07f;
    int triangleAmount9 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi9 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p9, q9); // center of circle
    for(jnine = 0; jnine <= triangleAmount9; jnine++)
    {
        glVertex2f(
            p9 + (radius9 * cos(jnine *  twicePi9 / triangleAmount9)),
            q9 + (radius9 * sin(jnine * twicePi9 / triangleAmount9))
        );
    }
    glEnd();

    //circle-3
    int jten;

    GLfloat p10=.30f;
    GLfloat q10=.87f;
    GLfloat radius10 =.08f;
    int triangleAmount10 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi10 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p10, q10); // center of circle
    for(jten = 0; jten <= triangleAmount10; jten++)
    {
        glVertex2f(
            p10 + (radius10 * cos(jten *  twicePi10 / triangleAmount10)),
            q10 + (radius10* sin(jten * twicePi10 / triangleAmount10))
        );
    }
    glEnd();

    //circle-4
    int jeleven;

    GLfloat p11=.45f;
    GLfloat q11=.8f;
    GLfloat radius11 =.08f;
    int triangleAmount11 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi11 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p11, q11); // center of circle
    for(jeleven = 0; jeleven <= triangleAmount11; jeleven++)
    {
        glVertex2f(
            p11 + (radius11 * cos(jeleven *  twicePi11 / triangleAmount11)),
            q11 + (radius11* sin(jeleven * twicePi11 / triangleAmount11))
        );
    }
    glEnd();

    glPopMatrix();
}


GLfloat positionCloud2 = 0.5f;
//GLfloat speed = 0.1f;

void updateCloud2(int value)
{

    if(positionCloud2 <-1.5)
        positionCloud2 = 1.0f;

    positionCloud2 -= speed;

    glutPostRedisplay();


    glutTimerFunc(100, updateCloud2, 0);
}


void cloud2()
{

    glPushMatrix();
    glTranslatef(-positionCloud2, 0.0f, 0.0f);

    //circle-1
    int j;

    GLfloat p=-.5f;
    GLfloat q=.77f;
    GLfloat radius1 =.09f;
    int triangleAmount1 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p, q); // center of circle
    for(j = 0; j <= triangleAmount1; j++)
    {
        glVertex2f(
            p + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
            q + (radius1 * sin(j * twicePi1 / triangleAmount1))
        );
    }
    glEnd();

    //circle-2
    int jj;

    GLfloat p2=-.4f;
    GLfloat q2=.77f;
    GLfloat radius2 =.09f;
    int triangleAmount2 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p2, q2); // center of circle
    for(jj = 0; jj <= triangleAmount1; jj++)
    {
        glVertex2f(
            p2 + (radius2 * cos(jj *  twicePi2 / triangleAmount2)),
            q2 + (radius2 * sin(jj * twicePi2 / triangleAmount2))
        );
    }
    glEnd();
    //circle-3
    int jjj;

    GLfloat p3=-.3f;
    GLfloat q3=.77f;
    GLfloat radius3 =.09f;
    int triangleAmount3 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi3 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p3, q3); // center of circle
    for(jjj = 0; jjj <= triangleAmount1; jjj++)
    {
        glVertex2f(
            p3 + (radius3 * cos(jjj *  twicePi3 / triangleAmount3)),
            q3 + (radius3 * sin(jjj * twicePi3 / triangleAmount3))
        );
    }
    glEnd();



    //circle-4
    int jfour;

    GLfloat p4=-.2f;
    GLfloat q4=.77f;
    GLfloat radius4 =.09f;
    int triangleAmount4 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi4 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p4, q4); // center of circle
    for(jfour = 0; jfour <= triangleAmount4; jfour++)
    {
        glVertex2f(
            p4 + (radius4 * cos(jfour *  twicePi4 / triangleAmount4)),
            q4 + (radius4 * sin(jfour * twicePi4 / triangleAmount4))
        );
    }
    glEnd();

    //circle-5
    int jfive;

    GLfloat p5=-.25f;
    GLfloat q5=.82f;
    GLfloat radius5 =.09f;
    int triangleAmount5 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi5 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p5, q5); // center of circle
    for(jfive = 0; jfive <= triangleAmount5; jfive++)
    {
        glVertex2f(
            p5 + (radius5 * cos(jfive *  twicePi5 / triangleAmount5)),
            q5 + (radius5 * sin(jfive * twicePi5 / triangleAmount5))
        );
    }
    glEnd();

    //circle-6
    int jsix;

    GLfloat p6=-.35f;
    GLfloat q6=.86f;
    GLfloat radius6 =.09f;
    int triangleAmount6 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi6 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p6, q6); // center of circle
    for(jsix = 0; jsix <= triangleAmount6; jsix++)
    {
        glVertex2f(
            p6 + (radius6 * cos(jsix *  twicePi6 / triangleAmount6)),
            q6 + (radius6 * sin(jsix * twicePi6 / triangleAmount6))
        );
    }
    glEnd();

    //circle-7
    int jsvn;

    GLfloat p7=-.45f;
    GLfloat q7=.82f;
    GLfloat radius7 =.09f;
    int triangleAmount7 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi7 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(253, 254, 254);
    glVertex2f(p7, q7); // center of circle
    for(jsvn = 0; jsvn <= triangleAmount7; jsvn++)
    {
        glVertex2f(
            p7 + (radius6 * cos(jsvn *  twicePi7 / triangleAmount7)),
            q7 + (radius6 * sin(jsvn * twicePi7 / triangleAmount7))
        );
    }
    glEnd();

    glPopMatrix();
}

void dayBeach()
{
    //GL_QUADS
    glBegin(GL_QUADS);
    glColor3ub(194, 178, 128);
    glVertex2f(-1.0f, -0.3f); //top left
    glColor3ub(194, 178, 128);
    glVertex2f(1.0f, -0.08f); //top right
    glColor3ub(246, 221, 204);
    glVertex2f(1.0f, -1.0f); //down right
    glColor3ub(246, 221, 204);
    glVertex2f(-1.0f, -1.0f); //down left



    glEnd();
}


//Horse
void horse()
{
    glPushMatrix();
    glTranslatef(0.0f,0.17, 0.0f);
    glScalef(0.7f,1.3f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(92, 65, 45);
    glVertex2f(-0.038f, -0.48f);
    glVertex2f(-0.038f, -0.487f);
    glVertex2f(-0.027f, -0.494f);
    glVertex2f(-0.005f, -0.494f);
    glVertex2f(-0.005f, -0.49f);
    glVertex2f(-0.023f, -0.48f);
    glVertex2f(-0.038f, -0.48f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, -0.44f);
    glVertex2f(-0.06f, -0.44f);
    glVertex2f(-0.07f, -0.458f);
    glVertex2f(-0.069f, -0.464f);
    glVertex2f(-0.06f, -0.464f);
    glVertex2f(-0.05f, -0.46f);
    glVertex2f(-0.05f, -0.44f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.162f, -0.452f);
    glVertex2f(-0.17f, -0.46f);
    glVertex2f(-0.17f, -0.47f);
    glVertex2f(-0.15f, -0.483f);
    glVertex2f(-0.14f, -0.483f);
    glVertex2f(-0.14f, -0.47f);
    glVertex2f(-0.15f, -0.452f);
    glVertex2f(-0.162f, -0.452f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.212f, -0.472f);
    glVertex2f(-0.212f, -0.49f);
    glVertex2f(-0.200f, -0.492f);
    glVertex2f(-0.177f, -0.49f);
    glVertex2f(-0.192f, -0.472f);
    glVertex2f(-0.212f, -0.472f);
    glEnd();


    //leg
    glBegin(GL_POLYGON);
    glColor3ub(140, 63, 4);
    glVertex2f(-0.05f, -0.44f);
    glVertex2f(-0.05f, -0.46f);
    glVertex2f(-0.00f, -0.42f);
    glVertex2f(-0.002f, -0.4f);
    glVertex2f(-0.02f, -0.36f);
    glVertex2f(-0.03f, -0.4f);
    glVertex2f(-0.02f, -0.416f);
    glVertex2f(-0.05f, -0.44f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(140, 63, 4);
    glVertex2f(-0.038f, -0.48f);
    glVertex2f(-0.023f, -0.48f);
    glVertex2f(-0.023f, -0.4654f);
    glVertex2f(-0.022f, -0.46f);
    glVertex2f(-0.03f, -0.42f);
    glVertex2f(-0.02f, -0.38f);
    glVertex2f(-0.06f, -0.38f);
    glVertex2f(-0.06f, -0.41f);
    glVertex2f(-0.05f, -0.42f);
    glVertex2f(-0.045f, -0.45f);
    glVertex2f(-0.038f, -0.48f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(140, 63, 4);
    glVertex2f(-0.162f, -0.452f);
    glVertex2f(-0.15f, -0.452f);
    glVertex2f(-0.155f, -0.4458f);
    glVertex2f(-0.158f, -0.39f);
    glVertex2f(-0.18f, -0.38f);
    glVertex2f(-0.167f, -0.44f);
    glVertex2f(-0.162f, -0.452f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(140, 63, 4);
    glVertex2f(-0.212f, -0.472f);
    glVertex2f(-0.192f, -0.472f);
    glVertex2f(-0.205f, -0.455f);
    glVertex2f(-0.205f, -0.430f);
    glVertex2f(-0.175f, -0.42f);
    glVertex2f(-0.17f, -0.41f);
    glVertex2f(-0.16f, -0.39f);
    glVertex2f(-0.16f, -0.38f);
    glVertex2f(-0.215f, -0.38f);
    glVertex2f(-0.21f, -0.4f);
    glVertex2f(-0.2f, -0.41f);
    glVertex2f(-0.225f, -0.424f);
    glVertex2f(-0.225f, -0.44f);
    glVertex2f(-0.225f, -0.455f);
    glVertex2f(-0.212f, -0.472f);
    glEnd();


    //Body
    glBegin(GL_POLYGON);
    glColor3ub(140, 63, 4);
    glVertex2f(-0.215f, -0.38f);
    glVertex2f(-0.20f, -0.34f);
    glVertex2f(-0.18f, -0.32f);
    glVertex2f(-0.15f, -0.32f);
    glVertex2f(-0.1f, -0.33f);
    glVertex2f(-0.06f, -0.32f);
    glVertex2f(-0.01f, -0.384f);
    glVertex2f(-0.02f, -0.38f);
    glVertex2f(-0.08f, -0.41f);
    glVertex2f(-0.1f, -0.42f);
    glVertex2f(-0.12f, -0.42f);
    glVertex2f(-0.13f, -0.41f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(140, 63, 4);
    glVertex2f(-0.06f, -0.32f);
    glVertex2f(-0.02f, -0.23f);
    glVertex2f(0.00f, -0.24f);
    glVertex2f(0.03f, -0.32f);
    glVertex2f(0.02f, -0.34f);
    glVertex2f(0.01f, -0.3f);
    glVertex2f(-0.02f, -0.38f);


    glEnd();


    //Tail
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(101, 42, 11);
    glVertex2f(-0.19f, -0.34f);
    glVertex2f(-0.22f, -0.33f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(101, 42, 11);
    glVertex2f(-0.22f, -0.33f);
    glVertex2f(-0.25f, -0.37f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(101, 42, 11);
    glVertex2f(-0.22f, -0.33f);
    glVertex2f(-0.25f, -0.36f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(101, 42, 11);
    glVertex2f(-0.22f, -0.33f);
    glVertex2f(-0.25f, -0.38f);
    glEnd();

    //Eye
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.01f, -0.27f);
    glVertex2f(0.0f, -0.28f);
    glEnd();

    //Hair
    glBegin(GL_LINES);
    glColor3ub(101, 42, 11);
    glVertex2f(-0.01f, -0.24f);
    glVertex2f(-0.05f, -0.32f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(101, 42, 11);
    glVertex2f(-0.01f, -0.24f);
    glVertex2f(-0.05f, -0.33f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(101, 42, 11);
    glVertex2f(-0.01f, -0.24f);
    glVertex2f(-0.05f, -0.31f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(101, 42, 11);
    glVertex2f(-0.01f, -0.233f);
    glVertex2f(-0.05f, -0.3f);
    glEnd();

    //man
    glBegin(GL_POLYGON);
    glColor3ub(195, 53, 38);
    glVertex2f(-0.145f, -0.32f);
    glVertex2f(-0.145f, -0.37f);
    glVertex2f(-0.08f, -0.37f);
    glVertex2f(-0.08f, -0.32f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(200, 93, 120);
    glVertex2f(-0.095f, -0.32f);
    glVertex2f(-0.08f, -0.37f);
    glVertex2f(-0.11f, -0.41f);
    glVertex2f(-0.1f, -0.41f);
    glVertex2f(-0.13f, -0.41f);
    glVertex2f(-0.1f, -0.39f);
    glVertex2f(-0.145f, -0.32f);
    glVertex2f(-0.145f, -0.3f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 110, 40);
    glVertex2f(-0.095f, -0.32f);
    glVertex2f(-0.145f, -0.3f);
    glVertex2f(-0.14f, -0.28f);
    glVertex2f(-0.12f, -0.24f);
    glVertex2f(-0.11f, -0.25f);
    glVertex2f(-0.1f, -0.28f);


    glEnd();

    //Hand
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.12f, -0.25f);
    glVertex2f(-0.09f, -0.3f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.095f, -0.3f);
    glVertex2f(-0.06f, -0.3f);
    glEnd();

    //Man Hair
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.12f, -0.24f);
    glVertex2f(-0.135f, -0.22f);
    glVertex2f(-0.13f, -0.2f);
    glVertex2f(-0.11f, -0.2f);


    glEnd();

    //Man Face
    glBegin(GL_POLYGON);
    glColor3ub(250, 200, 170);
    glVertex2f(-0.12f, -0.24f);
    glVertex2f(-0.11f, -0.2f);
    glVertex2f(-0.09f, -0.2f);
    glVertex2f(-0.09f, -0.22f);
    glVertex2f(-0.08f, -0.23f);
    glVertex2f(-0.09f, -0.21f);
    glVertex2f(-0.1f, -0.26f);


    glEnd();


    //cap
    glBegin(GL_POLYGON);
    glColor3ub(250, 20, 55);
    glVertex2f(-0.13f, -0.2f);
    glVertex2f(-0.11f, -0.2f);
    glVertex2f(-0.09f, -0.2f);
    glVertex2f(-0.07f, -0.18f);
    glVertex2f(-0.09f, -0.2f);
    glVertex2f(-0.105f, -0.18f);
    glVertex2f(-0.12f, -0.18f);


    glEnd();

    glPopMatrix();
}
void dayRiver()
{
    glBegin(GL_QUADS);
    glColor3ub(214, 234, 248);
    glVertex2f(-1.0f, -0.3f); //down left
    glColor3ub(36, 113, 163);
    glVertex2f(-1.0f, 0.2f); //top left
    glColor3ub(36, 113, 163);
    glVertex2f(1.0f, 0.2f); //top right
    glColor3ub(214, 234, 248);
    glVertex2f(1.0f, -0.08f); //down right

    glEnd();
}
void play()
{


    // Scale factor for the entire scene
    float scale = 0.01;
    float yOffset = -0.15;

    // MAN LEFT
    // man head
    glTranslatef(0.0, yOffset, 0.0);

    glColor3f(1, 0.76, 0.41);
    sun(1.5 * scale, 1.5 * scale, -0.6, -0.405);

// LEFT man chest
    glBegin(GL_QUADS);
    glColor3f(1, 0.76, 0.41);
    glVertex3f(-0.63, -0.42, 0);
    glVertex3f(-0.57, -0.42, 0.0);
    glVertex3f(-0.57, -0.48, 0);
    glVertex3f(-0.63, -0.48, 0.0);
    glEnd();
// LEFT man left arms
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0);
    glVertex3f(-0.62, -0.44, 0);
    glVertex3f(-0.62, -0.48, 0.0);
    glEnd();
// LEFT man right arms
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0);
    glVertex3f(-0.58, -0.44, 0);
    glVertex3f(-0.58, -0.48, 0.0);
    glEnd();
// LEFT man pent
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0);
    glVertex3f(-0.62, -0.48, 0);
    glVertex3f(-0.58, -0.48, 0.0);
    glVertex3f(-0.58, -0.55, 0);
    glVertex3f(-0.62, -0.55, 0.0);
    glEnd();
// LEFT man legs
    glBegin(GL_QUADS);
    glColor3f(1, 0.76, 0.41);
    glVertex3f(-0.615, -0.55, 0);
    glVertex3f(-0.585, -0.55, 0.0);
    glVertex3f(-0.585, -0.58, 0);
    glVertex3f(-0.615, -0.58, 0.0);
    glEnd();
// LEFT man leg divider
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0);
    glVertex3f(-0.60, -0.52, 0);
    glVertex3f(-0.60, -0.58, 0.0);
    glEnd();


    // MAN middle
// middle man head
    glColor3f(1, 0.76, 0.41);
    sun(1.5 * scale, 1.5 * scale, -0.3, -0.275);

// middle man chest
    glBegin(GL_QUADS);
    glColor3f(1, 0.76, 0.41);
    glVertex3f(-0.33, -0.29, 0);
    glVertex3f(-0.27, -0.29, 0.0);
    glVertex3f(-0.27, -0.34, 0);
    glVertex3f(-0.33, -0.34, 0.0);
    glEnd();
// middle man left arms
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0);
    glVertex3f(-0.32, -0.31, 0);
    glVertex3f(-0.32, -0.34, 0.0);
    glEnd();
// middle man right arms
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0);
    glVertex3f(-0.28, -0.31, 0);
    glVertex3f(-0.28, -0.34, 0.0);
    glEnd();
// middle man pent
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0);
    glVertex3f(-0.32, -0.34, 0);
    glVertex3f(-0.28, -0.34, 0.0);
    glVertex3f(-0.28, -0.40, 0);
    glVertex3f(-0.32, -0.40, 0.0);
    glEnd();
// middle man legs
    glBegin(GL_QUADS);
    glColor3f(1, 0.76, 0.41);
    glVertex3f(-0.315, -0.40, 0);
    glVertex3f(-0.285, -0.40, 0.0);
    glVertex3f(-0.285, -0.43, 0);
    glVertex3f(-0.315, -0.43, 0.0);
    glEnd();
// middle man leg divider
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0);
    glVertex3f(-0.30, -0.38, 0);
    glVertex3f(-0.30, -0.43, 0.0);
    glEnd();


    // MAN Right
// Right man head
    glColor3f(1, 0.76, 0.41);
    sun(1.5 * scale, 1.5 * scale, 0.3, -0.275);

// Right man chest
    glBegin(GL_QUADS);
    glColor3f(1, 0.76, 0.41);
    glVertex3f(0.27, -0.29, 0);
    glVertex3f(0.33, -0.29, 0.0);
    glVertex3f(0.33, -0.34, 0);
    glVertex3f(0.27, -0.34, 0.0);
    glEnd();
// Right man left arms
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0);
    glVertex3f(0.28, -0.31, 0);
    glVertex3f(0.28, -0.34, 0.0);
    glEnd();
// Right man right arms
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0);
    glVertex3f(0.32, -0.31, 0);
    glVertex3f(0.32, -0.34, 0.0);
    glEnd();
// Right man pent
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.28, -0.34, 0);
    glVertex3f(0.32, -0.34, 0.0);
    glVertex3f(0.32, -0.40, 0);
    glVertex3f(0.28, -0.40, 0.0);
    glEnd();
// Right man legs
    glBegin(GL_QUADS);
    glColor3f(1, 0.76, 0.41);
    glVertex3f(0.285, -0.40, 0);
    glVertex3f(0.315, -0.40, 0.0);
    glVertex3f(0.315, -0.43, 0);
    glVertex3f(0.285, -0.43, 0.0);
    glEnd();
// Right man leg divider
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0);
    glVertex3f(0.30, -0.38, 0);
    glVertex3f(0.30, -0.43, 0.0);
    glEnd();
    glTranslatef(0.0, -yOffset, 0.0);

// Football
    glColor3f(0, 0.0, 0.0);
    sun(1.5 * scale, 2.0 * scale, currentX, currentY - 0.1 + yOffset);




}
void chair1()
{


//Chair3 Umbrella
    glBegin(GL_TRIANGLES);
    glColor3ub(199, 0, 57);
    glVertex2f(0.25f + 0.7f + 0.05f + 0.06f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.1f + 0.7f + 0.05f + 0.06f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.175f + 0.7f + 0.05f + 0.06f, 0.025f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glEnd();

//Chair3 Umbrella Stand
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(0.17875f + 0.7f + 0.05f + 0.06f, -0.225f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.17125f + 0.7f + 0.05f + 0.06f, -0.225f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.17125f + 0.7f + 0.05f + 0.06f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glVertex2f(0.17875f + 0.7f + 0.05f + 0.06f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f + 0.1f);
    glEnd();




//Chair
    glBegin(GL_QUADS);
    glColor3ub(115, 147, 179);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glEnd();

//Chair left label
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glEnd();

//Chair back label
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.725f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glEnd();

//Chair relaxer
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.725f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.675f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.68f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.635f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glEnd();

//Chair legs - left front
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.365f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.365f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.825f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.825f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glEnd();

//Chair legs - right front
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.415f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.415f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.8f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.8f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glEnd();

//Chair legs - right back
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.645f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.645f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.775f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.7f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glEnd();

//Chair legs - left back
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.825f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.58f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.825f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glVertex2f((0.58f + 1.05f + 0.1f) * 0.5f + 0.06f, (-0.75f - 1.0f - 0.1f + 0.2f) * 0.5f + 0.04f + 0.1f);
    glEnd();

//Chair2 Umbrella Stand
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(0.17875f + 0.7f + 0.05f + 0.04f, -0.225f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.17125f + 0.7f + 0.05f + 0.04f, -0.225f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.17125f + 0.7f + 0.05f + 0.04f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.17875f + 0.7f + 0.05f + 0.04f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f);
    glEnd();



//chair 2
    glBegin(GL_QUADS);
    glColor3ub(115, 147, 179);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glEnd();

//chair 2 left label
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glEnd();

//chair 2 back label
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.725f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glEnd();

//chair 2 relaxer
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.725f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.675f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.68f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.635f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glEnd();

//chair 2 legs - left front
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.365f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.365f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.825f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.35f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.825f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glEnd();

//chair 2 legs - right front
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.415f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.415f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.8f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.4f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.8f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glEnd();

//chair 2 legs - right back
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.645f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.645f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.775f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.625f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.7f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glEnd();

//chair 2 legs - left back
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.6f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.825f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.58f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.825f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glVertex2f((0.58f + 1.05f + 0.1f) * 0.5f + 0.04f, (-0.75f -1.0f - 0.1f + 0.2f) * 0.5f + 0.04f);
    glEnd();


//chair1 Umbrella
    glBegin(GL_TRIANGLES);
    glColor3ub(144, 12, 63);
    glVertex2f(0.25f + 0.7f + 0.05f - 0.02f + 0.02f, -0.05f - 0.7f - 0.05f);
    glVertex2f(0.1f + 0.7f + 0.05f - 0.02f + 0.02f, -0.05f - 0.7f - 0.05f);
    glVertex2f(0.175f + 0.7f + 0.05f - 0.02f + 0.02f, 0.025f - 0.7f - 0.05f);
    glEnd();

//Chair2 Umbrella
    glBegin(GL_TRIANGLES);
    glColor3ub(88, 24, 69 );
    glVertex2f(0.25f + 0.7f + 0.05f + 0.04f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.1f + 0.7f + 0.05f + 0.04f, -0.05f - 0.7f - 0.05f + 0.2f - 0.06f);
    glVertex2f(0.175f + 0.7f + 0.05f + 0.04f, 0.025f - 0.7f - 0.05f + 0.2f - 0.06f);
    glEnd();



//chair1 Umbrella Stand
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(0.17875f + 0.7f + 0.05f - 0.02f + 0.02f, -0.225f - 0.7f - 0.05f);
    glVertex2f(0.17125f + 0.7f + 0.05f - 0.02f + 0.02f, -0.225f - 0.7f - 0.05f);
    glVertex2f(0.17125f + 0.7f + 0.05f - 0.02f + 0.02f, -0.05f - 0.7f - 0.05f);
    glVertex2f(0.17875f + 0.7f + 0.05f - 0.02f + 0.02f, -0.05f - 0.7f - 0.05f);
    glEnd();
//chair1
    glBegin(GL_QUADS);
    glColor3ub(115, 147, 179);
    glVertex2f((0.65f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.4f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.35f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glEnd();

//chair1 left label
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f - 0.04f + 0.04f) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.35f + 1.05f + 0.1f ) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.35f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glEnd();

//chair1 back label
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f ) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.65f + 1.05f + 0.1f ) * 0.5f, (-0.725f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glEnd();

//chair1 relaxer
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.65f + 1.05f + 0.1f ) * 0.5f, (-0.725f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.625f + 1.05f + 0.1f ) * 0.5f, (-0.675f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.68f + 1.05f + 0.1f ) * 0.5f, (-0.635f - 1.0f - 0.1f) * 0.5f);
    glEnd();

//chair1 legs - left front
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.35f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.365f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.365f + 1.05f + 0.1f ) * 0.5f, (-0.825f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.35f + 1.05f + 0.1f ) * 0.5f, (-0.825f - 1.0f - 0.1f) * 0.5f);
    glEnd();

//chair1 legs - right front
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.4f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.415f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.415f + 1.05f + 0.1f ) * 0.5f, (-0.8f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.4f + 1.05f + 0.1f ) * 0.5f, (-0.8f - 1.0f - 0.1f) * 0.5f);
    glEnd();

//chair1 legs - right back
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.645f + 1.05f + 0.1f ) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.645f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.625f + 1.05f + 0.1f ) * 0.5f, (-0.775f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.625f + 1.05f + 0.1f ) * 0.5f, (-0.7f - 1.0f - 0.1f) * 0.5f);
    glEnd();

//chair1 legs - left back
    glBegin(GL_QUADS);
    glColor3ub(114, 73, 53);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.6f + 1.05f + 0.1f ) * 0.5f, (-0.825f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.58f + 1.05f + 0.1f ) * 0.5f, (-0.825f - 1.0f - 0.1f) * 0.5f);
    glVertex2f((0.58f + 1.05f + 0.1f ) * 0.5f, (-0.75f - 1.0f - 0.1f) * 0.5f);
    glEnd();



}

void photographer()
{


    glPushMatrix();
    glTranslatef(0.2f, -0.3f, 0.0f);
    glScalef(0.5, 0.5, 1.0);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(55,55,0);
    glVertex2f(0.653f, -0.283f);
    glVertex2f(0.644f, -0.271f);
    glVertex2f(0.647f, -0.259f);
    glVertex2f(0.684f, -0.243f);
    glVertex2f(0.711f, -0.275f);
    glEnd();



    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(55,55,0);
    glVertex2f(0.840f, -0.243f);
    glVertex2f(0.840f, -0.235f);
    glVertex2f(0.849f, -0.219f);
    glVertex2f(0.853f, -0.188f);
    glVertex2f(0.851f, -0.176f);
    glVertex2f(0.864f, -0.215f);
    glVertex2f(0.864f, -0.243f);
    glVertex2f(0.860f, -0.259f);
    glVertex2f(0.856f, -0.271f);
    glVertex2f(0.847f, -0.287f);
    glVertex2f(0.827f, -0.283f);
    glVertex2f(0.827f, -0.267f);
    glVertex2f(0.833f, -0.251f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,74,111);
    glVertex2f(0.776f, -0.172f);
    glVertex2f(0.776f, -0.211f);
    glVertex2f(0.778f, -0.243f);
    glVertex2f(0.780f, -0.271f);
    glVertex2f(0.789f, -0.283f);
    glVertex2f(0.798f, -0.287f);
    glVertex2f(0.816f, -0.251f);
    glVertex2f(0.831f, -0.235f);
    glVertex2f(0.842f, -0.227f);
    glVertex2f(0.853f, -0.196f);
    glVertex2f(0.853f, -0.18f);
    glVertex2f(0.849f, -0.172f);
    glVertex2f(0.840f, -0.172f);
    glVertex2f(0.831f, -0.188f);
    glVertex2f(0.804f, -0.211f);
    glVertex2f(0.804f, -0.188f);
    glVertex2f(0.811f, -0.148f);
    glVertex2f(0.820f, -0.125f);
    glVertex2f(0.829f, -0.097f);
    glVertex2f(0.793f, -0.073f);
    glVertex2f(0.771f, -0.061f);
    glVertex2f(0.716f, -0.061f);
    glVertex2f(0.707f, -0.073f);
    glVertex2f(0.696f, -0.105f);
    glVertex2f(0.691f, -0.148f);
    glVertex2f(0.684f, -0.204f);
    glVertex2f(0.682f, -0.239f);
    glVertex2f(0.709f, -0.279f);
    glVertex2f(0.720f, -0.128f);
    glVertex2f(0.731f, -0.097f);
    glVertex2f(0.784f, -0.117f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,9);
    glVertex2f(0.798f, 0.034f);
    glVertex2f(0.784f, -0.022f);
    glVertex2f(0.776f, -0.034f);
    glVertex2f(0.767f, -0.057f);
    glVertex2f(0.827f, -0.093f);
    glVertex2f(0.829f, -0.026f);
    glVertex2f(0.831f, 0.026f);
    glVertex2f(0.822f, 0.085f);
    glVertex2f(0.807f, 0.128f);
    glVertex2f(0.798f, 0.053f);
    glVertex2f(0.831f, 0.006f);
    glVertex2f(0.836f, -0.022f);
    glEnd();



    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,9);
    glVertex2f(0.764f, 0.105f);
    glVertex2f(0.773f, 0.121f);
    glVertex2f(0.780f, 0.144f);
    glVertex2f(0.787f, 0.144f);
    glVertex2f(0.778f, 0.101f);
    glVertex2f(0.780f, 0.069f);
    glVertex2f(0.773f, 0.042f);
    glVertex2f(0.767f, 0.065f);
    glVertex2f(0.760f, 0.081f);
    glVertex2f(0.753f, 0.105f);
    glVertex2f(0.764f, 0.109f);
    glVertex2f(0.760f, 0.109f);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
    glVertex2f(0.833f, 0.038f);
    glVertex2f(0.836f, 0.014f);
    glVertex2f(0.836f, -0.002f);
    glVertex2f(0.836f, -0.014f);
    glVertex2f(0.798f, 0.053f);
    glVertex2f(0.796f, 0.042f);
    glVertex2f(0.836f, -0.022f);
    glVertex2f(0.836f, -0.089f);
    glVertex2f(0.831f, -0.077f);
    glVertex2f(0.844f, -0.081f);
    glVertex2f(0.856f, -0.061f);
    glVertex2f(0.862f, -0.045f);
    glVertex2f(0.862f, -0.026f);
    glVertex2f(0.862f, 0.002f);
    glVertex2f(0.856f, 0.018f);
    glVertex2f(0.853f, 0.042f);
    glVertex2f(0.829f, 0.117f);
    glVertex2f(0.816f, 0.148f);
    glVertex2f(0.791f, 0.16f);
    glVertex2f(0.784f, 0.148f);
    glVertex2f(0.807f, 0.128f);
    glVertex2f(0.816f, 0.113f);
    glVertex2f(0.822f, 0.097f);
    glVertex2f(0.829f, 0.077f);
    glVertex2f(0.833f, 0.057f);
    glEnd();



    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(128,128,0);
    glVertex2f(0.753f, 0.042f);
    glVertex2f(0.749f, 0.065f);
    glVertex2f(0.744f, 0.069f);
    glVertex2f(0.716f, -0.014f);
    glVertex2f(0.702f, -0.01f);
    glVertex2f(0.680f, 0.101f);
    glVertex2f(0.698f, 0.121f);
    glVertex2f(0.713f, 0.042f);
    glVertex2f(0.733f, 0.109f);
    glVertex2f(0.753f, 0.097f);
    glVertex2f(0.773f, 0.026f);
    glVertex2f(0.780f, 0.065f);
    glVertex2f(0.780f, 0.101f);
    glVertex2f(0.811f, 0.117f);
    glVertex2f(0.787f, -0.01f);
    glVertex2f(0.780f, -0.026f);
    glVertex2f(0.769f, -0.026f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232,190,172);
    glVertex2f(0.738f, 0.164f);
    glVertex2f(0.733f, 0.132f);
    glVertex2f(0.736f, 0.109f);
    glVertex2f(0.740f, 0.105f);
    glVertex2f(0.742f, 0.093f);
    glVertex2f(0.749f, 0.093f);
    glVertex2f(0.751f, 0.093f);
    glVertex2f(0.753f, 0.097f);
    glVertex2f(0.760f, 0.101f);
    glVertex2f(0.762f, 0.101f);
    glVertex2f(0.762f, 0.101f);
    glVertex2f(0.764f, 0.101f);
    glVertex2f(0.764f, 0.105f);
    glVertex2f(0.773f, 0.121f);
    glVertex2f(0.782f, 0.136f);
    glVertex2f(0.782f, 0.164f);
    glVertex2f(0.789f, 0.211f);
    glVertex2f(0.787f, 0.231f);
    glVertex2f(0.787f, 0.251f);
    glVertex2f(0.780f, 0.263f);
    glVertex2f(0.771f, 0.271f);
    glVertex2f(0.762f, 0.275f);
    glVertex2f(0.742f, 0.279f);
    glVertex2f(0.722f, 0.271f);
    glVertex2f(0.713f, 0.259f);
    glVertex2f(0.702f, 0.223f);
    glVertex2f(0.693f, 0.2f);
    glVertex2f(0.711f, 0.184f);
    glVertex2f(0.722f, 0.196f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(128,128,0);
    glVertex2f(0.793f, 0.093f);
    glVertex2f(0.787f, 0.093f);
    glVertex2f(0.784f, 0.097f);
    glVertex2f(0.776f, 0.113f);
    glVertex2f(0.787f, 0.156f);
    glVertex2f(0.796f, 0.148f);
    glVertex2f(0.813f, 0.132f);
    glVertex2f(0.811f, 0.117f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(128,128,0);
    glVertex2f(0.758f, 0.085f);
    glVertex2f(0.760f, 0.057f);
    glVertex2f(0.756f, 0.053f);
    glVertex2f(0.736f, 0.089f);
    glVertex2f(0.749f, 0.136f);
    glVertex2f(0.753f, 0.109f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78,78,78);
    glVertex2f(0.678f, 0.188f);
    glVertex2f(0.671f, 0.18f);
    glVertex2f(0.731f, 0.184f);
    glVertex2f(0.731f, 0.109f);
    glVertex2f(0.676f, 0.113f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(206,206,206);
    glVertex2f(0.698f, 0.152f);
    glVertex2f(0.704f, 0.156f);
    glVertex2f(0.711f, 0.148f);
    glVertex2f(0.707f, 0.128f);
    glVertex2f(0.700f, 0.125f);
    glVertex2f(0.696f, 0.132f);
    glVertex2f(0.693f, 0.152f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(22,22,22);
    glVertex2f(0.750f, 0.194f);
    glVertex2f(0.757f, 0.23f);
    glVertex2f(0.735f, 0.202f);
    glVertex2f(0.735f, 0.23f);
    glVertex2f(0.724f, 0.214f);
    glVertex2f(0.721f, 0.198f);
    glVertex2f(0.719f, 0.206f);
    glVertex2f(0.717f, 0.174f);
    glVertex2f(0.710f, 0.206f);
    glVertex2f(0.699f, 0.194f);
    glVertex2f(0.697f, 0.202f);
    glVertex2f(0.715f, 0.261f);
    glVertex2f(0.732f, 0.281f);
    glVertex2f(0.757f, 0.285f);
    glVertex2f(0.775f, 0.277f);
    glVertex2f(0.790f, 0.253f);
    glVertex2f(0.788f, 0.186f);
    glVertex2f(0.781f, 0.143f);
    glVertex2f(0.777f, 0.163f);
    glVertex2f(0.779f, 0.182f);
    glVertex2f(0.781f, 0.206f);
    glVertex2f(0.775f, 0.222f);
    glVertex2f(0.772f, 0.214f);
    glVertex2f(0.766f, 0.202f);
    glVertex2f(0.766f, 0.222f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(198,134,66);
    glVertex2f(0.732f, 0.139f);
    glVertex2f(0.739f, 0.143f);
    glVertex2f(0.735f, 0.123f);
    glVertex2f(0.730f, 0.115f);
    glVertex2f(0.730f, 0.103f);
    glVertex2f(0.741f, 0.107f);
    glVertex2f(0.746f, 0.119f);
    glVertex2f(0.755f, 0.127f);
    glVertex2f(0.750f, 0.127f);
    glVertex2f(0.746f, 0.159f);
    glVertex2f(0.741f, 0.17f);
    glVertex2f(0.730f, 0.186f);
    glVertex2f(0.721f, 0.186f);
    glVertex2f(0.721f, 0.174f);
    glVertex2f(0.732f, 0.163f);
    glVertex2f(0.737f, 0.159f);
    glVertex2f(0.726f, 0.151f);
    glVertex2f(0.719f, 0.143f);
    glVertex2f(0.724f, 0.127f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
    glVertex2f(0.830f, 0.008f);
    glVertex2f(0.830f, -0.011f);
    glVertex2f(0.832f, -0.023f);
    glVertex2f(0.832f, -0.047f);
    glVertex2f(0.830f, -0.079f);
    glVertex2f(0.830f, -0.102f);
    glVertex2f(0.830f, -0.094f);
    glVertex2f(0.839f, -0.079f);
    glVertex2f(0.837f, 0.04f);
    glVertex2f(0.815f, 0.123f);
    glVertex2f(0.812f, 0.111f);
    glVertex2f(0.821f, 0.076f);
    glVertex2f(0.826f, 0.068f);
    glVertex2f(0.830f, 0.044f);
    glVertex2f(0.830f, 0.032f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232,190,172);
    glVertex2f(0.710f, 0.206f);
    glVertex2f(0.732f, 0.226f);
    glVertex2f(0.719f, 0.178f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(232,190,172);
    glVertex2f(0.715f, 0.174f);
    glVertex2f(0.715f, 0.202f);
    glVertex2f(0.724f, 0.174f);
    glVertex2f(0.715f, 0.174f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(53,53,0);
    glVertex2f(0.870f, -0.213f);
    glVertex2f(0.864f, -0.233f);
    glVertex2f(0.850f, -0.177f);
    glVertex2f(0.872f, -0.185f);
    glEnd();
    glPopMatrix();
}
void Tower()        ///TOWER STRUCTURE
{
    glTranslatef(0.9, -0.3, 0.0);
    glScalef(0.4, 0.4, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(27, 38, 49);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2f(-0.15f, 0.28f);
    glVertex2f(-0.18f, 0.28f);
    glVertex2f(-0.18f, 0.1f);
    glVertex2f(-0.15f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2f(0.15f, 0.28f);
    glVertex2f(0.18f, 0.28f);
    glVertex2f(0.18f, 0.1f);
    glVertex2f(0.15f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 38, 49);
    glVertex2f(-0.2f, 0.32f);
    glVertex2f(0.2f, 0.32f);
    glVertex2f(0.2f, 0.28f);
    glVertex2f(-0.2f, 0.28f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(27, 38, 49);
    glVertex2f(-0.2, 0.32);
    glVertex2f(0.0, 0.52);
    glVertex2f(0.2, 0.32);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.0, 0.65);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(188, 0, 0);
    glVertex2f(0.0, 0.6);
    glVertex2f(0.05, 0.625);
    glVertex2f(0.0, 0.65);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.3, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.3, -0.5);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(-0.2, -0.1);
    glVertex2f(0.28, -0.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.2, -0.1);
    glVertex2f(-0.28, -0.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(0.08, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.08, -0.1);
    glVertex2f(-0.08, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();

    glTranslatef(0.0, -0.05, 0.0);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();

    glTranslatef(0.0, -0.05, 0.0);   ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);   ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();

    glLoadIdentity();
}



void bamboo()
{

    glPushMatrix();
    glTranslatef(-0.1, 0.1, 0.0);

    // water balloon
    glColor3f(1, 0, 0);
    sun(0.05, 0.02, 0.8, -0.3);
    glColor3f(0.0, 0.0, 0.1);
    sun(0.05, 0.02, 0.8, -0.28);
    glColor3f(0.0, 1, 0.0);
    sun(0.05, 0.02, 0.8, -0.26);
    glColor3f(1.0, 0, 1.0);
    sun(0.05, 0.02, 0.8, -0.24);
    glColor3f(0.4, 0.55, 0.05);
    sun(0.05, 0.02, 0.8, -0.22);
    glColor3f(1, 0.0, 0);
    sun(0.05, 0.02, 0.8, -0.20);
    glColor3f(0.4, 0.55, 0.05);
    sun(0.02, 0.005, 0.8, -0.20);

    // water balloon Bamboo
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.19, 0.12);
    glVertex3f(0.795, -0.16, 0);
    glVertex3f(0.805, -0.16, 0.0);
    glVertex3f(0.805, -0.207, 0);
    glVertex3f(0.795, -0.207, 0.0);
    glEnd();
    glPopMatrix();

}

void ship()
{
    glPushMatrix();
    //glTranslated(0.00, 0.0, 0.00);
    glScaled(0.015, 0.015, 1.0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(3.5, 5.5);
    glVertex2f(3.5, 8.5);
    glVertex2f(19.5, 8.5);
    glVertex2f(19.5, 5.5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1,5.5);
    glVertex2f(4,1);
    glVertex2f(19,1);
    glVertex2f(21.5,5.5);
    glEnd();
    glColor3f(0.7,0.4,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(4,5.5);
    glVertex2f(4,8);
    glVertex2f(5,8);
    glVertex2f(5,5.5);
    glEnd();
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(7,7.5);
    glVertex2f(7,8);
    glVertex2f(10,8);
    glVertex2f(10,7.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(11.5,7.5);
    glVertex2f(11.5,8);
    glVertex2f(15,8);
    glVertex2f(15,7.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(16,7.5);
    glVertex2f(16,8);
    glVertex2f(19,8);
    glVertex2f(19,7.5);
    glEnd();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(4.5,8.5);
    glVertex2f(4.5,10);
    glVertex2f(18.5,10);
    glVertex2f(18.5,8.5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(5.5,10);
    glVertex2f(5.5,12.9);
    glVertex2f(7,12.9);
    glVertex2f(7,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(5.5,12.9);
    glVertex2f(5.5,13.5);
    glVertex2f(7,13.5);
    glVertex2f(7,12.9);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(8.5,10);
    glVertex2f(8.5,12.9);
    glVertex2f(10,12.9);
    glVertex2f(10,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(8.5,12.9);
    glVertex2f(8.5,13.5);
    glVertex2f(10,13.5);
    glVertex2f(10,12.9);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(11.5,10);
    glVertex2f(11.5,12.9);
    glVertex2f(13,12.9);
    glVertex2f(13,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(11.5,12.9);
    glVertex2f(11.5,13.5);
    glVertex2f(13,13.5);
    glVertex2f(13,12.9);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(14.5,10);
    glVertex2f(14.5,12.9);
    glVertex2f(16,12.9);
    glVertex2f(16,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(14.5,12.9);
    glVertex2f(14.5,13.5);
    glVertex2f(16,13.5);
    glVertex2f(16,12.9);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1.5,5.5);
    glVertex2f(1.5,6.5);
    glVertex2f(2,6.2);
    glVertex2f(3,6.2);
    glVertex2f(3.5,6.5);
    glVertex2f(3.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(3.5,5.5);
    glVertex2f(3.5,6.5);
    glVertex2f(4,6.2);
    glVertex2f(5,6.2);
    glVertex2f(5.5,6.5);
    glVertex2f(5.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.5,5.5);
    glVertex2f(5.5,6.5);
    glVertex2f(6,6.2);
    glVertex2f(7,6.2);
    glVertex2f(7.5,6.5);
    glVertex2f(7.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(7.5,5.5);
    glVertex2f(7.5,6.5);
    glVertex2f(8,6.2);
    glVertex2f(9,6.2);
    glVertex2f(9.5,6.5);
    glVertex2f(9.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(9.5,5.5);
    glVertex2f(9.5,6.5);
    glVertex2f(10,6.2);
    glVertex2f(11,6.2);
    glVertex2f(11.5,6.5);
    glVertex2f(11.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(11.5,5.5);
    glVertex2f(11.5,6.5);
    glVertex2f(12,6.2);
    glVertex2f(13,6.2);
    glVertex2f(13.5,6.5);
    glVertex2f(13.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(13.5,5.5);
    glVertex2f(13.5,6.5);
    glVertex2f(14,6.2);
    glVertex2f(15,6.2);
    glVertex2f(15.5,6.5);
    glVertex2f(15.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(15.5,5.5);
    glVertex2f(15.5,6.5);
    glVertex2f(16,6.2);
    glVertex2f(17,6.2);
    glVertex2f(17.5,6.5);
    glVertex2f(17.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(17.5,5.5);
    glVertex2f(17.5,6.5);
    glVertex2f(18,6.2);
    glVertex2f(19,6.2);
    glVertex2f(19.5,6.5);
    glVertex2f(19.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(19.5,5.5);
    glVertex2f(19.5,6.5);
    glVertex2f(20,6.2);
    glVertex2f(20.5,6.2);
    glVertex2f(21,6.5);
    glVertex2f(21,5.5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(4.5,3.5);
    glVertex2f(4.5,4.5);
    glVertex2f(5.5,4.5);
    glVertex2f(5.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(7,3.5);
    glVertex2f(7,4.5);
    glVertex2f(8,4.5);
    glVertex2f(8,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(9.5,3.5);
    glVertex2f(9.5,4.5);
    glVertex2f(10.5,4.5);
    glVertex2f(10.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(12,3.5);
    glVertex2f(12,4.5);
    glVertex2f(13,4.5);
    glVertex2f(13,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(14.5,3.5);
    glVertex2f(14.5,4.5);
    glVertex2f(15.5,4.5);
    glVertex2f(15.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(17,3.5);
    glVertex2f(17,4.5);
    glVertex2f(18,4.5);
    glVertex2f(18,3.5);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(5,10);
    glVertex2f(5,11);
    glVertex2f(5.5,10.8);
    glVertex2f(6.5,10.8);
    glVertex2f(7,11);
    glVertex2f(7,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(7,10);
    glVertex2f(7,11);
    glVertex2f(7.5,10.8);
    glVertex2f(8.5,10.8);
    glVertex2f(9,11);
    glVertex2f(9,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(9,10);
    glVertex2f(9,11);
    glVertex2f(9.5,10.8);
    glVertex2f(10.5,10.8);
    glVertex2f(11,11);
    glVertex2f(11,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(11,10);
    glVertex2f(11,11);
    glVertex2f(11.5,10.8);
    glVertex2f(12.5,10.8);
    glVertex2f(13,11);
    glVertex2f(13,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(13,10);
    glVertex2f(13,11);
    glVertex2f(13.5,10.8);
    glVertex2f(14.5,10.8);
    glVertex2f(15,11);
    glVertex2f(15,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(15,10);
    glVertex2f(15,11);
    glVertex2f(15.5,10.8);
    glVertex2f(16.5,10.8);
    glVertex2f(17,11);
    glVertex2f(17,10);
    glEnd();


    glPopMatrix();
}

float shipXPosition = 0.0f; // Initial position of the ship on the x-axis
float shipYPosition = 0.15f; // Initial position of the ship on the y-axis
float shipSpeed = 0.001f;


void day()
{

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);
    daySky();

    //sun
    glColor3ub(245, 176, 65);
    int j;
    GLfloat x=-0.8f;
    GLfloat y=0.9f;
    GLfloat radius =.1f;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(j = 0; j <= triangleAmount+1; j++)
    {
        glVertex2f(
            x + (radius * cos(j *  twicePi / triangleAmount)),
            y + (radius * sin(j * twicePi / triangleAmount))
        );
        glColor3ub(245, 249, 10);
    }
    glEnd();
    cloud1();
    cloud2();
    dayRiver();
    dayBeach();
    play();
    kindergarten();

    chair1();
    bamboo();
    bike1();
    bike2();
    photographer();
    horse();
    glPushMatrix();
    glTranslatef(_move, 0.0, 0.0);
    ship();
    glPopMatrix();

    Tower();

    glFlush();  // Render now
}
////////////////////////sylhet////////////////////
void sky22()
{
    quad(-1, 1,-1, 0.2,1.1520904873806, 0.2088036964438,1.1439065905304, 1.0026416909165,101, 196, 212);
}

void mountain()
{
    glBegin(GL_POLYGON);
    glColor3ub(79, 180, 40);
    glVertex2f(-1.0377136472168, -0.3201334071613);
    glVertex2f(-1.0277305385936, 0.3054747332291);
    glVertex2f(-0.631733896538, 0.2222821613686);
    glVertex2f(-0.4748733904288, -0.06);
    glColor3ub(34, 106, 6);
    glVertex2f(-0.3621899637102, 0.0958294521408);
    glVertex2f(-0.303062608993, -0.1316944189211);
    glVertex2f(-0.2041240771754, -0.3317803672218);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(88, 165, 71);
    glVertex2f(-0.4170970611381, -0.3284526643474);
    glVertex2f(-0.2748733904288, -0.0104807790948);
    glVertex2f(-0.1525446826219, 0.1390895895082);
    glVertex2f(-0.0211704233503, 0.1614734541473);
    glColor3ub(58, 108, 47);
    glVertex2f(0.1254135131839, -0.0217564665205);
    glVertex2f(0.2234857421872, -0.3201334071613);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(37, 107, 21);
    glVertex2f(0.0903776272105, -0.3201334071613);
    glVertex2f(0.1564216536046, -0.1288754970647);
    glVertex2f(0.2268134450616, 0.0825186406431);
    glVertex2f(0.3847543239753, 0.1361031574395);
    glVertex2f(0.4467706048167, 0.0712679547416);
    glColor3ub(21, 93, 5);
    glVertex2f(0.5116058075145, -0.1006862785004);
    glVertex2f(0.6028438698707, -0.333444218659);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(88, 165, 71);
    glVertex2f(0.4913658235777, -0.3284526643474);
    glVertex2f(0.5200625730838, -0.1627025593418);
    glVertex2f(0.5792599320688, -0.0273943102333);
    glVertex2f(0.6627425216102, 0.1390895895082);
    glColor3ub(58, 108, 47);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.9598143826865, -0.0358510758026);
    glVertex2f(0.9880036012508, -0.1345133407776);
    glVertex2f(1.0454283521682, -0.3234611100357);
    glEnd();
}
void mountain2()
{
    glPushMatrix();
    glTranslatef(-.75f, 0.2f, 0.0f); // Adjusted translation to fit within the range
    mountain();
    glPopMatrix();
}

void mountain3()
{
    glPushMatrix();
    glTranslatef(-.15f, 0.37f, 0.0f); // Adjusted translation to fit within the range
    glBegin(GL_POLYGON);
    glColor3ub(84, 124, 69);
    glVertex2f(-1.0377136472168, -0.3201334071613);
    glVertex2f(-1.0277305385936, 0.3054747332291);
    glVertex2f(-0.631733896538, 0.2222821613686);
    glVertex2f(-0.4748733904288, -0.06);
    glColor3ub(75, 163, 42);
    glVertex2f(-0.3621899637102, 0.0958294521408);
    glVertex2f(-0.303062608993, -0.1316944189211);
    glVertex2f(-0.2041240771754, -0.3317803672218);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80, 188, 39);
    glVertex2f(-0.4170970611381, -0.3284526643474);
    glVertex2f(-0.2748733904288, -0.0104807790948);
    glVertex2f(-0.1525446826219, 0.1390895895082);
    glVertex2f(-0.0211704233503, 0.1614734541473);
    glColor3ub(35, 111, 6);
    glVertex2f(0.1254135131839, -0.0217564665205);
    glVertex2f(0.2234857421872, -0.3201334071613);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(15, 184, 49);
    glVertex2f(0.0903776272105, -0.3201334071613);
    glVertex2f(0.1564216536046, -0.1288754970647);
    glVertex2f(0.2268134450616, 0.0825186406431);
    glVertex2f(0.3847543239753, 0.1361031574395);
    glVertex2f(0.4467706048167, 0.0712679547416);
    glColor3ub(32, 143, 54);
    glVertex2f(0.5116058075145, -0.1006862785004);
    glVertex2f(0.6028438698707, -0.333444218659);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(73, 200, 45);
    glVertex2f(0.4913658235777, -0.3284526643474);
    glVertex2f(0.5200625730838, -0.1627025593418);
    glVertex2f(0.5792599320688, -0.0273943102333);
    glVertex2f(0.6627425216102, 0.1390895895082);
    glColor3ub(41, 132, 20);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.9598143826865, -0.0358510758026);
    glVertex2f(0.9880036012508, -0.1345133407776);
    glVertex2f(1.0454283521682, -0.3234611100357);
    glEnd();
    glPopMatrix();
}
void mounntain4()
{
    glPushMatrix();
    glTranslatef(.05f, -0.25f, 0.0f); // Adjusted translation to fit within the range
    mountain3();
    glPopMatrix();
}
void mountain5()
{
    glPushMatrix();
    glTranslatef(.2f, 0.15f, 0.0f); // Adjusted translation to fit within the range
    glBegin(GL_POLYGON);
    glColor3ub(73, 200, 45);
    glVertex2f(0.4913658235777, -0.3284526643474);
    glVertex2f(0.5200625730838, -0.1627025593418);
    glVertex2f(0.5792599320688, -0.0273943102333);
    glVertex2f(0.6627425216102, 0.1390895895082);
    glColor3ub(41, 132, 20);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.9598143826865, -0.0358510758026);
    glVertex2f(0.9880036012508, -0.1345133407776);
    glVertex2f(1.0454283521682, -0.3234611100357);
    glEnd();
    glPopMatrix();
}
void bottommountain()
{
    glPushMatrix();
    glTranslatef(-0.6,-0.87,0.0);
    glScalef(0.5,0.5,1.0);
    mountain3();
    mountain2();
    mounntain4();
    mountain5();
    mountain();
    glPopMatrix();

}
void bm1()
{
    glPushMatrix();
    glTranslatef(0.95,0.0,0.0);
    bottommountain();
    glPopMatrix();
}

void bussyl()
{
    // Center of the window
    float centerX = -0.9f;
    float centerY = -0.6f;

    // Bus dimensions
    float busWidth = 2.6f; // Increased width by 1 unit
    float busHeight = 2.4f;
    glPushMatrix();
    // Translate and scale the coordinates to center the bus within the window
    glTranslatef(centerX, centerY, 0);
    glScalef((1.0 / 350.0) * 2.0, (1.0 / 400.0)* 1.5, 1.0);

    // Draw bus body
    glBegin(GL_QUADS);
    glColor3ub(255, 81, 76);
    glVertex2f(10, 55);  // Lower-left corner
    glVertex2f(92, 55);  // Lower-right corner
    glVertex2f(92, 105); // Upper-right corner
    glVertex2f(10, 105); // Upper-left corner
    glEnd();

    // Draw front glass
    glBegin(GL_QUADS);
    glColor3ub(26, 26, 0);
    glVertex2f(90, 89);  // Lower-left corner
    glVertex2f(92, 89);  // Lower-right corner
    glVertex2f(92, 100); // Upper-right corner
    glVertex2f(90, 100); // Upper-left corner
    glEnd();



    buswindows();
    buswindows1();
    // Draw door
    wheels();
    glBegin(GL_QUADS);
    glColor3ub(230, 247, 255);
    glVertex2f(51, 55); // Lower-left corner
    glVertex2f(59, 55); // Lower-right corner
    glVertex2f(59, 95); // Upper-right corner
    glVertex2f(51, 95); // Upper-left corner
    glEnd();
    glPopMatrix();
}




void bm2()
{
    glPushMatrix();
    glTranslatef(0.1,0.2,0.0);
    bm1();
    glPopMatrix();
}
void bm3()
{
    glPushMatrix();
    glTranslatef(0.0,0.2,0.0);
    bottommountain();
    glPopMatrix();
}

void sylhetview()
{

    sky22();
//sun
    glColor3ub(245, 176, 65);
    int j;
    GLfloat x=-0.8f;
    GLfloat y=0.9f;
    GLfloat radius =.1f;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(j = 0; j <= triangleAmount+1; j++)
    {
        glVertex2f(
            x + (radius * cos(j *  twicePi / triangleAmount)),
            y + (radius * sin(j * twicePi / triangleAmount))
        );
        glColor3ub(245, 249, 10);
    }
    glEnd();
    road();
    glPushMatrix();
    glTranslatef(-_move, 0.4f, 0.0f); // Adjusted translation to fit within the range
    clouds();
    glPopMatrix();
    mountain3();
//mountain2();
//mounntain4();
    mountain5();

    glPushMatrix();
    glScalef(1.0,1.5,1.0);
    mountain3();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, 0.2f, 0.0f);
    glScalef(2.0,2.5,1.0);
    mountain();
    glPopMatrix();
    road();

    glPushMatrix();
    glTranslatef(busPositionX, 0.0f, 0.0f); // Adjusted translation to fit within the range
    bussyl();
    glPopMatrix();
    bm2();
    bm3();
    bm1();
    drawWoman1();
    drawWoman2();
    bottommountain();

    glPushMatrix();
    glTranslatef(-0.6, 0.2f, 0.0f); // Adjusted translation to fit within the range
    drawWoman1();
    drawWoman2();
    glPopMatrix();


    glutSwapBuffers();
}
//////////merge///////////
void coxsview()
{
    day();
}
void display3(int val)
{
    glutDisplayFunc(drawScene);
}

void drawScene4()
{
    sylhetview();
    glutTimerFunc(6400,display3,0);
    glutSwapBuffers();
}


void display2(int val)
{
    glutDisplayFunc(drawScene4);
}

void drawScene3()
{
    coxsview();
    glutTimerFunc(6400,display2,0);
    glutSwapBuffers();
}




void display1(int val)
{
    glutDisplayFunc(drawScene3);
}
void drawScene2()
{
    rangamati();
    glutTimerFunc(6400,display1,0);
    glutSwapBuffers();
}
void display(int val)
{
    glutDisplayFunc(drawScene2);
}
void drawScene()
{
    town();
    glutTimerFunc(6400,display,0);
    glutSwapBuffers();
}
void dis()
{
    glutDisplayFunc(drawScene);
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        busMoving = false; // Stop the bus
        break;
    case 's':
        busMoving = true; // Start the bus
        break;
    case 'q':
        boatMoving = false; // Stop the bus
        break;
    case 'w':
        boatMoving = true; // Start the bus
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800,400);
    glutInitWindowPosition(50, 50);

    glutCreateWindow("bus view");
    glutFullScreen();
    glutDisplayFunc(dis);
    myInit();

    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(100, updatebike1, 0);
    glutTimerFunc(100, updatebike2, 0);
    glutTimerFunc(100, updateCloud1, 0);
    glutTimerFunc(100, updateCloud2, 0);
    glutTimerFunc(100, updatecar, 0);
    glutTimerFunc(100, updateBall, 0);
    glutTimerFunc(20, updatewave, 0);
    glutTimerFunc(20, update1, 0);
    glutTimerFunc(20, updatebus, 0);
    glutTimerFunc(20, update3, 0);
    glutMainLoop();


    return 0;

}
