
#include<iostream>
#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
using namespace std;


void circle(int xc,int yc,int r)
{
   int x=0;
   int y=r;
   int d=3-2*r;
   
   glColor3f(1,0,0);
   glBegin(GL_POINTS);
   while(x<=y)
   {
     glVertex2i(xc+x,yc+y);
     glVertex2i(xc+x,yc-y);
     glVertex2i(xc-x,yc+y);
     glVertex2i(xc-x,yc-y);
     glVertex2i(xc+y,yc+x);
     glVertex2i(xc+y,yc-x);
     glVertex2i(xc-y,yc+x);
     glVertex2i(xc-y,yc-x);
     
     if(d<0)
     {
        d=d+4*x+6;
        x++;
     }
     else
     {
       d=d+4*(x-y)+10;
       x++;
       y--;
     }
    
   }
   glEnd();
   glFlush();
}
void shape()
{
  circle(0,0,160);
  circle(0,0,150);
  
  //circle(0,0,180);
  circle(180*cos(0),180*sin(0),20);
  circle(180*cos(12.84*3.142/180),180*sin(12.84*3.142/180),20);
  circle(180*cos(25.68*3.142/180),180*sin(25.68*3.142/180),20);
  circle(180*cos(38.52*3.142/180),180*sin(38.52*3.142/180),20);
  circle(180*cos(51.36*3.142/180),180*sin(51.36*3.142/180),20);
  circle(180*cos(12.84*5*3.142/180),180*sin(12.84*5*3.142/180),20);
  circle(180*cos(12.84*6*3.142/180),180*sin(12.84*6*3.142/180),20);
  circle(180*cos(12.84*7*3.142/180),180*sin(12.84*7*3.142/180),20);
  
  
  //
  
  circle(180*cos(180*3.142/180),180*sin(180*3.142/180),20);
  
  circle(-180*cos(12.84*3.142/180),180*sin(12.84*3.142/180),20);
  circle(-180*cos(25.68*3.142/180),180*sin(25.68*3.142/180),20);
  circle(-180*cos(38.52*3.142/180),180*sin(38.52*3.142/180),20);
  circle(-180*cos(51.36*3.142/180),180*sin(51.36*3.142/180),20);
  circle(-180*cos(12.84*5*3.142/180),180*sin(12.84*5*3.142/180),20);
  circle(-180*cos(12.84*6*3.142/180),180*sin(12.84*6*3.142/180),20);
  circle(-180*cos(12.84*7*3.142/180),180*sin(12.84*7*3.142/180),20);
 //
 
  circle(180*cos(270*3.142/180),180*sin(270*3.142/180),20);
  
  circle(-180*cos(12.84*3.142/180),-180*sin(12.84*3.142/180),20);
  circle(-180*cos(25.68*3.142/180),-180*sin(25.68*3.142/180),20);
  circle(-180*cos(38.52*3.142/180),-180*sin(38.52*3.142/180),20);
  circle(-180*cos(51.36*3.142/180),-180*sin(51.36*3.142/180),20);
  circle(-180*cos(12.84*5*3.142/180),-180*sin(12.84*5*3.142/180),20);
  circle(-180*cos(12.84*6*3.142/180),-180*sin(12.84*6*3.142/180),20);
  circle(-180*cos(12.84*7*3.142/180),-180*sin(12.84*7*3.142/180),20);
 //
  
  
  
  circle(180*cos(12.84*3.142/180),-180*sin(12.84*3.142/180),20);
  circle(180*cos(25.68*3.142/180),-180*sin(25.68*3.142/180),20);
  circle(180*cos(38.52*3.142/180),-180*sin(38.52*3.142/180),20);
  circle(180*cos(51.36*3.142/180),-180*sin(51.36*3.142/180),20);
  circle(180*cos(12.84*5*3.142/180),-180*sin(12.84*5*3.142/180),20);
  circle(180*cos(12.84*6*3.142/180),-180*sin(12.84*6*3.142/180),20);
  circle(180*cos(12.84*7*3.142/180),-180*sin(12.84*7*3.142/180),20);
  
  
   glBegin(GL_LINES);
     glVertex2f(-320,0);
     glVertex2f(320,0);
     glVertex2f(0,-240);
     glVertex2f(0,240);
    glEnd();
    glFlush(); 
     
  
  
  
   
   
   
   
}
void init()
{
   glClearColor(0.0,0.0,0.0,0.3);
   glLoadIdentity();
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(-320,320,-240,240);
   
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
 
    glutCreateWindow("Line");
    glutDisplayFunc(shape);
    init();
    //menu();
    glutMainLoop();
    
    return 0;
}





