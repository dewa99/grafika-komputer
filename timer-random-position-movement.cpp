#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>

#include <stdlib.h>

float randomX = 0;


int randomY = 0;


float gerak[] = {0,0};
int geraks = 0;
float timerandom = 0;
int ortho[] = {-50,50,-50,50};


void kotak()
{
    glTranslated(-10,-60,0);
    glColor3b(0.5,0.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2d(0,5);
    glVertex2d(5,5);
    glVertex2d(5,0);
    glEnd();
}

void kotak2()
{
    glTranslated(gerak[0],gerak[1],0);
    glColor3b(0.5,0.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2d(0,5);
    glVertex2d(5,5);
    glVertex2d(5,0);
    glEnd();
}

void init()
{
    glClearColor(1,1,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(ortho[0],ortho[1],ortho[2],ortho[3]);
}

void timer(int a)
{
    if(geraks==-1){
        gerak[0] -=0.5;
    }
    else if(geraks==1){
        gerak[0] +=0.5;
    }
    else if(geraks==2){
        gerak[1] += 0.5;
    }
    else if(geraks==-2){
        gerak[1] -=0.5;
    }

    timerandom +=0.5;

    if(timerandom>10){
        timerandom = -30;
    }
    
    randomY +=1;

    glutPostRedisplay();
    glutTimerFunc(1000/60, timer , 0);
}

void logikaRandomPosition()
{
    if(randomY<=150){
    
            
    glPushMatrix();
    
    glTranslated(randomX,randomY,0);
    kotak();
    
    glPopMatrix();
    
    
    }
    else{
        randomY=0;
    }

    if(randomY>=150){
            
            
        randomX = rand()%50 + timerandom;
        
        
        
        printf("%f \n",randomX);

        
        if(randomX>80){
            randomX = -20;
        }
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    logikaRandomPosition();
    glPushMatrix();
    kotak2();
    glPopMatrix();

    glFlush();
}

void keyboard(unsigned char key,int x,int y)
{
    switch(key){
    case 'a':
            geraks = -1;
        break;
    case 'd':
            geraks = 1;
        break;
    case 'w':
            geraks = 2;
        break;
    case 's':
            geraks = -2;
        break;

    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(3,50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glClearColor(1,1,1,1);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(50, timer,0);
    glutMainLoop();

    return EXIT_SUCCESS;
}
