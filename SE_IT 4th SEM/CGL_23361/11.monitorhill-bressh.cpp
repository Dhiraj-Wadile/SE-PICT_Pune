//  Write a Program in OpenGL on Linux Platform to draw a Dash-Dot-Dash Line & Dash
//  Line using DDA Line Drawing Algorithm. Divide the screen in four quadrants with
//  centre as (0,0). Use Mouse / Without Mouse to Plot the Points.


#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void displayPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhams(int x1, int y1, int x2, int y2)
{
    int x, y, dx, dy;
    int e, incx, incy, inc1, inc2;
    dx = x2 - x1;
    dy = y2 - y1;

    if(dx < 0)
        dx = -dx;
    if(dy < 0) 
        dy = -dy;

    incx = 1;
    if(x2 < x1)
        incx = -1;
    incy = 1;
    if(y2 < y1)
        incy = -1;

    x = x1;
    y = y1;
    if(dx >= dy)
    {
        displayPoint(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for(int i = 0; i < dx; i++)
        {
            if(e >= 0)
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
        for(int i = 0; i < dy; i++)
        {
            if(e >= 0)
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

void primitives(void)
{
    glColor3f(0, 0, 0);

    // lower line
    bresenhams(100, 500, 350, 500);
    bresenhams(450, 500, 700, 500);

    bresenhams(150, 450, 650, 450);

    // upper line
    bresenhams(100, 100, 700, 100);
    bresenhams(150, 150, 650, 150);

    // left line
    bresenhams(100, 100, 100, 500);
    bresenhams(150, 150, 150, 450);

    // right line
    bresenhams(700, 100, 700, 500);
    bresenhams(650, 150, 650, 450);


    // monitor stand
    bresenhams(250, 600, 550, 600);

    bresenhams(250, 600, 350, 500);
    bresenhams(550, 600, 450, 500);

    // hills on monitor
    bresenhams(150, 450, 250, 375);
    bresenhams(250, 375, 350, 450);

    bresenhams(350, 450, 500, 290);
    bresenhams(500, 290, 650, 450);

}

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 800, 800, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Monitor hills using bresenhams");

    initialize();
    glutDisplayFunc(primitives);
    glutMainLoop();
    return 0;
}
