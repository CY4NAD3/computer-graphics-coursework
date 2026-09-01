#include <windows.h>
#include <GL/glut.h>
float posA = -0.6f;
float posD = 0.6f;
float posW = 0.6f;
float posS = -0.6f;
bool moveA = false;
bool moveD = false;
bool moveW = false;
bool moveS = false;
void objectA(){
    glPushMatrix();
    glTranslatef(posA, 0.5f, 0.0f);
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();
}
void objectD(){
    glPushMatrix();
    glTranslatef(posD, 0.2f, 0.0f);
    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();
}
void objectW(){
    glPushMatrix();
    glTranslatef(-0.5f, posW, 0.0f);
    glColor3ub(0, 0, 255);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();
}
void objectS(){
    glPushMatrix();
    glTranslatef(-0.2f, posS, 0.0f);
    glColor3ub(255, 255, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    objectA();
    objectD();
    objectW();
    objectS();
    glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y){
    if(key == 'a' || key == 'A'){
        moveA = !moveA;
    }
    else if(key == 'd' || key == 'D'){
        moveD = !moveD;
    }
    else if(key == 'w' || key == 'W'){
        moveW = !moveW;
    }
    else if(key == 's' || key == 'S'){
        moveS = !moveS;
    }
}
void updateObjects(int value){
    if(moveA){
        posA -= 0.01f;
        if(posA < -1.2f){
            posA = 1.2f;
        }
    }

    if(moveD){
        posD += 0.01f;
        if(posD > 1.2f){
            posD = -1.2f;
        }
    }

    if(moveW){
        posW += 0.01f;
        if(posW > 1.2f){
            posW = -1.2f;
        }
    }

    if(moveS){
        posS -= 0.01f;
        if(posS < -1.2f){
            posS = 1.2f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, updateObjects, 0);
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("WASD Objects Moving");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(20, updateObjects, 0);
    glutMainLoop();
    return 0;
}
