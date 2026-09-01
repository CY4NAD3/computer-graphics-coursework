#include <windows.h>
#include <GL/glut.h>
float leftX = 0.0f;
float rightX = 0.0f;
float upY = 0.0f;
float downY = 0.0f;
void objectLeft(){
    glPushMatrix();
    glTranslatef(leftX, 0.5f, 0.0f);
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();
}
void objectRight(){
    glPushMatrix();
    glTranslatef(rightX, 0.2f, 0.0f);
    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();
}
void objectUp(){
    glPushMatrix();
    glTranslatef(-0.5f, upY, 0.0f);
    glColor3ub(0, 0, 255);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glPopMatrix();
}
void objectDown(){
    glPushMatrix();
    glTranslatef(-0.2f, downY, 0.0f);
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
    objectLeft();
    objectRight();
    objectUp();
    objectDown();
    glutSwapBuffers();
}
void moveObjects(int value){
    leftX -= 0.01f;
    if(leftX < -1.2f){
        leftX = 1.2f;
    }

    rightX += 0.01f;
    if(rightX > 1.2f){
        rightX = -1.2f;
    }

    upY += 0.01f;
    if(upY > 1.2f){
        upY = -1.2f;
    }

    downY -= 0.01f;
    if(downY < -1.2f){
        downY = 1.2f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, moveObjects, 0);
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Four Objects Moving");
    glutDisplayFunc(display);
    glutTimerFunc(20, moveObjects, 0);
    glutMainLoop();
    return 0;
}
