#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void putPixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresehamsLine(int x1, int y1, int x2, int y2){
    float dx, dy, x, y, p;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = min(x2, x1);
    y = min(y2 , y1);

    if(dx > dy){
        p = 2*dy - dx;
        int val = 0;
        for(int i=0; i<dx; i++){
            if(p>=0){
                p += 2*(dy-dx);
                y++;
            }else{
                p += 2*dy;
            }
            x++;
            if(val < 10 || (val>14 && val<17))
                putPixel(x, y);
            val++;
            if(val == 20) val = 0;
        }
    }else{
        p = 2*dx - dy;
        for(int i=0; i<dy; i++){
            if(p>=0){
                p += 2*(dx-dy);
                x++;
            }else{
                p += 2*dx;
            }
            y++;
            if(i%10 < 6){
                putPixel(x, y);
            }

        }
    }
}

void display(){
    glColor3f(1, 0, 0);
    bresehamsLine(100, 100, 300, 290);
    bresehamsLine(0, 0, 10, 200);
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Problem 3 - line patterns");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
