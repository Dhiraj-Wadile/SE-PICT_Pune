//  Write a program in OpenGL on Linux Platform to draw a design shown on using
//  Bresenhem Circle Drawing Algorithm & DDA Line Drawing Algorithm. ( A Truck as
//  given in figure )


#include<GL/glut.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cx, cy, radius;

void displayPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void simpleLine(int x1, int y1, int x2, int y2)
{
    float dx, dy, x, y, step, Xin, Yin;

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    Xin = dx/step;
    Yin = dy/step;

    x = x1;
    y = y1;
    displayPoint(x, y);

    for(int i = 0; i < step; i++)
    {
        x += Xin;
        y += Yin;

        displayPoint(x, y);
    }
    glFlush();
}

void drawCirclePoints(int cx, int cy, int x, int y)
{
    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);
    glVertex2i(cx + x, cy + y);
    glVertex2i(cx - x, cy + y);
    glVertex2i(cx + x, cy - y);
    glVertex2i(cx - x, cy - y);

    glVertex2i(cx + y, cy + x);
    glVertex2i(cx - y, cy + x);
    glVertex2i(cx + y, cy - x);
    glVertex2i(cx - y, cy - x);
    glEnd();
    glFlush();
}

void drawCircle()
{
    int x = 0;
    int y = radius;
    int d = 3 - 2*radius;
    drawCirclePoints(cx, cy, x, y);
    while(y >= x)
    {
        x++;
        if(d >= 0)
        {
            y--;
            d += 4* (x - y) + 10;

        }
        else
        {
            d += 4*x + 6;
        }
        drawCirclePoints(cx, cy, x, y);
    }

}

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 1300, 800, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    cout <<"The radius of the circle is : "<<key<<endl;
    radius = (key - '0')*20;
    drawCircle();
}

void mouseListener(int button, int state, int x, int y)
{
    cout <<"The mouse clicked co-ordinates are : "<<x <<", "<<y<<endl;
    cx = x;
    cy = y;
    cout<<"Enter the radius of the circle : "<<endl;
    glutKeyboardFunc(keyboard);
}


void primitives(void)
{
    //  driver side
    glColor3f(0, 0, 0);
    simpleLine(450, 100, 450, 500);
    simpleLine(50, 500, 450, 500);

    simpleLine(50, 500, 50, 363);
    simpleLine(330, 100, 450,100);
    simpleLine(330, 100, 330, 233);
    simpleLine(330, 233, 197, 233);
    simpleLine(50, 363, 197, 233);


    //  back container
    glColor3f(0, 0, 1);
    simpleLine(470, 100, 1200, 100);
    simpleLine(470, 500, 1200, 500);
    simpleLine(1200, 100, 1200, 500);
    simpleLine(470, 100, 470, 500);


    //  window
    //  top
    simpleLine(197, 253, 330, 253);
    simpleLine(217, 273, 310, 273);

    //  bottom
    simpleLine(197, 386, 330, 386);
    simpleLine(217, 366, 310, 366);

    //  left
    simpleLine(197, 253, 197, 386);
    simpleLine(217, 273, 217, 366);

    //  right
    simpleLine(330, 253, 330, 386);
    simpleLine(310, 273, 310, 366);

    glutMouseFunc(mouseListener);

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1300, 800);
    glutCreateWindow("CGL Transport Service");

    initialize();
    glutDisplayFunc(primitives);
    glutMainLoop();
    return 0;
}
