/*
Write a program in OpenGL on Linux Platform to draw a design
shown on Right using Bresenhem Circle Drawing Algorithm.
User should only give centre coordinates and radius. Rest should
be drawn automatically. Use Mouse to Plot the Points
circle pattern 3
*/

#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

using namespace std;

void drawCirclePoints(int cx, int cy, int x, int y){
    glBegin(GL_POINTS);

    glVertex2i(cx+x, cy+y);
    glVertex2i(cx+x, cy-y);
    glVertex2i(cx-x, cy+y);
    glVertex2i(cx-x, cy-y);
    glVertex2i(cx+y, cy+x);
    glVertex2i(cx+y, cy-x);
    glVertex2i(cx-y, cy+x);
    glVertex2i(cx-y, cy-x);

    glEnd();
    glFlush();
}

void drawCircle(int cx, int cy, int r){
    int x=0, y=r;
    int d = 3-2*r;

    while(y>=x){
        x++;
        if(d > 0){
            y--;
            d += 4*(x-y) + 10;
        }else{
            d += 4*x + 6;
        }
        drawCirclePoints(cx, cy, x, y);
    }
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 300, -300, 300);
}

void display(){
    glColor3f(1, 0, 0);
    /*glBegin(GL_LINE_LOOP);
    glVertex2i(-300, 0);
    glVertex2i( 300, 0);
    glEnd();
    glFlush();
    glBegin(GL_LINE_LOOP);
    glVertex2i(0, -300);
    glVertex2i(0, 300);
    glEnd();
    glFlush();*/

    int radius = 100;
    int cx = 0, cy = 0;

    glColor3f(0, 0, 0);
    drawCircle(cx, cy, radius);
    drawCircle(cx, cy, radius/2);

    drawCircle(cx, cy+radius/2 ,50);
    drawCircle(cx+radius/2/sqrt(2), cy+radius/2/sqrt(2), 50);

    drawCircle(cx, cy-radius/2 ,50);
    drawCircle(cx+radius/2/sqrt(2), cy-radius/2/sqrt(2), 50);

    drawCircle(cx-radius/2/sqrt(2), cy+radius/2/sqrt(2), 50);
    drawCircle(cx-radius/2/sqrt(2), cy-radius/2/sqrt(2), 50);

    drawCircle(cx+radius/2, cy ,50);
    drawCircle(cx-radius/2, cy ,50);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 14 - circle pattern 3");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
