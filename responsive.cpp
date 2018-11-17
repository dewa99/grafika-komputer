#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdio.h>

#define WINDOW_WIDTH 300 //pendefinisian ukuran width window saat dirun
#define WINDOW_HEIGHT 150 //pendefinisian ukuran height window saat dirun


int win_width, win_height; //inisialisasi variabel untuk proses responsive
float move_kotak[] = {0,0};
float move_kotak2[] = {0,0};
float kotak[] = {4,6,move_kotak[0],move_kotak[1]};
float kotak2[] = {1,3,move_kotak2[0],move_kotak2[1]};
float kotak3[] = {3,6,move_kotak2[0],move_kotak2[1]};
float dx,dy,dz;
float distance;
float velocity = 0.5f;
bool is_moving = true;

void cube1()
{   glPushMatrix();
    glScaled(10,10,0);
    glTranslatef(kotak2[2],kotak2[3],0);
    glColor3f(0,1,0);
    glBegin(GL_QUADS);
    glVertex2f(kotak2[0],kotak2[0]);
    glVertex2f(kotak2[0],kotak2[1]);
    glVertex2f(kotak2[1],kotak2[1]);
    glVertex2f(kotak2[1],kotak2[0]);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(kotak3[0],kotak3[0]);
    glVertex2f(kotak3[0],kotak3[1]);
    glVertex2f(kotak3[1],kotak3[1]);
    glVertex2f(kotak3[1],kotak3[0]);
    glEnd();
    glPopMatrix();

}
void cube2()
{
    glPushMatrix();
    glScaled(10,10,0);
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(kotak[0],kotak[0]);
    glVertex2f(kotak[0],kotak[1]);
    glVertex2f(kotak[1],kotak[1]);
    glVertex2f(kotak[1],kotak[0]);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(kotak[0],kotak[0]);
    glVertex2f(kotak[0],kotak[1]);
    glVertex2f(kotak[1],kotak[1]);
    glVertex2f(kotak[1],kotak[0]);
    glEnd();
    glPopMatrix();

}
void character()
{
    cube1();
    cube2();
}

void on_collision()
{
    dx = kotak[2] - kotak2[2];
    dy = kotak[3] - kotak2[3];
    distance = sqrt(dx*dx + dy*dy);


}

void anchor1()
{
    float ax,by,cx,dy,ex,ey;
    ax = kotak2[0]/2 + kotak2[1]/2 ;
    by = kotak2[1]/2 + kotak2[0]/2;
    cx = kotak2[0]/2 + kotak2[1]/2;
    dy = kotak2[1]/2 + kotak2[0]/2;

    ex = ax/2 + cx/2;
    ey = by/2 + dy/2;

    printf("%f%f", ex,ey);
}
void anchor2()
{
    float ax,by,cx,dy,ex,ey;
    ax = kotak[0]/2 + kotak[1]/2 ;
    by = kotak[1]/2 + kotak[0]/2;
    cx = kotak[0]/2 + kotak[1]/2;
    dy = kotak[1]/2 + kotak[0]/2;

    ex = ax/2 + cx/2;
    ey = by/2 + dy/2;

    printf("%f%f", ex,ey);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
cube1();
glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
switch(key) {
case 'a':
    kotak2[2]-=velocity;
break;
case 's':
    kotak2[3]-=velocity;
break;
case 'd':
    kotak2[2]+=velocity;
break;
case 'w':
    kotak2[3]+=velocity;
break;
default:
break;
}
glutPostRedisplay();
}

void on_resize(int w,int h)  //Method untuk responsivenya silahkan langsung di copas aja gpp
{
    win_width = w;
    win_height = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    display(); // refresh window.
}






int main(int argc, char * argv[]) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
glutInitWindowPosition(100, 100);
glutCreateWindow("Kubus");
glClearColor (1, 1, 0.0, 0.0);
glutKeyboardFunc(keyboard);
glutDisplayFunc(display);
glutReshapeFunc(on_resize); //method responsive di call di sini
glutMainLoop();
return 0;

}
