/*
Write a Program in OpenGL on Linux Platform to draw a fractal patterns by using Koch
curves.
*/

#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

using namespace std;

#define RADIAN (3.14/180)

void kochs(int xa, int ya, int xb, int yb, int n){
    float xc = (2*xa+xb) / 3;
    float yc = (2*ya+yb) / 3;
    float xd = (2*xb+xa) / 3;
    float yd = (2*yb+ya) / 3;
    float midx = xc + ((xd-xc)*cos(RADIAN*60)) + ((yd-yc)*sin(RADIAN*60));
    float midy = yc - ((xd-xc)*sin(RADIAN*60)) + ((yd-yc)*cos(RADIAN*60));

    if(n>0){
        kochs(xa, ya, xc, yc, n-1);
        kochs(xc, yc, midx, midy, n-1);
        kochs(midx, midy, xd, yd, n-1);
        kochs(xd, yd, xb, yb, n-1);
    } else{
        glVertex2i(xa, ya);
        glVertex2i(xc, yc);
        glVertex2i(xc, yc);
        glVertex2i(midx, midy);
        glVertex2i(midx, midy);
        glVertex2i(xd, yd);
        glVertex2i(xd, yd);
        glVertex2i(xb, yb);
    }
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 600, 0);
}

void display(){
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    kochs(200, 200, 400, 200, 4);
    glColor3f(0, 1, 0);
    kochs(400, 200, 300, 370, 4);
    glColor3f(0, 0, 1);
    kochs(300, 370, 200, 200, 4);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 11 - koch curve (practice)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
