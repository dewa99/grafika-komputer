#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(10);
    glColor3f(1,0,0);

    glBegin(GL_QUADS);
    glVertex2f(1,1);
    glVertex2f(1,3);
    glVertex2f(3,3);
    glVertex2f(3,1);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_QUADS);
    glVertex2f(1,1);
    glVertex2f(1,2);
    glVertex2f(2,2);
    glVertex2f(2,1);
    glEnd();
    glutSwapBuffers();
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Hello World");
    glClearColor( 1, 1, 1, 1.);
    gluOrtho2D(0 ,5  , 0 , 5);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
