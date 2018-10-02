#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void cube3d(){
glColor3f(0,1,0);

//depan
glBegin(GL_POLYGON);

glVertex3f(-1,1,-1);
glVertex3f(1,1,-1);
glVertex3f(1,-1,-1);
glVertex3f(-1,-1,-1);


glEnd();

glColor3f(0,0,1);

//kanan
glBegin(GL_POLYGON);


glVertex3f(1,1,-1);
glVertex3f(1,-1,-1);
glVertex3f(1,-1,1);
glVertex3f(1,1,1);


glEnd();

glColor3f(1,1,0);

//belakang
glBegin(GL_POLYGON);

glVertex3f(-1,1,1);
glVertex3f(1,1,1);
glVertex3f(1,-1,1);
glVertex3f(-1,-1,1);

glEnd();


//kanan
glColor3f(1,0,1);
glBegin(GL_POLYGON);


glVertex3f(-1,1,-1);
glVertex3f(-1,-1,-1);
glVertex3f(-1,-1,1);
glVertex3f(-1,1,1);


glEnd();
}



void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glColor3f(1.0, 0, 0);
glRotated(45,1,1,1);
cube3d();
glFlush();

}

void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
glMatrixMode(GL_MODELVIEW);
glShadeModel (GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
}



int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(400, 400);
glutInitWindowPosition(100, 100);
glutCreateWindow("Kubus");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
