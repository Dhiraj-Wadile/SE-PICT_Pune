#include<iostream>
#include<GL/glut.h>
using namespace std;


void bplot(int x,int y,int i)
{ 
   //glPointSize(2);
    glColor3f(1,1,0);
    glBegin(GL_POINTS);  
     if((i/10)&1) 
     {
      glVertex2f(x,y);     
     }
    glEnd();
    glFlush();
}


void bres(int X1,int Y1,int X2,int Y2)
{
    float x=X1;
    float y=Y1;
    
    float dx=abs(X2-X1);
    float dy=abs(Y2-Y1);
    
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


void shape()
{
   
         
         bres(100,100,500,100);
         
         bres(100,100,100,500);
         bres(100,500,500,500);
         bres(500,100,500,500);
      
         bres(300,100,500,300);
        bres(300,500,500,300);
        bres(300,500,100,300);
        bres(300,100,100,300);
        bres(200,200,400,200);
        bres(200,400,400,400);
        bres(200,200,200,400);
        bres(400,200,400,400);
                  
}

void init()
{
   glClearColor(0.0,0.0,0.0,0.3);
   glLoadIdentity();
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(0,1000,0,1000);
   
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
