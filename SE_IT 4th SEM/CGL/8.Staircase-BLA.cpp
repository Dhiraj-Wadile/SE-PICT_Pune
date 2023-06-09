
/*
Write a Program in OpenGL on Linux Platform to draw following pattern by a Line
using DDA Line Drawing Algorithm. (Use Mouse / Without Mouse to Plot the
Points.)
stairs and reflection combined
*/

#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

using namespace std;

double stairs[13][3]={1};

void putPixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawLine(int x1, int y1, int x2, int y2){
    float dx, dy, x, y, p;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = min(x2, x1);
    y = min(y2, y1);

    if(dx > dy){
        p = 2*dy - dx;
        for(int i=0; i<dx; i++){
            if(p>=0){
                p += 2*(dy-dx);
                y++;
            }else{
                p += 2*dy;
            }
            x++;
            putPixel(x, y);
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
            putPixel(x, y);
        }
    }
}

void createStairs(){
    int x=100, y=100;
    for(int i=0; i<10; i+=2){
        stairs[i][0] = x;
        stairs[i][1] = y;
        y+=20;
        stairs[i+1][0] = x;
        stairs[i+1][1] = y;
        x+=20;
    }
    stairs[10][0] = x;
    stairs[10][1] = y;
    stairs[11][0] = x;
    stairs[11][1] = 100;
    stairs[12][0] = 100;
    stairs[12][1] = 100;
}

void displayStairs(double arr[][3]){
    for(int i=0; i<12; i++){
        drawLine(arr[i][0], arr[i][1], arr[i+1][0], arr[i+1][1]);
    }
}

void drawDividers(){
    glColor3f(1, 0, 0);
    glPointSize(2);
    drawLine(-300, 0, 300, 0);
    drawLine(0, 300, 0, -300);
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 300, -300, 300);
}

void display(){
    glColor3f(0, 0, 0);
    createStairs();
    displayStairs(stairs);

    drawDividers();
}

void reflectionXaxis(){
    double m[3][3] = {0};
    m[0][0] = 1;
    m[1][1] = -1;
    m[2][2] = 1;

    double result[13][3] = {0};

    for(int i=0; i<13; i++){
        for(int j=0; j<3; j++){
            int sum=0;
            for(int k=0; k<3; k++){
                sum += stairs[i][k]*m[k][j];
            }
            result[i][j] = sum;
        }
    }
    glClear(GL_COLOR_BUFFER_BIT);
    drawDividers();
    glColor3f(0, 0, 0);
    displayStairs(stairs);
    displayStairs(result);
 }

void reflectionYaxis(){
    double m[3][3] = {
        {-1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    double result[13][3] = {0};

    for(int i=0; i<13; i++){
        for(int j=0; j<3; j++){
            int sum=0;
            for(int k=0; k<3; k++){
                sum += stairs[i][k]*m[k][j];
            }
            result[i][j] = sum;
            cout<<sum << " ";
        }
        cout << endl;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    drawDividers();
    glColor3f(0, 0, 0);
    displayStairs(stairs);
    displayStairs(result);
 }


void menu(int item){
    if(item == 1){
        reflectionXaxis();
    }
    if(item == 2){
        reflectionYaxis();
    }
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Problem 10 - create stairs");

    init();
    glutDisplayFunc(display);

    glutCreateMenu(menu);
    glutAddMenuEntry("reflection in x axis", 1);
    glutAddMenuEntry("reflection in y axis", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    return 0;
}
