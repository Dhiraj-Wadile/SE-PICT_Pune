

#include<iostream>
#include<stdio.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<vector>
using namespace std;
typedef struct pixel 
{
    GLubyte r,g,b;
} pixel;
pixel b_fill,f_fill;
 

int ch=1;
vector<int> x={200,250,250,300,300,250,250,200,200,150,150,200};
vector<int> y={100,100,150,150,200,200,250,250,200,200,150,150};
int ssize=12;
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,640,0,480);
}

void draw()
{
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<ssize;i++)
    {
        glVertex2f(x[i],y[i]);
    }
    
    glEnd();
    glFlush();
    

}
void point1()
{
     int x1 = (x[11]+x[5])/2;
    int y1 = (y[11]+y[5])/2;
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(x1,y1);
    glEnd();
    glFlush();
}
void boundry_fill(int x,int y)
{
    pixel c;
    b_fill.r=b_fill.g=b_fill.b=0;
    f_fill.r=0;
    f_fill.b=255;
    f_fill.g=0;
    glPointSize(1);
    glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&c);
    if(c.r!=b_fill.r &&c.g!=b_fill.g&&c.b!=b_fill.b )
    {
        glColor3ub(f_fill.r,f_fill.g,f_fill.b);
        glBegin(GL_POINTS);
        glVertex2d(x,y);
        glEnd();
        glFlush();
        boundry_fill(x+1,y);
        boundry_fill(x-1,y);
        boundry_fill(x,y+1);
        boundry_fill(x,y-1);
    }
}
void rotate()
{
    float angleRad = 45*3.13/180;
    float centerX = 100.0, centerY = 100.0; // Center of rotation

    for (int i = 0; i < ssize; i++)
    {
        float originalX = x[i] - centerX;
        float originalY =y[i] - centerY;

        // Apply rotation formula
    x[i] = originalX * cos(angleRad) - originalY * sin(angleRad) + centerX;
    y[i] = originalX * sin(angleRad) + originalY * cos(angleRad) + centerY;
    }

}
void before()
{
    draw();
    point1();

}
void after()
{
    glClear(GL_COLOR_BUFFER_BIT);
    rotate();
    draw();
    point1();
    int x1 = (x[11]+x[5])/2;
    int y1 = (y[11]+y[5])/2;
    boundry_fill(x1+25,y1);
}
void mymouse(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT && state==GLUT_DOWN)
    {
        switch(ch)
        {
            case 1:
            before();
            ch=2;
            break;
            case 2:
            after();
            ch=3;
            break;
            case 3:
            break;
        }
    }
}
void init_func()
{
    glFlush();
}
int main(int argc ,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE||GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Add Symbol");
    init();
    glutDisplayFunc(init_func);
    glutMouseFunc(mymouse);
    glutMainLoop();
    return 0;
}



