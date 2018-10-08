#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

float x ;
float y ;
float movement_x = 0.5;
float movement_y = 0.5;

void cube1()
{
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
    glVertex2f(1,1);
    glVertex2f(1,3);
    glVertex2f(3,3);
    glVertex2f(3,1);
    glEnd();

}
void cube2()
{
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(4,4);
    glVertex2f(4,6);
    glVertex2f(6,6);
    glVertex2f(6,4);
    glEnd();

}
void control()
{
        x=movement_x;
        y=movement_y;

glPushMatrix();
glTranslatef(x,y,0);
cube1();
glPopMatrix();

cube2();
}


void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
control();
glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
switch(key) {
case 'a':
    movement_x--;
break;
case 's':
    movement_y--;
break;
case 'd':
    movement_x++;
break;
case 'w':
    movement_y++;
break;
default:
break;
}
glutPostRedisplay(); /* this redraws the scene without
waiting for the display callback so that any changes appear
instantly */
}

void init(void)
{
glClearColor (1, 1, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glutKeyboardFunc(keyboard);
gluOrtho2D(-10,10,-10,10);
glMatrixMode(GL_MODELVIEW);
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
