#include <GL/freeglut.h>
#include<GL/gl.h>
#include<iostream>
using namespace std;
int p=0,q=0,r=250;
void putPixel(float x, float y)
{
glColor3f(1,1,1);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();
}
void bresenCircle(float p, float q, float r)
{
float x, y, d;
d = 3 - 2*r;
x = 0;
y = r;
while(x <= y)
{
putPixel(x+p, y+q);
putPixel(y+p, x+q);
putPixel(-y+p, x+q);
putPixel(-x+p, y+q);
putPixel(-x+p, -y+q);
putPixel(-y+p, -x+q);
putPixel(y+p, -x+q);
putPixel(x+p, -y+q);
if(d < 0)
d += 4*x + 6;
else

{
y--;
d += 4*(x - y) + 10;
}
x++;
}
glFlush();
}
void draw()
{

glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,1,1);
gluOrtho2D(-750, 750, -450, 450);


bresenCircle(0,0,r/1.9);
bresenCircle(0,-r*0.700,r/6);

bresenCircle(0,-r*1.056,r/6);
bresenCircle(-r*0.320,-r*0.625,r/6);
bresenCircle(r*0.320,-r*0.625,r/6);
bresenCircle(-r*0.320,r*0.625,r/6);
bresenCircle(r*0.320,r*0.625,r/6);
bresenCircle(r*0.540,r*0.850,r/6);
bresenCircle(r*0.820,r*1.046,r/6);
bresenCircle(-r*0.320,r*0.625,r/6);
bresenCircle(-r*0.540,r*0.850,r/6);
bresenCircle(-r*0.820,r*1.046,r/6);

glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowPosition(100,100);
glutInitWindowSize(1500,900);
glutCreateWindow("Circular Pattern");
glutDisplayFunc(draw);
glutMainLoop();
return 0;
}
