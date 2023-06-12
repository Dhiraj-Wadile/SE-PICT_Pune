/*
Write a program in OpenGL on Linux Platform to
draw a polygon as shown at right and perform
following 2D Transformation on it keeping the
centre dot as reference point. Rotate it by 45
Degrees anticlockwise. Fill it with any color using
any Seed Fill Algorithm
*/

#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double mat[20][3]={1}, ans[20][3];

void createFig(){
    mat[0][0]=200;
    mat[0][1]=200;
    mat[1][0]=320;
    mat[1][1]=200;
    mat[2][0]=320;
    mat[2][1]=280;
    mat[3][0]=360;
    mat[3][1]=280;
    mat[4][0]=360;
    mat[4][1]=200;
    mat[5][0]=400;
    mat[5][1]=200;
    mat[6][0]=400;
    mat[6][1]=320;
    mat[7][0]=320;
    mat[7][1]=320;
    mat[8][0]=320;
    mat[8][1]=360;
    mat[9][0]=400;
    mat[9][1]=360;
    mat[10][0]=400;
    mat[10][1]=400;
    mat[11][0]=280;
    mat[11][1]=400;
    mat[12][0]=280;
    mat[12][1]=320;
    mat[13][0]=240;
    mat[13][1]=320;
    mat[14][0]=240;
    mat[14][1]=400;
    mat[15][0]=200;
    mat[15][1]=400;
    mat[16][0]=200;
    mat[16][1]=280;
    mat[17][0]=280;
    mat[17][1]=280;
    mat[18][0]=280;
    mat[18][1]=240;
    mat[19][0]=200;
    mat[19][1]=240;
    mat[0][2] = 1;
    mat[1][2] = 1;
    mat[2][2] = 1;
    mat[3][2] = 1;
    mat[4][2] = 1;
    mat[5][2] = 1;
    mat[6][2] = 1;
    mat[7][2] = 1;
    mat[8][2] = 1;
    mat[9][2] = 1;
    mat[10][2] = 1;
    mat[11][2] = 1;
    mat[12][2] = 1;
    mat[13][2] = 1;
    mat[14][2] = 1;
    mat[15][2] = 1;
    mat[16][2] = 1;
    mat[17][2] = 1;
    mat[18][2] = 1;
    mat[19][2] = 1;
}

void displayFig(double arr[20][3]){
    glColor3f(1, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<20;i++){
        glVertex2i(arr[i][0], arr[i][1]);
    }
    glEnd();
    glFlush();
}

void putPixel(int x, int y){
    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 0, 600);
}

void display(){
    createFig();
    displayFig(mat);
}

void rotation(){
    int angle=45;
    int rx=0, ry=0;
    double rM[3][3] = {0};
    rM[0][0] = cos(angle);
    rM[0][1] = -sin(angle);
    rM[0][0] = cos(angle);
    rM[1][1] = sin(angle);
    rM[2][0] = rx - (rx*cos(angle))+(ry*sin(angle));
    rM[2][1] = ry - (rx*sin(angle))-(ry*cos(angle));
    rM[1][1] = 1;

    for(int i=0; i<20; i++){
        for(int j=0; j<3; j++){
            int sum = 0;
            for(int k=0; k<3; k++){
                sum += mat[i][k]*rM[k][j];
            }
            ans[i][j] = sum;
        }
    }
    glClear(GL_COLOR_BUFFER_BIT);
    displayFig(ans);
}

void flood_fill(int x, int y){
    float c[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &c);
    //cout << c[0] << " " << c[1] << " " << c[2] << endl;
    if(c[0]==1 && c[1]==1 && c[2]==1){
        putPixel(x, y);
        flood_fill(x+1, y);
        flood_fill(x-2, y);
        flood_fill(x, y+1);
        flood_fill(x, y-2);
    }
}

void menu(int i){
    if(i == 1){
        rotation();
    }
    if(i == 2){
        flood_fill(300, 300);
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 8 - swaastik");

    init();
    glutDisplayFunc(display);

    glutCreateMenu(menu);
    glutAddMenuEntry("Rotation", 1);
    glutAddMenuEntry("Fill the box", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    return 0;
}
