#include <GL/glut.h>  
#include<iostream> 

  int ww = 600, wh = 500;   

  float intCol[3];   
  float fillCol[3];  


      void setPixel(int x, int y, float *f)   
      {   
          glColor3f(f[0],f[1],f[2]);
             glBegin(GL_POINTS);   
                //   glColor3fv(f);   
                  glVertex2i(x,y);   
             glEnd();   
             glFlush();   
      }  

 
  
  
      void drawPolygon(int x1, int y1, int x2, int y2)   
       {      
             glColor3f(1.0, 0.0, 0.0);   
             glBegin(GL_POLYGON);   
                  glVertex2i(x1, y1);    
                  glVertex2i(x1, y2);   
                  glVertex2i(x2, y2);   
                  glVertex2i(x2, y1);   
             glEnd();   
             glFlush();  
             
             //initial color as red;
             intCol[0]=1; 
             intCol[1]=0; 
             intCol[2]=0; 
             
             //fill color as green
             
             fillCol[0]=0;
             fillCol[1]=1;
             fillCol[2]=0;
                                 
       }   
       void display()   
       {   
               
             glClear(GL_COLOR_BUFFER_BIT);   
             drawPolygon(100,100,200,200);   
             glFlush();   
       }  

 
       void floodfill4(int x,int y,float *oldcolor,float *newcolor)   
       {   
            float color[3];   
            glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
               
            if(color[0]==oldcolor[0] && (color[1])==oldcolor[1] && (color[2])==oldcolor[2])   
            {   
                     setPixel(x,y,newcolor);   
                     floodfill4(x+1,y,oldcolor,newcolor);   
                     floodfill4(x-1,y,oldcolor,newcolor);   
                     floodfill4(x,y+1,oldcolor,newcolor);   
                     floodfill4(x,y-1,oldcolor,newcolor);   
             }   
       }   

   
   void type(unsigned char key,int x,int y)
{
    if(key=='c')
    {
          floodfill4(110,110,intCol,fillCol);
       glFlush(); 
    }
}
       void mouse(int btn, int state, int x, int y)   
       {   
             if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)    
            {   
                     int xi = x;   
                     int yi = wh-y;   
                     floodfill4(xi,yi,intCol,fillCol);   
             }   
       }  
 
       void myinit()   
       
       {       
             glClearColor(1,1,1,1); 
            glMatrixMode(GL_PROJECTION);                 
            gluOrtho2D(0.0,ww,0.0,wh);   
             
       }   



int main(int argc, char** argv)   
       {   
             glutInit(&argc,argv);   
             glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   
             glutInitWindowSize(ww,wh);   
             glutCreateWindow("Flood-Fill-Recursive"); 
  
             glutDisplayFunc(display);   

             myinit();  
 
             //glutMouseFunc(mouse);   
             glutKeyboardFunc(type);
             glutMainLoop();   
             return 0;   
             
       }   
