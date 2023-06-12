#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

#define Xmax 1400
#define Ymax 900
#define Radian (3.14/180)


void draw(int );
void drawkoch(float,float,float,float,int);


void draw(int n)
{
   glBegin(GL_LINES);
      drawkoch(600,100,800,400,n);
      drawkoch(800,400,400,400,n);
      drawkoch(400,400,600,100,n);
   glEnd();
   glFlush();
      
}

void drawkoch(float xa,float ya,float xb,float yb,int n)
{
  float xc,yc,xd,yd,midx,midy;
  
  xc=(2*xa+xb)/3;
  yc=(2*ya+yb)/3;
  xd=(2*xb+xa)/3;
  yd=(2*yb+ya)/3;
  
  midx=xc+((xd-xc)*cos(60*Radian))+((yd-yc)*sin(60*Radian));
  midy=yc-((xd-xc)*sin(60*Radian))+((yd-yc)*cos(60*Radian));
  
  if(n>0)
  { 
    drawkoch(xa,ya,xc,yc,n-1);
    drawkoch(xc,yc,midx,midy,n-1);
    drawkoch(midx,midy,xd,yd,n-1);
    drawkoch(xd,yd,xb,yb,n-1);
  }
  else{
      glVertex2f(xa,ya);
      glVertex2f(xc,yc);
      
      glVertex2f(xc,yc);
      glVertex2f(midx,midy);
      
      glVertex2f(midx,midy);
      glVertex2f(xd,yd);
      
      glVertex2f(xd,yd);
      glVertex2f(xb,yb);
      
  }
  
}

void init()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0,0,0,0.3);
  glColor3f(1,1,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,Xmax,0,Ymax); 
}

int main(int argc,char **argv)
{
int n;
cout<<"Enter the no of iteration u want::"<<endl;
cin>>n;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
glutInitWindowSize(500,500);
//glutInitWindowPosition(0,0);
glutCreateWindow("Koch Curve");
init();
draw(n);

glutMainLoop();
return 0;
}





