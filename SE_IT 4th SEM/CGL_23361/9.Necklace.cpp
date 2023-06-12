/*
Write a program in OpenGL on Linux Platform to draw
a design shown on Right using Bresenhem Circle
Drawing Algorithm. User should only give centre
coordinates and radius. Rest should be drawn
automatically. Use Mouse/Without Mouse to Plot the
Points. (necklace)
*/

#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int m_x, m_y;

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

void drawCircle(int cx, int cy, int radius){
    int x=0;
    int y=radius;

    int d = 3-2*radius;
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
    gluOrtho2D(0, 600, 600, 0);
}

void display(){
    glPointSize(3);
    glColor3f(0, 0, 0);
    drawCircle(m_x, m_y, 100);

    // down part
    drawCircle(m_x, m_y+120, 20);
    drawCircle(m_x, m_y+160, 20);
    drawCircle(m_x-40, m_y+115, 20);
    drawCircle(m_x+40, m_y+115, 20);


    // left part
    drawCircle(m_x-105, m_y-55, 20);
    drawCircle(m_x-135, m_y-80, 20);
    drawCircle(m_x-160, m_y-105, 20);

    // right part
    drawCircle(m_x+105, m_y-55, 20);
    drawCircle(m_x+135, m_y-80, 20);
    drawCircle(m_x+160, m_y-105, 20);
}

void mouse(int button, int state, int x, int y){
    cout << x <<  " " << y <<endl;
    drawCircle(x, y, 20);
}

int main(int argc, char** argv){

    m_x = 300;
    m_y = 300;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 12 - necklace");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}

