#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double et[3][3] = {1}, ans[3][3]={0};
float xi, yi;
int length;

void dda(int x1, int y1, int x2, int y2){
    float dx, dy, incx, incy, steps;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = max(abs(dx), abs(dy));
    incx = dx!=0 ? steps / dx : 0;
    incy = dy!=0 ? steps / dy : 0;
    int x=x1, y=y1;
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    for(int i=1; i<=steps; i++){
        glVertex2i(x, y);
        x += incx;
        y += incy;
    }
    glEnd();
    glFlush();
}

void drawET(double triangle[3][3]){
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<3; i++){
        glVertex2i(triangle[i][0], triangle[i][1]);
    }
    glEnd();
    glFlush();
}

void multi3x3(double mat1[3][3], double mat2[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int sum = 0;
            for(int k=0; k<3; k++){
                sum += mat1[i][k] * mat2[k][j];
            }
            ans[i][j] = sum;
        }
    }
}

void translation(){
    int tx, ty;
    cout << "Enter the sx: ";
    cin >> tx;
    cout << "Enter the sy: ";
    cin >> ty;

    double tMatrix[3][3]={0};
    tMatrix[0][0] = 1;
    tMatrix[1][1] = 1;
    tMatrix[2][2] = 1;
    tMatrix[2][0] = tx;
    tMatrix[2][1] = ty;

    multi3x3(et, tMatrix);
    glColor3f(0, 0, 1);
    drawET(ans);
}

void scaling(){
    float sx, sy;
    cout << "Enter scaling for x: ";
    cin >> sx;
    cout << "Enter scaling for y: ";
    cin >> sy;
    double Smatrix[3][3]={0};
    Smatrix[0][0] = sx;
    Smatrix[1][1] = sy;
    Smatrix[2][2] = 1;

    multi3x3(et, Smatrix);
    glColor3f(1, 1, 0);
    drawET(ans);
}

void rotation(){
    double rx, ry, angle;
    cout << "Enter rotation angle: ";
    cin >> angle;
    cout << "Enter arbiratary x point: ";
    cin >> rx;
    cout << "Enter arbitratiry y point: ";
    cin >> ry;

    double rMatrix[3][3] = {0};
    rMatrix[0][0] = cos(angle);
    rMatrix[0][1] = sin(angle);
    rMatrix[1][0] = -sin(angle);
    rMatrix[1][1] = cos(angle);
    rMatrix[2][0] = rx - (rx*cos(angle)) + (ry*sin(angle));
    rMatrix[2][1] = ry - (rx*sin(angle)) - (ry*cos(angle));
    rMatrix[2][2] = 1;

    glColor3f(1, 0, 1);
    multi3x3(et, rMatrix);
    drawET(ans);
}

void menu(int item){
    switch(item){
    case 1:
        translation();
        break;
    case 2:
        scaling();
        break;
    case 3:
        rotation();
        break;
    default:
        break;
    }
}

void display(){
    dda(0, 300, 0, -300);
    dda(-300, 0, 300, 0);
    glColor3f(0, 1, 0);
    drawET(et);
}

void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv){
    /*
    cout << "Enter the length of eq triangle: ";
    cin >> length;
    cout << "Enter the starting point of triangle: ";
    cout << "\nx point: ";
    cin >> xi;
    cout << "y point: ";
    cin >> yi;
    */
    length = 100;
    xi = 50;
    yi = 50;

    et[0][0] = xi;
    et[0][1] = yi;
    et[0][2] = 1;
    et[1][0] = xi+length;
    et[1][1] = yi;
    et[1][2] = 1;
    et[2][0] = xi+length/2;
    et[2][1] = (sqrt(3)/2 * length) + yi;
    et[2][2] = 1;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Problem 2 - ");

    init();
    glutDisplayFunc(display);

    glutCreateMenu(menu);
    glutAddMenuEntry("Translation", 1);
    glutAddMenuEntry("Scaling", 2);
    glutAddMenuEntry("Rotation", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    return 0;
}
