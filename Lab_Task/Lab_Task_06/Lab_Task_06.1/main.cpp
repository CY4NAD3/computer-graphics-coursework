#include <windows.h>
#include <GL/glut.h>

int color = 0;


void display(){
    if(color == 0){
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    }

    else{
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}


void toggleBg(int value){
    if(color == 0){
        color = 1;
    }

    else{
        color = 0;
    }

    glutPostRedisplay();

    glutTimerFunc(20, toggleBg, 0);
}


int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Background Color Change");

    glutDisplayFunc(display);

    glutTimerFunc(20, toggleBg, 0);

    glutMainLoop();

    return 0;
}
