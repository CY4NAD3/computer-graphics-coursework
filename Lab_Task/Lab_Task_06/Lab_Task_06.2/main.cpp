#include <windows.h>
#include <GL/glut.h>
int objectIndex = 0;
void object1(){
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.2f, -0.5f);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(-0.5f, -0.2f);
    glEnd();
}
void object2(){
    glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);
        glVertex2f(0.2f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, -0.2f);
        glVertex2f(0.2f, -0.2f);
    glEnd();
}
void object3(){
    glColor3ub(0, 0, 255);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, 0.2f);
        glVertex2f(-0.2f, 0.2f);
        glVertex2f(-0.2f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
    glEnd();
}
void object4(){
    glColor3ub(255, 255, 0);
    glBegin(GL_QUADS);
        glVertex2f(0.2f, 0.2f);
        glVertex2f(0.5f, 0.2f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.2f, 0.5f);
    glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(objectIndex == 0){
        object1();
    }
    else if(objectIndex == 1){
        object2();
    }
    else if(objectIndex == 2){
        object3();
    }
    else if(objectIndex == 3){
        object4();
    }

    glutSwapBuffers();
}
void callObjects(int value){
    objectIndex = (objectIndex + 1) % 4;
    glutPostRedisplay();
    glutTimerFunc(20, callObjects, 0);
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Four Objects Animation");
    glutDisplayFunc(display);
    glutTimerFunc(20, callObjects, 0);
    glutMainLoop();
    return 0;
}
