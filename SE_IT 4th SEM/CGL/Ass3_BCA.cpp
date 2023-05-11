// Problem Statement: Implement Bresenham circle drawing algorithm to draw any object.
// The object should be displayed in all the quadrants with respect to center and radius.

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int cx, cy, radius;

void simpleLine(int x1, int y1, int x2, int y2){
    float dx, dy, step, x, y, Xin, Yin;
    dx = abs(x2-x1);
    dy = abs(y2-y1);

    if(dx > dy) step = dx;
    else step = dy;

    Xin = dx / step;
    Yin = dy / step;

    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for(int i=0; i<step; i++){
        x += Xin;
        y += Yin;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

    glFlush();
}

void drawCirclePoints(int xc, int yc, int x, int y){
    glColor3f(1, 0, 1);
    glBegin(GL_POINTS);
    glVertex2i(xc+x, yc+y);
    glVertex2i(xc-x, yc+y);
    glVertex2i(xc+x, yc-y);
    glVertex2i(xc-x, yc-y);
    glVertex2i(xc+y, yc+x);
    glVertex2i(xc-y, yc+x);
    glVertex2i(xc+y, yc-x);
    glVertex2i(xc-y, yc-x);
    glEnd();
    glFlush();
}

void drawCricle(){
    int x=0, y=radius;
    int d = 3-2*radius;

    drawCirclePoints(cx, cy, x, y);

    while(y >= x){
        x++;

        if(d > 0){
            y--;
            d = d+4*(x-y)+10;
        }else{
            d = d + 4*x + 6;
        }

        drawCirclePoints(cx, cy, x, y);

    }

    glFlush();

}

void keyboardListen(unsigned char key, int x, int y){
    cout << "Radius entered is " << key << endl;
    cout << "Center of circle is " << cx << ", " << cy << endl;
    radius =  (key - '0') * 10;
    drawCricle();
}

void mouseListner(int button,int state,int x,int y){
    cout << "Mouse clicked cordinates are (" << x << ", " << y << ")" << endl;
    cout << "Enter the circle radius: " << endl;
    cx = x;
    cy = y;
    glutKeyboardFunc(keyboardListen);    
}

void primitives() {
    glColor3f(1, 0, 0);
    simpleLine(300, 0, 300, 600);
    simpleLine(0, 300, 600, 300);
    glutMouseFunc(mouseListner);
}

void initialize() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 600, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Assignment 3 - circle drawing algorithm");

    initialize();

    glutDisplayFunc(primitives);

    glutMainLoop();
    return 0;
}

// to run
//  g++ assign3.cpp -o App -lglut -lGLU -lGL && ./App












