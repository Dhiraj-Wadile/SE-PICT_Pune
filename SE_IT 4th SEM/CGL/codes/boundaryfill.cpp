#include<GL/glut.h>
#include<iostream>
 
using namespace std;

float boundary_color[3],fill_color[3];
 
void init()
{
    gluOrtho2D(0,500,0,500); 
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glColor3f(1,0,0);
}
 
void plotPixel(int x,int y,float* fill_color)
{
    glColor3f(fill_color[0],fill_color[1],fill_color[2]);
     
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
 
    glFlush();    
}
 
 
void boundaryFill(int x,int y,float* fill_color,float* boundary_color)
{
    float current[3];
     
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,current);//Fetch the color information of the pixel 
    
    if((current[0] != boundary_color[0] || current[1] != boundary_color[1] ||current[2] != boundary_color[2] ) &&
    (current[0] != fill_color[0] || current[1] != fill_color[1] ||current[2] != fill_color[2] ))
    {
        plotPixel(x,y,fill_color);
        boundaryFill(x+1,y,fill_color,boundary_color);
        boundaryFill(x-1,y,fill_color,boundary_color);
        boundaryFill(x,y+1,fill_color,boundary_color);
        boundaryFill(x,y-1,fill_color,boundary_color);
    }
}
 
void polygonShape()
{
    glClear(GL_COLOR_BUFFER_BIT);
 
    glBegin(GL_LINE_LOOP); //Draw Polygon Shape
       /* glVertex2i(100,100);
        glVertex2i(250,100);
        glVertex2i(250,300);
        glVertex2i(400,300);
        glVertex2i(400,450);
        glVertex2i(240,450);
        glVertex2i(240,310);
        glVertex2i(100,310);
        */
        
        glVertex2i(100,100);
        glVertex2i(300,100);
        glVertex2i(150,300);
    
        
    glEnd();
 
    glFlush();
 
    //float boundary_color[3],fill_color[3];
     
    boundary_color[0] = 1;  //boundary color - Red color
    boundary_color[1] = 0;
    boundary_color[2] = 0;
     
     
    fill_color[0]=0; // fill color - Green Color
    fill_color[1]=1;
    fill_color[2]=0;
 
    //boundaryFill(110,110,fill_color,boundary_color); 
}
void type(unsigned char key,int x,int y)
{
    if(key=='c')
    {
       boundaryFill(110,110,fill_color,boundary_color);
       glFlush(); 
    }
}
 
int main(int argc,char **argv)
{
   glutInit(&argc, argv);       // Initializing the library
   glutInitWindowSize(500,500);
   glutInitWindowPosition(400,150);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
   glutCreateWindow("Boudary Fill");
  
   init(); 

   glutDisplayFunc(polygonShape);
    glutKeyboardFunc(type);
   glutMainLoop(); 
   return 0;
}


