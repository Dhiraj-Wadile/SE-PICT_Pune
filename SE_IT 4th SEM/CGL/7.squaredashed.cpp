

#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
using namespace std;

int px, py, qx, qy;

void putPixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void dda(int x1, int y1, int x2, int y2){
    float dx, dy, incx, incy, steps;
    dx = x2 - x1;
    dy = y2 - y1;

    steps = max(abs(dx), abs(dy));
    incx = dx / steps;
    incy = dy / steps;

    for(int i=0; i<steps; i++){
        if(i%10<5)
            putPixel(x1, y1);
        x1 += incx;
        y1 += incy;
    }
}

void init(){
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 600, 0);
}

void generateSq(int x, int y, int (&sq)[5][3], int l, int type){
    if(type == 1){
        sq[0][0] = x;
        sq[0][1] = y;
        sq[1][0] = x+l;
        sq[1][1] = y;
        sq[2][0] = x+l;
        sq[2][1] = y+l;
        sq[3][0] = x;
        sq[3][1] = y+l;
        sq[4][0] = x;
        sq[4][1] = y;
    }else{
        sq[0][0] = x;
        sq[0][1] = y;
        sq[1][0] = x+l/2;
        sq[1][1] = y+l/2;
        sq[2][0] = x;
        sq[2][1] = y+l;
        sq[3][0] = x-l/2;
        sq[3][1] = y+l/2;
        sq[4][0] = x;
        sq[4][1] = y;
    }

}

void displaySq(int sq[5][3]){
    for(int i=0; i<4; i++){
        dda(sq[i][0], sq[i][1], sq[i+1][0], sq[i+1][1]);
        cout << sq[i][0] << " " << sq[i][1]<< " " <<  sq[i+1][0]<< " " <<  sq[i+1][1]<<endl;
    }
}

void display(){
    glPointSize(3);
    glColor3f(1, 0, 0);
    int length = qy - py;

    int sq1[5][3], sq2[5][3], sq3[5][3];
    generateSq(px, py, sq1, length, 1);
    displaySq(sq1);
    generateSq(px+length/2, py, sq2, length, 2);
    displaySq(sq2);
    generateSq(px+length/4, py+length/4, sq3, length/2, 1);
    displaySq(sq3);
}

int main(int argc, char** argv){

   /* cout << "Enter px: ";
    cin >> px;
    cout << "Enter py: ";
    cin >> py;
    cout << "Enter qx: ";
    cin >> qx;
    cout << "Enter qy: ";
    cin >> qy;
    */

    px=200, py=200, qx=500, qy=500;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Problem 9 - differeent dashed lines and squares");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}
