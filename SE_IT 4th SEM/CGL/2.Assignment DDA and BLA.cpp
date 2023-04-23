
// Problem Statement: Implement DDA and Bresenham line drawing algorithm to draw: i) Simple
// Line ii) Dotted Line iii) Dashed Line iv) Solid line ;
// using mouse interface Divide the screen in four quadrants with center as (0, 0). The line should work
// for all the slopes positive as well as negative.

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void displayPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void SimpleLine(int x1, int y1, int x2, int y2)
{
    float dy, dx, step, x, y, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    Xin = dx / step;
    Yin = dy / step;

    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (int k = 0; k <= step; k++)
    {
        x += Xin;
        y += Yin;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
    glFlush();
}

void DottedLine(int x1, int y1, int x2, int y2)
{
    float dy, dx, step, x, y, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    Xin = dx / step;
    Yin = dy / step;

    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (int k = 0; k <= step; k++)
    {
        x += Xin;
        y += Yin;
        if (k % 5 == 0)
        {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }
    glFlush();
}

void DashedLine(int x1, int y1, int x2, int y2)
{
    float dy, dx, step, x, y, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    Xin = dx / step;
    Yin = dy / step;

    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    cout << step;

    for (int k = 0; k <= step; k++)
    {
        x += Xin;
        y += Yin;
        if (k % 10 != 0)
        {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }
    glFlush();
}

void bresenhams(int x1, int y1, int x2, int y2)
{
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (x2 < x1)
        incx = -1;
    incy = 1;
    if (y2 < y1)
        incy = -1;
    x = x1;
    y = y1;
    if (dx > dy)
    {
        displayPoint(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            displayPoint(x, y);
        }
    }
    else
    {
        displayPoint(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            displayPoint(x, y);
        }
    }
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        glColor3f(1, 0, 0);
        SimpleLine(100, 100, 500, 100);
        break;
    case 'd':
        glColor3f(1, 0, 0);
        DottedLine(500, 100, 500, 500);
        break;
    case 'D':
        glColor3f(1, 0, 0);
        DashedLine(500, 500, 100, 500);
        break;
    case 'b':
        glColor3f(1, 0, 0);
        bresenhams(100, 100, 100, 500);
        break;
    default:
        break;
    }
}

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 600, 0);
}

void primitives(void)
{
    glColor3f(0, 1, 0);
    SimpleLine(0, 300, 600, 300);
    SimpleLine(300, 0, 300, 600);

    glutKeyboardFunc(keyboard);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Assignment 2");

    initialize();

    cout << "s.Simple line\n";
    cout << "d.Dotted line\n";
    cout << "D.Dashed line\n";
    cout << "b.Bresenham's algorithm\n";

    glutDisplayFunc(primitives);
    glutMainLoop();
    return 0;
}

// to run
//  g++ assign2.cpp -o App -lglut -lGLU -lGL && ./App