//  Write a Program in OpenGL on Linux Platform to draw following pattern by a Line
//  using DDA Line Drawing Algorithm. (Use Mouse / Without Mouse to Plot the Points.)
//  ( A Monitor Screen with a Hill On Display )

// color it using any seedfill algorithm

#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


typedef struct Color
{
float r, g, b;
} Color;

Color b_color = {0, 0, 0};
Color f_color;

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
   
    // this is the main thing to keep in mind
    gluOrtho2D(0, 800, 0, 800);
}

Color getPixelColor(float x, float y)
{
Color c;
glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &c);
return c;
}

// boundary fill algorithm

void boundaryfill(int x, int y)
{

Color c;
c = getPixelColor(x, y);

if((c.r != b_color.r || c.g != b_color.g || c.b != b_color.b) && (c.r != f_color.r || c.g != f_color.g || c.b != f_color.b))
{
glBegin(GL_POINTS);
glColor3f(f_color.r, f_color.g, f_color.b);
glVertex2i(x,y);
glEnd();
glFlush();
boundaryfill(x+1, y);
boundaryfill(x-1, y);
boundaryfill(x, y+1);
boundaryfill(x, y-1);
}

glFlush();

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
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

    for(int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
    glFlush();

}


void primitives(void)
{
glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 0);

    simpleLine(100, 700, 700, 700);
    simpleLine(150, 650, 650, 650);
   
    simpleLine(100, 700, 100, 300);
    simpleLine(150, 650, 150, 350);
   
    simpleLine(700, 700, 700, 300);
    simpleLine(650, 650, 650, 350);
   
   
    simpleLine(150, 350, 650, 350);
    simpleLine(100, 300, 300, 300);
    simpleLine(500, 300, 700, 300);
   
    simpleLine(300, 300, 200, 200);
    simpleLine(500, 300, 600, 200);
    simpleLine(200, 200, 600, 200);
   
    // hills
   
    simpleLine(150, 350, 275, 500);
    simpleLine(275, 500, 400, 350);
   
    simpleLine(400, 350, 550, 500);
    simpleLine(550, 500, 650, 350);
   
   
    f_color.r = 0.0f;
    f_color.g = 1.0f;
    f_color.b = 0.0f;
   
    boundaryfill(500, 425);
    boundaryfill(200, 400);
   
    glFlush();
   
    f_color.r = 1.0f;
    f_color.g = 0.0f;
    f_color.b = 0.0f;
   
    boundaryfill(125, 325);
   
    glFlush();

}

// normal main function

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Monitor hills using DDA");

    initialize();
    glutDisplayFunc(primitives);

    glutMainLoop();
    return 0;
}