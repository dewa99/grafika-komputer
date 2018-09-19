#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); 
    glPointSize(10); //size point
    glColor3f(1,0,0); //warna format RGB

    //Quads 1
    glBegin(GL_QUADS);
    glVertex2f(1,1);//titik
    glVertex2f(1,3);
    glVertex2f(3,3);
    glVertex2f(3,1);
    glEnd();

    //Quads 2
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
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//inisialisasi mode display
    glutInitWindowPosition(0,0); //inisialisasi posisi pop up window
    glutInitWindowSize(500,500); //inisialisasi size pxl
    glutCreateWindow("Hello World"); 
    glClearColor( 1, 1, 1, 1.); // untuk mengatur warna belakang/background
    gluOrtho2D(0 ,5  , 0 , 5); //jumlah pixel dalam satu window size
    glutDisplayFunc(display); //fungsi memanggil method untuk ditampilkan
    glutMainLoop(); //untuk melooping program agar tidak langsung end
    return 0;
}
