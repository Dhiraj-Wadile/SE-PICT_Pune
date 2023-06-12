#include<iostream>
#include<GL/glut.h>
using namespace std;

int choice;

void plot(float x,float y,int i)
{ 

                
     glColor3f(1,0,0);
     glBegin(GL_POINTS);
          glColor3f(1,0,1);
                glVertex2f(x,y);
    glEnd();
    glFlush();   
}

void dda(int X1,int Y1,int X2,int Y2)
{
  float dx=X2-X1;
  float dy=Y2-Y1;
  float steps;
  
  if(abs(dx)>=abs(dy))
  {
     steps=abs(dx);
  }
  else
  {
      steps=abs(dy);
  }
  float xi=dx/steps;
  float yi=dy/steps;
  
  float x,y;
  x=X1;
  y=Y1;
  

  
  for(int i=0;i<=steps;i++)
  {
     plot(x,y,i);
     if(choice==4)
     {
           glPointSize(3);  
     }
     x+=xi;
     y+=yi;
  }
  glEnd();
  glFlush();
  
}
void bplot(int x,int y,int i)
{ 
   //glPointSize(2);
    glColor3f(1,1,0);
    glBegin(GL_POINTS);   
      glVertex2f(x,y);     
    glEnd();
    glFlush();
}

void bres(int X1,int Y1,int X2,int Y2)
{
    float x=X1;
    float y=Y1;
    
    float dx=X2-X1;
    float dy=Y2-Y1;
    
    float p=2*dy-dx;
    
    float x_inc=X2>=X1?1:-1;
    float y_inc=Y2>=Y1?1:-1;
    
   
    
    if(dx>=dy)
    { 
       bplot(x,y,0);
       
       for(int i=0;i<dx;i++)
       {
           if(p>0)
           { 
             y=y+y_inc;
             p=p-2*dx;
           }
            x=x+x_inc;
            p=p+2*dy; 
           bplot(x,y,i);
       }
    }
    else
    {
       bplot(x,y,0);
       
       for(int i=0;i<dy;i++)
       { 
         if(p>0)
         {
           x=x+x_inc;
           p=p-2*dy;
         }
         y=y+y_inc;
         p=p+2*dx;
        bplot(x,y,i);
         
       }
    }
    glEnd();
    glFlush();
}


void menu()
{
    cout<<"1. simple \n 2.dot\n 3.dash\n4.big\n";
    cout<<"enter choice \n";
    cin>>choice;
}
  
void shape()
{
 
   dda(100,100,150,100);
    dda(150,100,150,150);
     dda(150,150,200,150);
      dda(200,150,200,200);
       dda(200,200,250,200);
       dda(250,75,250,200);
        dda(100,75,100,100);
         bres(100,75,250,75);
}

void init()
{
   glClearColor(0.0,0.0,0.0,0.3);
   glLoadIdentity();
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(0,500,0,500);
   
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Line");
    glutDisplayFunc(shape);
    init();
    //menu();
    glutMainLoop();
    
    return 0;
}
